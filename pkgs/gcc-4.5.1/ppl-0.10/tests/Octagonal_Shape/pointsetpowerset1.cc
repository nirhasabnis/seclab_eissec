/* Test Pointset_Powerset<Octagonal_Shape<> >.
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

// Constructs the powerset of octagonal_shapes from an octagonal shape.
bool
test01() {
  Variable x(0);
  Variable y(1);
  Variable z(2);
  Variable w(3);

  TOctagonal_Shape os(4);
  os.add_constraint(x >= 2);
  os.add_constraint(x + y <= 4);
  os.add_constraint(z == 1);

  Pointset_Powerset<TOctagonal_Shape> pps1(os);
  Pointset_Powerset<TOctagonal_Shape> pps2(4, EMPTY);
  pps2.add_disjunct(os);

  bool ok = (pps1 == pps2);

  Pointset_Powerset<TOctagonal_Shape>::const_iterator i = pps1.begin();
  TOctagonal_Shape osi = i->element();
  print_constraints(osi, "*** osi ***");
  Pointset_Powerset<TOctagonal_Shape>::const_iterator i2 = pps2.begin();
  TOctagonal_Shape osi2 = i2->element();
  print_constraints(osi2, "*** osi2 ***");

  return ok && pps1.OK();
}

// Constructs the powerset of octagonal_shapes from an empty octagonal shape.
bool
test02() {
  Variable x(0);
  Variable y(1);

  TOctagonal_Shape os(2, EMPTY);

  Pointset_Powerset<TOctagonal_Shape> pps(os);

  Pointset_Powerset<TOctagonal_Shape> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of octagonal_shapes from a polyhedron.
bool
test03() {
  Variable x(0);
  Variable y(1);
  Variable z(2);
  Variable w(3);

  C_Polyhedron ph(4);
  ph.add_constraint(3*x >= 2);
  ph.add_constraint(z >= 1);
  ph.add_constraint(3*x + z <= 3);
  C_Polyhedron ph1(ph);

  // With the default complexity, the implied equalities 4*x = 2 and z = 1.
  // are found
  Pointset_Powerset<TOctagonal_Shape> pps(ph);
  Pointset_Powerset<TOctagonal_Shape>::const_iterator i = pps.begin();
  TOctagonal_Shape osi = i->element();

  Octagonal_Shape<mpq_class> known_osi(4);
  known_osi.add_constraint(3*x == 2);
  known_osi.add_constraint(z == 1);

  bool ok = check_result(osi, known_osi, "1.193e-7", "5.45e-8", "3.98e-8");

  print_constraints(osi, "*** osi ***");
  print_constraints(known_osi, "*** known_osi ***");

  // With the polynomial complexity, implied equalities are not found.
  Pointset_Powerset<TOctagonal_Shape> pps1(ph1, POLYNOMIAL_COMPLEXITY);
  Pointset_Powerset<TOctagonal_Shape>::const_iterator i1 = pps1.begin();
  TOctagonal_Shape osi1 = i1->element();

  Octagonal_Shape<mpq_class> known_osi1(4);
  known_osi1.add_constraint(3*x >= 2);
  known_osi1.add_constraint(z >= 1);

  ok = check_result(osi1, known_osi1, "1.193e-7", "8.89e-8", "7.95e-8") && ok;

  print_constraints(osi1, "*** osi1 ***");
  print_constraints(known_osi1, "*** known_osi1 ***");

  ok = ok && pps.OK() && pps1.OK();

  Pointset_Powerset<TOctagonal_Shape>::const_iterator i_ok = pps.begin();
  TOctagonal_Shape osi_ok = i_ok->element();
  Pointset_Powerset<TOctagonal_Shape>::const_iterator i1_ok = pps1.begin();
  TOctagonal_Shape osi1_ok = i1_ok->element();

  print_constraints(osi_ok, "*** osi after OK() ***");
  print_constraints(osi1_ok, "*** osi1 after OK() ***");

  return ok;
}

// Constructs the powerset of octagonal_shapes from a polyhedron whose
// constraints are inconsistent (i.e., is empty but not marked as
// empty).
bool
test04() {
  Variable x(0);
  Variable y(1);
  Variable z(2);
  Variable w(3);

  C_Polyhedron ph(4);
  ph.add_constraint(3*x >= 2);
  ph.add_constraint(z >= 1);
  ph.add_constraint(3*x + z <= 2);
  C_Polyhedron ph1(ph);

  // With the default complexity, the built powerset is empty.
  Pointset_Powerset<TOctagonal_Shape> pps(ph);
  // With the polynomial complexity, the built powerset is non-empty.
  Pointset_Powerset<TOctagonal_Shape> pps1(ph1, POLYNOMIAL_COMPLEXITY);

  Octagonal_Shape<mpq_class> known_os1(4);
  known_os1.add_constraint(3*x >= 2);
  known_os1.add_constraint(z >= 1);

  Pointset_Powerset<TOctagonal_Shape>::const_iterator i1 = pps1.begin();
  TOctagonal_Shape osi1 = i1->element();

  bool ok = check_result(osi1, known_os1, "1.92e-7", "8.89e-8", "7.95e-8")
    && pps.is_empty();

  print_constraints(osi1, "*** osi1 ***");

  return ok && pps.OK() && pps1.OK();
}

// Constructs the powerset of octagonal_shapes from an empty polyhedron.
bool
test05() {
  Variable x(0);
  Variable y(1);

  NNC_Polyhedron ph(2, EMPTY);

  Pointset_Powerset<TOctagonal_Shape> pps(ph);

  Pointset_Powerset<TOctagonal_Shape> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of octagonal_shapes from a bd shape.
bool
test06() {
  Variable x(0);
  Variable y(1);

  TBD_Shape bds(2);
  bds.add_constraint(x == 0);
  bds.add_constraint(x - y <= 1);
  bds.add_constraint(y >= 0);

  Pointset_Powerset<TOctagonal_Shape> pps(bds);

  Pointset_Powerset<TOctagonal_Shape> known_pps(2);
  known_pps.add_constraint(x == 0);
  known_pps.add_constraint(x - y <= 1);
  known_pps.add_constraint(y >= 0);

  bool ok = (pps == known_pps);

  Pointset_Powerset<TOctagonal_Shape>::const_iterator i = pps.begin();
  TOctagonal_Shape osi = i->element();
  print_constraints(osi, "*** osi ***");

  return ok;
}

// Constructs the powerset of octagonal_shapes from an empty bd shape.
bool
test07() {
  Variable x(0);
  Variable y(1);

  TBD_Shape bds(2, EMPTY);

  Pointset_Powerset<TOctagonal_Shape> pps(bds);

  Pointset_Powerset<TOctagonal_Shape> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of octagonal_shapes from a box.
bool
test08() {
  Variable x(0);
  Variable y(1);

  TBox box(2);
  box.add_constraint(x >= 0);
  box.add_constraint(y >= 0);

  // Complexity should be ignored.
  Pointset_Powerset<TOctagonal_Shape> pps(box, POLYNOMIAL_COMPLEXITY);

  Pointset_Powerset<TOctagonal_Shape> known_pps(2);
  known_pps.add_constraint(x >= 0);
  known_pps.add_constraint(y >= 0);

  bool ok = (pps == known_pps);

  Pointset_Powerset<TOctagonal_Shape>::const_iterator i = pps.begin();
  TOctagonal_Shape osi = i->element();
  print_constraints(osi, "*** osi ***");

  return ok;
}

// Constructs the powerset of octagonal_shapes from an empty box.
bool
test09() {
  Variable x(0);
  Variable y(1);

  TBox box(2, EMPTY);

  Pointset_Powerset<TOctagonal_Shape> pps(box);

  Pointset_Powerset<TOctagonal_Shape> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of octagonal_shapes from a grid.
bool
test10() {
  Variable x(0);
  Variable y(1);

  Grid gr(2);
  gr.add_congruence((2*x %= 1) / 0);
  gr.add_congruence(y %= 0);

  Pointset_Powerset<TOctagonal_Shape> pps(gr);

  Pointset_Powerset<TOctagonal_Shape> known_pps(2);
  known_pps.add_constraint(2*x == 1);

  bool ok = (pps == known_pps);

  Pointset_Powerset<TOctagonal_Shape>::const_iterator i = pps.begin();
  TOctagonal_Shape osi = i->element();
  print_constraints(osi, "*** osi ***");

  return ok;
}

// Constructs the powerset of octagonal_shapes from an empty grid.
bool
test11() {
  Variable x(0);
  Variable y(1);

  Grid gr(2, EMPTY);

  Pointset_Powerset<TOctagonal_Shape> pps(gr);

  Pointset_Powerset<TOctagonal_Shape> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of octagonal_shapes from a powerset of
// octagonal_shapes.
bool
test12() {
  Variable x(0);
  Variable y(1);

  Constraint_System cs;
  cs.insert(x >= 1);
  cs.insert(x <= 1);
  cs.insert(y <= 0);
  TOctagonal_Shape os(cs);

  // The complexity should be ignored.
  Pointset_Powerset<TOctagonal_Shape> pps_os(os, POLYNOMIAL_COMPLEXITY);

  // The complexity should be ignored.
  Pointset_Powerset<TOctagonal_Shape> pps(pps_os, POLYNOMIAL_COMPLEXITY);

  Pointset_Powerset<TOctagonal_Shape> known_pps(2);
  known_pps.add_constraint(x == 1);
  known_pps.add_constraint(y <= 0);

  bool ok = (pps == known_pps);

  Pointset_Powerset<TOctagonal_Shape>::const_iterator j = pps.begin();
  TOctagonal_Shape osj = j->element();
  print_constraints(osj, "*** pps disjunct ***");

  return ok;
}

// Constructs the powerset of octagonal_shapes from a powerset of polyhedra.
bool
test13() {
  Variable x(0);
  Variable y(1);

  Constraint_System cs;
  cs.insert(2*x >= 1);
  cs.insert(2*x + y <= 1);
  cs.insert(y >= 0);
  C_Polyhedron ph1(cs);
  C_Polyhedron ph2(cs);

  Pointset_Powerset<C_Polyhedron> pps1_c(ph1, POLYNOMIAL_COMPLEXITY);
  Pointset_Powerset<C_Polyhedron> pps2_c(ph2);

  Pointset_Powerset<TOctagonal_Shape> pps1(pps1_c, POLYNOMIAL_COMPLEXITY);
  Pointset_Powerset<TOctagonal_Shape> pps2(pps2_c);

  Pointset_Powerset<TOctagonal_Shape> known_pps1(2);
  known_pps1.add_constraint(2*x >= 1);
  known_pps1.add_constraint(y >= 0);
  Pointset_Powerset<TOctagonal_Shape> known_pps2(2);
  known_pps2.add_constraint(2*x == 1);
  known_pps2.add_constraint(y == 0);

  bool ok = (pps1 == known_pps1 && pps2 == known_pps2);

  Pointset_Powerset<TOctagonal_Shape>::const_iterator i1 = pps1.begin();
  TOctagonal_Shape osi1 = i1->element();
  print_constraints(osi1, "*** osi1 ***");

  Pointset_Powerset<TOctagonal_Shape>::const_iterator i2 = pps2.begin();
  TOctagonal_Shape osi2 = i2->element();
  print_constraints(osi2, "*** osi2 ***");

  return ok;
}

// Constructs the powerset of octagonal_shapes from a powerset of bd shapes.
bool
test14() {
  Variable x(0);
  Variable y(1);

  Constraint_System cs;
  cs.insert(x >= 1);
  cs.insert(x - y <= 1);
  cs.insert(y <= 0);
  TBD_Shape bd(cs);

  // The complexity should be ignored.
  Pointset_Powerset<TBD_Shape> pps_bd(bd, POLYNOMIAL_COMPLEXITY);

  // The complexity should be ignored.
  Pointset_Powerset<TOctagonal_Shape> pps(pps_bd, POLYNOMIAL_COMPLEXITY);

  Pointset_Powerset<TOctagonal_Shape> known_pps(2);
  known_pps.add_constraint(x == 1);
  known_pps.add_constraint(y == 0);

  bool ok = (pps == known_pps);

  Pointset_Powerset<TOctagonal_Shape>::const_iterator i_os = pps.begin();
  TOctagonal_Shape osi = i_os->element();
  print_constraints(osi, "*** osi ***");

  return ok;
}

// Constructs the powerset of octagonal_shapes from a powerset of boxes.
bool
test15() {
  Variable x(0);
  Variable y(1);

  Constraint_System cs;
  cs.insert(x >= 1);
  cs.insert(y <= 0);
  TBox box(cs);

  // The complexity should be ignored.
  Pointset_Powerset<TBox> pps_box(box, POLYNOMIAL_COMPLEXITY);

  // The complexity should be ignored.
  Pointset_Powerset<TOctagonal_Shape> pps(pps_box, POLYNOMIAL_COMPLEXITY);

  Pointset_Powerset<TOctagonal_Shape> known_pps(2);
  known_pps.add_constraint(x >= 1);
  known_pps.add_constraint(y <= 0);

  bool ok = (pps == known_pps);

  Pointset_Powerset<TOctagonal_Shape>::const_iterator i_os = pps.begin();
  TOctagonal_Shape osi = i_os->element();
  print_constraints(osi, "*** osi ***");

  return ok;
}

// Constructs the powerset of octagonal_shapes from a powerset of grids.
bool
test16() {
  Variable x(0);
  Variable y(1);

  Grid gr(2);
  gr.add_congruence((2*x %= 1) / 0);
  gr.add_congruence(y %= 0);

  Pointset_Powerset<Grid> pps_gr(gr);

  Pointset_Powerset<TOctagonal_Shape> pps(pps_gr);

  Pointset_Powerset<TOctagonal_Shape> known_pps(2);

  known_pps.add_constraint(2*x == 1);

  bool ok = (pps == known_pps);

  Pointset_Powerset<TOctagonal_Shape>::const_iterator i = pps.begin();
  TOctagonal_Shape osi = i->element();
  print_constraints(osi, "*** osi ***");

  return ok;
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
  DO_TEST(test11);
  DO_TEST(test12);
  DO_TEST(test13);
  DO_TEST(test14);
  DO_TEST(test15);
  DO_TEST(test16);
END_MAIN
