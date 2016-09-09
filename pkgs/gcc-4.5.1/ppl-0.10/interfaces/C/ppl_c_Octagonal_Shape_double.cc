/* C Octagonal_Shape_double interface code: definitions.
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

#include "ppl_c_implementation_common.defs.hh"
#include "interfaced_boxes.hh"
#include "ppl_c_implementation_domains.hh"

using namespace Parma_Polyhedra_Library;
using namespace Parma_Polyhedra_Library::Interfaces::C;

int
ppl_delete_Octagonal_Shape_double(ppl_const_Octagonal_Shape_double_t ph) try {
  delete to_const(ph);
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_space_dimension
(ppl_Octagonal_Shape_double_t* pph,
 ppl_dimension_type d,
 int empty) try {
  *pph = to_nonconst(new Octagonal_Shape<double>(d, empty ? EMPTY : UNIVERSE));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_C_Polyhedron
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Polyhedron_t ph) try {
  const C_Polyhedron& phh
    = *static_cast<const C_Polyhedron*>(to_const(ph));
  *pph = to_nonconst(new Octagonal_Shape<double>(phh));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_NNC_Polyhedron
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Polyhedron_t ph) try {
  const NNC_Polyhedron& phh
    = *static_cast<const NNC_Polyhedron*>(to_const(ph));
  *pph = to_nonconst(new Octagonal_Shape<double>(phh));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Grid
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Grid_t ph) try {
  const Grid& phh
    = *static_cast<const Grid*>(to_const(ph));
  *pph = to_nonconst(new Octagonal_Shape<double>(phh));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Rational_Box
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Rational_Box_t ph) try {
  const Rational_Box& phh
    = *static_cast<const Rational_Box*>(to_const(ph));
  *pph = to_nonconst(new Octagonal_Shape<double>(phh));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_BD_Shape_mpz_class
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_BD_Shape_mpz_class_t ph) try {
  const BD_Shape<mpz_class>& phh
    = *static_cast<const BD_Shape<mpz_class>*>(to_const(ph));
  *pph = to_nonconst(new Octagonal_Shape<double>(phh));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_BD_Shape_mpq_class
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_BD_Shape_mpq_class_t ph) try {
  const BD_Shape<mpq_class>& phh
    = *static_cast<const BD_Shape<mpq_class>*>(to_const(ph));
  *pph = to_nonconst(new Octagonal_Shape<double>(phh));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Octagonal_Shape_mpz_class
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Octagonal_Shape_mpz_class_t ph) try {
  const Octagonal_Shape<mpz_class>& phh
    = *static_cast<const Octagonal_Shape<mpz_class>*>(to_const(ph));
  *pph = to_nonconst(new Octagonal_Shape<double>(phh));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Octagonal_Shape_mpq_class
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Octagonal_Shape_mpq_class_t ph) try {
  const Octagonal_Shape<mpq_class>& phh
    = *static_cast<const Octagonal_Shape<mpq_class>*>(to_const(ph));
  *pph = to_nonconst(new Octagonal_Shape<double>(phh));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Double_Box
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Double_Box_t ph) try {
  const Double_Box& phh
    = *static_cast<const Double_Box*>(to_const(ph));
  *pph = to_nonconst(new Octagonal_Shape<double>(phh));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_BD_Shape_double
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_BD_Shape_double_t ph) try {
  const BD_Shape<double>& phh
    = *static_cast<const BD_Shape<double>*>(to_const(ph));
  *pph = to_nonconst(new Octagonal_Shape<double>(phh));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Octagonal_Shape_double
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Octagonal_Shape_double_t ph) try {
  const Octagonal_Shape<double>& phh
    = *static_cast<const Octagonal_Shape<double>*>(to_const(ph));
  *pph = to_nonconst(new Octagonal_Shape<double>(phh));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_C_Polyhedron_with_complexity
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Polyhedron_t ph,
 int complexity) try {
  const C_Polyhedron& phh
    = *static_cast<const C_Polyhedron*>(to_const(ph));
  switch (complexity) {
  case 0:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, POLYNOMIAL_COMPLEXITY));
    break;
  case 1:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, SIMPLEX_COMPLEXITY));
    break;
  case 2:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, ANY_COMPLEXITY));
    break;
  }
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_NNC_Polyhedron_with_complexity
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Polyhedron_t ph,
 int complexity) try {
  const NNC_Polyhedron& phh
    = *static_cast<const NNC_Polyhedron*>(to_const(ph));
  switch (complexity) {
  case 0:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, POLYNOMIAL_COMPLEXITY));
    break;
  case 1:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, SIMPLEX_COMPLEXITY));
    break;
  case 2:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, ANY_COMPLEXITY));
    break;
  }
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Grid_with_complexity
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Grid_t ph,
 int complexity) try {
  const Grid& phh
    = *static_cast<const Grid*>(to_const(ph));
  switch (complexity) {
  case 0:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, POLYNOMIAL_COMPLEXITY));
    break;
  case 1:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, SIMPLEX_COMPLEXITY));
    break;
  case 2:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, ANY_COMPLEXITY));
    break;
  }
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Rational_Box_with_complexity
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Rational_Box_t ph,
 int complexity) try {
  const Rational_Box& phh
    = *static_cast<const Rational_Box*>(to_const(ph));
  switch (complexity) {
  case 0:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, POLYNOMIAL_COMPLEXITY));
    break;
  case 1:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, SIMPLEX_COMPLEXITY));
    break;
  case 2:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, ANY_COMPLEXITY));
    break;
  }
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_BD_Shape_mpz_class_with_complexity
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_BD_Shape_mpz_class_t ph,
 int complexity) try {
  const BD_Shape<mpz_class>& phh
    = *static_cast<const BD_Shape<mpz_class>*>(to_const(ph));
  switch (complexity) {
  case 0:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, POLYNOMIAL_COMPLEXITY));
    break;
  case 1:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, SIMPLEX_COMPLEXITY));
    break;
  case 2:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, ANY_COMPLEXITY));
    break;
  }
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_BD_Shape_mpq_class_with_complexity
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_BD_Shape_mpq_class_t ph,
 int complexity) try {
  const BD_Shape<mpq_class>& phh
    = *static_cast<const BD_Shape<mpq_class>*>(to_const(ph));
  switch (complexity) {
  case 0:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, POLYNOMIAL_COMPLEXITY));
    break;
  case 1:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, SIMPLEX_COMPLEXITY));
    break;
  case 2:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, ANY_COMPLEXITY));
    break;
  }
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Octagonal_Shape_mpz_class_with_complexity
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Octagonal_Shape_mpz_class_t ph,
 int complexity) try {
  const Octagonal_Shape<mpz_class>& phh
    = *static_cast<const Octagonal_Shape<mpz_class>*>(to_const(ph));
  switch (complexity) {
  case 0:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, POLYNOMIAL_COMPLEXITY));
    break;
  case 1:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, SIMPLEX_COMPLEXITY));
    break;
  case 2:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, ANY_COMPLEXITY));
    break;
  }
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Octagonal_Shape_mpq_class_with_complexity
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Octagonal_Shape_mpq_class_t ph,
 int complexity) try {
  const Octagonal_Shape<mpq_class>& phh
    = *static_cast<const Octagonal_Shape<mpq_class>*>(to_const(ph));
  switch (complexity) {
  case 0:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, POLYNOMIAL_COMPLEXITY));
    break;
  case 1:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, SIMPLEX_COMPLEXITY));
    break;
  case 2:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, ANY_COMPLEXITY));
    break;
  }
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Double_Box_with_complexity
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Double_Box_t ph,
 int complexity) try {
  const Double_Box& phh
    = *static_cast<const Double_Box*>(to_const(ph));
  switch (complexity) {
  case 0:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, POLYNOMIAL_COMPLEXITY));
    break;
  case 1:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, SIMPLEX_COMPLEXITY));
    break;
  case 2:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, ANY_COMPLEXITY));
    break;
  }
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_BD_Shape_double_with_complexity
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_BD_Shape_double_t ph,
 int complexity) try {
  const BD_Shape<double>& phh
    = *static_cast<const BD_Shape<double>*>(to_const(ph));
  switch (complexity) {
  case 0:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, POLYNOMIAL_COMPLEXITY));
    break;
  case 1:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, SIMPLEX_COMPLEXITY));
    break;
  case 2:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, ANY_COMPLEXITY));
    break;
  }
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Octagonal_Shape_double_with_complexity
(ppl_Octagonal_Shape_double_t* pph,
 ppl_const_Octagonal_Shape_double_t ph,
 int complexity) try {
  const Octagonal_Shape<double>& phh
    = *static_cast<const Octagonal_Shape<double>*>(to_const(ph));
  switch (complexity) {
  case 0:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, POLYNOMIAL_COMPLEXITY));
    break;
  case 1:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, SIMPLEX_COMPLEXITY));
    break;
  case 2:
    *pph = to_nonconst(new Octagonal_Shape<double>(phh, ANY_COMPLEXITY));
    break;
  }
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Constraint_System
(ppl_Octagonal_Shape_double_t* pph, ppl_const_Constraint_System_t cs) try {
  const Constraint_System& ccs = *to_const(cs);
  *pph = to_nonconst(new Octagonal_Shape<double>(ccs));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Congruence_System
(ppl_Octagonal_Shape_double_t* pph, ppl_const_Congruence_System_t cs) try {
  const Congruence_System& ccs = *to_const(cs);
  *pph = to_nonconst(new Octagonal_Shape<double>(ccs));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_from_Generator_System
(ppl_Octagonal_Shape_double_t* pph, ppl_const_Generator_System_t cs) try {
  const Generator_System& ccs = *to_const(cs);
  *pph = to_nonconst(new Octagonal_Shape<double>(ccs));
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_space_dimension
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_dimension_type* m) try {
  *m = to_const(ph)->space_dimension();
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_affine_dimension
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_dimension_type* m) try {
  *m = to_const(ph)->affine_dimension();
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_relation_with_Constraint
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_const_Constraint_t c) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  const Constraint& cc = *to_const(c);
  return pph.relation_with(cc).get_flags();
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_relation_with_Generator
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_const_Generator_t c) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  const Generator& cc = *to_const(c);
  return pph.relation_with(cc).get_flags();
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_relation_with_Congruence
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_const_Congruence_t c) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  const Congruence& cc = *to_const(c);
  return pph.relation_with(cc).get_flags();
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_get_constraints
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_const_Constraint_System_t* pcs) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  const Constraint_System& cs = pph.constraints();
  *pcs = to_const(&cs);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_get_congruences
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_const_Congruence_System_t* pcs) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  const Congruence_System& cs = pph.congruences();
  *pcs = to_const(&cs);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_get_minimized_constraints
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_const_Constraint_System_t* pcs) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  const Constraint_System& cs = pph.minimized_constraints();
  *pcs = to_const(&cs);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_get_minimized_congruences
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_const_Congruence_System_t* pcs) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  const Congruence_System& cs = pph.minimized_congruences();
  *pcs = to_const(&cs);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_is_empty(ppl_const_Octagonal_Shape_double_t ph) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  return pph.is_empty() ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_is_universe(ppl_const_Octagonal_Shape_double_t ph) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  return pph.is_universe() ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_is_bounded(ppl_const_Octagonal_Shape_double_t ph) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  return pph.is_bounded() ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_contains_integer_point(ppl_const_Octagonal_Shape_double_t ph) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  return pph.contains_integer_point() ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_is_topologically_closed(ppl_const_Octagonal_Shape_double_t ph) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  return pph.is_topologically_closed() ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_is_discrete(ppl_const_Octagonal_Shape_double_t ph) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  return pph.is_discrete() ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_topological_closure_assign(ppl_Octagonal_Shape_double_t ph) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  pph.topological_closure_assign();
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_bounds_from_above
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_const_Linear_Expression_t le) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  const Linear_Expression& lle = *to_const(le);
  return pph.bounds_from_above(lle) ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_bounds_from_below
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_const_Linear_Expression_t le) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  const Linear_Expression& lle = *to_const(le);
  return pph.bounds_from_below(lle) ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_maximize
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_const_Linear_Expression_t le,
 ppl_Coefficient_t sup_n,
 ppl_Coefficient_t sup_d,
 int* poptimum) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  const Linear_Expression& lle = *to_const(le);
  Coefficient& ssup_n = *to_nonconst(sup_n);
  Coefficient& ssup_d = *to_nonconst(sup_d);
  bool optimum;
  bool ok = pph.maximize(lle, ssup_n, ssup_d, optimum);
  if (ok)
    *poptimum = optimum ? 1 : 0;
  return ok ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_minimize
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_const_Linear_Expression_t le,
 ppl_Coefficient_t sup_n,
 ppl_Coefficient_t sup_d,
 int* poptimum) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  const Linear_Expression& lle = *to_const(le);
  Coefficient& ssup_n = *to_nonconst(sup_n);
  Coefficient& ssup_d = *to_nonconst(sup_d);
  bool optimum;
  bool ok = pph.minimize(lle, ssup_n, ssup_d, optimum);
  if (ok)
    *poptimum = optimum ? 1 : 0;
  return ok ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_maximize_with_point
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_const_Linear_Expression_t le,
 ppl_Coefficient_t sup_n,
 ppl_Coefficient_t sup_d,
 int* poptimum,
 ppl_Generator_t point) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  const Linear_Expression& lle = *to_const(le);
  Coefficient& ssup_n = *to_nonconst(sup_n);
  Coefficient& ssup_d = *to_nonconst(sup_d);
  Generator& ppoint = *to_nonconst(point);
  bool optimum;
  bool ok = pph.maximize(lle, ssup_n, ssup_d, optimum, ppoint);
  if (ok)
    *poptimum = optimum ? 1 : 0;
  return ok ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_minimize_with_point
(ppl_const_Octagonal_Shape_double_t ph,
 ppl_const_Linear_Expression_t le,
 ppl_Coefficient_t sup_n,
 ppl_Coefficient_t sup_d,
 int* poptimum,
 ppl_Generator_t point) try {
  const Octagonal_Shape<double>& pph = *to_const(ph);
  const Linear_Expression& lle = *to_const(le);
  Coefficient& ssup_n = *to_nonconst(sup_n);
  Coefficient& ssup_d = *to_nonconst(sup_d);
  Generator& ppoint = *to_nonconst(point);
  bool optimum;
  bool ok = pph.minimize(lle, ssup_n, ssup_d, optimum, ppoint);
  if (ok)
    *poptimum = optimum ? 1 : 0;
  return ok ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_contains_Octagonal_Shape_double
(ppl_const_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  const Octagonal_Shape<double>& xx = *to_const(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  return xx.contains(yy) ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_strictly_contains_Octagonal_Shape_double
(ppl_const_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  const Octagonal_Shape<double>& xx = *to_const(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  return xx.strictly_contains(yy) ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_is_disjoint_from_Octagonal_Shape_double
(ppl_const_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  const Octagonal_Shape<double>& xx = *to_const(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  return xx.is_disjoint_from(yy) ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_equals_Octagonal_Shape_double
(ppl_const_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  const Octagonal_Shape<double>& xx = *to_const(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  return (xx == yy) ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_OK(ppl_const_Octagonal_Shape_double_t ph) try {
  return to_const(ph)->OK() ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_add_constraint
(ppl_Octagonal_Shape_double_t ph,
 ppl_const_Constraint_t c) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Constraint& cc = *to_const(c);
  pph.add_constraint(cc);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_add_congruence
(ppl_Octagonal_Shape_double_t ph,
 ppl_const_Congruence_t c) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Congruence& cc = *to_const(c);
  pph.add_congruence(cc);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_add_constraints
(ppl_Octagonal_Shape_double_t ph,
 ppl_const_Constraint_System_t cs) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Constraint_System& ccs = *to_const(cs);
  pph.add_constraints(ccs);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_add_congruences
(ppl_Octagonal_Shape_double_t ph,
 ppl_const_Congruence_System_t cs) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Congruence_System& ccs = *to_const(cs);
  pph.add_congruences(ccs);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_refine_with_constraint
(ppl_Octagonal_Shape_double_t ph,
 ppl_const_Constraint_t c) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Constraint& cc = *to_const(c);
  pph.refine_with_constraint(cc);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_refine_with_congruence
(ppl_Octagonal_Shape_double_t ph,
 ppl_const_Congruence_t c) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Congruence& cc = *to_const(c);
  pph.refine_with_congruence(cc);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_refine_with_constraints
(ppl_Octagonal_Shape_double_t ph,
 ppl_const_Constraint_System_t cs) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Constraint_System& ccs = *to_const(cs);
  pph.refine_with_constraints(ccs);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_refine_with_congruences
(ppl_Octagonal_Shape_double_t ph,
 ppl_const_Congruence_System_t cs) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Congruence_System& ccs = *to_const(cs);
  pph.refine_with_congruences(ccs);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_intersection_assign
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  Octagonal_Shape<double>& xx = *to_nonconst(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  xx.intersection_assign(yy);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_upper_bound_assign
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  Octagonal_Shape<double>& xx = *to_nonconst(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  xx.upper_bound_assign(yy);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_difference_assign
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  Octagonal_Shape<double>& xx = *to_nonconst(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  xx.difference_assign(yy);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_concatenate_assign
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  Octagonal_Shape<double>& xx = *to_nonconst(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  xx.concatenate_assign(yy);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_time_elapse_assign
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  Octagonal_Shape<double>& xx = *to_nonconst(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  xx.time_elapse_assign(yy);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_upper_bound_assign_if_exact
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  Octagonal_Shape<double>& xx = *to_nonconst(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  return xx.upper_bound_assign_if_exact(yy) ? 1 : 0;

}
CATCH_ALL

  int
ppl_Octagonal_Shape_double_simplify_using_context_assign
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  Octagonal_Shape<double>& xx = *to_nonconst(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  return xx.simplify_using_context_assign(yy) ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_constrains
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type var
) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  return pph.constrains(Variable(var)) ? 1 : 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_unconstrain_space_dimension
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type var
) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  pph.unconstrain(Variable(var));
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_unconstrain_space_dimensions
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type ds[],
 size_t n) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  Variables_Set to_be_unconstrained;
  for (ppl_dimension_type i = n; i-- > 0; )
    to_be_unconstrained.insert(ds[i]);
  pph.unconstrain(to_be_unconstrained);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_affine_image
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type var,
 ppl_const_Linear_Expression_t le,
 ppl_const_Coefficient_t d) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Linear_Expression& lle = *to_const(le);
  const Coefficient& dd = *to_const(d);
  pph.affine_image(Variable(var), lle, dd);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_affine_preimage
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type var,
 ppl_const_Linear_Expression_t le,
 ppl_const_Coefficient_t d) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Linear_Expression& lle = *to_const(le);
  const Coefficient& dd = *to_const(d);
  pph.affine_preimage(Variable(var), lle, dd);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_bounded_affine_image
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type var,
 ppl_const_Linear_Expression_t lb,
 ppl_const_Linear_Expression_t ub,
 ppl_const_Coefficient_t d) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Linear_Expression& llb = *to_const(lb);
  const Linear_Expression& uub = *to_const(ub);
  const Coefficient& dd = *to_const(d);
  pph.bounded_affine_image(Variable(var), llb, uub, dd);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_bounded_affine_preimage
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type var,
 ppl_const_Linear_Expression_t lb,
 ppl_const_Linear_Expression_t ub,
 ppl_const_Coefficient_t d) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Linear_Expression& llb = *to_const(lb);
  const Linear_Expression& uub = *to_const(ub);
  const Coefficient& dd = *to_const(d);
  pph.bounded_affine_preimage(Variable(var), llb, uub, dd);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_generalized_affine_image
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type var,
 enum ppl_enum_Constraint_Type relsym,
 ppl_const_Linear_Expression_t le,
 ppl_const_Coefficient_t d) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Linear_Expression& lle = *to_const(le);
  const Coefficient& dd = *to_const(d);
  pph.generalized_affine_image
    (Variable(var), relation_symbol(relsym), lle, dd);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_generalized_affine_preimage
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type var,
 enum ppl_enum_Constraint_Type relsym,
 ppl_const_Linear_Expression_t le,
 ppl_const_Coefficient_t d) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Linear_Expression& lle = *to_const(le);
  const Coefficient& dd = *to_const(d);
  pph.generalized_affine_preimage
    (Variable(var), relation_symbol(relsym), lle, dd);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_generalized_affine_image_lhs_rhs
(ppl_Octagonal_Shape_double_t ph,
 ppl_const_Linear_Expression_t lhs,
 enum ppl_enum_Constraint_Type relsym,
 ppl_const_Linear_Expression_t rhs) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Linear_Expression& llhs = *to_const(lhs);
  const Linear_Expression& rrhs = *to_const(rhs);
  pph.generalized_affine_image(llhs, relation_symbol(relsym), rrhs);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_generalized_affine_preimage_lhs_rhs
(ppl_Octagonal_Shape_double_t ph,
 ppl_const_Linear_Expression_t lhs,
 enum ppl_enum_Constraint_Type relsym,
 ppl_const_Linear_Expression_t rhs) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  const Linear_Expression& llhs = *to_const(lhs);
  const Linear_Expression& rrhs = *to_const(rhs);
  pph.generalized_affine_preimage(llhs, relation_symbol(relsym), rrhs);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_add_space_dimensions_and_embed
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type d) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  pph.add_space_dimensions_and_embed(d);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_add_space_dimensions_and_project
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type d) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  pph.add_space_dimensions_and_project(d);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_remove_space_dimensions
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type ds[],
 size_t n) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  Variables_Set to_be_removed;
  for (ppl_dimension_type i = n; i-- > 0; )
    to_be_removed.insert(ds[i]);
  pph.remove_space_dimensions(to_be_removed);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_remove_higher_space_dimensions
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type d) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  pph.remove_higher_space_dimensions(d);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_expand_space_dimension
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type d,
 ppl_dimension_type m) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  pph.expand_space_dimension(Variable(d), m);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_fold_space_dimensions
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type ds[],
 size_t n,
 ppl_dimension_type d) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  Variables_Set to_be_folded;
  for (ppl_dimension_type i = n; i-- > 0; )
    to_be_folded.insert(ds[i]);
  pph.fold_space_dimensions(to_be_folded, Variable(d));
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_map_space_dimensions
(ppl_Octagonal_Shape_double_t ph,
 ppl_dimension_type maps[],
 size_t n) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  Array_Partial_Function_Wrapper function(maps, n);
  pph.map_space_dimensions(function);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_external_memory_in_bytes
(ppl_const_Octagonal_Shape_double_t ps,
 size_t* sz) try {
  *sz = to_const(ps)->external_memory_in_bytes();
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_total_memory_in_bytes
(ppl_const_Octagonal_Shape_double_t ps,
 size_t* sz) try {
  *sz = to_const(ps)->total_memory_in_bytes();
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_BHMZ05_widening_assign_with_tokens
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y,
 unsigned* tp) try {
  Octagonal_Shape<double>& xx = *to_nonconst(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  xx.BHMZ05_widening_assign(yy, tp);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_BHMZ05_widening_assign
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  return ppl_Octagonal_Shape_double_BHMZ05_widening_assign_with_tokens(x, y, 0);
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_widening_assign_with_tokens
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y,
 unsigned* tp) try {
  Octagonal_Shape<double>& xx = *to_nonconst(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  xx.widening_assign(yy, tp);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_widening_assign
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  return ppl_Octagonal_Shape_double_widening_assign_with_tokens(x, y, 0);
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_limited_BHMZ05_extrapolation_assign_with_tokens
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y,
 ppl_const_Constraint_System_t cs,
 unsigned* tp) try {
  Octagonal_Shape<double>& xx = *to_nonconst(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  const Constraint_System& ccs = *to_const(cs);
  xx.limited_BHMZ05_extrapolation_assign(yy, ccs, tp);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_limited_CC76_extrapolation_assign_with_tokens
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y,
 ppl_const_Constraint_System_t cs,
 unsigned* tp) try {
  Octagonal_Shape<double>& xx = *to_nonconst(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  const Constraint_System& ccs = *to_const(cs);
  xx.limited_CC76_extrapolation_assign(yy, ccs, tp);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_limited_BHMZ05_extrapolation_assign
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y,
 ppl_const_Constraint_System_t cs) try {
  return
    ppl_Octagonal_Shape_double_limited_BHMZ05_extrapolation_assign_with_tokens
      (x, y, cs, 0);
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_limited_CC76_extrapolation_assign
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y,
 ppl_const_Constraint_System_t cs) try {
  return
    ppl_Octagonal_Shape_double_limited_CC76_extrapolation_assign_with_tokens
      (x, y, cs, 0);
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_CC76_extrapolation_assign_with_tokens
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y,
 unsigned* tp) try {
  Octagonal_Shape<double>& xx = *to_nonconst(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  xx.CC76_extrapolation_assign(yy, tp);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_CC76_extrapolation_assign
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  return
    ppl_Octagonal_Shape_double_CC76_extrapolation_assign_with_tokens
      (x, y, 0);
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_CC76_narrowing_assign
(ppl_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y) try {
  Octagonal_Shape<double>& xx = *to_nonconst(x);
  const Octagonal_Shape<double>& yy = *to_const(y);
  xx.CC76_narrowing_assign(yy);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_linear_partition
(ppl_const_Octagonal_Shape_double_t x,
 ppl_const_Octagonal_Shape_double_t y,
 ppl_Octagonal_Shape_double_t* p_inters,
 ppl_Pointset_Powerset_NNC_Polyhedron_t* p_rest) try {
    const Octagonal_Shape<double>& xx
      = static_cast<const Octagonal_Shape<double>&>(*to_const(x));
    const Octagonal_Shape<double>& yy
      = static_cast<const Octagonal_Shape<double>&>(*to_const(y));
    std::pair<Octagonal_Shape<double>, Pointset_Powerset<NNC_Polyhedron> >
      r = linear_partition(xx, yy);
    *p_inters = to_nonconst(&r.first);
    *p_rest = to_nonconst(&r.second);
  return 0;


}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_recycle_Constraint_System
(ppl_Octagonal_Shape_double_t* pph, ppl_Constraint_System_t cs) try {
  Constraint_System& ccs = *to_nonconst(cs);
  *pph = to_nonconst(new Octagonal_Shape<double>(ccs));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_recycle_Congruence_System
(ppl_Octagonal_Shape_double_t* pph, ppl_Congruence_System_t cs) try {
  Congruence_System& ccs = *to_nonconst(cs);
  *pph = to_nonconst(new Octagonal_Shape<double>(ccs));
  return 0;
}
CATCH_ALL

int
ppl_new_Octagonal_Shape_double_recycle_Generator_System
(ppl_Octagonal_Shape_double_t* pph, ppl_Generator_System_t cs) try {
  Generator_System& ccs = *to_nonconst(cs);
  *pph = to_nonconst(new Octagonal_Shape<double>(ccs));
  return 0;
}
CATCH_ALL

int
ppl_assign_Octagonal_Shape_double_from_Octagonal_Shape_double
(ppl_Octagonal_Shape_double_t dst,
 ppl_const_Octagonal_Shape_double_t src) try {
  const Octagonal_Shape<double>& ssrc
    = *static_cast<const Octagonal_Shape<double>*>(to_const(src));
  Octagonal_Shape<double>& ddst
    = *static_cast<Octagonal_Shape<double>*>(to_nonconst(dst));
  ddst = ssrc;
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_add_recycled_constraints
(ppl_Octagonal_Shape_double_t ph,
 ppl_Constraint_System_t cs) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  Constraint_System& ccs = *to_nonconst(cs);
  pph.add_recycled_constraints(ccs);
  return 0;
}
CATCH_ALL

int
ppl_Octagonal_Shape_double_add_recycled_congruences
(ppl_Octagonal_Shape_double_t ph,
 ppl_Congruence_System_t cs) try {
  Octagonal_Shape<double>& pph = *to_nonconst(ph);
  Congruence_System& ccs = *to_nonconst(cs);
  pph.add_recycled_congruences(ccs);
  return 0;
}
CATCH_ALL

DEFINE_OUTPUT_FUNCTIONS(Octagonal_Shape_double)