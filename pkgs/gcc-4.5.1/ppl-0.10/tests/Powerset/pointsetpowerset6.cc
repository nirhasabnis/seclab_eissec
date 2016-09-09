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

// Constructs the powerset of polyhedra from a closed polyhedron.
bool
test01() {
  Variable x(0);
  Variable y(1);
  Variable z(2);
  Variable w(3);

  C_Polyhedron c_ph(4);
  c_ph.add_constraint(x <= 2);
  c_ph.add_constraint(z == 1);
  NNC_Polyhedron nnc_ph(c_ph);

  Pointset_Powerset<C_Polyhedron> c_pps1(c_ph);
  Pointset_Powerset<C_Polyhedron> c_pps2(4, EMPTY);
  c_pps2.add_disjunct(c_ph);

  Pointset_Powerset<NNC_Polyhedron> nnc_pps1(c_ph);
  Pointset_Powerset<NNC_Polyhedron> nnc_pps2(4, EMPTY);
  nnc_pps2.add_disjunct(nnc_ph);

  bool ok = (c_pps1 == c_pps2 && nnc_pps1 == nnc_pps2);

  Pointset_Powerset<C_Polyhedron>::const_iterator c_i = c_pps1.begin();
  C_Polyhedron c_phi = c_i->element();
  print_constraints(c_phi, "*** c_phi ***");
  Pointset_Powerset<NNC_Polyhedron>::const_iterator nnc_i = nnc_pps1.begin();
  NNC_Polyhedron nnc_phi = nnc_i->element();
  print_constraints(nnc_phi, "*** nnc_phi ***");

  return ok && c_pps1.OK() && nnc_pps1.OK();
}

// Constructs the powerset of polyhedra from an nnc polyhedron.
bool
test02() {
  Variable x(0);
  Variable y(1);
  Variable z(2);
  Variable w(3);

  NNC_Polyhedron nnc_ph(4);
  nnc_ph.add_constraint(x <= 2);
  nnc_ph.add_constraint(z == 1);
  C_Polyhedron c_ph(nnc_ph);

  Pointset_Powerset<C_Polyhedron> c_pps1(nnc_ph);
  Pointset_Powerset<C_Polyhedron> c_pps2(4, EMPTY);
  c_pps2.add_disjunct(c_ph);

  Pointset_Powerset<NNC_Polyhedron> nnc_pps1(nnc_ph);
  Pointset_Powerset<NNC_Polyhedron> nnc_pps2(4, EMPTY);
  nnc_pps2.add_disjunct(nnc_ph);

  bool ok = (c_pps1 == c_pps2 && nnc_pps1 == nnc_pps2);

  Pointset_Powerset<C_Polyhedron>::const_iterator c_i = c_pps1.begin();
  C_Polyhedron c_phi = c_i->element();
  print_constraints(c_phi, "*** c_phi ***");
  Pointset_Powerset<NNC_Polyhedron>::const_iterator nnc_i = nnc_pps1.begin();
  NNC_Polyhedron nnc_phi = nnc_i->element();
  print_constraints(nnc_phi, "*** nnc_phi ***");

  return ok && c_pps1.OK() && nnc_pps1.OK();
}

// Constructs the powerset of polyhedra from a grid.
bool
test03() {
  Variable x(0);
  Variable y(1);

  Grid grid(2);
  grid.add_congruence((2*x %= 1) / 0);
  grid.add_congruence(y %= 0);

  Pointset_Powerset<C_Polyhedron> pps(grid);

  Pointset_Powerset<C_Polyhedron> known_pps(2);

  known_pps.add_constraint(2*x == 1);

  bool ok = (pps == known_pps);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = pps.begin();
  C_Polyhedron phi = i->element();
  print_constraints(phi, "*** phi ***");

  return ok;
}

// Constructs the powerset of polyhedra from an empty grid.
bool
test04() {
  Variable x(0);
  Variable y(1);

  Grid grid(2, EMPTY);

  Pointset_Powerset<C_Polyhedron> pps(grid);

  Pointset_Powerset<C_Polyhedron> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of polyhedra from a bd shape.
bool
test05() {
  Variable x(0);
  Variable y(1);

  TBD_Shape bds(2);
  bds.add_constraint(x >= 0);
  bds.add_constraint(x - y <= 1);
  bds.add_constraint(y >= 0);

  Pointset_Powerset<C_Polyhedron> pps(bds);

  Pointset_Powerset<C_Polyhedron> known_pps(2);
  known_pps.add_constraint(x >= 0);
  known_pps.add_constraint(x - y <= 1);
  known_pps.add_constraint(y >= 0);

  bool ok = (pps == known_pps);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = pps.begin();
  C_Polyhedron phi = i->element();
  print_constraints(phi, "*** phi ***");

  return ok;
}

// Constructs the powerset of polyhedra from an empty bd shape.
bool
test06() {
  Variable x(0);
  Variable y(1);

  TBD_Shape bds(2, EMPTY);

  Pointset_Powerset<C_Polyhedron> pps(bds);

  Pointset_Powerset<C_Polyhedron> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of polyhedra from an octagonal shape.
bool
test07() {
  Variable x(0);
  Variable y(1);

  TOctagonal_Shape os(2);
  os.add_constraint(x >= 0);
  os.add_constraint(x + y <= 1);
  os.add_constraint(x - y <= 3);
  os.add_constraint(y >= 0);

  Pointset_Powerset<C_Polyhedron> pps(os);

  Pointset_Powerset<C_Polyhedron> known_pps(2);
  known_pps.add_constraint(x >= 0);
  known_pps.add_constraint(x + y <= 1);
  known_pps.add_constraint(x - y <= 3);
  known_pps.add_constraint(y >= 0);

  bool ok = (pps == known_pps);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = pps.begin();
  C_Polyhedron phi = i->element();
  print_constraints(phi, "*** phi ***");

  return ok;
}

// Constructs the powerset of polyhedra from an empty octagonal shape.
bool
test08() {
  Variable x(0);
  Variable y(1);

  TOctagonal_Shape os(2, EMPTY);

  Pointset_Powerset<C_Polyhedron> pps(os);

  Pointset_Powerset<C_Polyhedron> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of polyhedra from a box.
bool
test09() {
  Variable x(0);
  Variable y(1);

  Rational_Box box(2);
  box.add_constraint(x >= 0);
  box.add_constraint(2*x <= 1);
  box.add_constraint(y >= 0);

  Pointset_Powerset<C_Polyhedron> pps(box);

  Pointset_Powerset<C_Polyhedron> known_pps(2);
  known_pps.add_constraint(x >= 0);
  known_pps.add_constraint(2*x <= 1);
  known_pps.add_constraint(y >= 0);

  bool ok = (pps == known_pps);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = pps.begin();
  C_Polyhedron phi = i->element();
  print_constraints(phi, "*** phi ***");

  return ok;
}

// Constructs the powerset of polyhedra from an empty box.
bool
test10() {
  Variable x(0);
  Variable y(1);

  Rational_Box box(2, EMPTY);

  Pointset_Powerset<C_Polyhedron> pps(box);

  Pointset_Powerset<C_Polyhedron> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Constructs the powerset of polyhedra from a powerset of grids.
bool
test11() {
  Variable x(0);
  Variable y(1);

  Grid grid(2);
  grid.add_congruence((2*x %= 1) / 0);
  grid.add_congruence(y %= 0);

  Pointset_Powerset<Grid> pps_gr(grid);

  Pointset_Powerset<C_Polyhedron> pps(pps_gr);

  Pointset_Powerset<C_Polyhedron> known_pps(2);

  known_pps.add_constraint(2*x == 1);

  bool ok = (pps == known_pps);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = pps.begin();
  C_Polyhedron phi = i->element();
  print_constraints(phi, "*** phi ***");

  return ok;
}

// Constructs the powerset of nnc polyhedra from a powerset of
// closed polyhedra.
bool
test12() {
  Variable x(0);
  Variable y(1);

  C_Polyhedron ph(2);
  ph.add_constraint(2*x == 1);
  ph.add_constraint(y >= 0);

  Pointset_Powerset<C_Polyhedron> pps_c(ph);

  Pointset_Powerset<NNC_Polyhedron> pps(pps_c);

  Pointset_Powerset<NNC_Polyhedron> known_pps(2);

  known_pps.add_constraint(2*x == 1);
  known_pps.add_constraint(y >= 0);

  bool ok = (pps == known_pps);

  Pointset_Powerset<NNC_Polyhedron>::const_iterator i = pps.begin();
  NNC_Polyhedron phi = i->element();
  print_constraints(phi, "*** phi ***");

  return ok;
}

// Constructs the powerset of nnc polyhedra from a powerset of
// closed polyhedra.
bool
test13() {
  Variable x(0);
  Variable y(1);

  Pointset_Powerset<C_Polyhedron> pps(2);

  pps.add_constraint(x >= 1);
  pps.add_constraint(x <= 1);
  pps.add_constraint(y >= 0);

  Pointset_Powerset<C_Polyhedron> pps1(pps, POLYNOMIAL_COMPLEXITY);

  Pointset_Powerset<C_Polyhedron>::const_iterator i1 = pps.begin();
  C_Polyhedron phi1 = i1->element();
  print_constraints(phi1, "*** phi1 ***");

  pps.OK();

  Pointset_Powerset<C_Polyhedron>::const_iterator i = pps.begin();
  C_Polyhedron phi = i->element();
  phi.OK();
  print_constraints(phi, "*** phi after ok check ***");

  bool ok = true;

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
END_MAIN
