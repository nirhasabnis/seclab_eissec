/* Test Pointset_Powerset<Pointset_Powerset<PH> >.
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

typedef NNC_Polyhedron Poly;
typedef Domain_Product<Poly, Grid>::Constraints_Product CProduct;

namespace {

bool
test01() {
  Constraint_System cs = Constraint_System::zero_dim_empty();
  Pointset_Powerset<CProduct> pscp(cs);
  return pscp.OK();
}

bool
test02() {
  Variable A(0);

  CProduct cp(1);
  cp.add_constraint(A == 0);
  Pointset_Powerset<CProduct> pscp(1);
  pscp.add_disjunct(cp);
  return pscp.OK();
}

} // namespace

BEGIN_MAIN
  DO_TEST(test01);
  DO_TEST(test02);
/*   DO_TEST(test03); */
/*   DO_TEST(test04); */
/*   DO_TEST(test05); */
/*   DO_TEST(test06); */
/*   DO_TEST(test07); */
/*   DO_TEST(test08); */
/*   DO_TEST(test09); */
/*   DO_TEST(test10); */
/*   DO_TEST(test11); */
/*   DO_TEST(test12); */
/*   DO_TEST(test13); */
/*   DO_TEST(test14); */
/*   DO_TEST(test15); */
/*   DO_TEST(test16); */
/*   DO_TEST(test17); */
/*   DO_TEST(test18); */
/*   DO_TEST(test19); */
/*   DO_TEST(test20); */
/*   DO_TEST(test21); */
END_MAIN
