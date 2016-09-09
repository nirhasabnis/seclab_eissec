/* C Pointset_Powerset_NNC_Polyhedron interface code: definitions.
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

typedef Pointset_Powerset<NNC_Polyhedron>::iterator
        Pointset_Powerset_NNC_Polyhedron_iterator;
typedef Pointset_Powerset<NNC_Polyhedron>::const_iterator
        Pointset_Powerset_NNC_Polyhedron_const_iterator;

DECLARE_CONVERSIONS(Pointset_Powerset_NNC_Polyhedron_iterator,
                    Pointset_Powerset_NNC_Polyhedron_iterator)
DECLARE_CONVERSIONS(Pointset_Powerset_NNC_Polyhedron_const_iterator,
                    Pointset_Powerset_NNC_Polyhedron_const_iterator)

int
ppl_new_Pointset_Powerset_NNC_Polyhedron_iterator
(ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t* pit) try {
  *pit = to_nonconst(new Pointset_Powerset_NNC_Polyhedron_iterator());
  return 0;
}
CATCH_ALL

int
ppl_new_Pointset_Powerset_NNC_Polyhedron_const_iterator
(ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_t* pit) try {
  *pit = to_nonconst(new Pointset_Powerset_NNC_Polyhedron_const_iterator());
  return 0;
}
CATCH_ALL

int
ppl_delete_Pointset_Powerset_NNC_Polyhedron(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph) try {
  delete to_const(ph);
  return 0;
}
CATCH_ALL

int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_space_dimension
(ppl_Pointset_Powerset_NNC_Polyhedron_t* pph,
 ppl_dimension_type d,
 int empty) try {
  *pph = to_nonconst(new Pointset_Powerset<NNC_Polyhedron>(d, empty ? EMPTY : UNIVERSE));
  return 0;
}
CATCH_ALL

int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_Pointset_Powerset_NNC_Polyhedron
(ppl_Pointset_Powerset_NNC_Polyhedron_t* pph,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph) try {
  const Pointset_Powerset<NNC_Polyhedron>& phh
    = *static_cast<const Pointset_Powerset<NNC_Polyhedron>*>(to_const(ph));
  *pph = to_nonconst(new Pointset_Powerset<NNC_Polyhedron>(phh));
  return 0;
}
CATCH_ALL

int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_NNC_Polyhedron
(ppl_Pointset_Powerset_NNC_Polyhedron_t* pph,
 ppl_const_Polyhedron_t ph) try {
  const NNC_Polyhedron& phh
    = *static_cast<const NNC_Polyhedron*>(to_const(ph));
  *pph = to_nonconst(new Pointset_Powerset<NNC_Polyhedron>(phh));
  return 0;
}
CATCH_ALL

int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_Pointset_Powerset_NNC_Polyhedron_with_complexity
(ppl_Pointset_Powerset_NNC_Polyhedron_t* pph,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
 int complexity) try {
  const Pointset_Powerset<NNC_Polyhedron>& phh
    = *static_cast<const Pointset_Powerset<NNC_Polyhedron>*>(to_const(ph));
  switch (complexity) {
  case 0:
    *pph = to_nonconst(new Pointset_Powerset<NNC_Polyhedron>(phh, POLYNOMIAL_COMPLEXITY));
    break;
  case 1:
    *pph = to_nonconst(new Pointset_Powerset<NNC_Polyhedron>(phh, SIMPLEX_COMPLEXITY));
    break;
  case 2:
    *pph = to_nonconst(new Pointset_Powerset<NNC_Polyhedron>(phh, ANY_COMPLEXITY));
    break;
  }
  return 0;
}
CATCH_ALL

int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_NNC_Polyhedron_with_complexity
(ppl_Pointset_Powerset_NNC_Polyhedron_t* pph,
 ppl_const_Polyhedron_t ph,
 int complexity) try {
  const NNC_Polyhedron& phh
    = *static_cast<const NNC_Polyhedron*>(to_const(ph));
  switch (complexity) {
  case 0:
    *pph = to_nonconst(new Pointset_Powerset<NNC_Polyhedron>(phh, POLYNOMIAL_COMPLEXITY));
    break;
  case 1:
    *pph = to_nonconst(new Pointset_Powerset<NNC_Polyhedron>(phh, SIMPLEX_COMPLEXITY));
    break;
  case 2:
    *pph = to_nonconst(new Pointset_Powerset<NNC_Polyhedron>(phh, ANY_COMPLEXITY));
    break;
  }
  return 0;
}
CATCH_ALL

int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_Constraint_System
(ppl_Pointset_Powerset_NNC_Polyhedron_t* pph, ppl_const_Constraint_System_t cs) try {
  const Constraint_System& ccs = *to_const(cs);
  *pph = to_nonconst(new Pointset_Powerset<NNC_Polyhedron>(ccs));
  return 0;
}
CATCH_ALL

int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_Congruence_System
(ppl_Pointset_Powerset_NNC_Polyhedron_t* pph, ppl_const_Congruence_System_t cs) try {
  const Congruence_System& ccs = *to_const(cs);
  *pph = to_nonconst(new Pointset_Powerset<NNC_Polyhedron>(ccs));
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_space_dimension
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type* m) try {
  *m = to_const(ph)->space_dimension();
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_affine_dimension
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type* m) try {
  *m = to_const(ph)->affine_dimension();
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_relation_with_Constraint
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Constraint_t c) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
  const Constraint& cc = *to_const(c);
  return pph.relation_with(cc).get_flags();
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_relation_with_Generator
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Generator_t c) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
  const Generator& cc = *to_const(c);
  return pph.relation_with(cc).get_flags();
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_relation_with_Congruence
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Congruence_t c) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
  const Congruence& cc = *to_const(c);
  return pph.relation_with(cc).get_flags();
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_is_empty(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
  return pph.is_empty() ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_is_universe(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
  return pph.is_universe() ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_is_bounded(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
  return pph.is_bounded() ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_contains_integer_point(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
  return pph.contains_integer_point() ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_is_topologically_closed(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
  return pph.is_topologically_closed() ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_is_discrete(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
  return pph.is_discrete() ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_pairwise_reduce(ppl_Pointset_Powerset_NNC_Polyhedron_t ph) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  pph.pairwise_reduce();
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_omega_reduce(ppl_Pointset_Powerset_NNC_Polyhedron_t ph) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  pph.omega_reduce();
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_topological_closure_assign(ppl_Pointset_Powerset_NNC_Polyhedron_t ph) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  pph.topological_closure_assign();
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_bounds_from_above
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Linear_Expression_t le) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
  const Linear_Expression& lle = *to_const(le);
  return pph.bounds_from_above(lle) ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_bounds_from_below
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Linear_Expression_t le) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
  const Linear_Expression& lle = *to_const(le);
  return pph.bounds_from_below(lle) ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_maximize
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Linear_Expression_t le,
 ppl_Coefficient_t sup_n,
 ppl_Coefficient_t sup_d,
 int* poptimum) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
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
ppl_Pointset_Powerset_NNC_Polyhedron_minimize
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Linear_Expression_t le,
 ppl_Coefficient_t sup_n,
 ppl_Coefficient_t sup_d,
 int* poptimum) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
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
ppl_Pointset_Powerset_NNC_Polyhedron_maximize_with_point
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Linear_Expression_t le,
 ppl_Coefficient_t sup_n,
 ppl_Coefficient_t sup_d,
 int* poptimum,
 ppl_Generator_t point) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
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
ppl_Pointset_Powerset_NNC_Polyhedron_minimize_with_point
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Linear_Expression_t le,
 ppl_Coefficient_t sup_n,
 ppl_Coefficient_t sup_d,
 int* poptimum,
 ppl_Generator_t point) try {
  const Pointset_Powerset<NNC_Polyhedron>& pph = *to_const(ph);
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
ppl_Pointset_Powerset_NNC_Polyhedron_contains_Pointset_Powerset_NNC_Polyhedron
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  const Pointset_Powerset<NNC_Polyhedron>& xx = *to_const(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  return xx.contains(yy) ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_strictly_contains_Pointset_Powerset_NNC_Polyhedron
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  const Pointset_Powerset<NNC_Polyhedron>& xx = *to_const(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  return xx.strictly_contains(yy) ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_is_disjoint_from_Pointset_Powerset_NNC_Polyhedron
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  const Pointset_Powerset<NNC_Polyhedron>& xx = *to_const(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  return xx.is_disjoint_from(yy) ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_geometrically_covers_Pointset_Powerset_NNC_Polyhedron
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  const Pointset_Powerset<NNC_Polyhedron>& xx = *to_const(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  return xx.geometrically_covers(yy) ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_geometrically_equals_Pointset_Powerset_NNC_Polyhedron
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  const Pointset_Powerset<NNC_Polyhedron>& xx = *to_const(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  return xx.geometrically_equals(yy) ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_equals_Pointset_Powerset_NNC_Polyhedron
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  const Pointset_Powerset<NNC_Polyhedron>& xx = *to_const(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  return (xx == yy) ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_OK(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph) try {
  return to_const(ph)->OK() ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_add_constraint
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Constraint_t c) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Constraint& cc = *to_const(c);
  pph.add_constraint(cc);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_add_congruence
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Congruence_t c) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Congruence& cc = *to_const(c);
  pph.add_congruence(cc);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_add_constraints
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Constraint_System_t cs) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Constraint_System& ccs = *to_const(cs);
  pph.add_constraints(ccs);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_add_congruences
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Congruence_System_t cs) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Congruence_System& ccs = *to_const(cs);
  pph.add_congruences(ccs);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_refine_with_constraint
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Constraint_t c) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Constraint& cc = *to_const(c);
  pph.refine_with_constraint(cc);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_refine_with_congruence
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Congruence_t c) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Congruence& cc = *to_const(c);
  pph.refine_with_congruence(cc);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_refine_with_constraints
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Constraint_System_t cs) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Constraint_System& ccs = *to_const(cs);
  pph.refine_with_constraints(ccs);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_refine_with_congruences
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Congruence_System_t cs) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Congruence_System& ccs = *to_const(cs);
  pph.refine_with_congruences(ccs);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_intersection_assign
(ppl_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  Pointset_Powerset<NNC_Polyhedron>& xx = *to_nonconst(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  xx.intersection_assign(yy);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_upper_bound_assign
(ppl_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  Pointset_Powerset<NNC_Polyhedron>& xx = *to_nonconst(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  xx.upper_bound_assign(yy);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_difference_assign
(ppl_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  Pointset_Powerset<NNC_Polyhedron>& xx = *to_nonconst(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  xx.difference_assign(yy);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_concatenate_assign
(ppl_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  Pointset_Powerset<NNC_Polyhedron>& xx = *to_nonconst(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  xx.concatenate_assign(yy);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_time_elapse_assign
(ppl_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  Pointset_Powerset<NNC_Polyhedron>& xx = *to_nonconst(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  xx.time_elapse_assign(yy);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_upper_bound_assign_if_exact
(ppl_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  Pointset_Powerset<NNC_Polyhedron>& xx = *to_nonconst(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  return xx.upper_bound_assign_if_exact(yy) ? 1 : 0;

}
CATCH_ALL

  int
ppl_Pointset_Powerset_NNC_Polyhedron_simplify_using_context_assign
(ppl_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  Pointset_Powerset<NNC_Polyhedron>& xx = *to_nonconst(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  return xx.simplify_using_context_assign(yy) ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_constrains
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type var
) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  return pph.constrains(Variable(var)) ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_unconstrain_space_dimension
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type var
) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  pph.unconstrain(Variable(var));
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_unconstrain_space_dimensions
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type ds[],
 size_t n) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  Variables_Set to_be_unconstrained;
  for (ppl_dimension_type i = n; i-- > 0; )
    to_be_unconstrained.insert(ds[i]);
  pph.unconstrain(to_be_unconstrained);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_affine_image
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type var,
 ppl_const_Linear_Expression_t le,
 ppl_const_Coefficient_t d) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Linear_Expression& lle = *to_const(le);
  const Coefficient& dd = *to_const(d);
  pph.affine_image(Variable(var), lle, dd);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_affine_preimage
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type var,
 ppl_const_Linear_Expression_t le,
 ppl_const_Coefficient_t d) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Linear_Expression& lle = *to_const(le);
  const Coefficient& dd = *to_const(d);
  pph.affine_preimage(Variable(var), lle, dd);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_bounded_affine_image
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type var,
 ppl_const_Linear_Expression_t lb,
 ppl_const_Linear_Expression_t ub,
 ppl_const_Coefficient_t d) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Linear_Expression& llb = *to_const(lb);
  const Linear_Expression& uub = *to_const(ub);
  const Coefficient& dd = *to_const(d);
  pph.bounded_affine_image(Variable(var), llb, uub, dd);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_bounded_affine_preimage
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type var,
 ppl_const_Linear_Expression_t lb,
 ppl_const_Linear_Expression_t ub,
 ppl_const_Coefficient_t d) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Linear_Expression& llb = *to_const(lb);
  const Linear_Expression& uub = *to_const(ub);
  const Coefficient& dd = *to_const(d);
  pph.bounded_affine_preimage(Variable(var), llb, uub, dd);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_generalized_affine_image
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type var,
 enum ppl_enum_Constraint_Type relsym,
 ppl_const_Linear_Expression_t le,
 ppl_const_Coefficient_t d) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Linear_Expression& lle = *to_const(le);
  const Coefficient& dd = *to_const(d);
  pph.generalized_affine_image
    (Variable(var), relation_symbol(relsym), lle, dd);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_generalized_affine_preimage
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type var,
 enum ppl_enum_Constraint_Type relsym,
 ppl_const_Linear_Expression_t le,
 ppl_const_Coefficient_t d) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Linear_Expression& lle = *to_const(le);
  const Coefficient& dd = *to_const(d);
  pph.generalized_affine_preimage
    (Variable(var), relation_symbol(relsym), lle, dd);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_generalized_affine_image_lhs_rhs
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Linear_Expression_t lhs,
 enum ppl_enum_Constraint_Type relsym,
 ppl_const_Linear_Expression_t rhs) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Linear_Expression& llhs = *to_const(lhs);
  const Linear_Expression& rrhs = *to_const(rhs);
  pph.generalized_affine_image(llhs, relation_symbol(relsym), rrhs);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_generalized_affine_preimage_lhs_rhs
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_const_Linear_Expression_t lhs,
 enum ppl_enum_Constraint_Type relsym,
 ppl_const_Linear_Expression_t rhs) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  const Linear_Expression& llhs = *to_const(lhs);
  const Linear_Expression& rrhs = *to_const(rhs);
  pph.generalized_affine_preimage(llhs, relation_symbol(relsym), rrhs);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_add_space_dimensions_and_embed
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type d) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  pph.add_space_dimensions_and_embed(d);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_add_space_dimensions_and_project
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type d) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  pph.add_space_dimensions_and_project(d);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_remove_space_dimensions
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type ds[],
 size_t n) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  Variables_Set to_be_removed;
  for (ppl_dimension_type i = n; i-- > 0; )
    to_be_removed.insert(ds[i]);
  pph.remove_space_dimensions(to_be_removed);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_remove_higher_space_dimensions
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type d) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  pph.remove_higher_space_dimensions(d);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_expand_space_dimension
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type d,
 ppl_dimension_type m) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  pph.expand_space_dimension(Variable(d), m);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_fold_space_dimensions
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type ds[],
 size_t n,
 ppl_dimension_type d) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  Variables_Set to_be_folded;
  for (ppl_dimension_type i = n; i-- > 0; )
    to_be_folded.insert(ds[i]);
  pph.fold_space_dimensions(to_be_folded, Variable(d));
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_map_space_dimensions
(ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
 ppl_dimension_type maps[],
 size_t n) try {
  Pointset_Powerset<NNC_Polyhedron>& pph = *to_nonconst(ph);
  Array_Partial_Function_Wrapper function(maps, n);
  pph.map_space_dimensions(function);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_external_memory_in_bytes
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ps,
 size_t* sz) try {
  *sz = to_const(ps)->external_memory_in_bytes();
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_total_memory_in_bytes
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ps,
 size_t* sz) try {
  *sz = to_const(ps)->total_memory_in_bytes();
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_size
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ps,
 size_t* sz) try {
  *sz = to_const(ps)->size();
  return 0;
}
CATCH_ALL

int
ppl_new_Pointset_Powerset_NNC_Polyhedron_iterator_from_iterator
(ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t* px, ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t y) try {
  const Pointset_Powerset_NNC_Polyhedron_iterator& yy
    = *static_cast<const Pointset_Powerset_NNC_Polyhedron_iterator*>(to_const(y));
  *px = to_nonconst(new Pointset_Powerset_NNC_Polyhedron_iterator(yy));
  return 0;
}
CATCH_ALL

int
ppl_new_Pointset_Powerset_NNC_Polyhedron_const_iterator_from_const_iterator
(ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_t* px,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_const_iterator_t y) try {
  const Pointset_Powerset_NNC_Polyhedron_const_iterator& yy
    = *static_cast<const Pointset_Powerset_NNC_Polyhedron_const_iterator*>(to_const(y));
  *px = to_nonconst(new Pointset_Powerset_NNC_Polyhedron_const_iterator(yy));
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_iterator_begin
(ppl_Pointset_Powerset_NNC_Polyhedron_t ps,
 ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t psit) try {
  Pointset_Powerset<NNC_Polyhedron>::iterator& ppsit = *to_nonconst(psit);
  ppsit = to_nonconst(ps)->begin();
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_begin
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ps,
 ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_t psit) try {
  Pointset_Powerset<NNC_Polyhedron>::const_iterator& ppsit = *to_nonconst(psit);
  ppsit = to_const(ps)->begin();
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_iterator_end
(ppl_Pointset_Powerset_NNC_Polyhedron_t ps,
 ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t psit) try {
  Pointset_Powerset<NNC_Polyhedron>::iterator& ppsit = *to_nonconst(psit);
  ppsit = to_nonconst(ps)->end();
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_end
(ppl_const_Pointset_Powerset_NNC_Polyhedron_t ps,
 ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_t psit) try {
  Pointset_Powerset<NNC_Polyhedron>::const_iterator& ppsit = *to_nonconst(psit);
  ppsit = to_const(ps)->end();
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_iterator_equal_test
(ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t y) try {
  return (*to_const(x) == *to_const(y)) ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_equal_test
(ppl_const_Pointset_Powerset_NNC_Polyhedron_const_iterator_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_const_iterator_t y) try {
  return (*to_const(x) == *to_const(y)) ? 1 : 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_iterator_increment
(ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t it)
  try {
    Pointset_Powerset<NNC_Polyhedron>::iterator& iit = *to_nonconst(it);
    ++iit;
    return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_increment
(ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_t it)
  try {
    Pointset_Powerset<NNC_Polyhedron>::const_iterator& iit = *to_nonconst(it);
    ++iit;
    return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_iterator_decrement
(ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t it)
  try {
    Pointset_Powerset<NNC_Polyhedron>::iterator& iit = *to_nonconst(it);
    --iit;
    return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_decrement
(ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_t it)
  try {
    Pointset_Powerset<NNC_Polyhedron>::const_iterator& iit = *to_nonconst(it);
    --iit;
    return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_iterator_dereference
(ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t psit,
 ppl_const_Polyhedron_t* cd) try {
   const Pointset_Powerset<NNC_Polyhedron>::iterator& cpsit = *to_const(psit);
   const NNC_Polyhedron& d = cpsit->element();
   *cd = to_const(&d);
   return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_dereference
(ppl_const_Pointset_Powerset_NNC_Polyhedron_const_iterator_t psit,
 ppl_const_Polyhedron_t* cd) try {
   const Pointset_Powerset<NNC_Polyhedron>::const_iterator& cpsit = *to_const(psit);
   const NNC_Polyhedron& d = cpsit->element();
   *cd = to_const(&d);
   return 0;
}
CATCH_ALL

int
ppl_delete_Pointset_Powerset_NNC_Polyhedron_iterator
(ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t it)
  try {
  delete to_const(it);
  return 0;
}
CATCH_ALL

int
ppl_delete_Pointset_Powerset_NNC_Polyhedron_const_iterator
(ppl_const_Pointset_Powerset_NNC_Polyhedron_const_iterator_t it)
  try {
  delete to_const(it);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_add_disjunct
(ppl_Pointset_Powerset_NNC_Polyhedron_t ps,
 ppl_const_Polyhedron_t d) try {
  Pointset_Powerset<NNC_Polyhedron>& pps = *to_nonconst(ps);
  const NNC_Polyhedron& dd
     = *static_cast<const NNC_Polyhedron*>(to_const(d));
  pps.add_disjunct(dd);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_drop_disjunct
(ppl_Pointset_Powerset_NNC_Polyhedron_t ps,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t cit,
 ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t it) try {
  Pointset_Powerset<NNC_Polyhedron>& pps = *to_nonconst(ps);
  const Pointset_Powerset<NNC_Polyhedron>::iterator& ccit = *to_const(cit);
  Pointset_Powerset<NNC_Polyhedron>::iterator& iit = *to_nonconst(it);
  iit = pps.drop_disjunct(ccit);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_drop_disjuncts
(ppl_Pointset_Powerset_NNC_Polyhedron_t ps,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t first,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t last) try {
  Pointset_Powerset<NNC_Polyhedron>& pps = *to_nonconst(ps);
  const Pointset_Powerset<NNC_Polyhedron>::iterator& ffirst = *to_const(first);
  const Pointset_Powerset<NNC_Polyhedron>::iterator& llast = *to_const(last);
  pps.drop_disjuncts(ffirst, llast);
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_BHZ03_BHRZ03_BHRZ03_widening_assign
(ppl_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  Pointset_Powerset<NNC_Polyhedron>& xx = *to_nonconst(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  xx.BHZ03_widening_assign<BHRZ03_Certificate>(yy,
       widen_fun_ref(
         &NNC_Polyhedron::BHRZ03_widening_assign));
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_BHZ03_H79_H79_widening_assign
(ppl_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y) try {
  Pointset_Powerset<NNC_Polyhedron>& xx = *to_nonconst(x);
  const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
  xx.BHZ03_widening_assign<H79_Certificate>(yy,
       widen_fun_ref(
         &NNC_Polyhedron::H79_widening_assign));
  return 0;
}
CATCH_ALL

int
ppl_Pointset_Powerset_NNC_Polyhedron_BGP99_BHRZ03_extrapolation_assign
(ppl_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y,
 int disjuncts) try {
   Pointset_Powerset<NNC_Polyhedron>& xx = *to_nonconst(x);
   const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
   xx.BGP99_extrapolation_assign(yy,
       widen_fun_ref(&NNC_Polyhedron::
           BHRZ03_widening_assign),
       disjuncts);
   return 0;
}
CATCH_ALL


int
ppl_Pointset_Powerset_NNC_Polyhedron_BGP99_H79_extrapolation_assign
(ppl_Pointset_Powerset_NNC_Polyhedron_t x,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_t y,
 int disjuncts) try {
   Pointset_Powerset<NNC_Polyhedron>& xx = *to_nonconst(x);
   const Pointset_Powerset<NNC_Polyhedron>& yy = *to_const(y);
   xx.BGP99_extrapolation_assign(yy,
       widen_fun_ref(&NNC_Polyhedron::
           H79_widening_assign),
       disjuncts);
   return 0;
}
CATCH_ALL


DEFINE_OUTPUT_FUNCTIONS(Pointset_Powerset_NNC_Polyhedron)
