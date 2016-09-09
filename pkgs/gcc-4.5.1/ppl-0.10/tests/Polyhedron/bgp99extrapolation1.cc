/* Test Pointset_Powerset<PH>::BGP99_extrapolation_assign().
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
#include <vector>

namespace {

const C_Polyhedron&
aux1_test01(unsigned n) {
  Variable x(0);
  Variable y(1);

  static std::vector<C_Polyhedron> p;
  if (p.size() < 5) {
    p.resize(5, C_Polyhedron(2));
    p[2].add_constraint(0 <= x);
    p[2].add_constraint(x <= 4);
    p[2].add_constraint(0 <= y);
    p[2].add_constraint(y <= 4);
    p[1] = p[2];
    p[1].add_constraint(x-y <= 3);
    p[0] = p[1];
    p[0].add_constraint(x+y >= 1);

    p[3].add_constraint(0 <= x);
    p[3].add_constraint(x <= 8);
    p[3].add_constraint(0 <= y);
    p[3].add_constraint(y <= 8);
    p[3].add_constraint(x+y <= 14);
    p[3].add_constraint(x-y >= -6);
    p[4] = p[3];
    p[3].add_constraint(5*x-y >= -2);
    p[3].add_constraint(x+3*y >= 3);
    p[4].add_constraint(4*x-y >= -3);
    p[4].add_constraint(x+2*y >= 2);
  }

  if (n >= p.size()) {
    unsigned new_size = p.size();
    while (n >= new_size)
      new_size *= 2;
    p.resize(p.size()*2);
  }

  if (p[n].is_universe()) {
    p[n] = aux1_test01(n-4);
    p[n].affine_image(x, 2*x);
    p[n].affine_image(y, 8 - 2*y);
  }

  return p[n];
}

Pointset_Powerset<C_Polyhedron>
aux2_test01(unsigned n) {
  Pointset_Powerset<C_Polyhedron> s(2, EMPTY);
  if (n == 0) {

    nout << "S0 = { P0 }" << endl;

    s.add_disjunct(aux1_test01(0));
    return s;
  }

  const int p_base = (n-1)/3*4;

  switch (n % 3) {
  case 1:

    nout << "S" << n << " = { "
	 << "P" << p_base + 1 << ", "
	 << "P" << p_base + 3 << " }" << endl;

    s.add_disjunct(aux1_test01(p_base + 1));
    s.add_disjunct(aux1_test01(p_base + 3));
    break;
  case 2:

    nout << "S" << n << " = { "
	 << "P" << p_base + 2 << ", "
	 << "P" << p_base + 3 << " }" << endl;

    s.add_disjunct(aux1_test01(p_base + 2));
    s.add_disjunct(aux1_test01(p_base + 3));
    break;
  case 0:

    nout << "S" << n << " = { "
	 << "P" << p_base + 2 << ", "
	 << "P" << p_base + 4 << " }" << endl;

    s.add_disjunct(aux1_test01(p_base + 2));
    s.add_disjunct(aux1_test01(p_base + 4));
    break;
  }
  return s;
}

void
aux3_test01(std::ostream& s, const Variable& v) {
  s << char('x' + v.id());
}

bool
test01() {
  // Install the alternate output function.
  Variable::set_output_function(aux3_test01);

  Pointset_Powerset<C_Polyhedron> T = aux2_test01(0);

  using namespace Parma_Polyhedra_Library::IO_Operators;

  nout << "T0 = " << T << endl;

  bool converged = false;
  for (unsigned n = 1; !converged && n <= 20; ++n) {
    Pointset_Powerset<C_Polyhedron> Sn = aux2_test01(n);

    nout << "S" << n << " = " << Sn << endl;

    Sn.BGP99_extrapolation_assign
      (T, widen_fun_ref(&Polyhedron::H79_widening_assign), 2);

    nout << "T" << n << " = " << Sn << endl;

    if (Sn.definitely_entails(T))
      converged = true;
    else
      std::swap(Sn, T);
  }

  return !converged;
}

bool
test02() {
  Variable A(0);
  Variable B(1);

  C_Polyhedron ps1_1(2);
  ps1_1.add_constraint(-A + B >= 5);
  ps1_1.add_constraint(A - B >= -13);
  ps1_1.add_constraint(A >= 3);
  C_Polyhedron ps1_2(2);
  ps1_2.add_constraint(-A + B >= 6);
  ps1_2.add_constraint(A - B >= -16);
  ps1_2.add_constraint(A >= 3);
  C_Polyhedron ps1_3(2);
  ps1_3.add_constraint(-A + B >= 7);
  ps1_3.add_constraint(A - B >= -20);
  ps1_3.add_constraint(A >= 4);
  C_Polyhedron ps1_4(2);
  ps1_4.add_constraint(-A + B >= 8);
  ps1_4.add_constraint(A - B >= -24);
  ps1_4.add_constraint(A >= 5);
  C_Polyhedron ps1_5(2);
  ps1_5.add_constraint(-A + B >= 10);
  ps1_5.add_constraint(A - B >= -28);
  ps1_5.add_constraint(A >= 6);
  C_Polyhedron ps1_6(2);
  ps1_6.add_constraint(-A + B >= 12);
  ps1_6.add_constraint(A - B >= -32);
  ps1_6.add_constraint(A >= 7);
  C_Polyhedron ps1_7(2);
  ps1_7.add_constraint(-A + B >= 2);
  ps1_7.add_constraint(A - B >= -4);
  ps1_7.add_constraint(A >= 0);
  C_Polyhedron ps1_8(2);
  ps1_8.add_constraint(-A + B >= 3);
  ps1_8.add_constraint(A - B >= -8);
  ps1_8.add_constraint(A >= 1);
  C_Polyhedron ps1_9(2);
  ps1_9.add_constraint(-A + B >= 4);
  ps1_9.add_constraint(A - B >= -12);
  ps1_9.add_constraint(A >= 2);

  Pointset_Powerset<C_Polyhedron> ps1(2, EMPTY);
  ps1.add_disjunct(ps1_1);
  ps1.add_disjunct(ps1_2);
  ps1.add_disjunct(ps1_3);
  ps1.add_disjunct(ps1_4);
  ps1.add_disjunct(ps1_5);
  ps1.add_disjunct(ps1_6);
  ps1.add_disjunct(ps1_7);
  ps1.add_disjunct(ps1_8);
  ps1.add_disjunct(ps1_9);

  C_Polyhedron ps2_1(2);
  ps2_1.add_constraint(-A + B >= 2);
  ps2_1.add_constraint(A - B >= -4);
  ps2_1.add_constraint(A >= 0);
  C_Polyhedron ps2_2(2);
  ps2_2.add_constraint(-A + B >= 3);
  ps2_2.add_constraint(A - B >= -8);
  ps2_2.add_constraint(A >= 1);
  C_Polyhedron ps2_3(2);
  ps2_3.add_constraint(-A + B >= 4);
  ps2_3.add_constraint(A - B >= -12);
  ps2_3.add_constraint(A >= 2);
  C_Polyhedron ps2_4(2);
  ps2_4.add_constraint(-A + B >= 6);
  ps2_4.add_constraint(A - B >= -16);
  ps2_4.add_constraint(A >= 3);

  Pointset_Powerset<C_Polyhedron> ps2(2, EMPTY);
  ps2.add_disjunct(ps2_1);
  ps2.add_disjunct(ps2_2);
  ps2.add_disjunct(ps2_3);
  ps2.add_disjunct(ps2_4);

  using namespace Parma_Polyhedra_Library::IO_Operators;
  nout << "*** ps1 ***" << endl
       << ps1 << endl;
  nout << "*** ps2 ***" << endl
       << ps2 << endl;

  ps1.BGP99_extrapolation_assign
    (ps2, widen_fun_ref(&Polyhedron::H79_widening_assign), 7);

  Pointset_Powerset<C_Polyhedron> known_result(2, EMPTY);
  C_Polyhedron kr_1(2);
  kr_1.add_constraint(A - B >= -16);
  kr_1.add_constraint(A >= 3);
  C_Polyhedron kr_2(2);
  kr_2.add_constraint(-A + B >= 3);
  kr_2.add_constraint(A >= 1);
  C_Polyhedron kr_3(2);
  kr_3.add_constraint(A - B >= -12);
  known_result.add_disjunct(kr_1);
  known_result.add_disjunct(kr_2);
  known_result.add_disjunct(kr_3);

  bool ok = ps1.geometrically_equals(known_result);

  nout
    << "*** ps1.BGP99_extrapolation_assign"
    << "(ps2, widen_fun_ref(&H79_widening_assign), 7) ***"
    << endl
    << ps1 << endl;

  return ok;
}

} // namespace

BEGIN_MAIN
  DO_TEST_F16(test01);
  DO_TEST_F8(test02);
END_MAIN
