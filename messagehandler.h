/******************************************************************************
 * Copyright 2019 Gereon Such                                                 *
 *                                                                            *
 * This is free software; you can redistribute it and/or modify               *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation; either version 3, or (at your option)        *
 * any later version.                                                         *
 *                                                                            *
 * This software is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this software; see the file COPYING.  If not, write to          *
 * the Free Software Foundation, Inc., 51 Franklin Street,                    *
 * Boston, MA 02110-1301, USA.                                                *
 ******************************************************************************/

#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <gnuradio/sync_block.h>
#include <pmt/pmt.h>
#include <map>
#include <string>
#include <mutex>

#include "processingunit.h"
#include "pmttools.h"

namespace gs {

class MessageHandler : public gr::sync_block{
    std::map<std::string, ProcessingUnit<pmt::pmt_t>* > d_processing_units;

    pmt::pmt_t d_msgin;
    pmt::pmt_t d_msgout;

    std::mutex d_output_mutex;

public:
    MessageHandler() :
        gr::sync_block("message_handler",
                       gr::io_signature::make(0, 0, 0),
                       gr::io_signature::make(0, 0, 0)),
        d_msgin(pmt::intern("msgin")),
        d_msgout(pmt::intern("msgout"))
    {
        //register in and out ports and bind the handle_input method to all incoming inputs.
        message_port_register_in(d_msgin);
        set_msg_handler(d_msgin, std::bind(&MessageHandler::handle_input, this, _1));
        message_port_register_out(d_msgout);
    }

    ~MessageHandler() {
        //make all processing unit exit, since the process method is executed in a seperate thread.
        std::map<std::string, ProcessingUnit<pmt::pmt_t>* >::iterator i;

        for(i=d_processing_units.begin();i!=d_processing_units.end();i++){
            try {
                i->second->set_suicidal(true); //makes the object delete themselves after finishing
                i->second->set_finished(); //makes the process routine run by the Processing unit exit after completion
            } catch (std::exception &e) {}
        }
    }

    void emit_msg(pmt::pmt_t msg){
        /** \brief Emits the message on the output port.
         *
         * This method is bound to all ProcessingUnits. Internal mutex and guard locks are implemented to make it thread safe.
         */

        std::lock_guard<std::mutex> lock(d_output_mutex);
        message_port_pub(d_msgout, msg);
    }

protected:
    virtual ProcessingUnit<pmt::pmt_t>* new_processingunit(){
        /** \brief Return a new ProcessingUnit instance.
         *
         * Overload this to create your Custom Processingunit and pass default parameters to it.
         *
         * DO NOT FORGET TO PASS EMIT FUNCTION!
         *
         * Defaults to: return new ProcessingUnit<pmt::pmt_t>( [this](pmt::pmt_t m){ this->emit_msg(m); } );
         */

        return new ProcessingUnit<pmt::pmt_t>( [this](pmt::pmt_t m){ this->emit_msg(m); } );
    }

    void handle_input(pmt::pmt_t msg){
        /** \brief Input method for all messages.
         *
         * Distributes all messages on seperate Processing units based on the messages ID.
         * If no ProcessingUnit is found, a new one is created.
         */

        //get ID
        std::string ID=pmttools::get_param(msg, "ID", std::string("None"));
        bool finished=pmttools::get_param(msg, "finished", true); /* if finished flag does not exist, force it true
                                                                   * by default value to make the thread finish. */

        //check if ID is in map or add new if it doesnt exist.
        std::map<std::string, ProcessingUnit<pmt::pmt_t>* >::iterator i=d_processing_units.find(ID);

        //if false, add new processing unit.
        if(i==d_processing_units.end()){
            ProcessingUnit<pmt::pmt_t> *unit=new_processingunit(); //create new instance

            //add new instance to the map
            std::pair<std::map<std::string, ProcessingUnit<pmt::pmt_t>* >::iterator,bool> p =
                    d_processing_units.insert(std::pair<std::string, ProcessingUnit<pmt::pmt_t>* >(ID, unit ) );

            if(p.second==false)
                return; //abort if Processing unit can not be inserted. This should not happen...

            i=p.first; //set iterator to the newly inserted processing unit
        }

        //add data to the processing unit.
        i->second->push(msg, finished);

        /* if finished flag is set, the pointer to the processing unit can be erased, since the object
         * deletes itself after completion of all messages in the queue(defaults to suicidal behaviour). */
        if(finished)
            d_processing_units.erase(i);
    }

private:
    int work(int noutput_items, gr_vector_const_void_star &input_items, gr_vector_void_star &output_items) {return 0;} //must be implemented to avoid abstract class.

};

} //namespace gs

#endif // MESSAGEHANDLER_H
