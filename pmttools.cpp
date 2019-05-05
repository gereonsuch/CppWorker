/******************************************************************************
 * Copyright 2018 Gereon Such                                                 *
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

#include "pmttools.h"

#include <exception>


pmt::pmt_t gs::pmttools::get_paramdict(pmt::pmt_t msg){
    /** \brief Returns the pmt value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        if(is_pair(msg)) msg=pmt::car(msg);
        if(!is_dict(msg)) return pmt::make_dict();

        return msg;
    } catch (std::exception &e) { /* Return the default value */ }

    return pmt::make_dict();
}


pmt::pmt_t gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, pmt::pmt_t default_value){
    /** \brief Returns the pmt value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::dict_ref(get_paramdict(msg), pmt::intern(key), default_value);
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

std::string gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, const std::string &default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::symbol_to_string(get_param(msg, key, pmt::intern(default_value)));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

bool gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, bool default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::to_bool(get_param(msg, key, pmt::from_bool(default_value)));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}


char gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, char default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::to_long(get_param(msg, key, pmt::from_long(default_value)));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

short gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, short default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::to_long(get_param(msg, key, pmt::from_long(default_value)));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

int gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, int default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::to_long(get_param(msg, key, pmt::from_long(default_value)));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

long gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, long default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::to_long(get_param(msg, key, pmt::from_long(default_value)));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}


unsigned char gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, unsigned char default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::to_uint64(get_param(msg, key, pmt::from_uint64(default_value)));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

unsigned short gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, unsigned short default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::to_uint64(get_param(msg, key, pmt::from_uint64(default_value)));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

unsigned int gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, unsigned int default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::to_uint64(get_param(msg, key, pmt::from_uint64(default_value)));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

unsigned long gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, unsigned long default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::to_uint64(get_param(msg, key, pmt::from_uint64(default_value)));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}


float gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, float default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::to_double(get_param(msg, key, pmt::from_double(default_value)));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

double gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, double default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::to_double(get_param(msg, key, pmt::from_double(default_value)));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}


std::complex<float> gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, std::complex<float> default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        std::complex<double> val=pmt::to_complex(get_param(msg, key, pmt::from_complex(default_value)));
        return {(float) val.real(), (float) val.imag()};
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

std::complex<double> gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, std::complex<double> default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return pmt::to_complex(get_param(msg, key, pmt::from_complex(default_value)));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}


std::vector<char> gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, const std::vector<char> &default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return get_values_s8(get_param(msg, key, pmt::init_s8vector(default_value.size(), (int8_t*) default_value.data())));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

std::vector<short> gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, const std::vector<short> &default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return get_values_s16(get_param(msg, key, pmt::init_s16vector(default_value.size(), (int16_t*) default_value.data())));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

std::vector<int> gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, const std::vector<int> &default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return get_values_s32(get_param(msg, key, pmt::init_s32vector(default_value.size(), (int32_t*) default_value.data())));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

std::vector<long> gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, const std::vector<long> &default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return get_values_s64(get_param(msg, key, pmt::init_s64vector(default_value.size(), (int64_t*) default_value.data())));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}


std::vector<unsigned char> gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, const std::vector<unsigned char> &default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return get_values_u8(get_param(msg, key, pmt::init_u8vector(default_value.size(), (uint8_t*) default_value.data())));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

std::vector<unsigned short> gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, const std::vector<unsigned short> &default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return get_values_u16(get_param(msg, key, pmt::init_u16vector(default_value.size(), (uint16_t*) default_value.data())));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

std::vector<unsigned int> gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, const std::vector<unsigned int> &default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return get_values_u32(get_param(msg, key, pmt::init_u32vector(default_value.size(), (uint32_t*) default_value.data())));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

std::vector<unsigned long> gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, const std::vector<unsigned long> &default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return get_values_u64(get_param(msg, key, pmt::init_u64vector(default_value.size(), (uint64_t*) default_value.data())));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}


std::vector<float> gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, const std::vector<float> &default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return get_values_f32(get_param(msg, key, pmt::init_f32vector(default_value.size(), default_value.data())));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

std::vector<double> gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, const std::vector<double> &default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return get_values_f64(get_param(msg, key, pmt::init_f64vector(default_value.size(), default_value.data())));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}


std::vector<std::complex<float> > gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, const std::vector<std::complex<float> > &default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return get_values_c32(get_param(msg, key, pmt::init_c32vector(default_value.size(), default_value.data())));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}

std::vector<std::complex<double> > gs::pmttools::get_param(pmt::pmt_t msg, const std::string &key, const std::vector<std::complex<double> > &default_value){
    /** \brief Returns the value of the key if a dict is found in msg.
     *
     * If no dict is found in the message or the key is not found in the dict, default_value is returned.
     */
    try {
        return get_values_c64(get_param(msg, key, pmt::init_c64vector(default_value.size(), default_value.data())));
    } catch (std::exception &e) { /* Return the default value */ }

    return default_value;
}



/* returns the values in the msg, i.e. 2nd item if the msg is a pair, else tries direct access. */

std::vector<char> gs::pmttools::get_values_s8(pmt::pmt_t msg){
    /** \brief Tries to return a vector. If none is found, return empty vector. */
    try {
        if(pmt::is_pair(msg)) msg=pmt::car(msg);
        std::vector<int8_t> invec=pmt::s8vector_elements(msg);
        std::vector<char> outvec(invec.size());
        memcpy(outvec.data(), invec.data(), invec.size() * sizeof(char));
        return outvec;
    } catch (std::exception &e) { /* Return the default value */ }

    return {};
}

std::vector<short> gs::pmttools::get_values_s16(pmt::pmt_t msg){
    /** \brief Tries to return a vector. If none is found, return empty vector. */
    try {
        if(pmt::is_pair(msg)) msg=pmt::car(msg);
        std::vector<int16_t> invec=pmt::s16vector_elements(msg);
        std::vector<short> outvec(invec.size());
        memcpy(outvec.data(), invec.data(), invec.size() * sizeof(short));
        return outvec;
    } catch (std::exception &e) { /* Return the default value */ }

    return {};
}

std::vector<int> gs::pmttools::get_values_s32(pmt::pmt_t msg){
    /** \brief Tries to return a vector. If none is found, return empty vector. */
    try {
        if(pmt::is_pair(msg)) msg=pmt::car(msg);
        std::vector<int32_t> invec=pmt::s32vector_elements(msg);
        std::vector<int> outvec(invec.size());
        memcpy(outvec.data(), invec.data(), invec.size() * sizeof(int));
        return outvec;
    } catch (std::exception &e) { /* Return the default value */ }

    return {};
}

std::vector<long> gs::pmttools::get_values_s64(pmt::pmt_t msg){
    /** \brief Tries to return a vector. If none is found, return empty vector. */
    try {
        if(pmt::is_pair(msg)) msg=pmt::car(msg);
        std::vector<int64_t> invec=pmt::s64vector_elements(msg);
        std::vector<long> outvec(invec.size());
        memcpy(outvec.data(), invec.data(), invec.size() * sizeof(long));
        return outvec;
    } catch (std::exception &e) { /* Return the default value */ }

    return {};
}


std::vector<unsigned char> gs::pmttools::get_values_u8(pmt::pmt_t msg){
    /** \brief Tries to return a vector. If none is found, return empty vector. */
    try {
        if(pmt::is_pair(msg)) msg=pmt::car(msg);
        std::vector<uint8_t> invec=pmt::u8vector_elements(msg);
        std::vector<unsigned char> outvec(invec.size());
        memcpy(outvec.data(), invec.data(), invec.size() * sizeof(unsigned char));
        return outvec;
    } catch (std::exception &e) { /* Return the default value */ }

    return {};
}

std::vector<unsigned short> gs::pmttools::get_values_u16(pmt::pmt_t msg){
    /** \brief Tries to return a vector. If none is found, return empty vector. */
    try {
        if(pmt::is_pair(msg)) msg=pmt::car(msg);
        std::vector<uint16_t> invec=pmt::u16vector_elements(msg);
        std::vector<unsigned short> outvec(invec.size());
        memcpy(outvec.data(), invec.data(), invec.size() * sizeof(unsigned short));
        return outvec;
    } catch (std::exception &e) { /* Return the default value */ }

    return {};
}

std::vector<unsigned int> gs::pmttools::get_values_u32(pmt::pmt_t msg){
    /** \brief Tries to return a vector. If none is found, return empty vector. */
    try {
        if(pmt::is_pair(msg)) msg=pmt::car(msg);
        std::vector<uint32_t> invec=pmt::u32vector_elements(msg);
        std::vector<unsigned int> outvec(invec.size());
        memcpy(outvec.data(), invec.data(), invec.size() * sizeof(unsigned int));
        return outvec;
    } catch (std::exception &e) { /* Return the default value */ }

    return {};
}

std::vector<unsigned long> gs::pmttools::get_values_u64(pmt::pmt_t msg){
    /** \brief Tries to return a vector. If none is found, return empty vector. */
    try {
        if(pmt::is_pair(msg)) msg=pmt::car(msg);
        std::vector<uint64_t> invec=pmt::u64vector_elements(msg);
        std::vector<unsigned long> outvec(invec.size());
        memcpy(outvec.data(), invec.data(), invec.size() * sizeof(unsigned long));
        return outvec;
    } catch (std::exception &e) { /* Return the default value */ }

    return {};
}


std::vector<float> gs::pmttools::get_values_f32(pmt::pmt_t msg){
    /** \brief Tries to return a vector. If none is found, return empty vector. */
    try {
        if(pmt::is_pair(msg)) msg=pmt::car(msg);
        return pmt::f32vector_elements(msg);
    } catch (std::exception &e) { /* Return the default value */ }

    return {};
}

std::vector<double> gs::pmttools::get_values_f64(pmt::pmt_t msg){
    /** \brief Tries to return a vector. If none is found, return empty vector. */
    try {
        if(pmt::is_pair(msg)) msg=pmt::car(msg);
        return pmt::f64vector_elements(msg);
    } catch (std::exception &e) { /* Return the default value */ }

    return {};
}


std::vector<std::complex<float> > gs::pmttools::get_values_c32(pmt::pmt_t msg){
    /** \brief Tries to return a vector. If none is found, return empty vector. */
    try {
        if(pmt::is_pair(msg)) msg=pmt::car(msg);
        return pmt::c32vector_elements(msg);
    } catch (std::exception &e) { /* Return the default value */ }

    return {};
}

std::vector<std::complex<double> > gs::pmttools::get_values_c64(pmt::pmt_t msg){
    /** \brief Tries to return a vector. If none is found, return empty vector. */
    try {
        if(pmt::is_pair(msg)) msg=pmt::car(msg);
        return pmt::c64vector_elements(msg);
    } catch (std::exception &e) { /* Return the default value */ }

    return {};
}

