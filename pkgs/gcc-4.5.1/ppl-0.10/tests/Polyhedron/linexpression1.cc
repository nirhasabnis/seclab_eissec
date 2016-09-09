/* Testing Linear_Expression.
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

#include "ppl_test.hh"

namespace {

// Test operator-=(Linear_Expression& e1, const Linear_Expression& e2):
// in this case the dimension of e2 is strictly greater than
// the dimension of e1.
bool
test01() {
  Variable A(0);
  Variable B(1);

  Linear_Expression e1 = A;
  Linear_Expression e2 = B;
  e1 -= e2;

  C_Polyhedron ph(2);
  ph.add_constraint(e1 >= 0);

  C_Polyhedron known_result(2);
  known_result.add_constraint(A - B >= 0);

  bool ok = (ph == known_result);

  print_constraints(ph, "*** ph ***");

  return ok;
}

} // namespace

BEGIN_MAIN
  DO_TEST(test01);
END_MAIN
