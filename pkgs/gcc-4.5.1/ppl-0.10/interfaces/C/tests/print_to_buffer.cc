/* Declarations of print_ppl_*_t_to_buffer() functions.
   Copyright (C) 2001-2008 Roberto Bagnara <bagnara@cs.unipr.it>

This file is part of the Parma Polyhedra Library (PPL).

The PPL is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

The PPL is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02111-1307, USA.

For the most up-to-date information see the Parma Polyhedra Library
site: http://www.cs.unipr.it/ppl/ . */

#include "ppl.hh"
#include "ppl_c.h"
#include "print_to_buffer.h"
#include <sstream>
#include <cassert>
#include <iostream>
#include <cstring>
#include <cctype>

#define DEFINE_PRINT_TO_BUFFER(Type)                                    \
char*                                                                   \
print_ppl_##Type##_t_to_buffer(ppl_##Type##_t p,                        \
                               unsigned indent_depth,                   \
                               unsigned preferred_first_line_length,    \
                               unsigned preferred_line_length) {        \
  using namespace Parma_Polyhedra_Library;                              \
  return print_to_buffer(*reinterpret_cast<const Type*>(p),             \
                         indent_depth,                                  \
                         preferred_first_line_length,                   \
                         preferred_line_length);                        \
}

namespace {

size_t
wrap_to_buffer(char *buf,
               size_t buf_size,
               const char* src,
               unsigned indent_depth,
               unsigned preferred_first_line_length,
               unsigned preferred_line_length) {
  char* dst = buf;
  size_t len = 0;
  for (int line = 0; ; ++line) {
    int linelen = (line == 0
                   ? preferred_first_line_length
                   : preferred_line_length);
    int last_comma = -1;
    int last_space = -1;
    int split_pos = -1;
    int i;
    for (i = 0; i <= linelen; ++i) {
      if (src[i] == '\0' || src[i] == '\n') {
	split_pos = i;
	break;
      }
      if (src[i] == ',' && i < linelen)
	last_comma = i;
      if (isspace(src[i]) && (i == 0 || !isspace(src[i-1])))
	last_space = i;
    }
    if (split_pos < 0) {
      if (last_comma >= 0)
	split_pos = last_comma + 1;
      else if (last_space >= 0)
	split_pos = last_space;
      else {
	for ( ; src[i]; ++i) {
	  if (src[i] == ',') {
	    ++i;
	    break;
	  }
	  if (isspace(src[i]))
	    break;
	}
	split_pos = i;
      }
    }
    if (split_pos > 0 && line > 0) {
      i = buf_size - len;
      if (i >= 0) {
	if (i > (int) indent_depth)
	  i = indent_depth;
	memset(dst, ' ', i);
	dst += i;
      }
      len += indent_depth;
    }
    i = buf_size - len;
    if (i >= 0) {
      if (i > split_pos)
	i = split_pos;
      memcpy(dst, src, i);
      dst += i;
    }
    src += split_pos;
    len += split_pos;
    if (isspace(*src))
      ++src;
    while (*src == ' ')
      ++src;
    if (*src == '\0')
      break;
    if (len < buf_size)
      *dst++ = '\n';
    ++len;
  }
  if (len < buf_size)
    *dst++ = '\0';
  ++len;
  return len;
}

template <typename T>
char*
print_to_buffer(const T& o,
                unsigned indent_depth,
                unsigned preferred_first_line_length,
                unsigned preferred_line_length) {
  using namespace Parma_Polyhedra_Library::IO_Operators;
  std::ostringstream s;
  s << o;
  std::string str = s.str();
  const char* c_str = str.c_str();
  size_t buf_size = wrap_to_buffer(0, 0, c_str,
                                   indent_depth,
                                   preferred_first_line_length,
                                   preferred_line_length);
  char* buf = (char*) malloc(buf_size);
  if (buf != 0)
    wrap_to_buffer(buf, buf_size, c_str,
                   indent_depth,
                   preferred_first_line_length,
                   preferred_line_length);
  return buf;
}

} // namespace

DEFINE_PRINT_TO_BUFFER(Coefficient)

DEFINE_PRINT_TO_BUFFER(Linear_Expression)

DEFINE_PRINT_TO_BUFFER(Constraint)

DEFINE_PRINT_TO_BUFFER(Constraint_System)

DEFINE_PRINT_TO_BUFFER(Generator)

DEFINE_PRINT_TO_BUFFER(Generator_System)

DEFINE_PRINT_TO_BUFFER(Congruence)

DEFINE_PRINT_TO_BUFFER(Congruence_System)

DEFINE_PRINT_TO_BUFFER(Grid_Generator)

DEFINE_PRINT_TO_BUFFER(Grid_Generator_System)

DEFINE_PRINT_TO_BUFFER(MIP_Problem)
