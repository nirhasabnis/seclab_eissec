/*C interface code: header file.
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

PPL_TYPE_DECLARATION(Polyhedron)
PPL_TYPE_DECLARATION(Grid)
PPL_TYPE_DECLARATION(Rational_Box)
PPL_TYPE_DECLARATION(BD_Shape_mpz_class)
PPL_TYPE_DECLARATION(BD_Shape_mpq_class)
PPL_TYPE_DECLARATION(Octagonal_Shape_mpz_class)
PPL_TYPE_DECLARATION(Octagonal_Shape_mpq_class)
PPL_TYPE_DECLARATION(Constraints_Product_C_Polyhedron_Grid)
PPL_TYPE_DECLARATION(Pointset_Powerset_C_Polyhedron)
PPL_TYPE_DECLARATION(Pointset_Powerset_NNC_Polyhedron)
PPL_TYPE_DECLARATION(Double_Box)
PPL_TYPE_DECLARATION(BD_Shape_double)
PPL_TYPE_DECLARATION(Octagonal_Shape_double)

/*! \interface ppl_Polyhedron_tag
  \brief Types and functions for ppl_Polyhedron_tag
*/

/*! \relates ppl_Polyhedron_tag */
int
ppl_delete_Polyhedron PPL_PROTO((ppl_const_Polyhedron_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_space_dimension
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_space_dimension
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_C_Polyhedron
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_NNC_Polyhedron
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Grid
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Grid_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Rational_Box
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Rational_Box_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_BD_Shape_mpz_class
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_BD_Shape_mpq_class
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Double_Box
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Double_Box_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_BD_Shape_double
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Octagonal_Shape_double
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_C_Polyhedron
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_NNC_Polyhedron
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Grid
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Grid_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Rational_Box
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Rational_Box_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_BD_Shape_mpz_class
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_BD_Shape_mpq_class
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Double_Box
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Double_Box_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_BD_Shape_double
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Octagonal_Shape_double
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_C_Polyhedron_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Grid_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Grid_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Rational_Box_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Rational_Box_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_BD_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_BD_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_BD_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_BD_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Octagonal_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Octagonal_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Double_Box_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Double_Box_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_BD_Shape_double_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_BD_Shape_double_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Octagonal_Shape_double_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Octagonal_Shape_double_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_C_Polyhedron_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Grid_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Grid_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Rational_Box_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Rational_Box_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_BD_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_BD_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_BD_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_BD_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Octagonal_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Octagonal_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Double_Box_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Double_Box_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_BD_Shape_double_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_BD_Shape_double_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Octagonal_Shape_double_with_complexity
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Octagonal_Shape_double_t ph, int complexity));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Constraint_System
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Constraint_System
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Congruence_System
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Congruence_System
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_from_Generator_System
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Generator_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_from_Generator_System
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_const_Generator_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_space_dimension
PPL_PROTO((ppl_const_Polyhedron_t ph, ppl_dimension_type* m));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_affine_dimension
PPL_PROTO((ppl_const_Polyhedron_t ph, ppl_dimension_type* m));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_relation_with_Constraint
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_relation_with_Generator
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_relation_with_Congruence
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_get_constraints
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_get_congruences
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_get_generators
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Generator_System_t* pcs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_get_minimized_constraints
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_get_minimized_congruences
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_get_minimized_generators
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Generator_System_t* pcs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_is_empty PPL_PROTO((ppl_const_Polyhedron_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_is_universe PPL_PROTO((ppl_const_Polyhedron_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_is_bounded PPL_PROTO((ppl_const_Polyhedron_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_contains_integer_point PPL_PROTO((ppl_const_Polyhedron_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_is_topologically_closed PPL_PROTO((ppl_const_Polyhedron_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_is_discrete PPL_PROTO((ppl_const_Polyhedron_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_topological_closure_assign PPL_PROTO((ppl_Polyhedron_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_bounds_from_above
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_bounds_from_below
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_maximize
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_minimize
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_maximize_with_point
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_minimize_with_point
PPL_PROTO((ppl_const_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_contains_Polyhedron
PPL_PROTO((ppl_const_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_strictly_contains_Polyhedron
PPL_PROTO((ppl_const_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_is_disjoint_from_Polyhedron
PPL_PROTO((ppl_const_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_equals_Polyhedron
PPL_PROTO((ppl_const_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_OK PPL_PROTO((ppl_const_Polyhedron_t ph));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_constraint
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_congruence
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_generator
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_constraints
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_congruences
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_generators
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Generator_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_refine_with_constraint
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_refine_with_congruence
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_refine_with_constraints
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_refine_with_congruences
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_intersection_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_upper_bound_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_difference_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_concatenate_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_time_elapse_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_poly_hull_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_poly_difference_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_upper_bound_assign_if_exact
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_poly_hull_assign_if_exact
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_simplify_using_context_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_constrains
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_unconstrain_space_dimension
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_unconstrain_space_dimensions
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_affine_image
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_affine_preimage
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_bounded_affine_image
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_bounded_affine_preimage
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_generalized_affine_image
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_generalized_affine_preimage
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_generalized_affine_image_lhs_rhs
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_generalized_affine_preimage_lhs_rhs
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_space_dimensions_and_embed
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_space_dimensions_and_project
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_remove_space_dimensions
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_remove_higher_space_dimensions
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_expand_space_dimension
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type d,
           ppl_dimension_type m));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_fold_space_dimensions
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type ds[],
           size_t n,
           ppl_dimension_type d));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_map_space_dimensions
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_dimension_type maps[],
           size_t n));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_external_memory_in_bytes
PPL_PROTO((ppl_const_Polyhedron_t ps,
           size_t* sz));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_total_memory_in_bytes
PPL_PROTO((ppl_const_Polyhedron_t ps,
           size_t* sz));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_BHRZ03_widening_assign_with_tokens
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y,
           unsigned* tp));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_H79_widening_assign_with_tokens
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y,
           unsigned* tp));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_BHRZ03_widening_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_H79_widening_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_widening_assign_with_tokens
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y,
           unsigned* tp));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_widening_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_limited_BHRZ03_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_limited_H79_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_bounded_BHRZ03_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_bounded_H79_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_limited_BHRZ03_extrapolation_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_limited_H79_extrapolation_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_bounded_BHRZ03_extrapolation_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_bounded_H79_extrapolation_assign
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_linear_partition
PPL_PROTO((ppl_const_Polyhedron_t x,
           ppl_const_Polyhedron_t y,
           ppl_Polyhedron_t* p_inters,
           ppl_Pointset_Powerset_NNC_Polyhedron_t* p_rest));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_recycle_Constraint_System
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_Constraint_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_recycle_Constraint_System
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_Constraint_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_recycle_Congruence_System
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_Congruence_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_recycle_Congruence_System
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_Congruence_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_C_Polyhedron_recycle_Generator_System
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_Generator_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_new_NNC_Polyhedron_recycle_Generator_System
PPL_PROTO((ppl_Polyhedron_t* pph, ppl_Generator_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_assign_C_Polyhedron_from_C_Polyhedron
PPL_PROTO((ppl_Polyhedron_t dst, ppl_const_Polyhedron_t src));

/*! \relates ppl_Polyhedron_tag */
int
ppl_assign_NNC_Polyhedron_from_NNC_Polyhedron
PPL_PROTO((ppl_Polyhedron_t dst, ppl_const_Polyhedron_t src));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_recycled_constraints
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_Constraint_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_recycled_congruences
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_Congruence_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_recycled_generators
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_Generator_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_constraint_and_minimize
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_congruence_and_minimize
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_generator_and_minimize
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_constraints_and_minimize
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_congruences_and_minimize
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_add_generators_and_minimize
PPL_PROTO((ppl_Polyhedron_t ph,
           ppl_const_Generator_System_t cs));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_intersection_assign_and_minimize
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

/*! \relates ppl_Polyhedron_tag */
int
ppl_Polyhedron_poly_hull_assign_and_minimize
PPL_PROTO((ppl_Polyhedron_t x,
           ppl_const_Polyhedron_t y));

PPL_DECLARE_IO_FUNCTIONS(Polyhedron)

/* End of Functions Related to ppl_Polyhedron_tag */

/*! \interface ppl_Grid_tag
  \brief Types and functions for ppl_Grid_tag
*/

/*! \relates ppl_Grid_tag */
int
ppl_delete_Grid PPL_PROTO((ppl_const_Grid_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_space_dimension
PPL_PROTO((ppl_Grid_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_C_Polyhedron
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_NNC_Polyhedron
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Grid
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Grid_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Rational_Box
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Rational_Box_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_BD_Shape_mpz_class
PPL_PROTO((ppl_Grid_t* pph, ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_BD_Shape_mpq_class
PPL_PROTO((ppl_Grid_t* pph, ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Double_Box
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Double_Box_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_BD_Shape_double
PPL_PROTO((ppl_Grid_t* pph, ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Octagonal_Shape_double
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_C_Polyhedron_with_complexity
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Grid_with_complexity
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Grid_t ph, int complexity));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Rational_Box_with_complexity
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Rational_Box_t ph, int complexity));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_BD_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Grid_t* pph, ppl_const_BD_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_BD_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Grid_t* pph, ppl_const_BD_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Octagonal_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Octagonal_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Double_Box_with_complexity
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Double_Box_t ph, int complexity));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_BD_Shape_double_with_complexity
PPL_PROTO((ppl_Grid_t* pph, ppl_const_BD_Shape_double_t ph, int complexity));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Octagonal_Shape_double_with_complexity
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Octagonal_Shape_double_t ph, int complexity));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Constraint_System
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Grid_Generator_System
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Grid_Generator_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_from_Congruence_System
PPL_PROTO((ppl_Grid_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_space_dimension
PPL_PROTO((ppl_const_Grid_t ph, ppl_dimension_type* m));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_affine_dimension
PPL_PROTO((ppl_const_Grid_t ph, ppl_dimension_type* m));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_relation_with_Constraint
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_relation_with_Generator
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_relation_with_Congruence
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_relation_with_Grid_Generator
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Grid_Generator_t c));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_get_constraints
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_get_congruences
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_get_grid_generators
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Grid_Generator_System_t* pcs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_get_minimized_constraints
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_get_minimized_congruences
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_get_minimized_grid_generators
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Grid_Generator_System_t* pcs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_is_empty PPL_PROTO((ppl_const_Grid_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_is_universe PPL_PROTO((ppl_const_Grid_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_is_bounded PPL_PROTO((ppl_const_Grid_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_contains_integer_point PPL_PROTO((ppl_const_Grid_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_is_topologically_closed PPL_PROTO((ppl_const_Grid_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_is_discrete PPL_PROTO((ppl_const_Grid_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_topological_closure_assign PPL_PROTO((ppl_Grid_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_bounds_from_above
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_bounds_from_below
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_maximize
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_minimize
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_maximize_with_point
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_minimize_with_point
PPL_PROTO((ppl_const_Grid_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_contains_Grid
PPL_PROTO((ppl_const_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_strictly_contains_Grid
PPL_PROTO((ppl_const_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_is_disjoint_from_Grid
PPL_PROTO((ppl_const_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_equals_Grid
PPL_PROTO((ppl_const_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_OK PPL_PROTO((ppl_const_Grid_t ph));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_add_constraint
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_add_congruence
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_add_grid_generator
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Grid_Generator_t c));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_add_constraints
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_add_congruences
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_add_grid_generators
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Grid_Generator_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_refine_with_constraint
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_refine_with_congruence
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_refine_with_constraints
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_refine_with_congruences
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_intersection_assign
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_upper_bound_assign
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_difference_assign
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_concatenate_assign
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_time_elapse_assign
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_upper_bound_assign_if_exact
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_simplify_using_context_assign
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_constrains
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_unconstrain_space_dimension
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_unconstrain_space_dimensions
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_affine_image
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_affine_preimage
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_bounded_affine_image
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_bounded_affine_preimage
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_generalized_affine_image
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_generalized_affine_preimage
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_generalized_affine_image_lhs_rhs
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_generalized_affine_preimage_lhs_rhs
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_generalized_affine_image_with_congruence
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d,
           ppl_const_Coefficient_t m));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_generalized_affine_preimage_with_congruence
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d,
           ppl_const_Coefficient_t m));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_generalized_affine_image_lhs_rhs_with_congruence
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs,
           ppl_const_Coefficient_t m));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_generalized_affine_preimage_lhs_rhs_with_congruence
PPL_PROTO((ppl_Grid_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs,
           ppl_const_Coefficient_t m));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_add_space_dimensions_and_embed
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_add_space_dimensions_and_project
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_remove_space_dimensions
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_remove_higher_space_dimensions
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_expand_space_dimension
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type d,
           ppl_dimension_type m));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_fold_space_dimensions
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type ds[],
           size_t n,
           ppl_dimension_type d));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_map_space_dimensions
PPL_PROTO((ppl_Grid_t ph,
           ppl_dimension_type maps[],
           size_t n));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_external_memory_in_bytes
PPL_PROTO((ppl_const_Grid_t ps,
           size_t* sz));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_total_memory_in_bytes
PPL_PROTO((ppl_const_Grid_t ps,
           size_t* sz));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_congruence_widening_assign_with_tokens
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y,
           unsigned* tp));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_generator_widening_assign_with_tokens
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y,
           unsigned* tp));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_congruence_widening_assign
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_generator_widening_assign
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_widening_assign_with_tokens
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y,
           unsigned* tp));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_widening_assign
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_limited_congruence_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y,
           ppl_const_Congruence_System_t cs,
           unsigned* tp));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_limited_generator_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y,
           ppl_const_Congruence_System_t cs,
           unsigned* tp));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_limited_congruence_extrapolation_assign
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_limited_generator_extrapolation_assign
PPL_PROTO((ppl_Grid_t x,
           ppl_const_Grid_t y,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_recycle_Constraint_System
PPL_PROTO((ppl_Grid_t* pph, ppl_Constraint_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_recycle_Grid_Generator_System
PPL_PROTO((ppl_Grid_t* pph, ppl_Grid_Generator_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_new_Grid_recycle_Congruence_System
PPL_PROTO((ppl_Grid_t* pph, ppl_Congruence_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_assign_Grid_from_Grid
PPL_PROTO((ppl_Grid_t dst, ppl_const_Grid_t src));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_add_recycled_constraints
PPL_PROTO((ppl_Grid_t ph,
           ppl_Constraint_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_add_recycled_congruences
PPL_PROTO((ppl_Grid_t ph,
           ppl_Congruence_System_t cs));

/*! \relates ppl_Grid_tag */
int
ppl_Grid_add_recycled_grid_generators
PPL_PROTO((ppl_Grid_t ph,
           ppl_Grid_Generator_System_t cs));

PPL_DECLARE_IO_FUNCTIONS(Grid)

/* End of Functions Related to ppl_Grid_tag */

/*! \interface ppl_Rational_Box_tag
  \brief Types and functions for ppl_Rational_Box_tag
*/

/*! \relates ppl_Rational_Box_tag */
int
ppl_delete_Rational_Box PPL_PROTO((ppl_const_Rational_Box_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_space_dimension
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_C_Polyhedron
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_NNC_Polyhedron
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Grid
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Grid_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Rational_Box
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Rational_Box_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_BD_Shape_mpz_class
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_BD_Shape_mpq_class
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Double_Box
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Double_Box_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_BD_Shape_double
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Octagonal_Shape_double
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_C_Polyhedron_with_complexity
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Grid_with_complexity
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Grid_t ph, int complexity));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Rational_Box_with_complexity
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Rational_Box_t ph, int complexity));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_BD_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_BD_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_BD_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_BD_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Octagonal_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Octagonal_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Double_Box_with_complexity
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Double_Box_t ph, int complexity));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_BD_Shape_double_with_complexity
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_BD_Shape_double_t ph, int complexity));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Octagonal_Shape_double_with_complexity
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Octagonal_Shape_double_t ph, int complexity));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Constraint_System
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Congruence_System
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_from_Generator_System
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_const_Generator_System_t cs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_space_dimension
PPL_PROTO((ppl_const_Rational_Box_t ph, ppl_dimension_type* m));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_affine_dimension
PPL_PROTO((ppl_const_Rational_Box_t ph, ppl_dimension_type* m));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_relation_with_Constraint
PPL_PROTO((ppl_const_Rational_Box_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_relation_with_Generator
PPL_PROTO((ppl_const_Rational_Box_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_relation_with_Congruence
PPL_PROTO((ppl_const_Rational_Box_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_get_constraints
PPL_PROTO((ppl_const_Rational_Box_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_get_congruences
PPL_PROTO((ppl_const_Rational_Box_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_get_minimized_constraints
PPL_PROTO((ppl_const_Rational_Box_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_get_minimized_congruences
PPL_PROTO((ppl_const_Rational_Box_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_is_empty PPL_PROTO((ppl_const_Rational_Box_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_is_universe PPL_PROTO((ppl_const_Rational_Box_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_is_bounded PPL_PROTO((ppl_const_Rational_Box_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_contains_integer_point PPL_PROTO((ppl_const_Rational_Box_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_is_topologically_closed PPL_PROTO((ppl_const_Rational_Box_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_is_discrete PPL_PROTO((ppl_const_Rational_Box_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_topological_closure_assign PPL_PROTO((ppl_Rational_Box_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_bounds_from_above
PPL_PROTO((ppl_const_Rational_Box_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_bounds_from_below
PPL_PROTO((ppl_const_Rational_Box_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_maximize
PPL_PROTO((ppl_const_Rational_Box_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_minimize
PPL_PROTO((ppl_const_Rational_Box_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_maximize_with_point
PPL_PROTO((ppl_const_Rational_Box_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_minimize_with_point
PPL_PROTO((ppl_const_Rational_Box_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_contains_Rational_Box
PPL_PROTO((ppl_const_Rational_Box_t x,
           ppl_const_Rational_Box_t y));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_strictly_contains_Rational_Box
PPL_PROTO((ppl_const_Rational_Box_t x,
           ppl_const_Rational_Box_t y));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_is_disjoint_from_Rational_Box
PPL_PROTO((ppl_const_Rational_Box_t x,
           ppl_const_Rational_Box_t y));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_equals_Rational_Box
PPL_PROTO((ppl_const_Rational_Box_t x,
           ppl_const_Rational_Box_t y));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_OK PPL_PROTO((ppl_const_Rational_Box_t ph));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_add_constraint
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_add_congruence
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_add_constraints
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_add_congruences
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_refine_with_constraint
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_refine_with_congruence
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_refine_with_constraints
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_refine_with_congruences
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_intersection_assign
PPL_PROTO((ppl_Rational_Box_t x,
           ppl_const_Rational_Box_t y));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_upper_bound_assign
PPL_PROTO((ppl_Rational_Box_t x,
           ppl_const_Rational_Box_t y));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_difference_assign
PPL_PROTO((ppl_Rational_Box_t x,
           ppl_const_Rational_Box_t y));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_concatenate_assign
PPL_PROTO((ppl_Rational_Box_t x,
           ppl_const_Rational_Box_t y));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_time_elapse_assign
PPL_PROTO((ppl_Rational_Box_t x,
           ppl_const_Rational_Box_t y));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_upper_bound_assign_if_exact
PPL_PROTO((ppl_Rational_Box_t x,
           ppl_const_Rational_Box_t y));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_simplify_using_context_assign
PPL_PROTO((ppl_Rational_Box_t x,
           ppl_const_Rational_Box_t y));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_constrains
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_unconstrain_space_dimension
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_unconstrain_space_dimensions
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_affine_image
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_affine_preimage
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_bounded_affine_image
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_bounded_affine_preimage
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_generalized_affine_image
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_generalized_affine_preimage
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_generalized_affine_image_lhs_rhs
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_generalized_affine_preimage_lhs_rhs
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_add_space_dimensions_and_embed
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_add_space_dimensions_and_project
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_remove_space_dimensions
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_remove_higher_space_dimensions
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_expand_space_dimension
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type d,
           ppl_dimension_type m));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_fold_space_dimensions
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type ds[],
           size_t n,
           ppl_dimension_type d));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_map_space_dimensions
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_dimension_type maps[],
           size_t n));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_external_memory_in_bytes
PPL_PROTO((ppl_const_Rational_Box_t ps,
           size_t* sz));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_total_memory_in_bytes
PPL_PROTO((ppl_const_Rational_Box_t ps,
           size_t* sz));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_CC76_widening_assign_with_tokens
PPL_PROTO((ppl_Rational_Box_t x,
           ppl_const_Rational_Box_t y,
           unsigned* tp));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_CC76_widening_assign
PPL_PROTO((ppl_Rational_Box_t x,
           ppl_const_Rational_Box_t y));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_widening_assign_with_tokens
PPL_PROTO((ppl_Rational_Box_t x,
           ppl_const_Rational_Box_t y,
           unsigned* tp));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_widening_assign
PPL_PROTO((ppl_Rational_Box_t x,
           ppl_const_Rational_Box_t y));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_limited_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Rational_Box_t x,
           ppl_const_Rational_Box_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_limited_CC76_extrapolation_assign
PPL_PROTO((ppl_Rational_Box_t x,
           ppl_const_Rational_Box_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_linear_partition
PPL_PROTO((ppl_const_Rational_Box_t x,
           ppl_const_Rational_Box_t y,
           ppl_Rational_Box_t* p_inters,
           ppl_Pointset_Powerset_NNC_Polyhedron_t* p_rest));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_recycle_Constraint_System
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_Constraint_System_t cs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_recycle_Congruence_System
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_Congruence_System_t cs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_new_Rational_Box_recycle_Generator_System
PPL_PROTO((ppl_Rational_Box_t* pph, ppl_Generator_System_t cs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_assign_Rational_Box_from_Rational_Box
PPL_PROTO((ppl_Rational_Box_t dst, ppl_const_Rational_Box_t src));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_add_recycled_constraints
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_Constraint_System_t cs));

/*! \relates ppl_Rational_Box_tag */
int
ppl_Rational_Box_add_recycled_congruences
PPL_PROTO((ppl_Rational_Box_t ph,
           ppl_Congruence_System_t cs));

PPL_DECLARE_IO_FUNCTIONS(Rational_Box)

/* End of Functions Related to ppl_Rational_Box_tag */

/*! \interface ppl_BD_Shape_mpz_class_tag
  \brief Types and functions for ppl_BD_Shape_mpz_class_tag
*/

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_delete_BD_Shape_mpz_class PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_space_dimension
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_C_Polyhedron
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_NNC_Polyhedron
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Grid
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Grid_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Rational_Box
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Rational_Box_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_BD_Shape_mpz_class
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_BD_Shape_mpq_class
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Double_Box
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Double_Box_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_BD_Shape_double
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Octagonal_Shape_double
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_C_Polyhedron_with_complexity
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Grid_with_complexity
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Grid_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Rational_Box_with_complexity
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Rational_Box_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_BD_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_BD_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_BD_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_BD_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Octagonal_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Octagonal_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Double_Box_with_complexity
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Double_Box_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_BD_Shape_double_with_complexity
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_BD_Shape_double_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Octagonal_Shape_double_with_complexity
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Octagonal_Shape_double_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Constraint_System
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Congruence_System
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_from_Generator_System
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_const_Generator_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_space_dimension
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph, ppl_dimension_type* m));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_affine_dimension
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph, ppl_dimension_type* m));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_relation_with_Constraint
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_relation_with_Generator
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_relation_with_Congruence
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_get_constraints
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_get_congruences
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_get_minimized_constraints
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_get_minimized_congruences
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_is_empty PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_is_universe PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_is_bounded PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_contains_integer_point PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_is_topologically_closed PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_is_discrete PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_topological_closure_assign PPL_PROTO((ppl_BD_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_bounds_from_above
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_bounds_from_below
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_maximize
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_minimize
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_maximize_with_point
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_minimize_with_point
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_contains_BD_Shape_mpz_class
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_strictly_contains_BD_Shape_mpz_class
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_is_disjoint_from_BD_Shape_mpz_class
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_equals_BD_Shape_mpz_class
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_OK PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_add_constraint
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_add_congruence
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_add_constraints
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_add_congruences
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_refine_with_constraint
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_refine_with_congruence
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_refine_with_constraints
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_refine_with_congruences
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_intersection_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_upper_bound_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_difference_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_concatenate_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_time_elapse_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_upper_bound_assign_if_exact
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_simplify_using_context_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_constrains
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type var));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_unconstrain_space_dimension
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type var));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_unconstrain_space_dimensions
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_affine_image
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_affine_preimage
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_bounded_affine_image
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_bounded_affine_preimage
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_generalized_affine_image
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_generalized_affine_preimage
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_generalized_affine_image_lhs_rhs
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_generalized_affine_preimage_lhs_rhs
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_add_space_dimensions_and_embed
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type d));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_add_space_dimensions_and_project
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type d));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_remove_space_dimensions
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_remove_higher_space_dimensions
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type d));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_expand_space_dimension
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type d,
           ppl_dimension_type m));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_fold_space_dimensions
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type ds[],
           size_t n,
           ppl_dimension_type d));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_map_space_dimensions
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_dimension_type maps[],
           size_t n));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_external_memory_in_bytes
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ps,
           size_t* sz));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_total_memory_in_bytes
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t ps,
           size_t* sz));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_BHMZ05_widening_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_H79_widening_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_BHMZ05_widening_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_H79_widening_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_widening_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_widening_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_limited_BHMZ05_extrapolation_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_limited_H79_extrapolation_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_limited_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_limited_BHMZ05_extrapolation_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_limited_H79_extrapolation_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_limited_CC76_extrapolation_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_CC76_extrapolation_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_CC76_narrowing_assign
PPL_PROTO((ppl_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_linear_partition
PPL_PROTO((ppl_const_BD_Shape_mpz_class_t x,
           ppl_const_BD_Shape_mpz_class_t y,
           ppl_BD_Shape_mpz_class_t* p_inters,
           ppl_Pointset_Powerset_NNC_Polyhedron_t* p_rest));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_recycle_Constraint_System
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_recycle_Congruence_System
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_Congruence_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_new_BD_Shape_mpz_class_recycle_Generator_System
PPL_PROTO((ppl_BD_Shape_mpz_class_t* pph, ppl_Generator_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_assign_BD_Shape_mpz_class_from_BD_Shape_mpz_class
PPL_PROTO((ppl_BD_Shape_mpz_class_t dst, ppl_const_BD_Shape_mpz_class_t src));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_add_recycled_constraints
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpz_class_tag */
int
ppl_BD_Shape_mpz_class_add_recycled_congruences
PPL_PROTO((ppl_BD_Shape_mpz_class_t ph,
           ppl_Congruence_System_t cs));

PPL_DECLARE_IO_FUNCTIONS(BD_Shape_mpz_class)

/* End of Functions Related to ppl_BD_Shape_mpz_class_tag */

/*! \interface ppl_BD_Shape_mpq_class_tag
  \brief Types and functions for ppl_BD_Shape_mpq_class_tag
*/

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_delete_BD_Shape_mpq_class PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_space_dimension
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_C_Polyhedron
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_NNC_Polyhedron
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Grid
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Grid_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Rational_Box
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Rational_Box_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_BD_Shape_mpz_class
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_BD_Shape_mpq_class
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Double_Box
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Double_Box_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_BD_Shape_double
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Octagonal_Shape_double
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_C_Polyhedron_with_complexity
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Grid_with_complexity
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Grid_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Rational_Box_with_complexity
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Rational_Box_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_BD_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_BD_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_BD_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_BD_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Octagonal_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Octagonal_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Double_Box_with_complexity
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Double_Box_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_BD_Shape_double_with_complexity
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_BD_Shape_double_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Octagonal_Shape_double_with_complexity
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Octagonal_Shape_double_t ph, int complexity));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Constraint_System
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Congruence_System
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_from_Generator_System
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_const_Generator_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_space_dimension
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph, ppl_dimension_type* m));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_affine_dimension
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph, ppl_dimension_type* m));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_relation_with_Constraint
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_relation_with_Generator
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_relation_with_Congruence
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_get_constraints
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_get_congruences
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_get_minimized_constraints
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_get_minimized_congruences
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_is_empty PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_is_universe PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_is_bounded PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_contains_integer_point PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_is_topologically_closed PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_is_discrete PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_topological_closure_assign PPL_PROTO((ppl_BD_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_bounds_from_above
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_bounds_from_below
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_maximize
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_minimize
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_maximize_with_point
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_minimize_with_point
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_contains_BD_Shape_mpq_class
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_strictly_contains_BD_Shape_mpq_class
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_is_disjoint_from_BD_Shape_mpq_class
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_equals_BD_Shape_mpq_class
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_OK PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_add_constraint
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_add_congruence
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_add_constraints
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_add_congruences
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_refine_with_constraint
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_refine_with_congruence
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_refine_with_constraints
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_refine_with_congruences
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_intersection_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_upper_bound_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_difference_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_concatenate_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_time_elapse_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_upper_bound_assign_if_exact
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_simplify_using_context_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_constrains
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type var));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_unconstrain_space_dimension
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type var));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_unconstrain_space_dimensions
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_affine_image
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_affine_preimage
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_bounded_affine_image
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_bounded_affine_preimage
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_generalized_affine_image
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_generalized_affine_preimage
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_generalized_affine_image_lhs_rhs
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_generalized_affine_preimage_lhs_rhs
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_add_space_dimensions_and_embed
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type d));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_add_space_dimensions_and_project
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type d));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_remove_space_dimensions
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_remove_higher_space_dimensions
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type d));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_expand_space_dimension
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type d,
           ppl_dimension_type m));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_fold_space_dimensions
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type ds[],
           size_t n,
           ppl_dimension_type d));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_map_space_dimensions
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_dimension_type maps[],
           size_t n));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_external_memory_in_bytes
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ps,
           size_t* sz));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_total_memory_in_bytes
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t ps,
           size_t* sz));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_BHMZ05_widening_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_H79_widening_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_BHMZ05_widening_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_H79_widening_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_widening_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_widening_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_limited_BHMZ05_extrapolation_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_limited_H79_extrapolation_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_limited_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_limited_BHMZ05_extrapolation_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_limited_H79_extrapolation_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_limited_CC76_extrapolation_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y,
           unsigned* tp));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_CC76_extrapolation_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_CC76_narrowing_assign
PPL_PROTO((ppl_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_linear_partition
PPL_PROTO((ppl_const_BD_Shape_mpq_class_t x,
           ppl_const_BD_Shape_mpq_class_t y,
           ppl_BD_Shape_mpq_class_t* p_inters,
           ppl_Pointset_Powerset_NNC_Polyhedron_t* p_rest));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_recycle_Constraint_System
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_recycle_Congruence_System
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_Congruence_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_new_BD_Shape_mpq_class_recycle_Generator_System
PPL_PROTO((ppl_BD_Shape_mpq_class_t* pph, ppl_Generator_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_assign_BD_Shape_mpq_class_from_BD_Shape_mpq_class
PPL_PROTO((ppl_BD_Shape_mpq_class_t dst, ppl_const_BD_Shape_mpq_class_t src));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_add_recycled_constraints
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_mpq_class_tag */
int
ppl_BD_Shape_mpq_class_add_recycled_congruences
PPL_PROTO((ppl_BD_Shape_mpq_class_t ph,
           ppl_Congruence_System_t cs));

PPL_DECLARE_IO_FUNCTIONS(BD_Shape_mpq_class)

/* End of Functions Related to ppl_BD_Shape_mpq_class_tag */

/*! \interface ppl_Octagonal_Shape_mpz_class_tag
  \brief Types and functions for ppl_Octagonal_Shape_mpz_class_tag
*/

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_delete_Octagonal_Shape_mpz_class PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_space_dimension
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_C_Polyhedron
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_NNC_Polyhedron
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Grid
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Grid_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Rational_Box
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Rational_Box_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_BD_Shape_mpz_class
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_BD_Shape_mpq_class
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Double_Box
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Double_Box_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_BD_Shape_double
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Octagonal_Shape_double
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_C_Polyhedron_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Grid_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Grid_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Rational_Box_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Rational_Box_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_BD_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_BD_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_BD_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_BD_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Octagonal_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Octagonal_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Double_Box_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Double_Box_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_BD_Shape_double_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_BD_Shape_double_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Octagonal_Shape_double_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Octagonal_Shape_double_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Constraint_System
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Congruence_System
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_from_Generator_System
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_const_Generator_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_space_dimension
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph, ppl_dimension_type* m));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_affine_dimension
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph, ppl_dimension_type* m));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_relation_with_Constraint
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_relation_with_Generator
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_relation_with_Congruence
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_get_constraints
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_get_congruences
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_get_minimized_constraints
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_get_minimized_congruences
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_is_empty PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_is_universe PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_is_bounded PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_contains_integer_point PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_is_topologically_closed PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_is_discrete PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_topological_closure_assign PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_bounds_from_above
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_bounds_from_below
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_maximize
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_minimize
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_maximize_with_point
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_minimize_with_point
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_contains_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_strictly_contains_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_is_disjoint_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_equals_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_OK PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_add_constraint
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_add_congruence
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_add_constraints
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_add_congruences
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_refine_with_constraint
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_refine_with_congruence
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_refine_with_constraints
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_refine_with_congruences
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_intersection_assign
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_upper_bound_assign
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_difference_assign
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_concatenate_assign
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_time_elapse_assign
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_upper_bound_assign_if_exact
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_simplify_using_context_assign
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_constrains
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_unconstrain_space_dimension
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_unconstrain_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_affine_image
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_affine_preimage
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_bounded_affine_image
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_bounded_affine_preimage
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_generalized_affine_image
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_generalized_affine_preimage
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_generalized_affine_image_lhs_rhs
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_generalized_affine_preimage_lhs_rhs
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_add_space_dimensions_and_embed
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_add_space_dimensions_and_project
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_remove_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_remove_higher_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_expand_space_dimension
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type d,
           ppl_dimension_type m));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_fold_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type ds[],
           size_t n,
           ppl_dimension_type d));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_map_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_dimension_type maps[],
           size_t n));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_external_memory_in_bytes
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ps,
           size_t* sz));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_total_memory_in_bytes
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t ps,
           size_t* sz));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_BHMZ05_widening_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_BHMZ05_widening_assign
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_widening_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_widening_assign
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_limited_BHMZ05_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_limited_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_limited_BHMZ05_extrapolation_assign
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_limited_CC76_extrapolation_assign
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_CC76_extrapolation_assign
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_CC76_narrowing_assign
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_linear_partition
PPL_PROTO((ppl_const_Octagonal_Shape_mpz_class_t x,
           ppl_const_Octagonal_Shape_mpz_class_t y,
           ppl_Octagonal_Shape_mpz_class_t* p_inters,
           ppl_Pointset_Powerset_NNC_Polyhedron_t* p_rest));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_recycle_Constraint_System
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_recycle_Congruence_System
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_Congruence_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_new_Octagonal_Shape_mpz_class_recycle_Generator_System
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t* pph, ppl_Generator_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_assign_Octagonal_Shape_mpz_class_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t dst, ppl_const_Octagonal_Shape_mpz_class_t src));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_add_recycled_constraints
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpz_class_tag */
int
ppl_Octagonal_Shape_mpz_class_add_recycled_congruences
PPL_PROTO((ppl_Octagonal_Shape_mpz_class_t ph,
           ppl_Congruence_System_t cs));

PPL_DECLARE_IO_FUNCTIONS(Octagonal_Shape_mpz_class)

/* End of Functions Related to ppl_Octagonal_Shape_mpz_class_tag */

/*! \interface ppl_Octagonal_Shape_mpq_class_tag
  \brief Types and functions for ppl_Octagonal_Shape_mpq_class_tag
*/

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_delete_Octagonal_Shape_mpq_class PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_space_dimension
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_C_Polyhedron
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_NNC_Polyhedron
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Grid
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Grid_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Rational_Box
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Rational_Box_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_BD_Shape_mpz_class
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_BD_Shape_mpq_class
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Double_Box
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Double_Box_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_BD_Shape_double
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Octagonal_Shape_double
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_C_Polyhedron_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Grid_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Grid_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Rational_Box_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Rational_Box_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_BD_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_BD_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_BD_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_BD_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Octagonal_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Octagonal_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Double_Box_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Double_Box_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_BD_Shape_double_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_BD_Shape_double_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Octagonal_Shape_double_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Octagonal_Shape_double_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Constraint_System
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Congruence_System
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_from_Generator_System
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_const_Generator_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_space_dimension
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph, ppl_dimension_type* m));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_affine_dimension
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph, ppl_dimension_type* m));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_relation_with_Constraint
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_relation_with_Generator
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_relation_with_Congruence
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_get_constraints
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_get_congruences
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_get_minimized_constraints
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_get_minimized_congruences
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_is_empty PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_is_universe PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_is_bounded PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_contains_integer_point PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_is_topologically_closed PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_is_discrete PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_topological_closure_assign PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_bounds_from_above
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_bounds_from_below
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_maximize
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_minimize
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_maximize_with_point
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_minimize_with_point
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_contains_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_strictly_contains_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_is_disjoint_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_equals_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_OK PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_add_constraint
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_add_congruence
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_add_constraints
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_add_congruences
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_refine_with_constraint
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_refine_with_congruence
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_refine_with_constraints
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_refine_with_congruences
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_intersection_assign
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_upper_bound_assign
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_difference_assign
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_concatenate_assign
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_time_elapse_assign
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_upper_bound_assign_if_exact
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_simplify_using_context_assign
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_constrains
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_unconstrain_space_dimension
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_unconstrain_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_affine_image
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_affine_preimage
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_bounded_affine_image
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_bounded_affine_preimage
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_generalized_affine_image
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_generalized_affine_preimage
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_generalized_affine_image_lhs_rhs
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_generalized_affine_preimage_lhs_rhs
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_add_space_dimensions_and_embed
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_add_space_dimensions_and_project
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_remove_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_remove_higher_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_expand_space_dimension
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type d,
           ppl_dimension_type m));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_fold_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type ds[],
           size_t n,
           ppl_dimension_type d));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_map_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_dimension_type maps[],
           size_t n));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_external_memory_in_bytes
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ps,
           size_t* sz));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_total_memory_in_bytes
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t ps,
           size_t* sz));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_BHMZ05_widening_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_BHMZ05_widening_assign
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_widening_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_widening_assign
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_limited_BHMZ05_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_limited_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_limited_BHMZ05_extrapolation_assign
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_limited_CC76_extrapolation_assign
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_CC76_extrapolation_assign
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_CC76_narrowing_assign
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_linear_partition
PPL_PROTO((ppl_const_Octagonal_Shape_mpq_class_t x,
           ppl_const_Octagonal_Shape_mpq_class_t y,
           ppl_Octagonal_Shape_mpq_class_t* p_inters,
           ppl_Pointset_Powerset_NNC_Polyhedron_t* p_rest));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_recycle_Constraint_System
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_recycle_Congruence_System
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_Congruence_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_new_Octagonal_Shape_mpq_class_recycle_Generator_System
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t* pph, ppl_Generator_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_assign_Octagonal_Shape_mpq_class_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t dst, ppl_const_Octagonal_Shape_mpq_class_t src));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_add_recycled_constraints
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_mpq_class_tag */
int
ppl_Octagonal_Shape_mpq_class_add_recycled_congruences
PPL_PROTO((ppl_Octagonal_Shape_mpq_class_t ph,
           ppl_Congruence_System_t cs));

PPL_DECLARE_IO_FUNCTIONS(Octagonal_Shape_mpq_class)

/* End of Functions Related to ppl_Octagonal_Shape_mpq_class_tag */

/*! \interface ppl_Constraints_Product_C_Polyhedron_Grid_tag
  \brief Types and functions for ppl_Constraints_Product_C_Polyhedron_Grid_tag
*/

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_delete_Constraints_Product_C_Polyhedron_Grid PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_space_dimension
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_C_Polyhedron
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_NNC_Polyhedron
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Grid
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Grid_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Rational_Box
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Rational_Box_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_BD_Shape_mpz_class
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_BD_Shape_mpq_class
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Double_Box
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Double_Box_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_BD_Shape_double
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Octagonal_Shape_double
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Constraints_Product_C_Polyhedron_Grid
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_C_Polyhedron_with_complexity
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Grid_with_complexity
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Grid_t ph, int complexity));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Rational_Box_with_complexity
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Rational_Box_t ph, int complexity));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_BD_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_BD_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_BD_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_BD_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Octagonal_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Octagonal_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Double_Box_with_complexity
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Double_Box_t ph, int complexity));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_BD_Shape_double_with_complexity
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_BD_Shape_double_t ph, int complexity));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Octagonal_Shape_double_with_complexity
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Octagonal_Shape_double_t ph, int complexity));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Constraints_Product_C_Polyhedron_Grid_with_complexity
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph, int complexity));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Constraint_System
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_new_Constraints_Product_C_Polyhedron_Grid_from_Congruence_System
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_space_dimension
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph, ppl_dimension_type* m));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_affine_dimension
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph, ppl_dimension_type* m));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_relation_with_Constraint
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_relation_with_Generator
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_relation_with_Congruence
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_is_empty PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_is_universe PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_is_bounded PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_is_topologically_closed PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_is_discrete PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_topological_closure_assign PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_bounds_from_above
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_bounds_from_below
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_maximize
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_minimize
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_maximize_with_point
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_minimize_with_point
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_contains_Constraints_Product_C_Polyhedron_Grid
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t x,
           ppl_const_Constraints_Product_C_Polyhedron_Grid_t y));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_strictly_contains_Constraints_Product_C_Polyhedron_Grid
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t x,
           ppl_const_Constraints_Product_C_Polyhedron_Grid_t y));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_is_disjoint_from_Constraints_Product_C_Polyhedron_Grid
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t x,
           ppl_const_Constraints_Product_C_Polyhedron_Grid_t y));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_equals_Constraints_Product_C_Polyhedron_Grid
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t x,
           ppl_const_Constraints_Product_C_Polyhedron_Grid_t y));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_OK PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ph));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_add_constraint
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_add_congruence
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_add_constraints
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_add_congruences
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_refine_with_constraint
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_refine_with_congruence
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_refine_with_constraints
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_refine_with_congruences
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_intersection_assign
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t x,
           ppl_const_Constraints_Product_C_Polyhedron_Grid_t y));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_upper_bound_assign
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t x,
           ppl_const_Constraints_Product_C_Polyhedron_Grid_t y));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_difference_assign
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t x,
           ppl_const_Constraints_Product_C_Polyhedron_Grid_t y));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_concatenate_assign
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t x,
           ppl_const_Constraints_Product_C_Polyhedron_Grid_t y));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_time_elapse_assign
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t x,
           ppl_const_Constraints_Product_C_Polyhedron_Grid_t y));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_upper_bound_assign_if_exact
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t x,
           ppl_const_Constraints_Product_C_Polyhedron_Grid_t y));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_constrains
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_unconstrain_space_dimension
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_unconstrain_space_dimensions
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_affine_image
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_affine_preimage
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_bounded_affine_image
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_bounded_affine_preimage
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_generalized_affine_image
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_generalized_affine_preimage
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_generalized_affine_image_lhs_rhs
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_generalized_affine_preimage_lhs_rhs
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_add_space_dimensions_and_embed
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_add_space_dimensions_and_project
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_remove_space_dimensions
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_remove_higher_space_dimensions
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_expand_space_dimension
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type d,
           ppl_dimension_type m));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_fold_space_dimensions
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type ds[],
           size_t n,
           ppl_dimension_type d));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_map_space_dimensions
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t ph,
           ppl_dimension_type maps[],
           size_t n));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_external_memory_in_bytes
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ps,
           size_t* sz));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_total_memory_in_bytes
PPL_PROTO((ppl_const_Constraints_Product_C_Polyhedron_Grid_t ps,
           size_t* sz));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_widening_assign_with_tokens
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t x,
           ppl_const_Constraints_Product_C_Polyhedron_Grid_t y,
           unsigned* tp));

/*! \relates ppl_Constraints_Product_C_Polyhedron_Grid_tag */
int
ppl_Constraints_Product_C_Polyhedron_Grid_widening_assign
PPL_PROTO((ppl_Constraints_Product_C_Polyhedron_Grid_t x,
           ppl_const_Constraints_Product_C_Polyhedron_Grid_t y));

PPL_DECLARE_IO_FUNCTIONS(Constraints_Product_C_Polyhedron_Grid)

/* End of Functions Related to ppl_Constraints_Product_C_Polyhedron_Grid_tag */

/*! \interface ppl_Pointset_Powerset_C_Polyhedron_tag
  \brief Types and functions for ppl_Pointset_Powerset_C_Polyhedron_tag
*/

/*! \interface ppl_Pointset_Powerset_C_Polyhedron_iterator_tag
  \brief Types and functions for iterating on the disjuncts of a
  ppl_Pointset_Powerset_C_Polyhedron_tag.
*/
/*! \interface ppl_Pointset_Powerset_C_Polyhedron_const_iterator_tag
  \brief Types and functions for iterating on the disjuncts of a
  const ppl_Pointset_Powerset_C_Polyhedron_tag.
*/

PPL_TYPE_DECLARATION(Pointset_Powerset_C_Polyhedron_iterator)
PPL_TYPE_DECLARATION(Pointset_Powerset_C_Polyhedron_const_iterator)

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_iterator_tag */
int
ppl_new_Pointset_Powerset_C_Polyhedron_iterator
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_iterator_t* pit));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_const_iterator_tag */
int
ppl_new_Pointset_Powerset_C_Polyhedron_const_iterator
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_const_iterator_t* pit));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_delete_Pointset_Powerset_C_Polyhedron PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_C_Polyhedron_from_space_dimension
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_C_Polyhedron_from_Pointset_Powerset_C_Polyhedron
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t* pph, ppl_const_Pointset_Powerset_C_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_C_Polyhedron_from_C_Polyhedron
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_C_Polyhedron_from_Pointset_Powerset_C_Polyhedron_with_complexity
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t* pph, ppl_const_Pointset_Powerset_C_Polyhedron_t ph, int complexity));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_C_Polyhedron_from_C_Polyhedron_with_complexity
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_C_Polyhedron_from_Constraint_System
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_C_Polyhedron_from_Congruence_System
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_space_dimension
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph, ppl_dimension_type* m));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_affine_dimension
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph, ppl_dimension_type* m));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_relation_with_Constraint
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_relation_with_Generator
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_relation_with_Congruence
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_is_empty PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_is_universe PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_is_bounded PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_contains_integer_point PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_is_topologically_closed PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_is_discrete PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_pairwise_reduce PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_omega_reduce PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_topological_closure_assign PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_bounds_from_above
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_bounds_from_below
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_maximize
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_minimize
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_maximize_with_point
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_minimize_with_point
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_contains_Pointset_Powerset_C_Polyhedron
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_strictly_contains_Pointset_Powerset_C_Polyhedron
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_is_disjoint_from_Pointset_Powerset_C_Polyhedron
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_geometrically_covers_Pointset_Powerset_C_Polyhedron
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_geometrically_equals_Pointset_Powerset_C_Polyhedron
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_equals_Pointset_Powerset_C_Polyhedron
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_OK PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_add_constraint
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_add_congruence
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_add_constraints
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_add_congruences
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_refine_with_constraint
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_refine_with_congruence
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_refine_with_constraints
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_refine_with_congruences
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_intersection_assign
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_upper_bound_assign
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_difference_assign
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_concatenate_assign
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_time_elapse_assign
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_upper_bound_assign_if_exact
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_simplify_using_context_assign
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_constrains
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_unconstrain_space_dimension
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_unconstrain_space_dimensions
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_affine_image
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_affine_preimage
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_bounded_affine_image
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_bounded_affine_preimage
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_generalized_affine_image
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_generalized_affine_preimage
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_generalized_affine_image_lhs_rhs
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_generalized_affine_preimage_lhs_rhs
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_add_space_dimensions_and_embed
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_add_space_dimensions_and_project
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_remove_space_dimensions
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_remove_higher_space_dimensions
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_expand_space_dimension
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type d,
           ppl_dimension_type m));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_fold_space_dimensions
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type ds[],
           size_t n,
           ppl_dimension_type d));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_map_space_dimensions
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ph,
           ppl_dimension_type maps[],
           size_t n));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_external_memory_in_bytes
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ps,
           size_t* sz));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_total_memory_in_bytes
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ps,
           size_t* sz));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_size
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ps,
           size_t* sz));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_iterator_tag */
int
ppl_new_Pointset_Powerset_C_Polyhedron_iterator_from_iterator
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_iterator_t* px,
           ppl_const_Pointset_Powerset_C_Polyhedron_iterator_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_const_iterator_tag */
int
ppl_new_Pointset_Powerset_C_Polyhedron_const_iterator_from_const_iterator
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_const_iterator_t* px,
           ppl_const_Pointset_Powerset_C_Polyhedron_const_iterator_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_iterator_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_iterator_begin
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ps,
           ppl_Pointset_Powerset_C_Polyhedron_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_const_iterator_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_const_iterator_begin
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ps,
           ppl_Pointset_Powerset_C_Polyhedron_const_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_iterator_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_iterator_end
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ps,
           ppl_Pointset_Powerset_C_Polyhedron_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_const_iterator_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_const_iterator_end
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_t ps,
           ppl_Pointset_Powerset_C_Polyhedron_const_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_iterator_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_iterator_equal_test
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_iterator_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_iterator_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_const_iterator_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_const_iterator_equal_test
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_const_iterator_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_const_iterator_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_iterator_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_iterator_increment
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_const_iterator_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_const_iterator_increment
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_const_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_iterator_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_iterator_decrement
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_const_iterator_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_const_iterator_decrement
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_const_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_iterator_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_iterator_dereference
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_iterator_t ps,
           ppl_const_Polyhedron_t* d));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_const_iterator_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_const_iterator_dereference
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_const_iterator_t ps,
           ppl_const_Polyhedron_t* d));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_iterator_tag */
int
ppl_delete_Pointset_Powerset_C_Polyhedron_iterator
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_const_iterator_tag */
int
ppl_delete_Pointset_Powerset_C_Polyhedron_const_iterator
PPL_PROTO((ppl_const_Pointset_Powerset_C_Polyhedron_const_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_add_disjunct
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ps,
           ppl_const_Polyhedron_t d));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_drop_disjunct
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ps,
 ppl_const_Pointset_Powerset_C_Polyhedron_iterator_t cit,
 ppl_Pointset_Powerset_C_Polyhedron_iterator_t it));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_drop_disjuncts
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t ps,
 ppl_const_Pointset_Powerset_C_Polyhedron_iterator_t first,
 ppl_const_Pointset_Powerset_C_Polyhedron_iterator_t last));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_BHZ03_BHRZ03_BHRZ03_widening_assign
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_BHZ03_H79_H79_widening_assign
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_BGP99_BHRZ03_extrapolation_assign
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y,
           int disjuncts));

/*! \relates ppl_Pointset_Powerset_C_Polyhedron_tag */
int
ppl_Pointset_Powerset_C_Polyhedron_BGP99_H79_extrapolation_assign
PPL_PROTO((ppl_Pointset_Powerset_C_Polyhedron_t x,
           ppl_const_Pointset_Powerset_C_Polyhedron_t y,
           int disjuncts));

PPL_DECLARE_IO_FUNCTIONS(Pointset_Powerset_C_Polyhedron)

/* End of Functions Related to ppl_Pointset_Powerset_C_Polyhedron_tag */

/*! \interface ppl_Pointset_Powerset_NNC_Polyhedron_tag
  \brief Types and functions for ppl_Pointset_Powerset_NNC_Polyhedron_tag
*/

/*! \interface ppl_Pointset_Powerset_NNC_Polyhedron_iterator_tag
  \brief Types and functions for iterating on the disjuncts of a
  ppl_Pointset_Powerset_NNC_Polyhedron_tag.
*/
/*! \interface ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_tag
  \brief Types and functions for iterating on the disjuncts of a
  const ppl_Pointset_Powerset_NNC_Polyhedron_tag.
*/

PPL_TYPE_DECLARATION(Pointset_Powerset_NNC_Polyhedron_iterator)
PPL_TYPE_DECLARATION(Pointset_Powerset_NNC_Polyhedron_const_iterator)

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_iterator_tag */
int
ppl_new_Pointset_Powerset_NNC_Polyhedron_iterator
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t* pit));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_tag */
int
ppl_new_Pointset_Powerset_NNC_Polyhedron_const_iterator
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_t* pit));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_delete_Pointset_Powerset_NNC_Polyhedron PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_space_dimension
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_Pointset_Powerset_NNC_Polyhedron
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t* pph, ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_NNC_Polyhedron
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_Pointset_Powerset_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t* pph, ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph, int complexity));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_Constraint_System
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_new_Pointset_Powerset_NNC_Polyhedron_from_Congruence_System
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_space_dimension
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph, ppl_dimension_type* m));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_affine_dimension
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph, ppl_dimension_type* m));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_relation_with_Constraint
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_relation_with_Generator
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_relation_with_Congruence
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_is_empty PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_is_universe PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_is_bounded PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_contains_integer_point PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_is_topologically_closed PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_is_discrete PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_pairwise_reduce PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_omega_reduce PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_topological_closure_assign PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_bounds_from_above
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_bounds_from_below
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_maximize
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_minimize
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_maximize_with_point
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_minimize_with_point
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_contains_Pointset_Powerset_NNC_Polyhedron
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_strictly_contains_Pointset_Powerset_NNC_Polyhedron
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_is_disjoint_from_Pointset_Powerset_NNC_Polyhedron
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_geometrically_covers_Pointset_Powerset_NNC_Polyhedron
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_geometrically_equals_Pointset_Powerset_NNC_Polyhedron
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_equals_Pointset_Powerset_NNC_Polyhedron
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_OK PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ph));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_add_constraint
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_add_congruence
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_add_constraints
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_add_congruences
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_refine_with_constraint
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_refine_with_congruence
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_refine_with_constraints
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_refine_with_congruences
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_intersection_assign
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_upper_bound_assign
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_difference_assign
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_concatenate_assign
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_time_elapse_assign
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_upper_bound_assign_if_exact
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_simplify_using_context_assign
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_constrains
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_unconstrain_space_dimension
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_unconstrain_space_dimensions
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_affine_image
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_affine_preimage
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_bounded_affine_image
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_bounded_affine_preimage
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_generalized_affine_image
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_generalized_affine_preimage
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_generalized_affine_image_lhs_rhs
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_generalized_affine_preimage_lhs_rhs
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_add_space_dimensions_and_embed
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_add_space_dimensions_and_project
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_remove_space_dimensions
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_remove_higher_space_dimensions
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_expand_space_dimension
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type d,
           ppl_dimension_type m));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_fold_space_dimensions
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type ds[],
           size_t n,
           ppl_dimension_type d));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_map_space_dimensions
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ph,
           ppl_dimension_type maps[],
           size_t n));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_external_memory_in_bytes
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ps,
           size_t* sz));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_total_memory_in_bytes
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ps,
           size_t* sz));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_size
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ps,
           size_t* sz));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_iterator_tag */
int
ppl_new_Pointset_Powerset_NNC_Polyhedron_iterator_from_iterator
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t* px,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_tag */
int
ppl_new_Pointset_Powerset_NNC_Polyhedron_const_iterator_from_const_iterator
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_t* px,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_const_iterator_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_iterator_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_iterator_begin
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ps,
           ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_begin
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ps,
           ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_iterator_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_iterator_end
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ps,
           ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_end
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_t ps,
           ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_iterator_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_iterator_equal_test
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_equal_test
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_const_iterator_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_const_iterator_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_iterator_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_iterator_increment
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_increment
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_iterator_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_iterator_decrement
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_decrement
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_iterator_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_iterator_dereference
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t ps,
           ppl_const_Polyhedron_t* d));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_dereference
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_const_iterator_t ps,
           ppl_const_Polyhedron_t* d));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_iterator_tag */
int
ppl_delete_Pointset_Powerset_NNC_Polyhedron_iterator
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_const_iterator_tag */
int
ppl_delete_Pointset_Powerset_NNC_Polyhedron_const_iterator
PPL_PROTO((ppl_const_Pointset_Powerset_NNC_Polyhedron_const_iterator_t psit));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_add_disjunct
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ps,
           ppl_const_Polyhedron_t d));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_drop_disjunct
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ps,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t cit,
 ppl_Pointset_Powerset_NNC_Polyhedron_iterator_t it));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_drop_disjuncts
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t ps,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t first,
 ppl_const_Pointset_Powerset_NNC_Polyhedron_iterator_t last));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_BHZ03_BHRZ03_BHRZ03_widening_assign
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_BHZ03_H79_H79_widening_assign
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_BGP99_BHRZ03_extrapolation_assign
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y,
           int disjuncts));

/*! \relates ppl_Pointset_Powerset_NNC_Polyhedron_tag */
int
ppl_Pointset_Powerset_NNC_Polyhedron_BGP99_H79_extrapolation_assign
PPL_PROTO((ppl_Pointset_Powerset_NNC_Polyhedron_t x,
           ppl_const_Pointset_Powerset_NNC_Polyhedron_t y,
           int disjuncts));

PPL_DECLARE_IO_FUNCTIONS(Pointset_Powerset_NNC_Polyhedron)

/* End of Functions Related to ppl_Pointset_Powerset_NNC_Polyhedron_tag */

/*! \interface ppl_Double_Box_tag
  \brief Types and functions for ppl_Double_Box_tag
*/

/*! \relates ppl_Double_Box_tag */
int
ppl_delete_Double_Box PPL_PROTO((ppl_const_Double_Box_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_space_dimension
PPL_PROTO((ppl_Double_Box_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_C_Polyhedron
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_NNC_Polyhedron
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Grid
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Grid_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Rational_Box
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Rational_Box_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_BD_Shape_mpz_class
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_BD_Shape_mpq_class
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Double_Box
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Double_Box_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_BD_Shape_double
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Octagonal_Shape_double
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_C_Polyhedron_with_complexity
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Grid_with_complexity
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Grid_t ph, int complexity));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Rational_Box_with_complexity
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Rational_Box_t ph, int complexity));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_BD_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_BD_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_BD_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_BD_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Octagonal_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Octagonal_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Double_Box_with_complexity
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Double_Box_t ph, int complexity));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_BD_Shape_double_with_complexity
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_BD_Shape_double_t ph, int complexity));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Octagonal_Shape_double_with_complexity
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Octagonal_Shape_double_t ph, int complexity));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Constraint_System
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Congruence_System
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_from_Generator_System
PPL_PROTO((ppl_Double_Box_t* pph, ppl_const_Generator_System_t cs));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_space_dimension
PPL_PROTO((ppl_const_Double_Box_t ph, ppl_dimension_type* m));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_affine_dimension
PPL_PROTO((ppl_const_Double_Box_t ph, ppl_dimension_type* m));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_relation_with_Constraint
PPL_PROTO((ppl_const_Double_Box_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_relation_with_Generator
PPL_PROTO((ppl_const_Double_Box_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_relation_with_Congruence
PPL_PROTO((ppl_const_Double_Box_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_get_constraints
PPL_PROTO((ppl_const_Double_Box_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_get_congruences
PPL_PROTO((ppl_const_Double_Box_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_get_minimized_constraints
PPL_PROTO((ppl_const_Double_Box_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_get_minimized_congruences
PPL_PROTO((ppl_const_Double_Box_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_is_empty PPL_PROTO((ppl_const_Double_Box_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_is_universe PPL_PROTO((ppl_const_Double_Box_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_is_bounded PPL_PROTO((ppl_const_Double_Box_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_contains_integer_point PPL_PROTO((ppl_const_Double_Box_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_is_topologically_closed PPL_PROTO((ppl_const_Double_Box_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_is_discrete PPL_PROTO((ppl_const_Double_Box_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_topological_closure_assign PPL_PROTO((ppl_Double_Box_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_bounds_from_above
PPL_PROTO((ppl_const_Double_Box_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_bounds_from_below
PPL_PROTO((ppl_const_Double_Box_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_maximize
PPL_PROTO((ppl_const_Double_Box_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_minimize
PPL_PROTO((ppl_const_Double_Box_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_maximize_with_point
PPL_PROTO((ppl_const_Double_Box_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_minimize_with_point
PPL_PROTO((ppl_const_Double_Box_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_contains_Double_Box
PPL_PROTO((ppl_const_Double_Box_t x,
           ppl_const_Double_Box_t y));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_strictly_contains_Double_Box
PPL_PROTO((ppl_const_Double_Box_t x,
           ppl_const_Double_Box_t y));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_is_disjoint_from_Double_Box
PPL_PROTO((ppl_const_Double_Box_t x,
           ppl_const_Double_Box_t y));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_equals_Double_Box
PPL_PROTO((ppl_const_Double_Box_t x,
           ppl_const_Double_Box_t y));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_OK PPL_PROTO((ppl_const_Double_Box_t ph));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_add_constraint
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_add_congruence
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_add_constraints
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_add_congruences
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_refine_with_constraint
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_refine_with_congruence
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_refine_with_constraints
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_refine_with_congruences
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_intersection_assign
PPL_PROTO((ppl_Double_Box_t x,
           ppl_const_Double_Box_t y));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_upper_bound_assign
PPL_PROTO((ppl_Double_Box_t x,
           ppl_const_Double_Box_t y));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_difference_assign
PPL_PROTO((ppl_Double_Box_t x,
           ppl_const_Double_Box_t y));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_concatenate_assign
PPL_PROTO((ppl_Double_Box_t x,
           ppl_const_Double_Box_t y));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_time_elapse_assign
PPL_PROTO((ppl_Double_Box_t x,
           ppl_const_Double_Box_t y));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_upper_bound_assign_if_exact
PPL_PROTO((ppl_Double_Box_t x,
           ppl_const_Double_Box_t y));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_simplify_using_context_assign
PPL_PROTO((ppl_Double_Box_t x,
           ppl_const_Double_Box_t y));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_constrains
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_unconstrain_space_dimension
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_unconstrain_space_dimensions
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_affine_image
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_affine_preimage
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_bounded_affine_image
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_bounded_affine_preimage
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_generalized_affine_image
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_generalized_affine_preimage
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_generalized_affine_image_lhs_rhs
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_generalized_affine_preimage_lhs_rhs
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_add_space_dimensions_and_embed
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_add_space_dimensions_and_project
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_remove_space_dimensions
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_remove_higher_space_dimensions
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_expand_space_dimension
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type d,
           ppl_dimension_type m));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_fold_space_dimensions
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type ds[],
           size_t n,
           ppl_dimension_type d));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_map_space_dimensions
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_dimension_type maps[],
           size_t n));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_external_memory_in_bytes
PPL_PROTO((ppl_const_Double_Box_t ps,
           size_t* sz));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_total_memory_in_bytes
PPL_PROTO((ppl_const_Double_Box_t ps,
           size_t* sz));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_CC76_widening_assign_with_tokens
PPL_PROTO((ppl_Double_Box_t x,
           ppl_const_Double_Box_t y,
           unsigned* tp));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_CC76_widening_assign
PPL_PROTO((ppl_Double_Box_t x,
           ppl_const_Double_Box_t y));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_widening_assign_with_tokens
PPL_PROTO((ppl_Double_Box_t x,
           ppl_const_Double_Box_t y,
           unsigned* tp));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_widening_assign
PPL_PROTO((ppl_Double_Box_t x,
           ppl_const_Double_Box_t y));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_limited_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Double_Box_t x,
           ppl_const_Double_Box_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_limited_CC76_extrapolation_assign
PPL_PROTO((ppl_Double_Box_t x,
           ppl_const_Double_Box_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_linear_partition
PPL_PROTO((ppl_const_Double_Box_t x,
           ppl_const_Double_Box_t y,
           ppl_Double_Box_t* p_inters,
           ppl_Pointset_Powerset_NNC_Polyhedron_t* p_rest));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_recycle_Constraint_System
PPL_PROTO((ppl_Double_Box_t* pph, ppl_Constraint_System_t cs));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_recycle_Congruence_System
PPL_PROTO((ppl_Double_Box_t* pph, ppl_Congruence_System_t cs));

/*! \relates ppl_Double_Box_tag */
int
ppl_new_Double_Box_recycle_Generator_System
PPL_PROTO((ppl_Double_Box_t* pph, ppl_Generator_System_t cs));

/*! \relates ppl_Double_Box_tag */
int
ppl_assign_Double_Box_from_Double_Box
PPL_PROTO((ppl_Double_Box_t dst, ppl_const_Double_Box_t src));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_add_recycled_constraints
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_Constraint_System_t cs));

/*! \relates ppl_Double_Box_tag */
int
ppl_Double_Box_add_recycled_congruences
PPL_PROTO((ppl_Double_Box_t ph,
           ppl_Congruence_System_t cs));

PPL_DECLARE_IO_FUNCTIONS(Double_Box)

/* End of Functions Related to ppl_Double_Box_tag */

/*! \interface ppl_BD_Shape_double_tag
  \brief Types and functions for ppl_BD_Shape_double_tag
*/

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_delete_BD_Shape_double PPL_PROTO((ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_space_dimension
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_C_Polyhedron
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_NNC_Polyhedron
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Grid
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Grid_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Rational_Box
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Rational_Box_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_BD_Shape_mpz_class
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_BD_Shape_mpq_class
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Double_Box
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Double_Box_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_BD_Shape_double
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Octagonal_Shape_double
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_C_Polyhedron_with_complexity
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Grid_with_complexity
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Grid_t ph, int complexity));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Rational_Box_with_complexity
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Rational_Box_t ph, int complexity));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_BD_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_BD_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_BD_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_BD_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Octagonal_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Octagonal_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Double_Box_with_complexity
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Double_Box_t ph, int complexity));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_BD_Shape_double_with_complexity
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_BD_Shape_double_t ph, int complexity));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Octagonal_Shape_double_with_complexity
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Octagonal_Shape_double_t ph, int complexity));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Constraint_System
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Congruence_System
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_from_Generator_System
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_const_Generator_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_space_dimension
PPL_PROTO((ppl_const_BD_Shape_double_t ph, ppl_dimension_type* m));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_affine_dimension
PPL_PROTO((ppl_const_BD_Shape_double_t ph, ppl_dimension_type* m));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_relation_with_Constraint
PPL_PROTO((ppl_const_BD_Shape_double_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_relation_with_Generator
PPL_PROTO((ppl_const_BD_Shape_double_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_relation_with_Congruence
PPL_PROTO((ppl_const_BD_Shape_double_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_get_constraints
PPL_PROTO((ppl_const_BD_Shape_double_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_get_congruences
PPL_PROTO((ppl_const_BD_Shape_double_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_get_minimized_constraints
PPL_PROTO((ppl_const_BD_Shape_double_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_get_minimized_congruences
PPL_PROTO((ppl_const_BD_Shape_double_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_is_empty PPL_PROTO((ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_is_universe PPL_PROTO((ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_is_bounded PPL_PROTO((ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_contains_integer_point PPL_PROTO((ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_is_topologically_closed PPL_PROTO((ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_is_discrete PPL_PROTO((ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_topological_closure_assign PPL_PROTO((ppl_BD_Shape_double_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_bounds_from_above
PPL_PROTO((ppl_const_BD_Shape_double_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_bounds_from_below
PPL_PROTO((ppl_const_BD_Shape_double_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_maximize
PPL_PROTO((ppl_const_BD_Shape_double_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_minimize
PPL_PROTO((ppl_const_BD_Shape_double_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_maximize_with_point
PPL_PROTO((ppl_const_BD_Shape_double_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_minimize_with_point
PPL_PROTO((ppl_const_BD_Shape_double_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_contains_BD_Shape_double
PPL_PROTO((ppl_const_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_strictly_contains_BD_Shape_double
PPL_PROTO((ppl_const_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_is_disjoint_from_BD_Shape_double
PPL_PROTO((ppl_const_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_equals_BD_Shape_double
PPL_PROTO((ppl_const_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_OK PPL_PROTO((ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_add_constraint
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_add_congruence
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_add_constraints
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_add_congruences
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_refine_with_constraint
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_refine_with_congruence
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_refine_with_constraints
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_refine_with_congruences
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_intersection_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_upper_bound_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_difference_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_concatenate_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_time_elapse_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_upper_bound_assign_if_exact
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_simplify_using_context_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_constrains
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type var));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_unconstrain_space_dimension
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type var));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_unconstrain_space_dimensions
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_affine_image
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_affine_preimage
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_bounded_affine_image
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_bounded_affine_preimage
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_generalized_affine_image
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_generalized_affine_preimage
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_generalized_affine_image_lhs_rhs
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_generalized_affine_preimage_lhs_rhs
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_add_space_dimensions_and_embed
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type d));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_add_space_dimensions_and_project
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type d));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_remove_space_dimensions
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_remove_higher_space_dimensions
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type d));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_expand_space_dimension
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type d,
           ppl_dimension_type m));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_fold_space_dimensions
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type ds[],
           size_t n,
           ppl_dimension_type d));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_map_space_dimensions
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_dimension_type maps[],
           size_t n));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_external_memory_in_bytes
PPL_PROTO((ppl_const_BD_Shape_double_t ps,
           size_t* sz));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_total_memory_in_bytes
PPL_PROTO((ppl_const_BD_Shape_double_t ps,
           size_t* sz));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_BHMZ05_widening_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y,
           unsigned* tp));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_H79_widening_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y,
           unsigned* tp));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_BHMZ05_widening_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_H79_widening_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_widening_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y,
           unsigned* tp));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_widening_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_limited_BHMZ05_extrapolation_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_limited_H79_extrapolation_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_limited_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_limited_BHMZ05_extrapolation_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_limited_H79_extrapolation_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_limited_CC76_extrapolation_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y,
           unsigned* tp));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_CC76_extrapolation_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_CC76_narrowing_assign
PPL_PROTO((ppl_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_linear_partition
PPL_PROTO((ppl_const_BD_Shape_double_t x,
           ppl_const_BD_Shape_double_t y,
           ppl_BD_Shape_double_t* p_inters,
           ppl_Pointset_Powerset_NNC_Polyhedron_t* p_rest));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_recycle_Constraint_System
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_recycle_Congruence_System
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_Congruence_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_new_BD_Shape_double_recycle_Generator_System
PPL_PROTO((ppl_BD_Shape_double_t* pph, ppl_Generator_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_assign_BD_Shape_double_from_BD_Shape_double
PPL_PROTO((ppl_BD_Shape_double_t dst, ppl_const_BD_Shape_double_t src));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_add_recycled_constraints
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_Constraint_System_t cs));

/*! \relates ppl_BD_Shape_double_tag */
int
ppl_BD_Shape_double_add_recycled_congruences
PPL_PROTO((ppl_BD_Shape_double_t ph,
           ppl_Congruence_System_t cs));

PPL_DECLARE_IO_FUNCTIONS(BD_Shape_double)

/* End of Functions Related to ppl_BD_Shape_double_tag */

/*! \interface ppl_Octagonal_Shape_double_tag
  \brief Types and functions for ppl_Octagonal_Shape_double_tag
*/

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_delete_Octagonal_Shape_double PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_space_dimension
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_dimension_type d, int empty));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_C_Polyhedron
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_NNC_Polyhedron
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Polyhedron_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Grid
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Grid_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Rational_Box
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Rational_Box_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_BD_Shape_mpz_class
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_BD_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_BD_Shape_mpq_class
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_BD_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Octagonal_Shape_mpz_class
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Octagonal_Shape_mpq_class
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Double_Box
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Double_Box_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_BD_Shape_double
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_BD_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Octagonal_Shape_double
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_C_Polyhedron_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_NNC_Polyhedron_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Polyhedron_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Grid_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Grid_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Rational_Box_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Rational_Box_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_BD_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_BD_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_BD_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_BD_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Octagonal_Shape_mpz_class_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Octagonal_Shape_mpz_class_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Octagonal_Shape_mpq_class_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Octagonal_Shape_mpq_class_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Double_Box_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Double_Box_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_BD_Shape_double_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_BD_Shape_double_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Octagonal_Shape_double_with_complexity
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Octagonal_Shape_double_t ph, int complexity));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Constraint_System
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Congruence_System
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Congruence_System_t cs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_from_Generator_System
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_const_Generator_System_t cs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_space_dimension
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph, ppl_dimension_type* m));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_affine_dimension
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph, ppl_dimension_type* m));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_relation_with_Constraint
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_relation_with_Generator
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph,
           ppl_const_Generator_t c));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_relation_with_Congruence
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_get_constraints
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_get_congruences
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_get_minimized_constraints
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph,
           ppl_const_Constraint_System_t* pcs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_get_minimized_congruences
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph,
           ppl_const_Congruence_System_t* pcs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_is_empty PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_is_universe PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_is_bounded PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_contains_integer_point PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_is_topologically_closed PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_is_discrete PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_topological_closure_assign PPL_PROTO((ppl_Octagonal_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_bounds_from_above
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_bounds_from_below
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph,
           ppl_const_Linear_Expression_t le));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_maximize
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_minimize
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_maximize_with_point
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_minimize_with_point
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph,
           ppl_const_Linear_Expression_t le,
           ppl_Coefficient_t ext_n,
           ppl_Coefficient_t ext_d,
           int* poptimum,
           ppl_Generator_t point));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_contains_Octagonal_Shape_double
PPL_PROTO((ppl_const_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_strictly_contains_Octagonal_Shape_double
PPL_PROTO((ppl_const_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_is_disjoint_from_Octagonal_Shape_double
PPL_PROTO((ppl_const_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_equals_Octagonal_Shape_double
PPL_PROTO((ppl_const_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_OK PPL_PROTO((ppl_const_Octagonal_Shape_double_t ph));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_add_constraint
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_add_congruence
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_add_constraints
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_add_congruences
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_refine_with_constraint
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_const_Constraint_t c));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_refine_with_congruence
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_const_Congruence_t c));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_refine_with_constraints
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_refine_with_congruences
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_const_Congruence_System_t cs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_intersection_assign
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_upper_bound_assign
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_difference_assign
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_concatenate_assign
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_time_elapse_assign
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_upper_bound_assign_if_exact
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_simplify_using_context_assign
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_constrains
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_unconstrain_space_dimension
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type var));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_unconstrain_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_affine_image
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_affine_preimage
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_bounded_affine_image
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_bounded_affine_preimage
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type var,
           ppl_const_Linear_Expression_t lb,
           ppl_const_Linear_Expression_t ub,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_generalized_affine_image
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_generalized_affine_preimage
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type var,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t le,
           ppl_const_Coefficient_t d));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_generalized_affine_image_lhs_rhs
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_generalized_affine_preimage_lhs_rhs
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_const_Linear_Expression_t lhs,
           enum ppl_enum_Constraint_Type relsym,
           ppl_const_Linear_Expression_t rhs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_add_space_dimensions_and_embed
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_add_space_dimensions_and_project
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_remove_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type ds[],
           size_t n));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_remove_higher_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type d));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_expand_space_dimension
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type d,
           ppl_dimension_type m));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_fold_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type ds[],
           size_t n,
           ppl_dimension_type d));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_map_space_dimensions
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_dimension_type maps[],
           size_t n));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_external_memory_in_bytes
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ps,
           size_t* sz));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_total_memory_in_bytes
PPL_PROTO((ppl_const_Octagonal_Shape_double_t ps,
           size_t* sz));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_BHMZ05_widening_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_BHMZ05_widening_assign
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_widening_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_widening_assign
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_limited_BHMZ05_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_limited_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y,
           ppl_const_Constraint_System_t cs,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_limited_BHMZ05_extrapolation_assign
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_limited_CC76_extrapolation_assign
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y,
           ppl_const_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_CC76_extrapolation_assign_with_tokens
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y,
           unsigned* tp));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_CC76_extrapolation_assign
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_CC76_narrowing_assign
PPL_PROTO((ppl_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_linear_partition
PPL_PROTO((ppl_const_Octagonal_Shape_double_t x,
           ppl_const_Octagonal_Shape_double_t y,
           ppl_Octagonal_Shape_double_t* p_inters,
           ppl_Pointset_Powerset_NNC_Polyhedron_t* p_rest));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_recycle_Constraint_System
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_recycle_Congruence_System
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_Congruence_System_t cs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_new_Octagonal_Shape_double_recycle_Generator_System
PPL_PROTO((ppl_Octagonal_Shape_double_t* pph, ppl_Generator_System_t cs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_assign_Octagonal_Shape_double_from_Octagonal_Shape_double
PPL_PROTO((ppl_Octagonal_Shape_double_t dst, ppl_const_Octagonal_Shape_double_t src));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_add_recycled_constraints
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_Constraint_System_t cs));

/*! \relates ppl_Octagonal_Shape_double_tag */
int
ppl_Octagonal_Shape_double_add_recycled_congruences
PPL_PROTO((ppl_Octagonal_Shape_double_t ph,
           ppl_Congruence_System_t cs));

PPL_DECLARE_IO_FUNCTIONS(Octagonal_Shape_double)

/* End of Functions Related to ppl_Octagonal_Shape_double_tag */
