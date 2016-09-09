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
  Constraint_System cs = Constraint_System::zero_dim_empty();
  Pointset_Powerset<C_Polyhedron> ps(cs);
  return ps.OK();
}

bool
test02() {
  Variable x(0);
  Constraint_System cs;
  Pointset_Powerset<NNC_Polyhedron> nnc_ps(1, EMPTY);

  cs.clear();
  cs.insert(x > 0);
  cs.insert(x <= 1);
  nnc_ps.add_disjunct(NNC_Polyhedron(cs));

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x < 1);
  nnc_ps.add_disjunct(NNC_Polyhedron(cs));

  Pointset_Powerset<C_Polyhedron> c_ps(nnc_ps);

  return c_ps.OK();
}

bool
test03() {
  Variable x(0);
  Constraint_System cs;
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  c_ps.add_disjunct(C_Polyhedron(cs));

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);
  c_ps.add_disjunct(C_Polyhedron(cs));

  c_ps.add_constraint(x == 1);

  Pointset_Powerset<NNC_Polyhedron> nnc_ps(c_ps);

  return nnc_ps.OK();
}

bool
test04() {
  Variable x(0);
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  c_ps.add_disjunct(C_Polyhedron(cs));

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);
  c_ps.add_disjunct(C_Polyhedron(cs));

  c_ps.concatenate_assign(c_ps);

  return c_ps.OK();
}

bool
test05() {
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);

  bool ok = c_ps.is_bottom();

  c_ps.add_disjunct(C_Polyhedron(1, UNIVERSE));

  bool ok1 = c_ps.is_top();

  c_ps.total_memory_in_bytes();
  c_ps.external_memory_in_bytes();

  return ok && ok1;
}

bool
test06() {
  Variable x(0);
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  c_ps.add_disjunct(C_Polyhedron(cs));

  Pointset_Powerset<C_Polyhedron> c_ps1(1, EMPTY);
  Constraint_System cs1;
  cs1.insert(x >= 0);
  cs1.insert(x <= 2);
  c_ps1.add_disjunct(C_Polyhedron(cs1));

  bool ok = c_ps1.definitely_entails(c_ps);

  return ok;
}

bool
test07() {
  Variable x(0);
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  c_ps.add_disjunct(C_Polyhedron(cs));

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);
  c_ps.add_disjunct(C_Polyhedron(cs));

  bool ok = (c_ps.size() == 2);

  return ok;
}

bool
test08() {
  Variable x(0);
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  c_ps.add_disjunct(C_Polyhedron(cs));

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x <= 3);
  c_ps.add_disjunct(C_Polyhedron(cs));
  c_ps.omega_reduce();

  bool ok = (c_ps.size() == 1);

  return ok;
}

bool
test09() {
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);
  bool ok = (c_ps.space_dimension() == 1);
  return ok;
}

bool
test10() {
  Variable x(0);
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  Constraint_System cs1 = cs;
  c_ps.add_disjunct(C_Polyhedron(cs));
  c_ps.drop_disjunct(c_ps.begin());

  bool ok = c_ps.empty();

  Constraint_System cs2 = cs1;
  c_ps.add_disjunct(C_Polyhedron(cs1));

  cs.insert(x >= 0);
  cs.insert(x <= 3);
  c_ps.add_disjunct(C_Polyhedron(cs));
  c_ps.drop_disjuncts(c_ps.begin(), c_ps.end());

  bool ok1 = c_ps.empty();

  return ok && ok1;
}

bool
test11() {
  Variable x(0);
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  c_ps.add_disjunct(C_Polyhedron(cs));

  Pointset_Powerset<C_Polyhedron> c_ps1;
  c_ps1 = c_ps;

  bool ok = !c_ps.empty();
  return ok;
}

bool
test12() {
  Variable x(0);
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  c_ps.add_disjunct(C_Polyhedron(cs));

  Pointset_Powerset<C_Polyhedron> c_ps1(1, EMPTY);
  c_ps.swap(c_ps1);

  bool ok = (c_ps.empty() && !c_ps1.empty());
  return ok;
}

bool
test13() {
  Variable x(0);
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  c_ps.add_disjunct(C_Polyhedron(cs));

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);

  Pointset_Powerset<C_Polyhedron> c_ps1(1, EMPTY);
  c_ps1.add_disjunct(C_Polyhedron(cs));
  c_ps.least_upper_bound_assign(c_ps1);

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x <= 3);

  Pointset_Powerset<C_Polyhedron> c_ps2(1, EMPTY);
  c_ps2.add_disjunct(C_Polyhedron(cs));

  bool ok = c_ps.definitely_entails(c_ps2);
  bool ok1 = !c_ps2.definitely_entails(c_ps);

  return ok && ok1;
}

bool
test14() {
  Variable x(0);
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  c_ps.add_disjunct(C_Polyhedron(cs));

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);

  Pointset_Powerset<C_Polyhedron> c_ps1(1, EMPTY);
  c_ps1.add_disjunct(C_Polyhedron(cs));
  c_ps.upper_bound_assign(c_ps1);

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x <= 3);

  Pointset_Powerset<C_Polyhedron> c_ps2(1, EMPTY);
  c_ps2.add_disjunct(C_Polyhedron(cs));

  bool ok = c_ps.definitely_entails(c_ps2);
  bool ok1 = !c_ps2.definitely_entails(c_ps);

  return ok && ok1;
}

bool
test15() {
  Variable x(0);
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  c_ps.add_disjunct(C_Polyhedron(cs));

  Pointset_Powerset<C_Polyhedron> c_ps1(1, EMPTY);

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);

  c_ps.meet_assign(c_ps1);

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 2);
  Pointset_Powerset<C_Polyhedron> c_ps_expected(1, EMPTY);
  c_ps_expected.add_disjunct(C_Polyhedron(cs));

  bool ok = c_ps.definitely_entails(c_ps_expected);
  bool ok1 = !c_ps_expected.definitely_entails(c_ps);

  return ok && ok1;
}

bool
test16() {
  Variable x(0);
  Pointset_Powerset<C_Polyhedron> c_ps(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  c_ps.add_disjunct(C_Polyhedron(cs));

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);
  c_ps.add_disjunct(C_Polyhedron(cs));

  c_ps.collapse();

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x <= 3);
  Pointset_Powerset<C_Polyhedron> c_ps_expected(1, EMPTY);
  c_ps_expected.add_disjunct(C_Polyhedron(cs));

  bool ok = c_ps.definitely_entails(c_ps_expected);
  bool ok1 = c_ps_expected.definitely_entails(c_ps);
  bool ok2 = (c_ps.size() == 1);

  return ok && ok1 && ok2;
}

bool
test17() {
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

  phi.upper_bound_assign(phi1);
  print_constraints(phi, "*** phi ***");

  return ok && ok1;
}

bool
test18() {
  Variable x(0);
  Pointset_Powerset<C_Polyhedron> c_ps1(1);
  Constraint_System cs;
  cs.insert(x >= 5);
  cs.insert(x <= 3);
  c_ps1.add_constraints(cs);

  Pointset_Powerset<C_Polyhedron> c_ps2(1, EMPTY);

  bool ok1 = c_ps1.geometrically_equals(c_ps2);
  bool ok2 = c_ps2.geometrically_equals(c_ps1);

  return ok1 && ok2;
}

bool
test19() {
  Variable x(0);
  Pointset_Powerset<C_Polyhedron> c_ps1(1);
  Constraint_System cs;
  cs.insert(x >= 5);
  cs.insert(x >= 8);
  c_ps1.add_constraints(cs);

  Pointset_Powerset<C_Polyhedron> c_ps2(1);
  cs.clear();
  cs.insert(x >= 8);
  c_ps2.add_constraints(cs);

  bool ok1 = c_ps1.geometrically_equals(c_ps2);
  bool ok2 = c_ps2.geometrically_equals(c_ps1);

  return ok1 && ok2;
}

bool
test20() {
  Variable x(0);
  Variable y(1);
  Pointset_Powerset<C_Polyhedron> c_ps1(2, UNIVERSE);

  Pointset_Powerset<C_Polyhedron> c_ps2(2);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 1);
  cs.insert(y >= 0);
  cs.insert(y <= 1);
  c_ps2.add_constraints(cs);

  using namespace IO_Operators;
  c_ps1.difference_assign(c_ps2);

  nout << c_ps1 << endl;

  return true;
}

bool
test21() {
  Variable x(0);
  Variable y(1);
  Pointset_Powerset<C_Polyhedron> c_ps1(2, UNIVERSE);

  Pointset_Powerset<C_Polyhedron> c_ps2(2);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 1);
  cs.insert(y >= 0);
  cs.insert(y <= 1);
  c_ps2.add_constraints(cs);

  using namespace IO_Operators;
  c_ps1.difference_assign(c_ps2);

  nout << c_ps1 << endl;

  return true;
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
  DO_TEST(test21);
END_MAIN
