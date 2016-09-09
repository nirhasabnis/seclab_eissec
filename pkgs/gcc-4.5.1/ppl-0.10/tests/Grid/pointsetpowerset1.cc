/* Test Pointset_Powerset<Grid>.
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

// Constructs the powerset of grids from a grid.
bool
test01() {
  Variable x(0);
  Variable y(1);
  Variable z(2);
  Variable w(3);

  Grid gr(4);
  gr.add_congruence(x %= 2);
  gr.add_constraint(z == 1);

  Pointset_Powerset<Grid> pps1(gr);
  Pointset_Powerset<Grid> pps2(4, EMPTY);
  pps2.add_disjunct(gr);

  bool ok = (pps1 == pps2);

  print_congruences(gr, "*** gr ***");
  Pointset_Powerset<Grid>::const_iterator i = pps1.begin();
  Grid gri = i->element();
  print_congruences(gri, "*** gri ***");
  Pointset_Powerset<Grid>::const_iterator i2 = pps2.begin();
  Grid gri2 = i2->element();
  print_congruences(gri2, "*** gri2 ***");

  return ok && pps1.OK();
}

// Constructs the powerset of grids from an empty grid.
bool
test02() {
  Variable x(0);
  Variable y(1);

  Grid gr(2, EMPTY);

  Pointset_Powerset<Grid> pps(gr);

  Pointset_Powerset<Grid> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of grids from a polyhedron.
bool
test03() {
  Variable x(0);
  Variable y(1);
  Variable z(2);
  Variable w(3);

  C_Polyhedron ph(4);
  ph.add_constraint(x >= 2);
  ph.add_constraint(z >= 1);
  ph.add_constraint(x + z <= 3);
  C_Polyhedron ph1(4);
  ph1.add_constraint(x >= 2);
  ph1.add_constraint(z >= 1);
  ph1.add_constraint(x + z <= 3);

  // With the default complexity, the implied equalities x = 2 and z = 1.
  // are found
  Pointset_Powerset<Grid> pps(ph);
  // With the polynomial complexity, no implied equalities are found.
  Pointset_Powerset<Grid> pps1(ph1, POLYNOMIAL_COMPLEXITY);

  Pointset_Powerset<Grid> known_pps(4);
  known_pps.add_congruence((x %= 2) / 0);
  known_pps.add_congruence((z %= 1) / 0);
  Pointset_Powerset<Grid> known_pps1(4);

  bool ok = (pps == known_pps && pps1 == known_pps1);

  Pointset_Powerset<Grid>::const_iterator i = pps.begin();
  Grid gri = i->element();
  print_congruences(gri, "*** gri ***");
  Pointset_Powerset<Grid>::const_iterator i1 = pps1.begin();
  Grid gri1 = i1->element();
  print_congruences(gri1, "*** gri1 ***");

  return ok && pps.OK() && pps1.OK();
}

// Constructs the powerset of grids from a polyhedron whose constraints
// are inconsistent (i.e., is empty but not marked as empty).
bool
test04() {
  Variable x(0);
  Variable y(1);
  Variable z(2);
  Variable w(3);

  C_Polyhedron ph(4);
  ph.add_constraint(x >= 2);
  ph.add_constraint(z >= 1);
  ph.add_constraint(x + z <= 2);
  C_Polyhedron ph1(4);
  ph1.add_constraint(x >= 2);
  ph1.add_constraint(z >= 1);
  ph1.add_constraint(x + z <= 2);

  // With the default complexity, the built powerset is empty.
  Pointset_Powerset<Grid> pps(ph);
  // With the polynomial complexity, the built powerset is the universe.
  Pointset_Powerset<Grid> pps1(ph1, POLYNOMIAL_COMPLEXITY);

  Pointset_Powerset<Grid> known_pps(4, EMPTY);
  Pointset_Powerset<Grid> known_pps1(4);

  bool ok = (pps == known_pps && pps1 == known_pps1);

  Pointset_Powerset<Grid>::const_iterator i1 = pps1.begin();
  Grid gri1 = i1->element();
  print_congruences(gri1, "*** gri1 ***");

  return ok && pps.OK() && pps1.OK();
}

// Constructs the powerset of grids from an empty polyhedron.
bool
test05() {
  Variable x(0);
  Variable y(1);

  NNC_Polyhedron ph(2, EMPTY);

  Pointset_Powerset<Grid> pps(ph);

  Pointset_Powerset<Grid> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of grids from a bd shape.
bool
test06() {
  Variable x(0);
  Variable y(1);

  TBD_Shape bds(2);
  bds.add_constraint(x == 0);
  bds.add_constraint(x - y <= 1);
  bds.add_constraint(y >= 0);

  Pointset_Powerset<Grid> pps(bds);

  Pointset_Powerset<Grid> known_pps(2);
  known_pps.add_congruence((x %= 0) / 0);

  bool ok = (pps == known_pps);

  Pointset_Powerset<Grid>::const_iterator i = pps.begin();
  Grid phi = i->element();
  print_congruences(phi, "*** phi ***");

  return ok;
}

// Constructs the powerset of grids from an empty bd shape.
bool
test07() {
  Variable x(0);
  Variable y(1);

  TBD_Shape bds(2, EMPTY);

  Pointset_Powerset<Grid> pps(bds);

  Pointset_Powerset<Grid> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of grids from an octagonal shape.
bool
test08() {
  Variable x(0);
  Variable y(1);

  TOctagonal_Shape os(2);
  os.add_constraint(x >= 0);
  os.add_constraint(x + y <= 4);
  os.add_constraint(x - y == 3);
  os.add_constraint(y >= 0);

  // Complexity should be ignored.
  Pointset_Powerset<Grid> pps(os, POLYNOMIAL_COMPLEXITY);

  Pointset_Powerset<Grid> known_pps(2);
  known_pps.add_constraint(x - y == 3);

  bool ok = (pps == known_pps);

  Pointset_Powerset<Grid>::const_iterator i = pps.begin();
  Grid phi = i->element();
  print_congruences(phi, "*** phi ***");

  return ok;
}

// Constructs the powerset of grids from an empty octagonal shape.
bool
test09() {
  Variable x(0);
  Variable y(1);

  TOctagonal_Shape os(2, EMPTY);

  Pointset_Powerset<Grid> pps(os);

  Pointset_Powerset<Grid> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of grids from a box.
bool
test10() {
  Variable x(0);
  Variable y(1);

  Rational_Box box(2);
  box.add_constraint(x >= 0);
  box.add_constraint(2*x == 1);
  box.add_constraint(y >= 0);

  Pointset_Powerset<Grid> pps(box);

  Pointset_Powerset<Grid> known_pps(2);
  known_pps.add_constraint(2*x == 1);

  bool ok = (pps == known_pps);

  Pointset_Powerset<Grid>::const_iterator i = pps.begin();
  Grid phi = i->element();
  print_congruences(phi, "*** phi ***");

  return ok;
}

// Constructs the powerset of grids from an empty box.
bool
test11() {
  Variable x(0);
  Variable y(1);

  Rational_Box box(2, EMPTY);

  Pointset_Powerset<Grid> pps(box);

  Pointset_Powerset<Grid> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of grids from a powerset of grids.
bool
test12() {
  Variable x(0);
  Variable y(1);

  Grid grid(2);
  grid.add_congruence((2*x %= 1) / 0);
  grid.add_congruence(y %= 0);

  Pointset_Powerset<Grid> pps_gr(grid);

  Pointset_Powerset<Grid> pps(pps_gr);

  Pointset_Powerset<Grid> known_pps(2);

  known_pps.add_constraint(2*x == 1);
  known_pps.add_congruence(y %= 0);

  bool ok = (pps == known_pps);

  Pointset_Powerset<Grid>::const_iterator i = pps.begin();
  Grid gri = i->element();
  print_congruences(gri, "*** gri ***");

  return ok;
}

// Constructs the powerset of grids from a powerset of polyhedra.
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

  Pointset_Powerset<Grid> pps1(pps1_c, POLYNOMIAL_COMPLEXITY);
  Pointset_Powerset<Grid> pps2(pps2_c);

  Pointset_Powerset<Grid> known_pps1(2);
  Pointset_Powerset<Grid> known_pps2(2);
  known_pps2.add_constraint(2*x == 1);
  known_pps2.add_constraint(y == 0);

  bool ok = (pps1 == known_pps1 && pps2 == known_pps2);

  Pointset_Powerset<Grid>::const_iterator i1 = pps1.begin();
  Grid gri1 = i1->element();
  print_congruences(gri1, "*** gri1 ***");

  Pointset_Powerset<Grid>::const_iterator i2 = pps2.begin();
  Grid gri2 = i2->element();
  print_congruences(gri2, "*** gri2 ***");

  return ok;
}

// Constructs the powerset of grids from a powerset of bd shapes.
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

  Pointset_Powerset<TBD_Shape>::const_iterator i_bd = pps_bd.begin();
  TBD_Shape bdi = i_bd->element();
  print_constraints(bdi, "*** bdi ***");

  // The complexity should be ignored.
  Pointset_Powerset<Grid> pps(pps_bd, POLYNOMIAL_COMPLEXITY);

  Pointset_Powerset<Grid> known_pps(2);
  known_pps.add_constraint(x == 1);
  known_pps.add_constraint(y == 0);

  bool ok = (pps == known_pps);

  Pointset_Powerset<Grid>::const_iterator i_gr = pps.begin();
  Grid gri = i_gr->element();
  print_congruences(gri, "*** gri ***");

  return ok;
}

// Constructs the powerset of grids from a powerset of octagonal shapes.
bool
test15() {
  Variable x(0);
  Variable y(1);

  Constraint_System cs;
  cs.insert(x >= 1);
  cs.insert(x - y <= 1);
  cs.insert(y <= 0);
  TOctagonal_Shape os(cs);

  // The complexity should be ignored.
  Pointset_Powerset<TOctagonal_Shape> pps_os(os, POLYNOMIAL_COMPLEXITY);

  Pointset_Powerset<TOctagonal_Shape>::const_iterator i_os = pps_os.begin();
  TOctagonal_Shape osi = i_os->element();
  print_constraints(osi, "*** osi ***");

  // The complexity should be ignored.
  Pointset_Powerset<Grid> pps(pps_os, POLYNOMIAL_COMPLEXITY);

  Pointset_Powerset<Grid> known_pps(2);
  known_pps.add_constraint(x == 1);
  known_pps.add_constraint(y == 0);

  bool ok = (pps == known_pps);

  Pointset_Powerset<Grid>::const_iterator i_gr = pps.begin();
  Grid gri = i_gr->element();
  print_congruences(gri, "*** gri ***");

  return ok;
}

// Constructs the powerset of grids from a powerset of boxes.
bool
test16() {
  Variable x(0);
  Variable y(1);

  Constraint_System cs;
  cs.insert(x >= 1);
  cs.insert(x <= 1);
  cs.insert(y <= 0);
  TBox box(cs);

  // The complexity should be ignored.
  Pointset_Powerset<TBox> pps_box(box, POLYNOMIAL_COMPLEXITY);

  Pointset_Powerset<TBox>::const_iterator i_box = pps_box.begin();
  TBox boxi = i_box->element();
  print_constraints(boxi, "*** boxi ***");

  // The complexity should be ignored.
  Pointset_Powerset<Grid> pps(pps_box, POLYNOMIAL_COMPLEXITY);

  Pointset_Powerset<Grid> known_pps(2);
  known_pps.add_constraint(x == 1);

  bool ok = (pps == known_pps);

  Pointset_Powerset<Grid>::const_iterator i_gr = pps.begin();
  Grid gri = i_gr->element();
  print_congruences(gri, "*** gri ***");

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
