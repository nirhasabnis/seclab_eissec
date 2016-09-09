dnl  -*- Tuareg -*-
m4_divert(-1)

This m4 file contains the program code for generating ppl_ocaml.mli

dnl Copyright (C) 2001-2008 Roberto Bagnara <bagnara@cs.unipr.it>
dnl
dnl This file is part of the Parma Polyhedra Library (PPL).
dnl
dnl The PPL is free software; you can redistribute it and/or modify it
dnl under the terms of the GNU General Public License as published by the
dnl Free Software Foundation; either version 3 of the License, or (at your
dnl option) any later version.
dnl
dnl The PPL is distributed in the hope that it will be useful, but WITHOUT
dnl ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
dnl FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
dnl for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program; if not, write to the Free Software Foundation,
dnl Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02111-1307, USA.
dnl
dnl For the most up-to-date information see the Parma Polyhedra Library
dnl site: http://www.cs.unipr.it/ppl/ .

dnl No code is needed for these procedure schemas in the OCaml interface.
dnl
m4_define(`ppl_delete_@CLASS@_code', `')
m4_define(`ppl_delete_@CLASS@_iterator_code', `')

Define here as empty any known schematic method macros for which
the definition is not yet implemented.

m4_define(`ppl_new_@TOPOLOGY@@CLASS@_from_space_dimension_code',
`dnl
val ppl_new_@TOPOLOGY@@CLASS@_from_space_dimension:
  int -> degenerate_element -> @LCLASS@

')

m4_define(`ppl_new_@TOPOLOGY@@CLASS@_from_@BUILD_REPRESENT@s_code',
`dnl
val ppl_new_@TOPOLOGY@@CLASS@_from_@BUILD_REPRESENT@s:
  @BUILD_REPRESENT@_system -> @LCLASS@

')

m4_define(`ppl_@CLASS@_relation_with_@RELATION_REPRESENT@_code',
`dnl
val ppl_@CLASS@_relation_with_@RELATION_REPRESENT@:
  @LCLASS@ -> linear_@RELATION_REPRESENT@
  -> poly_@ALT_RELATION_REPRESENT@_relation list

')

m4_define(`ppl_@CLASS@_@DIMENSION@_code',
`dnl
val ppl_@CLASS@_@DIMENSION@:
  @LCLASS@ -> int
')

m4_define(`ppl_@CLASS@_@HAS_PROPERTY@_code',
`dnl
val ppl_@CLASS@_@HAS_PROPERTY@:
  @LCLASS@ -> bool

')

m4_define(`ppl_@CLASS@_@SIMPLIFY@_code',
`dnl
val ppl_@CLASS@_@SIMPLIFY@:
  @LCLASS@ -> unit

')

m4_define(`ppl_@CLASS@_bounds_from_@ABOVEBELOW@_code',
`dnl
val ppl_@CLASS@_bounds_from_@ABOVEBELOW@:
  @LCLASS@ -> linear_expression -> bool

')

m4_define(`ppl_@CLASS@_add_@ADD_REPRESENT@_code',
`dnl
val ppl_@CLASS@_add_@ADD_REPRESENT@:
  @LCLASS@ -> linear_@ADD_REPRESENT@ -> unit

')

m4_define(`ppl_@CLASS@_add_@ADD_REPRESENT@s_code',
`dnl
val ppl_@CLASS@_add_@ADD_REPRESENT@s:
  @LCLASS@ -> @ADD_REPRESENT@_system -> unit

')

m4_define(`ppl_@CLASS@_refine_with_@REFINE_REPRESENT@_code',
`dnl
val ppl_@CLASS@_refine_with_@REFINE_REPRESENT@:
  @LCLASS@ -> linear_@REFINE_REPRESENT@ -> unit

')

m4_define(`ppl_@CLASS@_refine_with_@REFINE_REPRESENT@s_code',
`dnl
val ppl_@CLASS@_refine_with_@REFINE_REPRESENT@s:
  @LCLASS@ -> @REFINE_REPRESENT@_system -> unit

')

m4_define(`ppl_@CLASS@_@COMPARISON@_@CLASS@_code',
`dnl
val ppl_@CLASS@_@COMPARISON@_@CLASS@:
  @LCLASS@ -> @LCLASS@ -> bool

')

m4_define(`ppl_@CLASS@_equals_@CLASS@_code',
`dnl
val ppl_@CLASS@_equals_@CLASS@:
  @LCLASS@ -> @LCLASS@ -> bool

')


m4_define(`ppl_@CLASS@_@BINOP@_code',
`dnl
val ppl_@CLASS@_@BINOP@:
   @LCLASS@ -> @LCLASS@ -> unit

')

m4_define(`ppl_@CLASS@_simplify_using_context_assign_code',
`dnl
val ppl_@CLASS@_simplify_using_context_assign:
  @LCLASS@ -> @LCLASS@ -> bool

')

m4_define(`ppl_@CLASS@_add_space_dimensions_@EMBEDPROJECT@_code',
`dnl
val ppl_@CLASS@_add_space_dimensions_@EMBEDPROJECT@:
  @LCLASS@ -> int -> unit

')

m4_define(`ppl_@CLASS@_remove_space_dimensions_code',
`dnl
val ppl_@CLASS@_remove_space_dimensions:
  @LCLASS@ -> int list -> unit

')

m4_define(`ppl_@CLASS@_remove_higher_space_dimensions_code',
`dnl
val ppl_@CLASS@_remove_higher_space_dimensions:
  @LCLASS@ -> int -> unit

')

m4_define(`ppl_@CLASS@_fold_space_dimensions_code',
`dnl
val ppl_@CLASS@_fold_space_dimensions:
  @LCLASS@ -> int list -> int -> unit

')

m4_define(`ppl_@CLASS@_map_space_dimensions_code',
`dnl
val ppl_@CLASS@_map_space_dimensions:
  @LCLASS@ -> (int*int) list -> unit
')

m4_define(`ppl_@CLASS@_expand_space_dimension_code',
`dnl
val ppl_@CLASS@_expand_space_dimension:
  @LCLASS@ -> int -> int -> unit
')

m4_define(`ppl_@CLASS@_get_@GET_REPRESENT@s_code',
`dnl
val ppl_@CLASS@_get_@GET_REPRESENT@s:
  @LCLASS@ -> @GET_REPRESENT@_system

')

m4_define(`ppl_@CLASS@_get_minimized_@GET_REPRESENT@s_code',
`dnl
val ppl_@CLASS@_get_minimized_@GET_REPRESENT@s:
  @LCLASS@ -> @GET_REPRESENT@_system

')

m4_define(`ppl_@CLASS@_constrains_code',
`dnl
val ppl_@CLASS@_constrains:
  @LCLASS@ -> int -> bool

')

m4_define(`ppl_@CLASS@_unconstrain_space_dimension_code',
`dnl
val ppl_@CLASS@_unconstrain_space_dimension:
  @LCLASS@ -> int -> unit

')

m4_define(`ppl_@CLASS@_unconstrain_space_dimensions_code',
`dnl
val ppl_@CLASS@_unconstrain_space_dimensions:
  @LCLASS@ -> int list -> unit

')

m4_define(`ppl_@CLASS@_bounded_@AFFIMAGE@_code',
`dnl
val ppl_@CLASS@_bounded_@AFFIMAGE@:
  @LCLASS@ -> int
  -> linear_expression -> linear_expression
  -> Z.t -> unit
')

m4_define(`ppl_@CLASS@_@AFFIMAGE@_code',
`dnl
val ppl_@CLASS@_@AFFIMAGE@:
  @LCLASS@ -> int -> linear_expression -> Z.t -> unit

')

m4_define(`ppl_@CLASS@_generalized_@AFFIMAGE@_lhs_rhs_code',
`dnl
val ppl_@CLASS@_generalized_@AFFIMAGE@_lhs_rhs:
  @LCLASS@ -> linear_expression
  -> relation_symbol -> linear_expression
  -> unit

')

m4_define(`ppl_@CLASS@_generalized_@AFFIMAGE@_code',
`dnl
val ppl_@CLASS@_generalized_@AFFIMAGE@:
  @LCLASS@ -> int -> relation_symbol -> linear_expression
  -> Z.t -> unit

')

m4_define(`ppl_@CLASS@_generalized_@AFFIMAGE@_with_congruence_code',
`dnl
val ppl_@CLASS@_generalized_@AFFIMAGE@_with_congruence:
  @LCLASS@ -> int -> relation_symbol -> linear_expression
  -> Z.t -> Z.t -> unit

')

m4_define(`ppl_@CLASS@_generalized_@AFFIMAGE@_lhs_rhs_with_congruence_code',
`dnl
val ppl_@CLASS@_generalized_@AFFIMAGE@_lhs_rhs_with_congruence:
  @LCLASS@ -> linear_expression
  -> relation_symbol -> linear_expression -> Z.t
  -> unit

')

m4_define(`ppl_@CLASS@_@WIDEN@_widening_assign_code',
`dnl
val ppl_@CLASS@_@WIDEN@_widening_assign:
  @LCLASS@ -> @LCLASS@ -> unit

')

m4_define(`ppl_@CLASS@_@WIDEN@_widening_assign_with_tokens_code',
`dnl
val ppl_@CLASS@_@WIDEN@_widening_assign_with_tokens:
  @LCLASS@ -> @LCLASS@ -> int -> int

')

m4_define(`ppl_@CLASS@_widening_assign_code',
`dnl
val ppl_@CLASS@_widening_assign:
  @LCLASS@ -> @LCLASS@ -> unit

')

m4_define(`ppl_@CLASS@_widening_assign_with_tokens_code',
`dnl
val ppl_@CLASS@_widening_assign_with_tokens:
  @LCLASS@ -> @LCLASS@ -> int -> int

')

m4_define(`ppl_@CLASS@_@LIMITEDBOUNDED@_@WIDENEXPN@_extrapolation_assign_with_tokens_code',
`dnl
val ppl_@CLASS@_@LIMITEDBOUNDED@_@WIDENEXPN@_extrapolation_assign_with_tokens:
  @LCLASS@ -> @LCLASS@
  -> @CONSTRAINER@_system -> int -> int

')

m4_define(`ppl_@CLASS@_@LIMITEDBOUNDED@_@WIDENEXPN@_extrapolation_assign_code',
`dnl
val ppl_@CLASS@_@LIMITEDBOUNDED@_@WIDENEXPN@_extrapolation_assign:
  @LCLASS@ -> @LCLASS@
  -> @CONSTRAINER@_system -> unit

')

m4_define(`ppl_@CLASS@_@MAXMIN@_code',
`dnl
val ppl_@CLASS@_@MAXMIN@:
  @LCLASS@ -> linear_expression
  -> bool * Z.t * Z.t * bool

')

m4_define(`ppl_@CLASS@_@MAXMIN@_with_point_code',
`dnl
val ppl_@CLASS@_@MAXMIN@_with_point:
  @LCLASS@ -> linear_expression
  -> bool * Z.t * Z.t * bool * linear_generator

')

m4_define(`ppl_@CLASS@_OK_code',
`dnl
val ppl_@CLASS@_OK:
  @LCLASS@ -> bool
')

m4_define(`ppl_@CLASS@_@MEMBYTES@_code',
 `dnl
val ppl_@CLASS@_@MEMBYTES@:
  @LCLASS@  -> int

')


m4_define(`ppl_@CLASS@_swap_code',
`dnl
val ppl_@CLASS@_swap:
  @LCLASS@ -> @LCLASS@ -> unit

')

m4_define(`ppl_new_@TOPOLOGY@@CLASS@_from_@FRIEND@_code',
`dnl
val ppl_new_@TOPOLOGY@@CLASS@_from_@FRIEND@:
  @LALT_FRIEND@ -> @LCLASS@

')

m4_define(`ppl_new_@TOPOLOGY@@CLASS@_from_@FRIEND@_with_complexity_code',
`dnl
val ppl_new_@TOPOLOGY@@CLASS@_from_@FRIEND@_with_complexity:
  @LALT_FRIEND@ -> complexity_class -> @LCLASS@

')


 m4_define(`ppl_@CLASS@_@UB_EXACT@_code',
 `dnl
 val ppl_@CLASS@_@UB_EXACT@:
   @LCLASS@ -> @LCLASS@ -> bool

 ')

 m4_define(`ppl_@CLASS@_@EXTRAPOLATION@_extrapolation_assign_code',
 `dnl
val ppl_@CLASS@_@EXTRAPOLATION@_extrapolation_assign:
  @LCLASS@  -> @LCLASS@ -> unit

 ')

 m4_define(`ppl_@CLASS@_@EXTRAPOLATION@_extrapolation_assign_with_tokens_code',
 `dnl
val ppl_@CLASS@_@EXTRAPOLATION@_extrapolation_assign_with_tokens:
  @LCLASS@  -> @LCLASS@ -> int -> int

 ')

 m4_define(`ppl_@CLASS@_@EXTRAPOLATION@_narrowing_assign_code',
 `dnl
val ppl_@CLASS@_@EXTRAPOLATION@_narrowing_assign:
  @LCLASS@  -> @LCLASS@ -> unit

 ')

 m4_define(`ppl_@CLASS@_@BEGINEND@_iterator_code',
 `dnl
val ppl_@CLASS@_@BEGINEND@_iterator:
  @LCLASS@  -> @LCLASS@_iterator

')

m4_define(`ppl_@CLASS@_get_disjunct_code',
 `dnl
val ppl_@CLASS@_get_disjunct:
  @LCLASS@_iterator  ->  @LDISJUNCT@

')

m4_define(`ppl_@CLASS@_add_disjunct_code',
 `dnl
val ppl_@CLASS@_add_disjunct:
  @LCLASS@  ->  @LDISJUNCT@ -> unit

')

m4_define(`ppl_@CLASS@_drop_disjunct_code',
 `dnl
val ppl_@CLASS@_drop_disjunct:
  @LCLASS@  ->  @LCLASS@_iterator -> unit

')

m4_define(`ppl_@CLASS@_drop_disjuncts_code',
 `dnl
val ppl_@CLASS@_drop_disjuncts:
  @LCLASS@  ->  @LCLASS@_iterator -> @LCLASS@_iterator -> unit

')

m4_define(`ppl_new_@CLASS@_iterator_from_iterator_code',
 `dnl
type @LCLASS@_iterator

val ppl_new_@CLASS@_iterator_from_iterator:
  @LCLASS@_iterator ->  @LCLASS@_iterator

')

m4_define(`ppl_@CLASS@_iterator_equals_iterator_code',
 `dnl

val ppl_@CLASS@_iterator_equals_iterator:
  @LCLASS@_iterator ->  @LCLASS@_iterator -> bool

')

m4_define(`ppl_@CLASS@_@INCDEC@_iterator_code',
 `dnl
val ppl_@CLASS@_@INCDEC@_iterator:
  @LCLASS@_iterator -> unit

')


m4_define(`ppl_@CLASS@_BHZ03_@ALT_DISJUNCT_WIDEN@_@DISJUNCT_WIDEN@_widening_assign_code',
`dnl
val ppl_@CLASS@_BHZ03_@ALT_DISJUNCT_WIDEN@_@DISJUNCT_WIDEN@_widening_assign:
  @LCLASS@ -> @LCLASS@ -> unit

')

m4_define(`ppl_@CLASS@_BGP99_@DISJUNCT_WIDEN@_extrapolation_assign_code',
`dnl
val ppl_@CLASS@_BGP99_@DISJUNCT_WIDEN@_extrapolation_assign:
  @LCLASS@ -> @LCLASS@ -> int -> unit

')

m4_define(`ppl_@CLASS@_ascii_dump_code',
`dnl

val ppl_@CLASS@_ascii_dump:
  @LCLASS@ -> string

')

m4_define(`ppl_@CLASS@_linear_@PARTITION@_code',
`dnl
val ppl_@CLASS@_linear_@PARTITION@:
 @LCLASS@ -> @LCLASS@ -> @LCLASS@ * pointset_powerset_nnc_polyhedron

')

m4_define(`ppl_@CLASS@_approximate_@PARTITION@_code',
`dnl
val ppl_@CLASS@_approximate_@PARTITION@:
 @LCLASS@ -> @LCLASS@ ->
   @LCLASS@ * pointset_powerset_grid * bool

')
