/* Domain-independent part of the OCaml interface: inline functions.
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

#ifndef PPL_ppl_ocaml_common_inlines_hh
#define PPL_ppl_ocaml_common_inlines_hh 1

namespace Parma_Polyhedra_Library {

namespace Interfaces {

namespace OCaml {

inline void
check_int_is_unsigned(int i) {
  if (i < 0)
    caml_raise_with_string(*caml_named_value("PPL_not_an_unsigned_exception"),
			   "negative number given, should be unsigned" );
}

inline
Partial_Function::Partial_Function() {
}

inline bool
Partial_Function::has_empty_codomain() const {
  return codomain.empty();
}

inline dimension_type
Partial_Function::max_in_codomain() const {
  if (codomain.empty())
    throw std::runtime_error("Partial_Function::max_in_codomain()");
  return *codomain.rbegin();
}

inline bool
Partial_Function::maps(dimension_type i, dimension_type& j) const {
  if (i >= vec.size())
    return false;
  dimension_type vec_i = vec[i];
  if (vec_i == not_a_dimension())
    return false;
  j = vec_i;
  return true;
}

inline bool
Partial_Function::insert(dimension_type i, dimension_type j) {
  std::pair<std::set<dimension_type>::iterator, bool> s = codomain.insert(j);
  if (!s.second)
    // *this is not injective!
    return false;
  if (i > vec.size())
    vec.insert(vec.end(), i - vec.size(), not_a_dimension());
  if (i == vec.size()) {
    vec.insert(vec.end(), j);
    return true;
  }
  dimension_type& vec_i = vec[i];
  if (vec_i != not_a_dimension())
    // Already mapped: *this is not a function!
    return false;
  vec_i = j;
  return true;
}

} // namespace OCaml

} // namespace Interfaces

} // namespace Parma_Polyhedra_Library

#endif // !defined(PPL_ppl_ocaml_common_inlines_hh)
