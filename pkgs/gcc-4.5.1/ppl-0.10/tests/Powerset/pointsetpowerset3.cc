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

bool
test01() {
  Pointset_Powerset<C_Polyhedron> ps(0, EMPTY);
  bool b = !ps.is_universe();

  ps.add_disjunct(C_Polyhedron(0));
  bool b1 = ps.is_universe();
  return b && b1;
}

bool
test02() {
  Variable x(0);
  Constraint_System cs;
  Pointset_Powerset<NNC_Polyhedron> ps(1, EMPTY);

  cs.clear();
  cs.insert(x > 0);
  cs.insert(x <= 1);
  ps.add_disjunct(NNC_Polyhedron(cs));

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x < 1);
  ps.add_disjunct(NNC_Polyhedron(cs));

  bool b = !ps.is_universe();
  return b;
}

bool
test03() {
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);
  bool b = !ps.is_universe();

  ps.add_disjunct(C_Polyhedron(1));

  bool b1 = ps.is_universe();
  return b && b1;
}

bool
test04() {
  Pointset_Powerset<C_Polyhedron> ps(0, EMPTY);
  bool b = ps.is_empty();

  ps.add_disjunct(C_Polyhedron(0));
  bool b1 = !ps.is_empty();
  return b && b1;
}

bool
test05() {
  Variable x(0);
  Constraint_System cs;
  Pointset_Powerset<NNC_Polyhedron> ps(1, EMPTY);

  cs.clear();
  cs.insert(x > 0);
  cs.insert(x <= 1);
  ps.add_disjunct(NNC_Polyhedron(cs));

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x < 1);
  ps.add_disjunct(NNC_Polyhedron(cs));

  bool b = !ps.is_empty();
  return b;
}

bool
test06() {
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);
  bool b = ps.is_empty();

  ps.add_disjunct(C_Polyhedron(1));

  bool b1 = !ps.is_empty();
  return b && b1;
}

bool
test07() {
  Pointset_Powerset<C_Polyhedron> ps(0, EMPTY);
  bool b = ps.is_topologically_closed();

  ps.add_disjunct(C_Polyhedron(0));
  bool b1 = ps.is_topologically_closed();
  return b && b1;
}

bool
test08() {
  Variable x(0);
  Constraint_System cs;
  Pointset_Powerset<NNC_Polyhedron> ps(1, EMPTY);

  cs.clear();
  cs.insert(x > 0);
  cs.insert(x <= 1);
  ps.add_disjunct(NNC_Polyhedron(cs));

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  ps.add_disjunct(NNC_Polyhedron(cs));

  bool b = ps.is_topologically_closed();
  return b;
}

bool
test09() {
  Variable x(0);
  Constraint_System cs;
  Pointset_Powerset<NNC_Polyhedron> ps(1, EMPTY);

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x <= 1);
  ps.add_disjunct(NNC_Polyhedron(cs));

  cs.clear();
  cs.insert(x > 0);
  cs.insert(x < 2);
  ps.add_disjunct(NNC_Polyhedron(cs));

  bool b = !ps.is_topologically_closed();
  return b;
}

bool
test10() {
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);
  bool b = ps.is_topologically_closed();

  ps.add_disjunct(C_Polyhedron(1));

  bool b1 = ps.is_topologically_closed();
  return b && b1;
}

bool
test11() {
  Pointset_Powerset<C_Polyhedron> ps(0, EMPTY);
  bool b = ps.is_bounded();

  ps.add_disjunct(C_Polyhedron(0));
  // A zero-dimension universe is bounded.
  bool b1 = ps.is_bounded();
  return b && b1;
}

bool
test12() {
  Variable x(0);
  Constraint_System cs;
  Pointset_Powerset<NNC_Polyhedron> ps(1, EMPTY);

  cs.clear();
  cs.insert(x > 0);
  cs.insert(x <= 1);
  ps.add_disjunct(NNC_Polyhedron(cs));

  cs.clear();
  cs.insert(x >= 2);
  ps.add_disjunct(NNC_Polyhedron(cs));

  bool b = !ps.is_bounded();
  return b;
}

bool
test13() {
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);
  bool b = ps.is_bounded();

  ps.add_disjunct(C_Polyhedron(1));

  bool b1 = !ps.is_bounded();
  return b && b1;
}

bool
test14() {
  Pointset_Powerset<C_Polyhedron> ps1(0, EMPTY);

  Pointset_Powerset<C_Polyhedron> ps2(0, EMPTY);
  bool b = ps1.is_disjoint_from(ps2);
  bool c = ps2.is_disjoint_from(ps1);

  ps1.add_disjunct(C_Polyhedron(0));
  bool b1 = ps1.is_disjoint_from(ps2);
  bool c1 = ps2.is_disjoint_from(ps1);

  ps2.add_disjunct(C_Polyhedron(0));
  bool b2 = !ps1.is_disjoint_from(ps2);
  bool c2 = !ps2.is_disjoint_from(ps1);

  return b && c && b1 && c1 && b2 && c2;
}

bool
test15() {
  Variable x(0);
  Constraint_System cs;
  Pointset_Powerset<NNC_Polyhedron> ps1(1, EMPTY);

  cs.clear();
  cs.insert(x > 0);
  cs.insert(x <= 1);
  ps1.add_disjunct(NNC_Polyhedron(cs));

  cs.clear();
  cs.insert(x == 2);
  ps1.add_disjunct(NNC_Polyhedron(cs));

  Pointset_Powerset<NNC_Polyhedron> ps2(1, EMPTY);

  cs.clear();
  cs.insert(x > 2);
  cs.insert(x <= 6);
  ps2.add_disjunct(NNC_Polyhedron(cs));

  bool b = ps1.is_disjoint_from(ps2);
  bool c = ps2.is_disjoint_from(ps1);

  cs.clear();
  cs.insert(x >= 2);
  ps2.add_disjunct(NNC_Polyhedron(cs));

  bool b1 = !ps1.is_disjoint_from(ps2);
  bool c1 = !ps2.is_disjoint_from(ps1);

  return b && c && b1 && c1;
}

bool
test16() {
  Variable x(0);
  Constraint_System cs;
  Pointset_Powerset<C_Polyhedron> ps1(1, EMPTY);

  Pointset_Powerset<C_Polyhedron> ps2(1, EMPTY);
  bool b = ps1.is_disjoint_from(ps2);
  bool c = ps2.is_disjoint_from(ps1);

  ps1.add_disjunct(C_Polyhedron(1));

  bool b1 = ps1.is_disjoint_from(ps2);
  bool c1 = ps2.is_disjoint_from(ps1);

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x <= 1);
  ps2.add_disjunct(C_Polyhedron(cs));

  bool b2 = !ps1.is_disjoint_from(ps2);
  bool c2 = !ps2.is_disjoint_from(ps1);

  return b && c && b1 && c1 && b2 && c2;
}

bool
test17() {
  Pointset_Powerset<C_Polyhedron> ps(0, EMPTY);
  bool b = ps.is_discrete();

  ps.add_disjunct(C_Polyhedron(0));
  // A zero-dimension universe is discrete.
  bool b1 = ps.is_discrete();
  return b && b1;
}

bool
test18() {
  Variable x(0);
  Constraint_System cs;
  Pointset_Powerset<NNC_Polyhedron> ps(1, EMPTY);

  cs.clear();
  cs.insert(x == 2);
  ps.add_disjunct(NNC_Polyhedron(cs));

  bool b = ps.is_discrete();

  cs.clear();
  cs.insert(x > 0);
  cs.insert(x <= 1);
  ps.add_disjunct(NNC_Polyhedron(cs));

  bool b1 = !ps.is_discrete();
  return b && b1;
}

bool
test19() {
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);
  bool b = ps.is_discrete();

  ps.add_disjunct(C_Polyhedron(1));

  bool b1 = !ps.is_discrete();
  return b && b1;
}

bool
test20() {
  Variable A(0);
  Variable B(1);
  Pointset_Powerset<Grid> ps(2, EMPTY);
  bool b0 = !ps.is_universe();

  Grid g(2);
  g.add_congruence((A %= 0) / 2);
  ps.add_disjunct(g);
  bool b1 = !ps.is_universe();

  g = Grid(2);
  g.add_congruence((A + B %= 0) / 2);
  ps.add_disjunct(g);
  bool b2 = !ps.is_universe();

  g = Grid(2);
  ps.add_disjunct(g);
  bool b3 = ps.is_universe();

  return b0 && b1 && b2 && b3;
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
  DO_TEST(test17);
  DO_TEST(test18);
  DO_TEST(test19);
  DO_TEST(test20);
END_MAIN
