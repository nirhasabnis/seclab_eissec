/* Test Polyhedron::difference_assign().
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

bool
test01() {
  Variable x(0);
  Variable y(1);

  Generator_System gs1;
  gs1.insert(point(0*x + 0*y));
  gs1.insert(point(4*x + 0*y));
  gs1.insert(point(2*x + 2*y));

  C_Polyhedron ph1(gs1);

  print_generators(ph1, "*** ph1 ***");

  Generator_System gs2;
  gs2.insert(point(0*x + 3*y));
  gs2.insert(point(4*x + 3*y));
  gs2.insert(point(2*x + 1*y));

  C_Polyhedron ph2(gs2);

  print_generators(ph2, "*** ph2 ***");

  C_Polyhedron computed_result = ph1;

  computed_result.difference_assign(ph2);

  Generator_System gs_known_result;
  gs_known_result.insert(point());
  gs_known_result.insert(point(3*x + 3*y, 2));
  gs_known_result.insert(point(4*x));
  gs_known_result.insert(point(5*x + 3*y, 2));

  C_Polyhedron known_result(gs_known_result);

  C_Polyhedron ph3(2);
  ph3.add_constraint(2*y >= 3);

  known_result.difference_assign(ph3);

  bool ok = (computed_result == known_result);

  print_generators(computed_result, "*** after difference_assign ***");
  print_generators(known_result, "*** known_result ***");

  return ok;
}

bool
test02() {
  C_Polyhedron ph1;
  C_Polyhedron ph2;

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(ph2, "*** ph2 ***");

  Constraint_System cs;
  cs.insert(Linear_Expression(-4) >= 0);
  C_Polyhedron known_result(cs);

  ph1.difference_assign(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1, "*** after ph1.difference_assign(ph2) ***");

  return ok;
}

bool
test03() {
  Variable A(0);
  Variable B(1);

  C_Polyhedron ph1(2);
  ph1.add_constraint(A >= 0);
  ph1.add_constraint(A <= 2);
  ph1.add_constraint(B == 0);

  C_Polyhedron ph2(2);
  ph1.add_constraint(A >= 0);
  ph1.add_constraint(A <= 2);
  ph1.add_constraint(B >= 0);
  ph1.add_constraint(B <= 2);

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(ph2, "*** ph2 ***");

  C_Polyhedron known_result(2, EMPTY);

  ph1.difference_assign(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1, "*** after ph1.difference_assign(ph2) ***");

  return ok;
}

bool
test04() {
  Variable A(0);

  C_Polyhedron ph1(1);
  ph1.add_constraint(A >= 0);
  ph1.add_constraint(A <= 7);
  C_Polyhedron ph2(1);
  ph2.add_constraint(A == 5);

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(ph2, "*** ph2 ***");

  C_Polyhedron known_result(ph1);

  ph1.difference_assign(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1, "*** after ph1.difference_assign(ph2) ***");

  return ok;
}

bool
test05() {
  Variable A(0);
  Variable B(1);

  C_Polyhedron ph1(2, EMPTY);
  C_Polyhedron ph2(2);
  ph2.add_constraint(A == B);

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(ph2, "*** ph2 ***");

  C_Polyhedron known_result(ph1);

  ph1.difference_assign(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1, "*** after ph1.difference_assign(ph2) ***");

  return ok;
}

bool
test06() {
  Variable A(0);
  Variable B(1);

  C_Polyhedron ph1(2);
  ph1.add_constraint(A + B == 0);
  C_Polyhedron ph2(2, EMPTY);

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(ph2, "*** ph2 ***");

  C_Polyhedron known_result(ph1);

  ph1.difference_assign(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1, "*** after ph1.difference_assign(ph2) ***");

  return ok;
}

// Creating a rectangle.
C_Polyhedron
aux_test07(int lx, int ly, int dx, int dy) {
  Variable x(0);
  Variable y(1);
  C_Polyhedron ph(2, EMPTY);
  ph.add_generator(point((lx+0*dx)*x + (ly+0*dy)*y));
  ph.add_generator(point((lx+1*dx)*x + (ly+0*dy)*y));
  ph.add_generator(point((lx+1*dx)*x + (ly+1*dy)*y));
  ph.add_generator(point((lx+0*dx)*x + (ly+1*dy)*y));
  return ph;
}

bool
test07() {
  Pointset_Powerset<C_Polyhedron> cross(2, EMPTY);
  cross.add_disjunct(aux_test07(0, 3, 9, 3));
  cross.add_disjunct(aux_test07(3, 0, 3, 9));

  using namespace IO_Operators;
  nout << "cross = " << cross << endl;

  Pointset_Powerset<C_Polyhedron> squares(2, EMPTY);
  squares.add_disjunct(aux_test07(1, 4, 1, 1));
  squares.add_disjunct(aux_test07(4, 4, 1, 1));
  squares.add_disjunct(aux_test07(7, 4, 1, 1));
  squares.add_disjunct(aux_test07(4, 1, 1, 1));
  squares.add_disjunct(aux_test07(4, 7, 1, 1));

  nout << "squares = " << squares << endl;

  Pointset_Powerset<C_Polyhedron> difference = cross;
  difference.difference_assign(squares);

  nout << "cross - squares = " << difference << endl;

  Pointset_Powerset<C_Polyhedron> intersection = difference;
  intersection.meet_assign(squares);

  nout << "(cross - squares) inters squares = " << intersection << endl;

  // When using Pointset_Powerset<NNC_Polyhedron>, intersection will be
  // empty.  When using Pointset_Powerset<C_Polyhedron>,
  // intersection will consist of objects of affine dimension at most 1.
  bool ok1 = true;
  for (Pointset_Powerset<C_Polyhedron>::const_iterator
	 i = intersection.begin(), in_end = intersection.end();
       i != in_end; ++i)
    if (i->element().affine_dimension() > 1) {
      nout << "intersection contains " << i->element() << "," << endl
	   << "which is of affine dimension greater than 1" << endl;
      ok1 = false;
    }

  Pointset_Powerset<C_Polyhedron> re_union = difference;
  re_union.upper_bound_assign(squares);

  nout << "(cross - squares) union squares = " << re_union << endl;
  re_union.pairwise_reduce();
  nout << "<Above union pairwise reduced>  = " << re_union << endl;

  bool ok2 = re_union.geometrically_equals(cross);

  if (!ok2)
    nout << "Union does not give back the original!" << endl;

  return ok1 && ok2;
}

} // namespace

BEGIN_MAIN
  DO_TEST(test01);
  DO_TEST(test02);
  DO_TEST(test03);
  DO_TEST(test04);
  DO_TEST(test05);
  DO_TEST(test06);
  DO_TEST_F8(test07);
END_MAIN
