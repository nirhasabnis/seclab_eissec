/* Domain-independent part of the OCaml interface: non-inline functions.
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

#include "ppl_ocaml_common.defs.hh"
//#include <stdexcept>

namespace Parma_Polyhedra_Library {

namespace Interfaces {

namespace OCaml {

class PFunc {
 private:
   std::set<dimension_type> codomain;
   std::vector<dimension_type> vec;

 public:
   PFunc() {
   }

  bool has_empty_codomain() const {
    return codomain.empty();
   }

  dimension_type max_in_codomain() const {
    if (codomain.empty())
      throw std::runtime_error("PFunc::max_in_codomain()");
    return *codomain.rbegin();
  }

  bool maps(dimension_type i, dimension_type& j) const {
    if (i >= vec.size())
      return false;
    dimension_type vec_i = vec[i];
    if (vec_i == not_a_dimension())
      return false;
    j = vec_i;
    return true;
  }

  bool insert(dimension_type i, dimension_type j) {
    std::pair<std::set<dimension_type>::iterator, bool> s
      = codomain.insert(j);
    if (!s.second)
      // *this is not injective!
      return false;
    if (i > vec.size())
      vec.insert(vec.end(), i - vec.size(), not_a_dimension());
    if (i == vec.size()) {
      vec.insert(vec.end(), j);
      return true;
    }
    dimension_type& vec_i = vec[i];
    if (vec_i != not_a_dimension())
      // Already mapped: *this is not a function!
      return false;
    vec_i = j;
    return true;
  }
};

#define CATCH_ALL							\
  catch(std::bad_alloc&) {						\
    caml_raise_out_of_memory();						\
  }									\
  catch(std::invalid_argument& e) {					\
    caml_invalid_argument(const_cast<char*>(e.what()));			\
  }									\
  catch(std::overflow_error& e) {					\
    caml_raise_with_string(*caml_named_value("PPL_arithmetic_overflow"), \
			   (const_cast<char*>(e.what())));		\
  }									\
  catch(std::runtime_error& e) {					\
    caml_raise_with_string(*caml_named_value("PPL_internal_error"),	\
			   (const_cast<char*>(e.what())));		\
  }									\
  catch(std::exception& e) {						\
    caml_raise_with_string(*caml_named_value("PPL_unknown_standard_exception"), \
			   (const_cast<char*>(e.what())));		\
  }									\
  catch(...) {								\
    caml_raise_constant(*caml_named_value("PPL_unexpected_error"));	\
  }

static inline mpz_t* mpz_val(value val) {
  return ((mpz_t*) (Data_custom_val(val)));
}

// Function for the management of mpz_t integers.
extern "C" struct custom_operations _mlgmp_custom_z;

static inline value alloc_mpz(void) {

  return caml_alloc_custom(&_mlgmp_custom_z, sizeof(mpz_t), 0, 1);
}

Variable
build_ppl_Variable(value caml_var) {
  long ppl_var_index = Int_val(caml_var);
  check_int_is_unsigned(ppl_var_index);
  return Variable(ppl_var_index);
}

// FIXME: this same function is used also in the C interface.
// It should be placed in some common header file in the interfaces
// directory.
//! Reinterpret an mpz_t as mpz_class.
inline mpz_class&
reinterpret_mpz_class(mpz_t n) {
  return reinterpret_cast<mpz_class&>(*n);
}

value
build_ocaml_coefficient(const Coefficient& ppl_coeff) {
  value ml_coeff = alloc_mpz();
  mpz_init(*mpz_val(ml_coeff));
  assign_r(reinterpret_mpz_class(*mpz_val(ml_coeff)), ppl_coeff,
 	   ROUND_NOT_NEEDED);
  return ml_coeff;
}

Coefficient
build_ppl_Coefficient(value coeff) {
   mpz_class z((__mpz_struct*) Data_custom_val(coeff));
   return Coefficient(z);
}

Linear_Expression
build_ppl_Linear_Expression(value e) {
  switch (Tag_val(e)) {
  case 0:
    // Variable
    return Variable(Long_val(Field(e, 0)));
  case 1: {
    // Coefficient
    mpz_class z((__mpz_struct*) Data_custom_val(Field(e, 0)));
    return Linear_Expression(Coefficient(z));
  }
  case 2:
    // Unary_Plus
    return build_ppl_Linear_Expression(Field(e, 0));
  case 3:
    // Unary_Minus
    return -build_ppl_Linear_Expression(Field(e, 0));
  case 4:
    // Plus
    return build_ppl_Linear_Expression(Field(e, 0))
      + build_ppl_Linear_Expression(Field(e, 1));
  case 5:
    // Minus
    return build_ppl_Linear_Expression(Field(e, 0))
      - build_ppl_Linear_Expression(Field(e, 1));
  case 6: {
    // Times
    mpz_class z((__mpz_struct*) Data_custom_val(Field(e, 0)));
    return Coefficient(z) * build_ppl_Linear_Expression(Field(e, 1));
  }
  default:
    caml_invalid_argument("Error building PPL::Linear_Expression");
  }
}

Relation_Symbol
build_ppl_relsym(value caml_relsym) {
  switch (Int_val(caml_relsym)) {
  case 0:
    return LESS_THAN;
  case 1:
    return LESS_OR_EQUAL;
  case 2:
    return EQUAL;
  case 3:
    return GREATER_OR_EQUAL;
  case 4:
    return GREATER_THAN;
 default:
   // We should not be here!
   throw std::runtime_error("PPL OCaml interface internal error");
  }
}

Optimization_Mode
build_ppl_opt_mode(value caml_opt_mode) {
  switch (Int_val(caml_opt_mode)) {
  case 0:
    return MINIMIZATION;
  case 1:
    return MAXIMIZATION;
  default:
    // We should not be here!
    throw std::runtime_error("PPL OCaml interface internal error");
  }
}

Degenerate_Element
build_ppl_Degenerate_Element(value de) {
  switch (Int_val(de)) {
  case 0: {
    return UNIVERSE;
  }
  case 1: {
    return EMPTY;
  }
 default:
  // We should not be here!
  throw std::runtime_error("PPL OCaml interface internal error");
  }
}

Complexity_Class
build_ppl_Complexity_Class(value cc) {
  switch (Int_val(cc)) {
  case 0: {
    return POLYNOMIAL_COMPLEXITY;
  }
  case 1: {
    return SIMPLEX_COMPLEXITY;
  }
  case 2: {
    return ANY_COMPLEXITY;
  }
 default:
  // We should not be here!
  throw std::runtime_error("PPL OCaml interface internal error");
  }
}

 MIP_Problem::Control_Parameter_Name
build_ppl_control_parameter_name(value caml_cp_name) {
  switch (Int_val(caml_cp_name)) {
  case 0:
    return  MIP_Problem::PRICING;
  default:
    // We should not be here!
    throw std::runtime_error("PPL OCaml interface internal error");
  }
}

 MIP_Problem::Control_Parameter_Value
build_ppl_control_parameter_value(value caml_cp_value) {
  switch (Int_val(caml_cp_value)) {
  case 0:
    return MIP_Problem::PRICING_STEEPEST_EDGE_FLOAT;
  case 1:
    return MIP_Problem::PRICING_STEEPEST_EDGE_EXACT;
  case 2:
    return MIP_Problem::PRICING_TEXTBOOK;
  default:
    // We should not be here!
    throw std::runtime_error("PPL OCaml interface internal error");
  }
}

Variables_Set
build_ppl_Variables_Set(value caml_vset) {
  Variables_Set ppl_vset;
  if (Int_val(caml_vset) == 0)
    return ppl_vset;
  while (true) {
    ppl_vset.insert(Int_val(Field(caml_vset, 0)));
    if (Int_val(Field(caml_vset, 1)) == 0)
      break;
    caml_vset = Field(caml_vset, 1);
  }
  return ppl_vset;
}

Constraint
build_ppl_Constraint(value c) {
  value e1 = Field(c, 0);
  value e2 = Field(c, 1);
  switch (Tag_val(c)) {
  case 0:
    // Less_Than
    return build_ppl_Linear_Expression(e1) < build_ppl_Linear_Expression(e2);
  case 1:
    // Less_Or_Equal
    return build_ppl_Linear_Expression(e1) <= build_ppl_Linear_Expression(e2);
  case 2:
    // Equal
    return build_ppl_Linear_Expression(e1) == build_ppl_Linear_Expression(e2);
  case 3:
    // Greater_Than
    return build_ppl_Linear_Expression(e1) > build_ppl_Linear_Expression(e2);
  case 4:
    // Greater_Or_Equal
    return build_ppl_Linear_Expression(e1) >= build_ppl_Linear_Expression(e2);
  default:
    caml_invalid_argument("Error building PPL::Constraint");
  }
}


template <typename R>
CAMLprim value
get_inhomogeneous_term(const R& r) {
  TEMP_INTEGER(coeff);
  neg_assign(coeff, r.inhomogeneous_term());
  value coeff_term = caml_alloc(1,1);
  Field(coeff_term, 0) = build_ocaml_coefficient(coeff);
  return coeff_term;
}

// Takes from constraints, generators... the embedded linear
// expression.
template <typename R>
CAMLprim value
get_linear_expression(const R& r) {
  dimension_type space_dimension = r.space_dimension();
  dimension_type varid = 0;
  TEMP_INTEGER(coeff);
  while (varid < space_dimension
	 && (coeff = r.coefficient(Variable(varid))) == 0)
    ++varid;
  if (varid >= space_dimension) {
    value zero_term = caml_alloc(1,1);
    value zero_mpz = alloc_mpz();
    mpz_init_set_ui(*mpz_val(zero_mpz), 0);
    Field(zero_term, 0) = zero_mpz;
    return zero_term;
  }
  else {
    value term1 = caml_alloc(2,6);
    TEMP_INTEGER(ppl_coeff);
    ppl_coeff = r.coefficient(Variable(varid));
    Field(term1, 0) = build_ocaml_coefficient(ppl_coeff);
    value ml_le_var1 = caml_alloc(1,0);
    Field(ml_le_var1, 0) = Val_int(varid);
    Field(term1, 1) = ml_le_var1;
    while (true) {
      ++varid;
      value sum;
      while (varid < space_dimension
	     && (coeff = r.coefficient(Variable(varid))) == 0)
	++varid;
      if (varid >= space_dimension)
	return term1;
      else {
	sum = caml_alloc(2,4);
	value term2 = caml_alloc(2,6);
	ppl_coeff = r.coefficient(Variable(varid));
	Field(term2, 0) = build_ocaml_coefficient(ppl_coeff);
	value ml_le_var2 = caml_alloc(1,0);
	Field(ml_le_var2, 0) = Val_int(varid);
	Field(term2, 1) = ml_le_var2;
	Field(sum, 0) = term1;
	Field(sum, 1) = term2;
	term1 = sum;
      }
    }
  }
}

value
build_ocaml_generator(const Generator& ppl_generator) {
  switch (ppl_generator.type()) {
  case Generator::LINE: {
    // Store the linear expression. (1,0) stands for
    // allocate one block (the linear expression) with Tag 0 (a line here).
    value caml_generator = caml_alloc(1,0);
    Field(caml_generator, 0) = get_linear_expression(ppl_generator);
    return caml_generator;
  }
  case Generator::RAY: {
    value caml_generator = caml_alloc(1,1);
    Field(caml_generator, 0) = get_linear_expression(ppl_generator);
    return caml_generator;
  }
  case Generator::POINT: {
    // Allocates two blocks (the linear expression and the divisor)
    // of tag 2 (Point).
    value caml_generator = caml_alloc(2,2);
    Field(caml_generator, 0) = get_linear_expression(ppl_generator);
    const Coefficient& divisor = ppl_generator.divisor();
    Field(caml_generator, 1) = build_ocaml_coefficient(divisor);
    return caml_generator;
  }
  case Generator::CLOSURE_POINT:  {
    value caml_generator = caml_alloc(2,3);
    Field(caml_generator, 0) = get_linear_expression(ppl_generator);
    const Coefficient& divisor = ppl_generator.divisor();
    Field(caml_generator, 1) =  build_ocaml_coefficient(divisor);
    return caml_generator;
  }
  default:
    throw std::runtime_error("PPL OCaml interface internal error");
  }
}

value
build_ocaml_grid_generator(const Grid_Generator& ppl_grid_generator) {
  switch (ppl_grid_generator.type()) {
  case Grid_Generator::LINE: {
    // Store the linear expression. (1,0) stands for
    // allocate one block (the linear expression) with Tag 0 (a line here).
    value caml_generator = caml_alloc(1,0);
    Field(caml_generator, 0) = get_linear_expression(ppl_grid_generator);
    return caml_generator;
  }
  case Grid_Generator::PARAMETER: {
    value caml_generator = caml_alloc(2,1);
    Field(caml_generator, 0) = get_linear_expression(ppl_grid_generator);
    const Coefficient& divisor = ppl_grid_generator.divisor();
    Field(caml_generator, 1) = build_ocaml_coefficient(divisor);
    return caml_generator;
  }
  case Grid_Generator::POINT: {
    // Allocates two blocks (the linear expression and the divisor)
    // of tag 2 (Point).
    value caml_generator = caml_alloc(2,2);
    Field(caml_generator, 0) = get_linear_expression(ppl_grid_generator);
    const Coefficient& divisor = ppl_grid_generator.divisor();
    Field(caml_generator, 1) = build_ocaml_coefficient(divisor);
    return caml_generator;
  }

  default:
    throw std::runtime_error("PPL OCaml interface internal error");
  }
}

value
build_ocaml_constraint(const Constraint& ppl_constraint) {
  switch (ppl_constraint.type()) {
  case Constraint::EQUALITY: {
    value caml_constraint = caml_alloc(2,2);
    Field(caml_constraint, 0) = get_linear_expression(ppl_constraint);
    Field(caml_constraint, 1) = get_inhomogeneous_term(ppl_constraint);
    return caml_constraint;
  }
  case Constraint::STRICT_INEQUALITY: {
    value caml_constraint = caml_alloc(2,3);
    Field(caml_constraint, 0) = get_linear_expression(ppl_constraint);
    Field(caml_constraint, 1) = get_inhomogeneous_term(ppl_constraint);
    return caml_constraint;
  }
  case Constraint::NONSTRICT_INEQUALITY: {
    value caml_constraint = caml_alloc(2,4);
    Field(caml_constraint, 0) = get_linear_expression(ppl_constraint);
    Field(caml_constraint, 1) = get_inhomogeneous_term(ppl_constraint);
    return caml_constraint;
  }
  default:
    throw std::runtime_error("PPL OCaml interface internal error");
  }
}

value
build_ocaml_congruence(const Congruence& ppl_congruence) {
    value caml_congruence = caml_alloc(3,0);
    Field(caml_congruence, 0) = get_linear_expression(ppl_congruence);
    Field(caml_congruence, 1) = get_inhomogeneous_term(ppl_congruence);
    const Coefficient& modulus = ppl_congruence.modulus();
    Field(caml_congruence, 2) = build_ocaml_coefficient(modulus);
    return caml_congruence;
}

value
build_ocaml_congruence_system(const Congruence_System& ppl_cgs) {
  // This code builds a list of constraints starting from bottom to
  // top. A list on OCaml must be built like a sequence of Cons and Tail.
  // The first element is the Nil list (the Val_int(0)).
  value result = Val_int(0);
  for (Congruence_System::const_iterator v_begin = ppl_cgs.begin(),
  	 v_end = ppl_cgs.end(); v_begin != v_end; ++v_begin) {
    value new_tail = caml_alloc_tuple(2);
    Field(new_tail, 0) = build_ocaml_congruence(*v_begin);
    Field(new_tail, 1) = result;
    result = new_tail;
  }
  return result;
}

value
build_ocaml_constraint_system(const Constraint_System& ppl_cs) {
  // This code builds a list of constraints starting from bottom to
  // top. A list on OCaml must be built like a sequence of Cons and Tail.
  // The first element is the Nil list (the Val_int(0)).
  value result = Val_int(0);
  for (Constraint_System::const_iterator v_begin = ppl_cs.begin(),
  	 v_end = ppl_cs.end(); v_begin != v_end; ++v_begin) {
    value new_tail = caml_alloc_tuple(2);
    Field(new_tail, 0) = build_ocaml_constraint(*v_begin);
    Field(new_tail, 1) = result;
    result = new_tail;
  }
  return result;
}

value
build_ocaml_generator_system(const Generator_System& ppl_gs) {
  value result = Val_int(0);
  for (Generator_System::const_iterator v_begin = ppl_gs.begin(),
  	 v_end = ppl_gs.end(); v_begin != v_end; ++v_begin) {
    value new_tail = caml_alloc_tuple(2);
    Field(new_tail, 0) = build_ocaml_generator(*v_begin);
    Field(new_tail, 1) = result;
    result = new_tail;
  }
  return result;
}

value
build_ocaml_grid_generator_system(const Grid_Generator_System& ppl_ggs) {
  value result = Val_int(0);
  for (Grid_Generator_System::const_iterator v_begin = ppl_ggs.begin(),
  	 v_end = ppl_ggs.end(); v_begin != v_end; ++v_begin) {
    value new_tail = caml_alloc_tuple(2);
    Field(new_tail, 0) = build_ocaml_grid_generator(*v_begin);
    Field(new_tail, 1) = result;
    result = new_tail;
  }
  return result;
}

value
build_ocaml_poly_con_relation(Poly_Con_Relation& r) {
  value result = Val_int(0);
  value cons;
  while (r != Poly_Con_Relation::nothing()) {
    if (r.implies(Poly_Con_Relation::is_disjoint())) {
      cons = caml_alloc_tuple(2);
      Field(cons, 0) = Val_int(0);
      Field(cons, 1) = result;
      result = cons;
      r = r - Poly_Con_Relation::is_disjoint();
    }
    else if (r.implies(Poly_Con_Relation::strictly_intersects())) {
      cons = caml_alloc_tuple(2);
      Field(cons, 0) = Val_int(1);
      Field(cons, 1) = result;
      result = cons;
      r = r - Poly_Con_Relation::strictly_intersects();
    }
    else if (r.implies(Poly_Con_Relation::is_included())) {
      cons = caml_alloc_tuple(2);
      Field(cons, 0) = Val_int(2);
      Field(cons, 1) = result;
      result = cons;
      r = r - Poly_Con_Relation::is_included();
    }
    else if (r.implies(Poly_Con_Relation::saturates())) {
      cons = caml_alloc_tuple(2);
      Field(cons, 0) = Val_int(3);
      Field(cons, 1) = result;
      result = cons;
      r = r - Poly_Con_Relation::saturates();
    }
  }
  return result;
}

value
build_ocaml_poly_gen_relation(Poly_Gen_Relation& r) {
  value result = Val_int(0);
  value cons;
  while (r != Poly_Gen_Relation::nothing()) {
    if (r.implies(Poly_Gen_Relation::subsumes())) {
      cons = caml_alloc_tuple(2);
      Field(cons, 0) = Val_int(0);
      Field(cons, 1) = result;
      result = cons;
      r = r - Poly_Gen_Relation::subsumes();
    }
  }
  return result;
}

Congruence
build_ppl_Congruence(value c) {
  value e1 = Field(c, 0);
  value e2 = Field(c, 1);
  mpz_class z((__mpz_struct*) Data_custom_val(Field(c, 2)));
  Linear_Expression lhs = build_ppl_Linear_Expression(e1);
  Linear_Expression rhs = build_ppl_Linear_Expression(e2);
  return ((lhs %= rhs) / z);
}

Generator
build_ppl_Generator(value g) {
  switch (Tag_val(g)) {
  case 0:
    // Line
    return Generator::line(build_ppl_Linear_Expression(Field(g, 0)));
  case 1:
    // Ray
    return Generator::ray(build_ppl_Linear_Expression(Field(g, 0)));
  case 2: {
    // Point
    mpz_class z((__mpz_struct*) Data_custom_val(Field(g, 1)));
    return Generator::point(build_ppl_Linear_Expression(Field(g, 0)),
			    Coefficient(z));
  }
  case 3: {
    // Closure_point
    mpz_class z((__mpz_struct*) Data_custom_val(Field(g, 1)));
    return Generator::closure_point(build_ppl_Linear_Expression(Field(g, 0)),
				    Coefficient(z));
  }
  default:
    caml_invalid_argument("Error building PPL::Constraint");
  }
}

Grid_Generator
build_ppl_Grid_Generator(value gg) {
  switch (Tag_val(gg)) {
   case 0:
     // Line
     return grid_line(build_ppl_Linear_Expression(Field(gg, 0)));
   case 1: {
     // Parameter
     mpz_class z((__mpz_struct*) Data_custom_val(Field(gg, 1)));
     return parameter(build_ppl_Linear_Expression(Field(gg, 0)),
		      Coefficient(z));
   }
   case 2: {
     // Point
     mpz_class z((__mpz_struct*) Data_custom_val(Field(gg, 1)));
     return grid_point(build_ppl_Linear_Expression(Field(gg, 0)),
		       Coefficient(z));
   }
  default:
    // We should not be here!
    throw std::runtime_error("PPL OCaml interface internal error");
  }
}

Constraint_System
build_ppl_Constraint_System(value cl) {
  Constraint_System cs;
  while (cl != Val_int(0)) {
    cs.insert(build_ppl_Constraint(Field(cl, 0)));
    cl = Field(cl, 1);
  }
  return cs;
}

Generator_System
build_ppl_Generator_System(value gl) {
  Generator_System gs;
  while (gl != Val_int(0)) {
    gs.insert(build_ppl_Generator(Field(gl, 0)));
    gl = Field(gl, 1);
  }
  return gs;
}

Congruence_System
build_ppl_Congruence_System(value cgl) {
  Congruence_System cgs;
  while (cgl != Val_int(0)) {
    cgs.insert(build_ppl_Congruence(Field(cgl, 0)));
    cgl = Field(cgl, 1);
  }
  return cgs;
}

Grid_Generator_System
build_ppl_Grid_Generator_System(value caml_ggs) {
  Grid_Generator_System ggs;
  while (caml_ggs != Val_int(0)) {
    ggs.insert(build_ppl_Grid_Generator(Field(caml_ggs, 0)));
    caml_ggs = Field(caml_ggs, 1);
  }
  return ggs;
}

//! Give access to the embedded MIP_Problem* in \p v.
inline MIP_Problem*&
p_MIP_Problem_val(value v) {
  return *reinterpret_cast<MIP_Problem**>(Data_custom_val(v));
}

void
custom_MIP_Problem_finalize(value v) {
  delete p_MIP_Problem_val(v);
}

static struct custom_operations MIP_Problem_custom_operations = {
  "it.unipr.cs.ppl" "." PPL_VERSION "." "MIP_Problem",
  custom_MIP_Problem_finalize,
  custom_compare_default,
  custom_hash_default,
  custom_serialize_default,
  custom_deserialize_default
};

inline value
val_p_MIP_Problem(const MIP_Problem& ph) {
  value v = caml_alloc_custom(&MIP_Problem_custom_operations,
			      sizeof(MIP_Problem*), 0, 1);
  p_MIP_Problem_val(v) = const_cast<MIP_Problem*>(&ph);
  return(v);
}

} // namespace OCaml

} // namespace Interfaces

} // namespace Parma_Polyhedra_Library

using namespace Parma_Polyhedra_Library;
using namespace Parma_Polyhedra_Library::Interfaces::OCaml;

extern "C"
CAMLprim value
ppl_new_MIP_Problem_from_space_dimension(value d) try {
  CAMLparam1(d);
  int dd = Int_val(d);
  if (dd < 0)
    abort();
  CAMLreturn(val_p_MIP_Problem(*new MIP_Problem(dd)));
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_new_MIP_Problem(value d, value caml_cs, value caml_cost,
		    value caml_opt_mode) try {
  CAMLparam4(d, caml_cs, caml_cost, caml_opt_mode);
  int dd = Int_val(d);
  if (dd < 0)
    abort();
  Constraint_System ppl_cs = build_ppl_Constraint_System(caml_cs);
  Linear_Expression ppl_cost = build_ppl_Linear_Expression(caml_cost);
  Optimization_Mode ppl_opt_mode = build_ppl_opt_mode(caml_opt_mode);
  CAMLreturn(val_p_MIP_Problem(*new MIP_Problem(dd, ppl_cs, ppl_cost,
						ppl_opt_mode)));
}
CATCH_ALL


extern "C"
CAMLprim value
ppl_MIP_Problem_space_dimension(value ph) try {
  CAMLparam1(ph);
  const MIP_Problem& pph = *p_MIP_Problem_val(ph);
  dimension_type d = pph.space_dimension();
  if (d > INT_MAX)
    abort();
  CAMLreturn(Val_int(d));
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_MIP_Problem_constraints(value caml_mip) try {
  CAMLparam1(caml_mip);
  const MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  Constraint_System cs;
  for (MIP_Problem::const_iterator cs_it = ppl_mip.constraints_begin(),
	 cs_end = ppl_mip.constraints_end(); cs_it != cs_end; ++cs_it) {
    cs.insert(*cs_it);
  }
  CAMLreturn(build_ocaml_constraint_system(cs));
}
CATCH_ALL

extern "C"
void
ppl_MIP_Problem_add_space_dimensions_and_embed(value caml_mip, value dim) try {
  CAMLparam2(caml_mip, dim);
  dimension_type ppl_dim = Int_val(dim);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  ppl_mip.add_space_dimensions_and_embed(ppl_dim);
  CAMLreturn0;
}
CATCH_ALL

extern "C"
void
ppl_MIP_Problem_add_to_integer_space_dimensions(value caml_mip,
						value caml_ivars) try {
  CAMLparam2(caml_mip, caml_ivars);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  ppl_mip.add_to_integer_space_dimensions(build_ppl_Variables_Set(caml_ivars));
  CAMLreturn0;
}
CATCH_ALL

extern "C"
void
ppl_MIP_Problem_add_constraint(value caml_mip,
			       value caml_constraint) try {
  CAMLparam2(caml_mip, caml_constraint);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  ppl_mip.add_constraint(build_ppl_Constraint(caml_constraint));
  CAMLreturn0;
}
CATCH_ALL

extern "C"
void
ppl_MIP_Problem_add_constraints(value caml_mip,
			       value caml_constraints) try {
  CAMLparam2(caml_mip, caml_constraints);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  ppl_mip.add_constraints(build_ppl_Constraint_System(caml_constraints));
  CAMLreturn0;
}
CATCH_ALL

extern "C"
void
ppl_MIP_Problem_set_objective_function(value caml_mip,
				       value caml_cost) try {
  CAMLparam2(caml_mip, caml_cost);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  ppl_mip.set_objective_function(build_ppl_Linear_Expression(caml_cost));
  CAMLreturn0;
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_MIP_Problem_is_satisfiable(value caml_mip) try {
  CAMLparam1(caml_mip);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  CAMLreturn(ppl_mip.is_satisfiable());
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_MIP_Problem_solve(value caml_mip) try {
  CAMLparam1(caml_mip);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  MIP_Problem_Status mip_status = ppl_mip.solve();
  switch (mip_status) {
  case UNFEASIBLE_MIP_PROBLEM:
    CAMLreturn(Val_int(0));
  case UNBOUNDED_MIP_PROBLEM:
    CAMLreturn(Val_int(1));
  case OPTIMIZED_MIP_PROBLEM:
    CAMLreturn(Val_int(2));
  default:
    ;
  }
  // We should not be here!
  throw std::runtime_error("PPL OCaml interface internal error");
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_MIP_Problem_optimization_mode(value caml_mip) try {
  CAMLparam1(caml_mip);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  Optimization_Mode opt_mode = ppl_mip.optimization_mode();
  switch (opt_mode) {
  case MINIMIZATION:
    CAMLreturn(Val_int(0));
  case MAXIMIZATION:
    CAMLreturn(Val_int(1));
  default:
    ;
  }
  // We should not be here!
  throw std::runtime_error("PPL OCaml interface internal error");
 }
CATCH_ALL

extern "C"
void
ppl_MIP_Problem_set_control_parameter(value caml_mip,
                                      value caml_cp_value) try {
  CAMLparam2(caml_mip, caml_cp_value);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  MIP_Problem::Control_Parameter_Value ppl_cp_value
    = build_ppl_control_parameter_value(caml_cp_value);
  ppl_mip.set_control_parameter(ppl_cp_value);
  CAMLreturn0;
 }
CATCH_ALL

extern "C"
CAMLprim value
ppl_MIP_Problem_get_control_parameter(value caml_mip,
                                      value caml_cp_name) try {
  CAMLparam2(caml_mip, caml_cp_name);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  MIP_Problem::Control_Parameter_Name ppl_cp_name
    = build_ppl_control_parameter_name(caml_cp_name);
  MIP_Problem::Control_Parameter_Value ppl_cp_value
    = ppl_mip.get_control_parameter(ppl_cp_name);
  switch (ppl_cp_value) {
  case MIP_Problem::PRICING_STEEPEST_EDGE_FLOAT:
    CAMLreturn(Val_int(0));
  case MIP_Problem::PRICING_STEEPEST_EDGE_EXACT:
    CAMLreturn(Val_int(1));
  case MIP_Problem::PRICING_TEXTBOOK:
    CAMLreturn(Val_int(2));
  default:
    ;
  }
  // We should not be here!
  throw std::runtime_error("PPL OCaml interface internal error");
 }
CATCH_ALL

extern "C"
CAMLprim value
ppl_MIP_Problem_feasible_point(value caml_mip) try {
  CAMLparam1(caml_mip);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  CAMLreturn(build_ocaml_generator(ppl_mip.feasible_point()));
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_MIP_Problem_optimizing_point(value caml_mip) try {
  CAMLparam1(caml_mip);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  CAMLreturn(build_ocaml_generator(ppl_mip.optimizing_point()));
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_MIP_Problem_optimal_value(value caml_mip) try {
  CAMLparam1(caml_mip);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  TEMP_INTEGER(num);
  TEMP_INTEGER(den);
  ppl_mip.optimal_value(num, den);
  value caml_return_value = caml_alloc(2,0);
  Field(caml_return_value, 0) = build_ocaml_coefficient(num);
  Field(caml_return_value, 1) = build_ocaml_coefficient(den);
  CAMLreturn(caml_return_value);

}
CATCH_ALL

extern "C"
CAMLprim value
ppl_MIP_Problem_evaluate_objective_function(value caml_mip,
					    value caml_generator) try {
  CAMLparam2(caml_mip, caml_generator);
  Generator g = build_ppl_Generator(caml_generator);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  TEMP_INTEGER(num);
  TEMP_INTEGER(den);
  ppl_mip.evaluate_objective_function(g, num, den);
  value caml_return_value = caml_alloc(2,0);
  Field(caml_return_value, 0) = build_ocaml_coefficient(num);
  Field(caml_return_value, 1) = build_ocaml_coefficient(den);
  CAMLreturn(caml_return_value);

}
CATCH_ALL

extern "C"
CAMLprim value
ppl_MIP_Problem_OK(value caml_mip) try {
  CAMLparam1(caml_mip);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  CAMLreturn(ppl_mip.OK());
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_MIP_Problem_objective_function
(value caml_mip) try {
  CAMLparam1(caml_mip);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  TEMP_INTEGER(inhomogeneous_term);
  inhomogeneous_term = ppl_mip.objective_function().inhomogeneous_term();
  value homogeneous_term = get_linear_expression(ppl_mip.objective_function());
  value inhom_term
    = build_ocaml_coefficient(ppl_mip.objective_function().inhomogeneous_term());
  value sum = caml_alloc(2,4);
  value coeff = caml_alloc(1,1);
  Field(coeff, 0) = inhom_term;
  Field(sum, 0) = homogeneous_term;
  Field(sum, 1) = coeff;
  CAMLreturn(sum);
}
CATCH_ALL

extern "C"
void
ppl_MIP_Problem_clear(value caml_mip) try {
  CAMLparam1(caml_mip);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  ppl_mip.clear();
  CAMLreturn0;
}
CATCH_ALL

extern "C"
void
ppl_MIP_Problem_set_optimization_mode(value caml_mip, value caml_opt_mode) try{
  CAMLparam2(caml_mip, caml_opt_mode);
  Optimization_Mode ppl_opt_mode= build_ppl_opt_mode(caml_opt_mode);
  MIP_Problem& ppl_mip = *p_MIP_Problem_val(caml_mip);
  ppl_mip.set_optimization_mode(ppl_opt_mode);
  CAMLreturn0;
}
CATCH_ALL

extern "C"
void
ppl_MIP_Problem_swap(value caml_mip1, value caml_mip2) try{
  CAMLparam2(caml_mip1, caml_mip2);
  MIP_Problem& ppl_mip1 = *p_MIP_Problem_val(caml_mip1);
  MIP_Problem& ppl_mip2 = *p_MIP_Problem_val(caml_mip2);
  ppl_mip1.swap(ppl_mip2);
  CAMLreturn0;
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_version_major(value unit) try {
  CAMLparam1(unit);
  CAMLreturn(Val_long(version_major()));
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_version_minor(value unit) try {
  CAMLparam1(unit);
  CAMLreturn(Val_long(version_minor()));
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_version_revision(value unit) try {
  CAMLparam1(unit);
  CAMLreturn(Val_long(version_revision()));
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_version_beta(value unit) try {
  CAMLparam1(unit);
  CAMLreturn(Val_long(version_beta()));
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_version(value unit) try {
  CAMLparam1(unit);
  CAMLreturn(caml_copy_string(version()));
}
CATCH_ALL

extern "C"
CAMLprim value
ppl_banner(value unit) try {
  CAMLparam1(unit);
  CAMLreturn(caml_copy_string(banner()));
}
CATCH_ALL

extern "C"
void
ppl_set_rounding_for_PPL(value unit) try {
  CAMLparam1(unit);
  set_rounding_for_PPL();
  CAMLreturn0;
}
CATCH_ALL


extern "C"
void
ppl_restore_pre_PPL_rounding(value unit) try {
  CAMLparam1(unit);
  restore_pre_PPL_rounding();
  CAMLreturn0;
}
CATCH_ALL
