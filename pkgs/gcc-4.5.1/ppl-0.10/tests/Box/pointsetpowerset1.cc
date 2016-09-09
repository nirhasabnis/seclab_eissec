/* Test Pointset_Powerset<PH> with boxes.
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

// Construct powerset from zero dimension empty constraint system.
bool
test01() {
  Constraint_System cs = Constraint_System::zero_dim_empty();
  Pointset_Powerset<TBox> ps(cs);

  print_constraints(ps, "*** ps ***");

  return ps.OK();
}

// add_disjunct(), affine_image() and intersection_assign().
bool
test02() {
  Variable x(0);
  Constraint_System cs;
  Pointset_Powerset<TBox> ps1(1, EMPTY);

  cs.clear();
  cs.insert(x > 0);
  cs.insert(x <= 1);
  ps1.add_disjunct(TBox(cs));

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x < 1);
  ps1.add_disjunct(TBox(cs));

  Pointset_Powerset<TBox> ps2(ps1);
  ps2.affine_image(x, 2*x+1, 2);

  print_constraints(ps1, "*** ps1 ***");
  print_constraints(ps2, "*** ps2 ***");

  ps1.intersection_assign(ps2);

  Pointset_Powerset<TBox> known_result(1, EMPTY);
  TBox box(1);
  box.add_constraint(2*x >= 1);
  box.add_constraint(2*x <= 2);
  known_result.add_disjunct(box);

  bool ok = (ps1 == known_result);

  print_constraints(ps1, "*** ps1.intersect_assign(ps2) ***");
  print_constraints(known_result, "*** known_result ***");

  return ok;
}

bool
test03() {
  Variable x(0);

  Pointset_Powerset<TBox> ps(1, EMPTY);
  Constraint_System cs;
  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x < 2);
  ps.add_disjunct(TBox(cs));

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);
  ps.add_disjunct(TBox(cs));

  print_constraints(ps, "*** ps ***");

  ps.add_constraint(x == 1);

  Pointset_Powerset<TBox> known_result(1, EMPTY);
  TBox box(1);
  box.add_constraint(x == 1);
  known_result.add_disjunct(box);

  bool ok = (ps == known_result);

  print_constraints(ps, "*** ps.add_constraint(x == 1) ***");
  print_constraints(known_result, "*** known_result ***");

  return ok;
}

// add_disjunct() and concatenate_assign().
bool
test04() {
  Variable x(0);
  Pointset_Powerset<TBox> pps_box(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  pps_box.add_disjunct(TBox(cs));

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);
  pps_box.add_disjunct(TBox(cs));

  pps_box.concatenate_assign(pps_box);

  return pps_box.OK();
}

// total_memory_in_bytes() and external_memory_in_bytes().
bool
test05() {
  Pointset_Powerset<TBox> pps_box(1, EMPTY);

  bool ok = pps_box.is_bottom();

  pps_box.add_disjunct(TBox(1, UNIVERSE));

  bool ok1 = pps_box.is_top();

  pps_box.total_memory_in_bytes();
  pps_box.external_memory_in_bytes();

  return ok && ok1;
}

// definitely_entails().
bool
test06() {
  Variable x(0);
  Pointset_Powerset<TBox> pps_box(1, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  pps_box.add_disjunct(TBox(cs));

  Pointset_Powerset<TBox> pps_box1(1, EMPTY);
  Constraint_System cs1;
  cs1.insert(x >= 0);
  cs1.insert(x <= 2);
  pps_box1.add_disjunct(TBox(cs1));

  bool ok = pps_box1.definitely_entails(pps_box);

  return ok;
}

// size().
bool
test07() {
  Variable x(0);
  Pointset_Powerset<TBox> pps_box(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  pps_box.add_disjunct(TBox(cs));

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);
  pps_box.add_disjunct(TBox(cs));

  bool ok = (pps_box.size() == 2);

  return ok;
}

// omega_reduce().
bool
test08() {
  Variable x(0);
  Pointset_Powerset<TBox> pps_box(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  pps_box.add_disjunct(TBox(cs));

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x <= 3);
  pps_box.add_disjunct(TBox(cs));
  pps_box.omega_reduce();

  bool ok = (pps_box.size() == 1);

  return ok;
}

// space_dimension().
bool
test09() {
  Pointset_Powerset<TBox> pps_box(1, EMPTY);
  bool ok = (pps_box.space_dimension() == 1);
  return ok;
}

// add_disjunct(), drop_disjuncts(), empty().
bool
test10() {
  Variable x(0);
  Pointset_Powerset<TBox> pps_box(1, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  Constraint_System cs1 = cs;
  pps_box.add_disjunct(TBox(cs));
  pps_box.drop_disjunct(pps_box.begin());

  bool ok = pps_box.empty();

  Constraint_System cs2 = cs1;
  pps_box.add_disjunct(TBox(cs1));

  cs.insert(x >= 0);
  cs.insert(x <= 3);
  pps_box.add_disjunct(TBox(cs));
  pps_box.drop_disjuncts(pps_box.begin(), pps_box.end());

  bool ok1 = pps_box.empty();

  return ok && ok1;
}

// !empty().
bool
test11() {
  Variable x(0);
  Pointset_Powerset<TBox> pps_box(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  pps_box.add_disjunct(TBox(cs));

  Pointset_Powerset<TBox> pps_box1;
  pps_box1 = pps_box;

  bool ok = !pps_box.empty();
  return ok;
}

// swap().
bool
test12() {
  Variable x(0);
  Pointset_Powerset<TBox> pps_box(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  pps_box.add_disjunct(TBox(cs));

  Pointset_Powerset<TBox> pps_box1(1, EMPTY);
  pps_box.swap(pps_box1);

  bool ok = (pps_box.empty() && !pps_box1.empty());
  return ok;
}

// least_upper_bound_assign().
bool
test13() {
  Variable x(0);
  Pointset_Powerset<TBox> pps_box(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  pps_box.add_disjunct(TBox(cs));

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);

  Pointset_Powerset<TBox> pps_box1(1, EMPTY);
  pps_box1.add_disjunct(TBox(cs));
  pps_box.least_upper_bound_assign(pps_box1);

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x <= 3);

  Pointset_Powerset<TBox> pps_box2(1, EMPTY);
  pps_box2.add_disjunct(TBox(cs));

  bool ok = pps_box.definitely_entails(pps_box2);
  bool ok1 = !pps_box2.definitely_entails(pps_box);

  return ok && ok1;
}

// upper_bound_assign().
bool
test14() {
  Variable x(0);
  Pointset_Powerset<TBox> pps_box(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  pps_box.add_disjunct(TBox(cs));

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);

  Pointset_Powerset<TBox> pps_box1(1, EMPTY);
  pps_box1.add_disjunct(TBox(cs));
  pps_box.upper_bound_assign(pps_box1);

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x <= 3);

  Pointset_Powerset<TBox> pps_box2(1, EMPTY);
  pps_box2.add_disjunct(TBox(cs));

  bool ok = pps_box.definitely_entails(pps_box2);
  bool ok1 = !pps_box2.definitely_entails(pps_box);

  return ok && ok1;
}

// meet_assign().
bool
test15() {
  Variable x(0);
  Pointset_Powerset<TBox> pps_box(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  pps_box.add_disjunct(TBox(cs));

  Pointset_Powerset<TBox> pps_box1(1, EMPTY);

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);

  pps_box.meet_assign(pps_box1);

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 2);
  Pointset_Powerset<TBox> pps_box_expected(1, EMPTY);
  pps_box_expected.add_disjunct(TBox(cs));

  bool ok = pps_box.definitely_entails(pps_box_expected);
  bool ok1 = !pps_box_expected.definitely_entails(pps_box);

  return ok && ok1;
}

// collapse().
bool
test16() {
  Variable x(0);
  Pointset_Powerset<TBox> pps_box(1, EMPTY);
  Constraint_System cs;

  cs.insert(x >= 0);
  cs.insert(x <= 2);
  pps_box.add_disjunct(TBox(cs));

  cs.clear();
  cs.insert(x >= 1);
  cs.insert(x <= 3);
  pps_box.add_disjunct(TBox(cs));

  pps_box.collapse();

  cs.clear();
  cs.insert(x >= 0);
  cs.insert(x <= 3);
  Pointset_Powerset<TBox> pps_box_expected(1, EMPTY);
  pps_box_expected.add_disjunct(TBox(cs));

  bool ok = pps_box.definitely_entails(pps_box_expected);
  bool ok1 = pps_box_expected.definitely_entails(pps_box);
  bool ok2 = (pps_box.size() == 1);

  return ok && ok1 && ok2;
}
// upper_bound_assign().
bool
test17() {
  Variable x(0);
  Variable y(1);
  Pointset_Powerset<TBox> pps_box(2, EMPTY);
  Constraint_System cs;
  cs.insert(x >= 0);
  cs.insert(x <= 2);
  TBox box(2);
  box.add_constraints(cs);
  pps_box.add_disjunct(box);

  Constraint_System cs1;
  cs1.insert(y >= 3);
  cs1.insert(y <= 5);
  TBox box1(2);
  box1.add_constraints(cs1);
  pps_box.add_disjunct(box1);

  Pointset_Powerset<TBox>::const_iterator i = pps_box.begin();
  TBox pps_boxi = i->element();
  i++;
  TBox pps_boxi1 = i->element();

  bool ok = pps_boxi.OK() && pps_boxi == box;

  print_constraints(box, "*** box ***");
  print_constraints(pps_boxi, "*** pps_boxi ***");

  bool ok1 = pps_boxi1.OK() && pps_boxi1 == box1;

  print_constraints(box1, "*** box1 ***");
  print_constraints(pps_boxi1, "*** pps_boxi1 ***");

  pps_boxi.upper_bound_assign(pps_boxi1);
  print_constraints(pps_boxi, "*** pps_boxi ***");

  return ok && ok1;
}

// geometrically_equals().
bool
test18() {
  Variable x(0);
  Pointset_Powerset<TBox> pps_box(1);
  Constraint_System cs;
  cs.insert(x >= 5);
  cs.insert(x <= 3);
  pps_box.add_constraints(cs);

  Pointset_Powerset<TBox> pps_box1(1, EMPTY);

  // pps_box.ascii_dump();
  // pps_box1.ascii_dump();

  bool ok = pps_box.geometrically_equals(pps_box1);
  bool ok1 = pps_box.geometrically_equals(pps_box1);

  return ok && ok1;
}

// geometrically_equals().
bool
test19() {
  Variable x(0);
  Pointset_Powerset<TBox> pps_box(1);
  Constraint_System cs;
  cs.insert(x >= 5);
  cs.insert(x >= 8);
  pps_box.add_constraints(cs);

  Pointset_Powerset<TBox> pps_box1(1);
  cs.clear();
  cs.insert(x >= 8);
  pps_box1.add_constraints(cs);

  // pps_box.ascii_dump();
  // pps_box1.ascii_dump();

  bool ok = pps_box.geometrically_equals(pps_box1);
  bool ok1 = pps_box.geometrically_equals(pps_box1);

  return ok && ok1;
}

// set_interval(), get_interval() and affine_image().
bool
test20() {
  Variable x(0);
  Variable y(1);
  Variable z(2);

  Pointset_Powerset<TBox> ps(3, EMPTY);
  for (int i = -10; i <= 9; ++i) {
    TBox pps_box(3, UNIVERSE);
    pps_box.add_constraint(i <= x);
    pps_box.add_constraint(x <= i+1);
    const TBox::interval_type& ix = pps_box.get_interval(x);
    TBox::interval_type iy = ix*ix;
    pps_box.set_interval(y, iy);
    ps.add_disjunct(pps_box);
  }

  print_constraints(ps, "*** ps ***");

  ps.affine_image(z, y+2*x+1, 2);

  print_constraints(ps, "*** ps ***");

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
END_MAIN
