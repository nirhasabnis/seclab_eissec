/* Test Polyhedron::simplify_using_context_assign().
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
  Variable z(2);

  C_Polyhedron icosahedron(3);
  icosahedron.add_constraint(4*x - 2*y - z + 14 >= 0);
  icosahedron.add_constraint(4*x + 2*y - z + 2 >= 0);
  icosahedron.add_constraint(x + y - 1 >= 0);
  icosahedron.add_constraint(x + y + 2*z - 5 >= 0);
  icosahedron.add_constraint(x + 1 >= 0);
  icosahedron.add_constraint(x + z - 1 >= 0);
  icosahedron.add_constraint(2*x + y -2*z + 7 >= 0);
  icosahedron.add_constraint(x - y + 2*z + 1 >= 0);
  icosahedron.add_constraint(x - y + 5 >= 0);
  icosahedron.add_constraint(2*x - y - 2*z + 13 >= 0);
  icosahedron.add_constraint(-2*x - y + 2*z + 1 >= 0);
  icosahedron.add_constraint(-x + y - 1 >= 0);
  icosahedron.add_constraint(-x + y -2*z + 7 >= 0);
  icosahedron.add_constraint(-4*x + 2*y + z - 4 >= 0);
  icosahedron.add_constraint(-2*x + y + 2*z - 5 >= 0);
  icosahedron.add_constraint(-x + 1 >= 0);
  icosahedron.add_constraint(-x - z + 5 >= 0);
  icosahedron.add_constraint(-4*x - 2*y + z + 8 >= 0);
  icosahedron.add_constraint(-x - y + 5 >= 0);
  icosahedron.add_constraint(-x - y -2*z +13 >= 0);

  C_Polyhedron column(3);
  column.add_constraint(y >= 2);
  column.add_constraint(y <= 4);
  column.add_constraint(x >= 0);
  column.add_constraint(x <= 1);

  C_Polyhedron computed_result = icosahedron;
  computed_result.simplify_using_context_assign(column);

#if 0
  C_Polyhedron known_result(3);
  known_result.add_constraint(-4*x - 2*y + z >= -8);
  known_result.add_constraint(-4*x + 2*y + z >= 4);
  known_result.add_constraint(-2*x - y + 2*z >= -1);
  known_result.add_constraint(-2*x + y + 2*z >= 5);
  known_result.add_constraint(-x - y - 2*z >= -13);
  known_result.add_constraint(-x - z >= -5);
  known_result.add_constraint(-x >= -1);
  known_result.add_constraint(-x + y - 2*z >= -7);
  known_result.add_constraint(-y >= -4);
  known_result.add_constraint(y >= 2);
  known_result.add_constraint(x >= 0);

  bool ok = (computed_result == known_result);
#endif

  print_constraints(icosahedron, "*** icosahedron ***");
  print_constraints(column, "*** column ***");
  print_constraints(computed_result, "*** computed_result ***");
#if 0
  print_constraints(known_result, "*** known_result ***");
#endif
  return true;
  //return ok;
}

bool
test02() {
  Variable x(0);
  Variable y(1);
  Variable z(2);

  C_Polyhedron icosahedron1(3);
  icosahedron1.add_constraint(4*x - 2*y - z + 14 >= 0);
  icosahedron1.add_constraint(4*x + 2*y - z + 2 >= 0);
  icosahedron1.add_constraint(x + y - 1 >= 0);
  icosahedron1.add_constraint(x + y + 2*z - 5 >= 0);
  icosahedron1.add_constraint(x + 1 >= 0);
  icosahedron1.add_constraint(x + z - 1 >= 0);
  icosahedron1.add_constraint(2*x + y -2*z + 7 >= 0);
  icosahedron1.add_constraint(x - y + 2*z + 1 >= 0);
  icosahedron1.add_constraint(x - y + 5 >= 0);
  icosahedron1.add_constraint(2*x - y - 2*z + 13 >= 0);
  icosahedron1.add_constraint(-2*x - y + 2*z + 1 >= 0);
  icosahedron1.add_constraint(-x + y - 1 >= 0);
  icosahedron1.add_constraint(-x + y -2*z + 7 >= 0);
  icosahedron1.add_constraint(-4*x + 2*y + z - 4 >= 0);
  icosahedron1.add_constraint(-2*x + y + 2*z - 5 >= 0);
  icosahedron1.add_constraint(-x + 1 >= 0);
  icosahedron1.add_constraint(-x - z + 5 >= 0);
  icosahedron1.add_constraint(-4*x - 2*y + z + 8 >= 0);
  icosahedron1.add_constraint(-x - y + 5 >= 0);
  icosahedron1.add_constraint(-x - y -2*z +13 >= 0);

  C_Polyhedron icosahedron2 = icosahedron1;
  icosahedron2.affine_image(x, x+5);


  C_Polyhedron computed_result = icosahedron1;
  computed_result.simplify_using_context_assign(icosahedron2);

  C_Polyhedron known_result(3);
  known_result.add_constraint(-4*x - 2*y + z >= -8);

  bool ok = (computed_result == known_result);

  print_constraints(icosahedron1, "*** icosahedron1 ***");
  print_constraints(icosahedron2, "*** icosahedron2 ***");
  print_constraints(computed_result, "*** computed_result ***");
  print_constraints(known_result, "*** known_result ***");

  return ok;
}

#if 0
int
aux_test02(const C_Polyhedron& ph) {
  if (ph.is_empty() || ph.space_dimension() == 0)
    return 0;

  int count = 0;
  const Generator_System& gs = ph.generators();
  for (Generator_System::const_iterator i = gs.begin(), gs_end = gs.end();
       i != gs_end;
       ++i)
    if (i->type() == Generator::POINT)
      ++count;
  return count;
}

// Intersection of a pyramid with an half-space of variable height.
bool
test02() {
  Variable x(0);
  Variable y(1);
  Variable z(2);

  // This is the height of the pyramid.
  const Coefficient pyramid_height = 16;

  // We will intersect it with the half-spaces `z <= k' and `z >= k'
  // with k = i*(height/4) for i = -1, 0, 1, ..., 5.
  struct {
    Coefficient plane_height;
    int num_points_above;
    int num_points_below;
  } ph_nv[]
      = { {-1*(pyramid_height/4), 5, 0},
	  { 0*(pyramid_height/4), 5, 4},
	  { 1*(pyramid_height/4), 5, 8},
	  { 2*(pyramid_height/4), 5, 8},
	  { 3*(pyramid_height/4), 5, 8},
	  { 4*(pyramid_height/4), 1, 5},
	  { 5*(pyramid_height/4), 0, 5}
      };

  Generator_System gs;
  gs.insert(point(0*x + 0*y + 0*z));
  gs.insert(point(2*x + 0*y + 0*z));
  gs.insert(point(0*x + 2*y + 0*z));
  gs.insert(point(2*x + 2*y + 0*z));
  gs.insert(point(x + y + pyramid_height*z));
  C_Polyhedron pyramid(gs);

    print_constraints(pyramid, "*** pyramid constraints ***");
    print_generators(pyramid, "*** pyramid generators ***");

  bool ok = true;

  for (dimension_type i = 0; i <= 6; ++i) {
    // Above.
    C_Polyhedron hyper_space_above(3);
    hyper_space_above.add_constraint(z >= ph_nv[i].plane_height);

    C_Polyhedron computed_result = pyramid;
    computed_result.intersection_assign_and_minimize(hyper_space_above);

    if (ok
	&& aux_test02(computed_result) != ph_nv[i].num_points_above)
      ok = false;

    print_constraints(hyper_space_above, "*** hyper_space_above ***");
    print_generators(computed_result, "*** computed_result ***");

    // Below.
    C_Polyhedron hyper_space_below(3);
    hyper_space_below.add_constraint(z <= ph_nv[i].plane_height);

    computed_result = pyramid;
    computed_result.intersection_assign_and_minimize(hyper_space_below);

    if (ok
	&& aux_test02(computed_result) != ph_nv[i].num_points_below)
      ok = false;

    print_constraints(hyper_space_below, "*** hyper_space_below ***");
    print_generators(computed_result, "*** computed_result ***");

  }
  return ok;
}
#endif

bool
test03() {
  Variable x(0);

  C_Polyhedron ph1(1);
  ph1.add_constraint(x >= 0);
  ph1.add_constraint(x <= 6);

  print_constraints(ph1, "*** ph1 ***");

  C_Polyhedron ph2(1);
  ph2.add_constraint(x >= 0);
  ph2.add_constraint(x <= 5);

  print_constraints(ph2, "*** ph2 ***");

  C_Polyhedron computed_result = ph1;

  computed_result.simplify_using_context_assign(ph2);

  C_Polyhedron known_result(1);

  bool ok = (computed_result == known_result);

  print_constraints(computed_result,
                    "*** ph1.simplify_using_context_assign ***");

  return ok;
}

bool
test04() {
  Variable i(0);
  Variable j(1);
  Variable k(2);

  C_Polyhedron ph1 = C_Polyhedron(3, UNIVERSE);
  ph1.add_constraint(i >= 1);
  ph1.add_constraint(i <= 10);
  ph1.add_constraint(j >= 1);
  ph1.add_constraint(j <= 10);
  ph1.add_constraint(k == 0);

  C_Polyhedron ph2 = C_Polyhedron(3, UNIVERSE);
  ph2.add_constraint(i >= 0);
  ph2.add_constraint(i <= 2);
  ph2.add_constraint(j >= 2);
  ph2.add_constraint(j <= 9);
  ph2.add_constraint(k == 0);

  print_constraints(ph1, "=== ph1 ===");
  print_constraints(ph2, "=== ph2 ===");

  C_Polyhedron known_result = C_Polyhedron(3, UNIVERSE);
  known_result.add_constraint(i >= 1);

  ph1.simplify_using_context_assign(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1, "=== ph1.simplify_using_context_assign(ph2) ===");

  return ok;
}

bool
test05() {
  Variable i(0);
  Variable j(1);
  Variable k(2);

  C_Polyhedron ph1(3, UNIVERSE);
  ph1.add_constraint(i == 1);
  ph1.add_constraint(j + 1 == 0);
  ph1.add_constraint(k == 3);

  C_Polyhedron ph2(3, UNIVERSE);
  ph2.add_constraint(i == 1);
  ph2.add_constraint(j + k == 2);
  ph2.add_constraint(k >= 0);
  ph2.add_constraint(k <= 3);

  C_Polyhedron known_result(3, UNIVERSE);
  known_result.add_constraint(k == 3);
  // known_result.add_constraint(j + 1 == 0);

  ph1.simplify_using_context_assign(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1, "=== ph1.simplify_using_context_assign(ph2) ===");

  return ok;
}

bool
test06() {
  Variable A(0);
  Variable B(1);
  Variable C(2);

  C_Polyhedron ph1(3, UNIVERSE);
  ph1.add_constraint(A == 0);
  ph1.add_constraint(B == C);
  ph1.add_constraint(B >= 2);
  print_constraints(ph1, "\n=== ph1 ===");

  C_Polyhedron ph2(3, UNIVERSE);
  ph2.add_constraint(A == 0);
  ph2.add_constraint(C >= 2);
  print_constraints(ph2, "\n=== ph2 ===");

  ph1.simplify_using_context_assign(ph2);

  C_Polyhedron known_result(3, UNIVERSE);
  known_result.add_constraint(B == C);

  bool ok = (ph1 == known_result);

  print_constraints(ph1, "\n=== ph1.simplify_using_context_assign(ph2) ===");

  return ok;
}

#if 0
bool
aux_test07(C_Polyhedron& ph1,
	   const C_Polyhedron& ph2,
	   // Note intentional call-by-value!
	   C_Polyhedron known_result) {

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(ph2, "*** ph2 ***");

  ph1.intersection_assign_and_minimize(ph2);

  print_generators(ph1, "*** after intersection_assign ***");

  return ph1 == known_result;
}

bool
test07() {
  Variable x(0);
  Variable y(1);

  C_Polyhedron ph1_1(2);
  ph1_1.add_constraint(x >= 0);
  ph1_1.add_constraint(y >= 0);
  ph1_1.add_constraint(x <= 2);
  ph1_1.add_constraint(y <= 2);
  C_Polyhedron ph1_2(ph1_1);

  C_Polyhedron ph2_1(2);
  ph2_1.add_constraint(x+y <= 0);
  ph2_1.add_constraint(x+y >= 2);
  C_Polyhedron ph2_2(ph2_1);
  C_Polyhedron ph2_3(ph2_1);
  C_Polyhedron ph2_4(ph2_1);

  bool ok = aux_test07(ph1_1, ph2_1, ph2_1)
    && aux_test07(ph2_2, ph1_2, ph2_2)
    && aux_test07(ph2_3, ph2_4, ph2_3);

  return ok;
}

bool
test08() {
  Variable A(0);

  C_Polyhedron ph1(2, EMPTY);
  C_Polyhedron ph2(2);
  ph2.add_constraint(A == 0);

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(ph2, "*** ph2 ***");

  C_Polyhedron known_result(ph1);

  ph1.intersection_assign_and_minimize(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1,
		    "*** after ph1.intersection_assign_and_minimize(ph2) ***");

  return ok;
}

bool
test09() {
  C_Polyhedron ph1;
  C_Polyhedron ph2(0, EMPTY);
  ph2.add_generator(point());

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(ph2, "*** ph2 ***");

  C_Polyhedron known_result = ph1;

  ph1.intersection_assign_and_minimize(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1,
		    "*** after ph1.intersection_assign_and_minimize(ph2) ***");

  return ok;
}

bool
test10() {
  Variable A(0);
  Variable B(1);

  C_Polyhedron ph1(2, EMPTY);
  C_Polyhedron ph2(2);
  ph2.add_constraint(A - B >= 0);

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(ph2, "*** ph2 ***");

  C_Polyhedron known_result(ph1);

  ph1.intersection_assign(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1, "*** after ph1.intersection_assign(ph2) ***");

  return ok;
}

bool
test11() {
  C_Polyhedron ph1;
  C_Polyhedron ph2;

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(ph2, "*** ph2 ***");

  C_Polyhedron known_result(ph1);

  ph1.intersection_assign(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1, "*** after ph1.intersection_assign(ph2) ***");

  return ok;
}

bool
test12() {
  Variable A(0);
  Variable B(1);

  C_Polyhedron ph1(2);
  ph1.generators();
  ph1.add_constraint(A == B);
  C_Polyhedron copy_ph1 = ph1;

  C_Polyhedron ph2(2);
  ph2.generators();
  ph2.add_constraint(A >= B + 1);
  C_Polyhedron copy_ph2 = ph2;

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(ph2, "*** ph2 ***");

  ph1.intersection_assign(ph2);
  copy_ph1.intersection_assign_and_minimize(copy_ph2);

  bool ok = (ph1 == copy_ph1);

  print_constraints(ph1, "*** after intersection_assign ***");
  print_constraints(copy_ph1,
		    "*** after intersection_assign_and_minimize ***");

  return ok;
}

bool
test13() {
  Variable A(0);
  Variable B(1);

  C_Polyhedron ph1(2, EMPTY);
  ph1.add_generator(point());
  ph1.constraints();
  ph1.add_generator(line(A + B));
  C_Polyhedron copy_ph1 = ph1;

  C_Polyhedron ph2(2, EMPTY);
  ph2.add_generator(point());
  ph2.constraints();
  ph2.add_generator(ray(A));
  ph2.add_generator(ray(B));

  C_Polyhedron copy_ph2 = ph2;

  print_generators(ph1, "*** ph1 ***");
  print_generators(ph2, "*** ph2 ***");

  ph1.intersection_assign(ph2);
  copy_ph1.intersection_assign_and_minimize(copy_ph2);

  bool ok = (ph1 == copy_ph1);

  print_constraints(ph1, "*** after intersection_assign ***");
  print_constraints(copy_ph1,
		    "*** after intersection_assign_and_minimize ***");

  return ok;
}
#endif

bool
test14() {
  C_Polyhedron ph1(0, EMPTY);
  C_Polyhedron ph2;

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(ph2, "*** ph2 ***");

  C_Polyhedron known_result = ph1;

  ph1.simplify_using_context_assign(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1,
            "*** after ph1.simplify_using_context_assign(ph2) ***");

  return ok;
}

bool
test15() {
  Variable A(0);

  C_Polyhedron ph1(1);
  C_Polyhedron ph2(1);

  ph2.add_constraint( A == 0);

  print_constraints(ph1, "*** ph1 ***");
  print_constraints(ph2, "*** ph2 ***");

  C_Polyhedron known_result = ph1;

  ph1.simplify_using_context_assign(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1,
                    "*** after ph1.simplify_using_context_assign(ph2) ***");

  return ok;
}

bool
test16() {
  Variable i(0);
  Variable j(1);
  Variable k(2);

  C_Polyhedron ph1(3, UNIVERSE);
  ph1.add_constraint(i >= 1);
  ph1.add_constraint(i <= 10);
  ph1.add_constraint(j >= 1);
  ph1.add_constraint(j <= 10);
  ph1.add_constraint(k == 0);

  C_Polyhedron ph2(3, UNIVERSE);
  ph2.add_constraint(i <= 25);
  ph2.add_constraint(j <= 25);
  ph2.add_constraint(i + j >= 25);
  ph2.add_constraint(k == 0);

  // CHECKME: C_Polyhedron known_result(3, EMPTY); ?
  C_Polyhedron known_result(3, UNIVERSE);
  known_result.add_constraint(i <= 10);
  known_result.add_constraint(j <= 10);

  ph1.simplify_using_context_assign(ph2);

  bool ok = (ph1 == known_result);

  print_constraints(ph1);

  return ok;
}

} // namespace

BEGIN_MAIN
  DO_TEST(test01);
  DO_TEST_F8(test02);
  DO_TEST(test03);
  DO_TEST(test04);
  DO_TEST(test05);
  DO_TEST(test06);
#if 0
  DO_TEST(test07);
  DO_TEST(test08);
  DO_TEST(test09);
  DO_TEST(test10);
  DO_TEST(test11);
  DO_TEST(test12);
  DO_TEST(test13);
#endif
  DO_TEST(test14);
  DO_TEST(test15);
  DO_TEST(test16);
END_MAIN
