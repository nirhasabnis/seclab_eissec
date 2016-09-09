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
  Variable x(0);
  Constraint c = (x == 0);
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);
  ps.add_disjunct(C_Polyhedron(1));
  ps.add_constraint(c);
  Congruence cg((x %= 0) / 0);
  Poly_Con_Relation rel = ps.relation_with(cg);

  Poly_Con_Relation known_rel = Poly_Con_Relation::saturates()
    && Poly_Con_Relation::is_included();

  bool ok = (rel == known_rel);;

  return ok && ps.OK();
}

bool
test02() {
  Variable x(0);

  C_Polyhedron ph1(1);
  ph1.add_constraint(x == 1);

  C_Polyhedron ph2(1);
  ph2.add_constraint(x == 2);
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);

  ps.add_disjunct(ph1);
  ps.add_disjunct(ph2);

  Congruence cg((x %= 1) / 0);
  Poly_Con_Relation rel = ps.relation_with(cg);

  Poly_Con_Relation known_rel = Poly_Con_Relation::saturates();

  bool ok = (rel == known_rel);

  return ok && ps.OK();
}

bool
test03() {
  Variable x(0);

  C_Polyhedron ph1(1);
  ph1.add_constraint(x == 1);

  C_Polyhedron ph2(1);
  ph2.add_constraint(x == 2);
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);

  ps.add_disjunct(ph1);
  ps.add_disjunct(ph2);

  Congruence cg((x %= 3) / 4);
  Poly_Con_Relation rel = ps.relation_with(cg);

  Poly_Con_Relation known_rel = Poly_Con_Relation::is_disjoint();

  bool ok = (rel == known_rel);

  return ok && ps.OK();
}

bool
test04() {
  Variable x(0);

  C_Polyhedron ph1(1);
  ph1.add_constraint(x >= 1);

  C_Polyhedron ph2(1);
  ph2.add_constraint(x <= 2);
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);

  ps.add_disjunct(ph1);
  ps.add_disjunct(ph2);

  Congruence cg((x %= 3) / 4);
  Poly_Con_Relation rel = ps.relation_with(cg);

  Poly_Con_Relation known_rel = Poly_Con_Relation::strictly_intersects();

  bool ok = (rel == known_rel);

  return ok && ps.OK();
}

bool
test05() {
  Variable x(0);
  Constraint c = (x == 0);
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);
  ps.add_disjunct(C_Polyhedron(1));
  ps.add_constraint(c);
  Poly_Con_Relation rel = ps.relation_with(c);

  Poly_Con_Relation known_rel = Poly_Con_Relation::saturates()
    && Poly_Con_Relation::is_included();

  bool ok = (rel == known_rel);;

  return ok && ps.OK();
}

bool
test06() {
  Variable x(0);

  C_Polyhedron ph1(1);
  ph1.add_constraint(x == 1);

  C_Polyhedron ph2(1);
  ph2.add_constraint(x == 2);
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);

  ps.add_disjunct(ph1);
  ps.add_disjunct(ph2);

  Constraint c(x == 1);
  Poly_Con_Relation rel = ps.relation_with(c);

  Poly_Con_Relation known_rel = Poly_Con_Relation::saturates();

  bool ok = (rel == known_rel);

  return ok && ps.OK();
}

bool
test07() {
  Variable x(0);

  C_Polyhedron ph1(1);
  ph1.add_constraint(x == 1);

  C_Polyhedron ph2(1);
  ph2.add_constraint(x == 2);
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);

  ps.add_disjunct(ph1);
  ps.add_disjunct(ph2);

  Constraint c(x >= 3);
  Poly_Con_Relation rel = ps.relation_with(c);

  Poly_Con_Relation known_rel = Poly_Con_Relation::is_disjoint();

  bool ok = (rel == known_rel);

  return ok && ps.OK();
}

bool
test08() {
  Variable x(0);

  C_Polyhedron ph1(1);
  ph1.add_constraint(x >= 1);

  C_Polyhedron ph2(1);
  ph2.add_constraint(x <= 2);
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);

  ps.add_disjunct(ph1);
  ps.add_disjunct(ph2);

  Constraint c(x >= 3);
  Poly_Con_Relation rel = ps.relation_with(c);

  Poly_Con_Relation known_rel = Poly_Con_Relation::strictly_intersects();

  bool ok = (rel == known_rel);

  return ok && ps.OK();
}

bool
test09() {
  Variable x(0);

  C_Polyhedron ph1(1);
  ph1.add_constraint(x == 1);

  C_Polyhedron ph2(1);
  ph2.add_constraint(x == 2);
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);

  ps.add_disjunct(ph1);
  ps.add_disjunct(ph2);

  Generator g(point(x));
  Poly_Gen_Relation rel = ps.relation_with(g);

  Poly_Gen_Relation known_rel = Poly_Gen_Relation::subsumes();

  bool ok = (rel == known_rel);

  return ok && ps.OK();
}

bool
test10() {
  Variable x(0);

  C_Polyhedron ph1(1);
  ph1.add_constraint(x == 1);

  C_Polyhedron ph2(1);
  ph2.add_constraint(x <= 2);
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);

  ps.add_disjunct(ph1);
  ps.add_disjunct(ph2);

  Generator g(line(3*x));
  Poly_Gen_Relation rel = ps.relation_with(g);

  Poly_Gen_Relation known_rel = Poly_Gen_Relation::nothing();

  bool ok = (rel == known_rel);

  return ok && ps.OK();
}

bool
test11() {
  Variable x(0);

  C_Polyhedron ph1(1);
  ph1.add_constraint(x == 1);

  C_Polyhedron ph2(1);
  ph2.add_constraint(x <= 2);
  Pointset_Powerset<C_Polyhedron> ps(1, EMPTY);

  ps.add_disjunct(ph1);
  ps.add_disjunct(ph2);

  dimension_type m = 2;

  ps.add_space_dimensions_and_embed(m);
  bool ok = (ps.space_dimension() == 3 && ps.affine_dimension() == 3);

  ps.add_space_dimensions_and_project(m);
  bool ok1 = (ps.space_dimension() == 5 && ps.affine_dimension() == 3);

  ps.remove_higher_space_dimensions(4);
  bool ok2 = (ps.space_dimension() == 4 && ps.affine_dimension() == 3);

  Pointset_Powerset<Rational_Box> psb(7, EMPTY);
  Rational_Box b(7);
  b.add_constraint(x >= 1);
  b.add_constraint(x <= 0);
  psb.add_disjunct(b);
  bool ok3 = (psb.space_dimension() == 7 && psb.affine_dimension() == 0);

  Pointset_Powerset<Grid> psg(7, EMPTY);
  Grid g(7);
  g.add_congruence((x %= 0) / 2);
  g.add_congruence((x %= 1) / 2);
  psg.add_disjunct(g);
  bool ok4 = (psg.space_dimension() == 7 && psg.affine_dimension() == 0);

  return ok && ok1 && ok2 && ok3 && ok4 && ps.OK();
}

bool
test12() {
  Variable x(0);
  Variable y(1);
  Variable z(2);
  Variable w(3);

  C_Polyhedron ph1(4);
  ph1.add_constraint(x == 1);
  ph1.add_constraint(z == 1);

  C_Polyhedron ph2(4);
  ph2.add_constraint(x <= 2);
  ph2.add_constraint(z == 1);
  Pointset_Powerset<C_Polyhedron> ps(4, EMPTY);

  ps.add_disjunct(ph1);
  ps.add_disjunct(ph2);

  Variables_Set to_be_removed;
  to_be_removed.insert(y);
  to_be_removed.insert(w);

  ps.remove_space_dimensions(to_be_removed);
  bool ok = (ps.space_dimension() == 2 && ps.affine_dimension() == 1);

  return ok && ps.OK();
}

bool
test13() {
  Variable x(0);
  Variable y(1);
  Variable z(2);
  Variable w(3);

  C_Polyhedron ph1(4);
  ph1.add_constraint(x == 1);
  ph1.add_constraint(z == 1);

  C_Polyhedron ph2(4);
  ph2.add_constraint(x <= 2);
  ph2.add_constraint(z == 1);
  Pointset_Powerset<C_Polyhedron> ps(4, EMPTY);

  ps.add_disjunct(ph1);
  ps.add_disjunct(ph2);

  ps.expand_space_dimension(y, 2);
  bool ok = (ps.space_dimension() == 6 && ps.affine_dimension() == 5);

  return ok && ps.OK();
}

bool
test14() {
  Variable x(0);
  Variable y(1);
  Variable z(2);
  Variable w(3);

  C_Polyhedron ph1(4);
  ph1.add_constraint(x == 1);
  ph1.add_constraint(z == 1);

  C_Polyhedron ph2(4);
  ph2.add_constraint(x <= 2);
  ph2.add_constraint(z == 1);
  Pointset_Powerset<C_Polyhedron> ps(4, EMPTY);

  ps.add_disjunct(ph1);
  ps.add_disjunct(ph2);

  Variables_Set to_be_folded;
  to_be_folded.insert(y);
  to_be_folded.insert(w);

  ps.fold_space_dimensions(to_be_folded, z);
  bool ok = (ps.space_dimension() == 2 && ps.affine_dimension() == 2);

  return ok && ps.OK();
}

// Constructs the powerset of one polyhedron { x >= 0, x <= 1/2, y >= 0 }
// from the corresponding box.
bool
test15() {
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

  return ok;
}

// Constructs the powerset of one polyhedron
// from the empty box.
bool
test16() {
  Variable x(0);
  Variable y(1);

  Rational_Box box(2, EMPTY);

  Pointset_Powerset<C_Polyhedron> pps(box);

  Pointset_Powerset<C_Polyhedron> known_pps(2, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Uses refine_with_constraint and refine_with_congruence
bool
test17() {
  Variable A(0);
  Variable B(1);
  Variable C(2);
  Variable D(3);

  C_Polyhedron ph1(4);
  ph1.add_constraint(A == 1);
  ph1.add_constraint(C >= 0);
  ph1.add_constraint(B >= 0);

  C_Polyhedron ph2(4);
  ph2.add_constraint(A <= 2);
  ph2.add_constraint(B >= 2);
  Pointset_Powerset<C_Polyhedron> pps(4, EMPTY);

  pps.add_disjunct(ph1);
  pps.add_disjunct(ph2);

  Pointset_Powerset<C_Polyhedron> known_pps(pps);

  pps.refine_with_constraint(C == 0);
  pps.refine_with_constraint(D < 0);
  pps.refine_with_congruence(B + D %= 2);
  pps.refine_with_congruence((B - D %= 2) / 0);


  known_pps.add_constraint(C == 0);
  known_pps.add_constraint(A <= 2);
  known_pps.add_constraint(B <= 2);
  known_pps.add_constraint(B - D == 2);


  bool ok = (pps == known_pps);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = pps.begin();
  C_Polyhedron phi = i->element();
  print_constraints(phi, "*** phi ***");
  i++;
  C_Polyhedron phi1 = i->element();
  print_constraints(phi1, "*** phi1 ***");

  return ok;
}

// Uses refine_with_constraints and refine_with_congruences
bool
test18() {
  Variable A(0);
  Variable B(1);
  Variable C(2);
  Variable D(3);

  C_Polyhedron ph1(4);
  ph1.add_constraint(A == 1);
  ph1.add_constraint(C >= 0);

  C_Polyhedron ph2(4);
  ph2.add_constraint(A <= 2);
  Pointset_Powerset<C_Polyhedron> pps(4, EMPTY);

  pps.add_disjunct(ph1);
  pps.add_disjunct(ph2);

  Pointset_Powerset<C_Polyhedron> known_pps(pps);

  Constraint_System cs;
  cs.insert(A + 2*B >= 0);
  cs.insert(B - C < 3);
  cs.insert(D == 1);

  Congruence_System cgs;
  cgs.insert(A + B %= 0);
  cgs.insert((C %= 2) / 0);

  pps.refine_with_constraints(cs);
  pps.refine_with_congruences(cgs);

  known_pps.add_constraint(C == 2);
  known_pps.add_constraint(D == 1);
  known_pps.add_constraint(A + 2*B >= 0);
  known_pps.add_constraint(B - C <= 3);

  bool ok = (pps == known_pps);

  Pointset_Powerset<C_Polyhedron>::const_iterator i = pps.begin();
  C_Polyhedron phi = i->element();
  print_constraints(phi, "*** phi ***");

  return ok;
}

// use of refine_with_constraints() makes the powerset empty.
bool
test19() {
  Variable A(0);
  Variable B(1);
  Variable C(2);
  Variable D(3);

  C_Polyhedron ph1(4);
  ph1.add_constraint(A == 1);
  ph1.add_constraint(C >= 0);

  C_Polyhedron ph2(4);
  ph2.add_constraint(A <= 2);
  Pointset_Powerset<C_Polyhedron> pps(4, EMPTY);

  pps.add_disjunct(ph1);
  pps.add_disjunct(ph2);

  Constraint_System cs;
  cs.insert(A + 2*B >= 0);
  cs.insert(B - C < 3);
  cs.insert(A > 1);

  Congruence_System cgs;
  cgs.insert(A + B %= 0);
  cgs.insert((B - C %= 4) / 0);

  pps.refine_with_constraints(cs);
  pps.refine_with_congruences(cgs);

  Pointset_Powerset<C_Polyhedron> known_pps(4, EMPTY);

  bool ok = (pps == known_pps);

  return ok;
}

// Uses refine_with_constraints and refine_with_congruences
// with NNC polyhedra
bool
test20() {
  Variable A(0);
  Variable B(1);
  Variable C(2);
  Variable D(3);

  NNC_Polyhedron ph1(4);
  ph1.add_constraint(A == 1);
  ph1.add_constraint(C >= 0);
  ph1.add_constraint(B >= 0);

  NNC_Polyhedron ph2(4);
  ph2.add_constraint(A <= 2);
  ph2.add_constraint(B >= 2);
  Pointset_Powerset<NNC_Polyhedron> pps(4, EMPTY);

  pps.add_disjunct(ph1);
  pps.add_disjunct(ph2);

  Pointset_Powerset<NNC_Polyhedron> known_pps(pps);

  Constraint_System cs;
  cs.insert(A + 2*B >= 0);
  cs.insert(B - C < 3);
  cs.insert(D == 1);

  Congruence_System cgs;
  cgs.insert(A + B %= 0);
  cgs.insert((C %= 2) / 0);

  pps.refine_with_constraints(cs);
  pps.refine_with_congruences(cgs);

  known_pps.add_constraint(C == 2);
  known_pps.add_constraint(D == 1);
  known_pps.add_constraint(A + 2*B >= 0);
  known_pps.add_constraint(B - C < 3);

  bool ok = (pps == known_pps);

  Pointset_Powerset<NNC_Polyhedron>::const_iterator i = pps.begin();
  NNC_Polyhedron phi = i->element();
  print_constraints(phi, "*** phi ***");
  i++;
  NNC_Polyhedron phi1 = i->element();
  print_constraints(phi1, "*** phi1 ***");

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
  DO_TEST(test17);
  DO_TEST(test18);
  DO_TEST(test19);
  DO_TEST(test20);
END_MAIN
