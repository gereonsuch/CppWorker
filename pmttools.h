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

/* Please note: I don't want to distribute unter GPL v3, but since pmt lib is
 * licensed under GPL v3, I have to...
 */

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
