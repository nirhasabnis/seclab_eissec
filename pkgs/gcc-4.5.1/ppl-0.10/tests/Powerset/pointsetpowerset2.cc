/* Test Pointset_Powerset<PH>.
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

// Test affine_image().
bool
test01() {
  Variable x(0);
  Variable y(1);
  Pointset_Powerset<C_Polyhedron> c_ps(2, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  C_Polyhedron ph(2);
  ph.add_constraints(cs);
  c_ps.add_disjunct(ph);

  Constraint_System cs1;
  cs1.insert(y >= 3);
  cs1.insert(y <= 5);
  C_Polyhedron ph1(2);
  ph1.add_constraints(cs1);
  c_ps.add_disjunct(ph1);

  c_ps.affine_image(x, x + y);

  ph.affine_image(x, x + y);
  ph1.affine_image(x, x + y);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = c_ps.begin();
  C_Polyhedron phi = i->element();
  i++;
  C_Polyhedron phi1 = i->element();

  bool ok = phi.OK() && phi == ph;

  print_constraints(ph, "*** ph ***");
  print_constraints(phi, "*** phi ***");

  bool ok1 = phi1.OK() && phi1 == ph1;

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(phi1, "*** phi1 ***");

  return ok && ok1;
}

// Test affine_preimage().
bool
test02() {
  Variable x(0);
  Variable y(1);
  Pointset_Powerset<C_Polyhedron> c_ps(2, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  C_Polyhedron ph(2);
  ph.add_constraints(cs);
  c_ps.add_disjunct(ph);

  Constraint_System cs1;
  cs1.insert(y >= 3);
  cs1.insert(y <= 5);
  C_Polyhedron ph1(2);
  ph1.add_constraints(cs1);
  c_ps.add_disjunct(ph1);

  c_ps.affine_preimage(x, x + y);

  ph.affine_preimage(x, x + y);
  ph1.affine_preimage(x, x + y);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = c_ps.begin();
  C_Polyhedron phi = i->element();
  i++;
  C_Polyhedron phi1 = i->element();

  bool ok = phi.OK() && phi == ph;

  print_constraints(ph, "*** ph ***");
  print_constraints(phi, "*** phi ***");

  bool ok1 = phi1.OK() && phi1 == ph1;

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(phi1, "*** phi1 ***");

  return ok && ok1;
}

// Test generalized_affine_image(const Linear_Expression&,
//                               Relation_Symbol relsym,
//                               const Linear_Expression&).
bool
test03() {
  Variable x(0);
  Variable y(1);
  Pointset_Powerset<C_Polyhedron> c_ps(2, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  C_Polyhedron ph(2);
  ph.add_constraints(cs);
  c_ps.add_disjunct(ph);

  Constraint_System cs1;
  cs1.insert(y >= 3);
  cs1.insert(y <= 5);
  C_Polyhedron ph1(2);
  ph1.add_constraints(cs1);
  c_ps.add_disjunct(ph1);

  c_ps.generalized_affine_image(x - y, GREATER_OR_EQUAL, Linear_Expression(3));

  ph.generalized_affine_image(x - y, GREATER_OR_EQUAL, Linear_Expression(3));
  ph1.generalized_affine_image(x - y, GREATER_OR_EQUAL, Linear_Expression(3));

  Pointset_Powerset<C_Polyhedron>::const_iterator i = c_ps.begin();
  C_Polyhedron phi = i->element();
  i++;
  C_Polyhedron phi1 = i->element();

  bool ok = phi.OK() && phi == ph;

  print_constraints(ph, "*** ph ***");
  print_constraints(phi, "*** phi ***");

  bool ok1 = phi1.OK() && phi1 == ph1;

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(phi1, "*** phi1 ***");

  return ok && ok1;
}

// Test generalized_affine_preimage(const Linear_Expression&,
//                                  Relation_Symbol relsym,
//                                  const Linear_Expression&).
bool
test04() {
  Variable x(0);
  Variable y(1);
  Pointset_Powerset<C_Polyhedron> c_ps(2, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  C_Polyhedron ph(2);
  ph.add_constraints(cs);
  c_ps.add_disjunct(ph);

  Constraint_System cs1;
  cs1.insert(y >= 3);
  cs1.insert(y <= 5);
  C_Polyhedron ph1(2);
  ph1.add_constraints(cs1);
  c_ps.add_disjunct(ph1);

  c_ps.generalized_affine_preimage(2*y, LESS_OR_EQUAL, 4*y);

  ph.generalized_affine_preimage(2*y, LESS_OR_EQUAL, 4*y);
  ph1.generalized_affine_preimage(2*y, LESS_OR_EQUAL, 4*y);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = c_ps.begin();
  C_Polyhedron phi = i->element();
  i++;
  C_Polyhedron phi1 = i->element();

  bool ok = phi.OK() && phi == ph;

  print_constraints(ph, "*** ph ***");
  print_constraints(phi, "*** phi ***");

  bool ok1 = phi1.OK() && phi1 == ph1;

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(phi1, "*** phi1 ***");

  return ok && ok1;
}

// Test generalized_affine_image(Variable,
//                               Relation_Symbol relsym,
//                               const Linear_Expression&,
//                               Coefficient_traits::const_reference).
bool
test05() {
  Variable x(0);
  Variable y(1);
  Pointset_Powerset<C_Polyhedron> c_ps(2, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  C_Polyhedron ph(2);
  ph.add_constraints(cs);
  c_ps.add_disjunct(ph);

  Constraint_System cs1;
  cs1.insert(y >= 3);
  cs1.insert(y <= 5);
  C_Polyhedron ph1(2);
  ph1.add_constraints(cs1);
  c_ps.add_disjunct(ph1);

  c_ps.generalized_affine_image(x, GREATER_OR_EQUAL, Linear_Expression(3), 2);

  ph.generalized_affine_image(x, GREATER_OR_EQUAL, Linear_Expression(3), 2);
  ph1.generalized_affine_image(x, GREATER_OR_EQUAL, Linear_Expression(3), 2);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = c_ps.begin();
  C_Polyhedron phi = i->element();
  i++;
  C_Polyhedron phi1 = i->element();

  bool ok = phi.OK() && phi == ph;

  print_constraints(ph, "*** ph ***");
  print_constraints(phi, "*** phi ***");

  bool ok1 = phi1.OK() && phi1 == ph1;

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(phi1, "*** phi1 ***");

  return ok && ok1;
}

// Test generalized_affine_image(Variable,
//                               Relation_Symbol relsym,
//                               const Linear_Expression&,
//                               Coefficient_traits::const_reference).
bool
test06() {
  Variable x(0);
  Variable y(1);
  Pointset_Powerset<C_Polyhedron> c_ps(2, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  C_Polyhedron ph(2);
  ph.add_constraints(cs);
  c_ps.add_disjunct(ph);

  Constraint_System cs1;
  cs1.insert(y >= 3);
  cs1.insert(y <= 5);
  C_Polyhedron ph1(2);
  ph1.add_constraints(cs1);
  c_ps.add_disjunct(ph1);

  c_ps.generalized_affine_image(x, GREATER_OR_EQUAL, Linear_Expression(3), 2);

  ph.generalized_affine_image(x, GREATER_OR_EQUAL, Linear_Expression(3), 2);
  ph1.generalized_affine_image(x, GREATER_OR_EQUAL, Linear_Expression(3), 2);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = c_ps.begin();
  C_Polyhedron phi = i->element();
  i++;
  C_Polyhedron phi1 = i->element();

  bool ok = phi.OK() && phi == ph;

  print_constraints(ph, "*** ph ***");
  print_constraints(phi, "*** phi ***");

  bool ok1 = phi1.OK() && phi1 == ph1;

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(phi1, "*** phi1 ***");

  return ok && ok1;
}

// Test bounded_affine_image(Variable,
//                           Relation_Symbol relsym,
//                           const Linear_Expression&,
//                           Coefficient_traits::const_reference).
bool
test07() {
  Variable x(0);
  Variable y(1);
  Pointset_Powerset<C_Polyhedron> c_ps(2, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  C_Polyhedron ph(2);
  ph.add_constraints(cs);
  c_ps.add_disjunct(ph);

  Constraint_System cs1;
  cs1.insert(y >= 3);
  cs1.insert(y <= 5);
  C_Polyhedron ph1(2);
  ph1.add_constraints(cs1);
  c_ps.add_disjunct(ph1);

  c_ps.bounded_affine_image(y, Linear_Expression(0), 2*y, 5);

  ph.bounded_affine_image(y, Linear_Expression(0), 2*y, 5);
  ph1.bounded_affine_image(y, Linear_Expression(0), 2*y, 5);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = c_ps.begin();
  C_Polyhedron phi = i->element();
  i++;
  C_Polyhedron phi1 = i->element();

  bool ok = phi.OK() && phi == ph;

  print_constraints(ph, "*** ph ***");
  print_constraints(phi, "*** phi ***");

  bool ok1 = phi1.OK() && phi1 == ph1;

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(phi1, "*** phi1 ***");

  return ok && ok1;
}

// Test bounded_affine_preimage(Variable,
//                              Relation_Symbol relsym,
//                              const Linear_Expression&,
//                              Coefficient_traits::const_reference).
bool
test08() {
  Variable x(0);
  Variable y(1);
  Pointset_Powerset<C_Polyhedron> c_ps(2, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  C_Polyhedron ph(2);
  ph.add_constraints(cs);
  c_ps.add_disjunct(ph);

  Constraint_System cs1;
  cs1.insert(y >= 3);
  cs1.insert(y <= 5);
  C_Polyhedron ph1(2);
  ph1.add_constraints(cs1);
  c_ps.add_disjunct(ph1);

  c_ps.bounded_affine_preimage(y, x, 2*y, 5);

  ph.bounded_affine_preimage(y, x, 2*y, 5);
  ph1.bounded_affine_preimage(y, x, 2*y, 5);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = c_ps.begin();
  C_Polyhedron phi = i->element();
  i++;
  C_Polyhedron phi1 = i->element();

  bool ok = phi.OK() && phi == ph;

  print_constraints(ph, "*** ph ***");
  print_constraints(phi, "*** phi ***");

  bool ok1 = phi1.OK() && phi1 == ph1;

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(phi1, "*** phi1 ***");

  return ok && ok1;
}

// Test affine_dimension() for powersets of C polyhedra.
bool
test09() {
  Variable x(0);
  Variable y(1);
  Variable z(1);
  Pointset_Powerset<C_Polyhedron> c_ps(3, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  cs.insert(z <= 2);
  cs.insert(z >= 2);
  C_Polyhedron ph(3);
  ph.add_constraints(cs);
  c_ps.add_disjunct(ph);

  Constraint_System cs1;
  cs1.insert(y >= 3);
  cs1.insert(y <= 5);
  cs1.insert(x == 6);
  C_Polyhedron ph1(3);
  ph1.add_constraints(cs1);
  c_ps.add_disjunct(ph1);

  dimension_type d = c_ps.affine_dimension();

  bool ok = (d == 3);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = c_ps.begin();
  C_Polyhedron phi = i->element();
  i++;
  C_Polyhedron phi1 = i->element();

  print_constraints(phi, "*** phi ***");
  print_constraints(phi1, "*** phi1 ***");

  c_ps.add_constraint(z == 2);

  dimension_type d1 = c_ps.affine_dimension();

  bool ok1 = (d1 == 2);

  Pointset_Powerset<C_Polyhedron>::const_iterator j = c_ps.begin();
  C_Polyhedron phj = j->element();
  j++;
  C_Polyhedron phj1 = j->element();

  print_constraints(phj, "*** phj ***");
  print_constraints(phj1, "*** phj1 ***");

  return ok && ok1;
}

// Test affine_dimension() for powersets of NNC polyhedra.
bool
test10() {
  Variable x(0);
  Variable y(1);
  Variable z(1);
  Pointset_Powerset<NNC_Polyhedron> c_ps(3, EMPTY);
  Constraint_System cs;
  cs.insert(x > 0);
  cs.insert(x <= 2);
  cs.insert(z <= 2);
  cs.insert(z >= 2);
  NNC_Polyhedron ph(3);
  ph.add_constraints(cs);
  c_ps.add_disjunct(ph);

  Constraint_System cs1;
  cs1.insert(y >= 3);
  cs1.insert(y <= 5);
  cs1.insert(x == 6);
  NNC_Polyhedron ph1(3);
  ph1.add_constraints(cs1);
  c_ps.add_disjunct(ph1);

  dimension_type d = c_ps.affine_dimension();

  bool ok = (d == 3);

  Pointset_Powerset<NNC_Polyhedron>::const_iterator i = c_ps.begin();
  NNC_Polyhedron phi = i->element();
  i++;
  NNC_Polyhedron phi1 = i->element();

  print_constraints(phi, "*** phi ***");
  print_constraints(phi1, "*** phi1 ***");

  c_ps.add_constraint(z == 2);

  dimension_type d1 = c_ps.affine_dimension();

  bool ok1 = (d1 == 2);

  Pointset_Powerset<NNC_Polyhedron>::const_iterator j = c_ps.begin();
  NNC_Polyhedron phj = j->element();
  j++;
  NNC_Polyhedron phj1 = j->element();

  print_constraints(phj, "*** phj ***");
  print_constraints(phj1, "*** phj1 ***");

  return ok && ok1;
}

} // namespace

BEGIN_MAIN
  DO_TEST(test01);
  DO_TEST(test02);
  DO_TEST(test03);
  DO_TEST(test04);
  DO_TEST(test05);
  DO_TEST(test06);
  DO_TEST(test07);
  DO_TEST(test08);
  DO_TEST(test09);
  DO_TEST(test10);
END_MAIN
