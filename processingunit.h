/******************************************************************************
 *                                                                            *
 * MIT License                                                                *
 *                                                                            *
 * Copyright 2019 Gereon Such                                                 *
 *                                                                            *
 * Permission is hereby granted, free of charge, to any person obtaining      *
 * a copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including        *
 * without limitation the rights to use, copy, modify, merge, publish,        *
 * distribute, sublicense, and/or sell copies of the Software, and to         *
 * permit persons to whom the Software is furnished to do so, subject         *
 * to the following conditions:                                               *
 *                                                                            *
 * The above copyright notice and this permission notice shall be             *
 * included in all copies or substantial portions of the Software.            *
 *                                                                            *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,            *
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES            *
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                   *
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS        *
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN         *
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN          *
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. *
 ******************************************************************************/

#ifndef PROCESSINGUNIT_H
#define PROCESSINGUNIT_H

#include <functional>
#include <thread>
#include <mutex>
#include <vector>
#include "threadfifoqueue.h"

namespace gs {

/**
 * \class ProcessingUnit
 *
 * \brief Interface to process incoming data threadsafe
 *
 * Baseclass for a parallelized data processing. This units
 * process method is called in a seperate thread AUTOMATICALLY
 * when the constructor is called and manages reading the
 * data from a thread safe queue and emission via a bound
 * external function. By default, the thread and the object
 * itself are deleted.
 *
 * \author Gereon Such
 *
 * Contact: gereonsuch@gmail.com
 */

template <typename T>
class ProcessingUnit //all methods are implemented in class, thus are implicitly inline, thus class is inline
{
    std::mutex d_controllock;
    ThreadFIFOQueue<T> d_queue;
    std::function<void(T)> d_emit;
    bool d_finished;
    bool d_suicidal; //if true, object deletes itself after process method finished.

public:
    ProcessingUnit(std::function<void(T)> emission_func) :
        d_emit(emission_func),
        d_finished(false),
        d_suicidal(true)
    {
        /** \brief Creates a BaseProcessUnit
         *
         * @param[in] emission_func Link to the function, which is called after procession of a data block.
         */

        std::thread t(&ProcessingUnit<T>::process, this);
        t.detach();
    }

    void set_finished() {
        /** \brief Sets the processing unit to finished.
         *
         * Sets the finished flag to true, which has several flow control impacts
         *  - No more data can be enqueued
         *  - process method processes all items still in queue and exits then.
         *  - Processing units cannot be reactivated.
         */

        std::lock_guard<std::mutex> lock(d_controllock);
        d_finished=true;
    }

    bool finished() {
        /** \brief Returns true, if the Processing unit is finished and exited or about to exit, else false */

        std::lock_guard<std::mutex> lock(d_controllock);
        return d_finished;
    }

    void set_suicidal(bool suicidal=true) {
        /** \brief Sets the behaviour after process method has finished.
         *
         * If suicidal is true, the object deletes itself after process method is finished.
         * Property defaults to true.
         */

        std::lock_guard<std::mutex> lock(d_controllock);
        d_suicidal=suicidal;
    }

    bool push(T val, bool lastitem=false) {
        /** \brief Enqueues the given value in the processing chain if the unit is not yet finished.
         *
         * Returns true, if the item was enqueued, false, if enqueueing failed.
         *
         * @param[in] val      Value to be enqueued.
         * @param[in] lastitem Sets finished flag if true.
         */

        std::lock_guard<std::mutex> lock(d_controllock);

        if(d_finished) return false;

        d_finished=lastitem;

        d_queue.push(val);
        return true;
    }

protected:
    void process() {
        /** \brief Processing method which is called on construction and placed in another thread.
         *
         * Waits for data on input queue, which can be added via push method.
         * Until finished flag is set, more items are awaited.
         * If suicidal flag is set, process deletes the ProcessungUnit object
         * on completion.
         */

        while(!finished() || d_queue.size()){
            try{
                T val=d_queue.pop();

                d_emit( this->work(val) );
            }catch(std::exception &e){
                this->handle_exception(e);
            }
        }

        if(d_suicidal) delete this; //delete object on end of processing.
    }

    virtual void handle_exception(std::exception &e){
        /** \brief Virtual handle_exception method, by default, ignores the error.
         *
         * Overload this to handle errors.
         */
    }

    virtual T work(T input){
        /** \brief Virtual work method, which processes the input and returns the output.
         *
         * Overload this method for processing.
         */

        return input;
    }

};



/**
 * \class BufferedProcessingUnit
 *
 * \brief Interface to process incoming data with integrated buffering.
 *
 * Baseclass for a parallelized data processing. This object implements
 * the same interface as ProcessingUnit, but has additional internal
 * interface for the work method to transfer samples from one work
 * iteration to the next. Direct access to d_inbuffer is granted in
 * work methods.
 *
 * \author Gereon Such
 *
 * Contact: gereonsuch@gmail.com
 */


template <typename packetT, typename sampT>
class BufferedProcessingUnit : public ProcessingUnit<packetT>
{
    using ProcessingUnit<packetT>::ProcessingUnit; //inherit constructors

protected:
    std::vector<sampT> d_inbuffer;

    void append_buffer(std::vector<sampT> buffer){
        /** \brief Appends data to the buffer.*/

        d_inbuffer.insert(d_inbuffer.end(), buffer.begin(), buffer.end());
    }

    void clear_buffer(){
        /** \brief Clears the input buffer */

        d_inbuffer.clear();
    }

    void pop_buffer(size_t n){
        /** \brief Pops the first n items from inbuffer. */

        if(n>=d_inbuffer.size())
            d_inbuffer.clear();
        else
            d_inbuffer.erase(d_inbuffer.begin(), d_inbuffer.begin()+n);
    }

};

} //namespace gs



#endif // PROCESSINGUNIT_H
