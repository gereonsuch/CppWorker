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

#ifndef PMTTOOLS_H
#define PMTTOOLS_H

#include <pmt/pmt.h>
#include <vector>
#include <string>
#include <complex>

namespace gs {
namespace pmttools {

// Auxilliary functions to access pmts


/* get_paramdict searches for a dict in the msg and returns it. If none is found, an
 * empty dict is returned. */

pmt::pmt_t get_paramdict(pmt::pmt_t msg);


/* get_param functions look inside the msg for a dict in a pair and return the value held by
 * the key. default_value is returned, if the key is not found or msg is not compatible */

pmt::pmt_t get_param(pmt::pmt_t msg, const std::string &key, pmt::pmt_t default_value);

std::string get_param(pmt::pmt_t msg, const std::string &key, const std::string &default_value);

bool get_param(pmt::pmt_t msg, const std::string &key, bool default_value);

char get_param(pmt::pmt_t msg, const std::string &key, char default_value);
short get_param(pmt::pmt_t msg, const std::string &key, short default_value);
int get_param(pmt::pmt_t msg, const std::string &key, int default_value);
long get_param(pmt::pmt_t msg, const std::string &key, long default_value);

unsigned char get_param(pmt::pmt_t msg, const std::string &key, unsigned char default_value);
unsigned short get_param(pmt::pmt_t msg, const std::string &key, unsigned short default_value);
unsigned int get_param(pmt::pmt_t msg, const std::string &key, unsigned int default_value);
unsigned long get_param(pmt::pmt_t msg, const std::string &key, unsigned long default_value);

float get_param(pmt::pmt_t msg, const std::string &key, float default_value);
double get_param(pmt::pmt_t msg, const std::string &key, double default_value);

std::complex<float> get_param(pmt::pmt_t msg, const std::string &key, std::complex<float> default_value);
std::complex<double> get_param(pmt::pmt_t msg, const std::string &key, std::complex<double> default_value);

std::vector<char> get_param(pmt::pmt_t msg, const std::string &key, const std::vector<char> &default_value);
std::vector<short> get_param(pmt::pmt_t msg, const std::string &key, const std::vector<short> &default_value);
std::vector<int> get_param(pmt::pmt_t msg, const std::string &key, const std::vector<int> &default_value);
std::vector<long> get_param(pmt::pmt_t msg, const std::string &key, const std::vector<long> &default_value);

std::vector<unsigned char> get_param(pmt::pmt_t msg, const std::string &key, const std::vector<unsigned char> &default_value);
std::vector<unsigned short> get_param(pmt::pmt_t msg, const std::string &key, const std::vector<unsigned short> &default_value);
std::vector<unsigned int> get_param(pmt::pmt_t msg, const std::string &key, const std::vector<unsigned int> &default_value);
std::vector<unsigned long> get_param(pmt::pmt_t msg, const std::string &key, const std::vector<unsigned long> &default_value);

std::vector<float> get_param(pmt::pmt_t msg, const std::string &key, const std::vector<float> &default_value);
std::vector<double> get_param(pmt::pmt_t msg, const std::string &key, const std::vector<double> &default_value);

std::vector<std::complex<float> > get_param(pmt::pmt_t msg, const std::string &key, const std::vector<std::complex<float> > &default_value);
std::vector<std::complex<double> > get_param(pmt::pmt_t msg, const std::string &key, const std::vector<std::complex<double> > &default_value);


/* returns the values in the msg, i.e. 2nd item if the msg is a pair, else tries direct access. */

std::vector<char> get_values_s8(pmt::pmt_t msg);
std::vector<short> get_values_s16(pmt::pmt_t msg);
std::vector<int> get_values_s32(pmt::pmt_t msg);
std::vector<long> get_values_s64(pmt::pmt_t msg);

std::vector<unsigned char> get_values_u8(pmt::pmt_t msg);
std::vector<unsigned short> get_values_u16(pmt::pmt_t msg);
std::vector<unsigned int> get_values_u32(pmt::pmt_t msg);
std::vector<unsigned long> get_values_u64(pmt::pmt_t msg);

std::vector<float> get_values_f32(pmt::pmt_t msg);
std::vector<double> get_values_f64(pmt::pmt_t msg);

std::vector<std::complex<float> > get_values_c32(pmt::pmt_t msg);
std::vector<std::complex<double> > get_values_c64(pmt::pmt_t msg);

} //namespace pmttools
} //namespace gs

#endif // PMTTOOLS_H
