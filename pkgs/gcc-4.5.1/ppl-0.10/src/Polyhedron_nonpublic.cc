/* Polyhedron class implementation
   (non-inline private or protected functions).
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

#include <ppl-config.h>

#include "Polyhedron.defs.hh"
#include "Scalar_Products.defs.hh"
#include <cassert>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

#ifdef PPL_DOXYGEN_INCLUDE_IMPLEMENTATION_DETAILS
/*! \ingroup PPL_defines
  \brief
  Controls the laziness level of the implementation.

  Temporarily used in a few of the function implementations to
  switch to an even more lazy algorithm. To be removed as soon as
  we collect enough information to decide which is the better
  implementation alternative.
*/
#endif // defined(PPL_DOXYGEN_INCLUDE_IMPLEMENTATION_DETAILS)
#define BE_LAZY 1

namespace PPL = Parma_Polyhedra_Library;

PPL::Polyhedron::Polyhedron(const Topology topol,
			    const dimension_type num_dimensions,
			    const Degenerate_Element kind)
  : con_sys(topol),
    gen_sys(topol),
    sat_c(),
    sat_g() {
  // Protecting against space dimension overflow is up to the caller.
  assert(num_dimensions <= max_space_dimension());

  if (kind == EMPTY)
    status.set_empty();
  else if (num_dimensions > 0) {
    con_sys.add_low_level_constraints();
    con_sys.adjust_topology_and_space_dimension(topol, num_dimensions);
    set_constraints_minimized();
  }
  space_dim = num_dimensions;
  assert(OK());
}

PPL::Polyhedron::Polyhedron(const Polyhedron& y, Complexity_Class)
  : con_sys(y.topology()),
    gen_sys(y.topology()),
    status(y.status),
    space_dim(y.space_dim) {
  // Being a protected method, we simply assert that topologies do match.
  assert(topology() == y.topology());
  if (y.constraints_are_up_to_date())
    con_sys.assign_with_pending(y.con_sys);
  if (y.generators_are_up_to_date())
    gen_sys.assign_with_pending(y.gen_sys);
  if (y.sat_c_is_up_to_date())
    sat_c = y.sat_c;
  if (y.sat_g_is_up_to_date())
    sat_g = y.sat_g;
}

PPL::Polyhedron::Polyhedron(const Topology topol, const Constraint_System& ccs)
  : con_sys(topol),
    gen_sys(topol),
    sat_c(),
    sat_g() {
  // Protecting against space dimension overflow is up to the caller.
  assert(ccs.space_dimension() <= max_space_dimension());

  // TODO: this implementation is just an executable specification.
  Constraint_System cs = ccs;

  // Try to adapt `cs' to the required topology.
  const dimension_type cs_space_dim = cs.space_dimension();
  if (!cs.adjust_topology_and_space_dimension(topol, cs_space_dim))
    throw_topology_incompatible((topol == NECESSARILY_CLOSED)
				? "C_Polyhedron(cs)"
				: "NNC_Polyhedron(cs)", "cs", cs);

  // Set the space dimension.
  space_dim = cs_space_dim;

  if (space_dim > 0) {
    // Stealing the rows from `cs'.
    std::swap(con_sys, cs);
    if (con_sys.num_pending_rows() > 0) {
      // Even though `cs' has pending constraints, since the generators
      // of the polyhedron are not up-to-date, the polyhedron cannot
      // have pending constraints. By integrating the pending part
      // of `con_sys' we may loose sortedness.
      con_sys.unset_pending_rows();
      con_sys.set_sorted(false);
    }
    con_sys.add_low_level_constraints();
    set_constraints_up_to_date();
  }
  else {
    // Here `space_dim == 0'.
    if (cs.num_columns() > 0)
      // See if an inconsistent constraint has been passed.
      for (dimension_type i = cs.num_rows(); i-- > 0; )
	if (cs[i].is_inconsistent()) {
	  // Inconsistent constraint found: the polyhedron is empty.
	  set_empty();
	  break;
	}
  }
  assert(OK());
}

PPL::Polyhedron::Polyhedron(const Topology topol,
			    Constraint_System& cs,
			    Recycle_Input)
  : con_sys(topol),
    gen_sys(topol),
    sat_c(),
    sat_g() {
  // Protecting against space dimension overflow is up to the caller.
  assert(cs.space_dimension() <= max_space_dimension());

  // Try to adapt `cs' to the required topology.
  const dimension_type cs_space_dim = cs.space_dimension();
  if (!cs.adjust_topology_and_space_dimension(topol, cs_space_dim))
    throw_topology_incompatible((topol == NECESSARILY_CLOSED)
				? "C_Polyhedron(cs, recycle)"
				: "NNC_Polyhedron(cs, recycle)", "cs", cs);

  // Set the space dimension.
  space_dim = cs_space_dim;

  if (space_dim > 0) {
    // Stealing the rows from `cs'.
    std::swap(con_sys, cs);
    if (con_sys.num_pending_rows() > 0) {
      // Even though `cs' has pending constraints, since the generators
      // of the polyhedron are not up-to-date, the polyhedron cannot
      // have pending constraints. By integrating the pending part
      // of `con_sys' we may loose sortedness.
      con_sys.unset_pending_rows();
      con_sys.set_sorted(false);
    }
    con_sys.add_low_level_constraints();
    set_constraints_up_to_date();
  }
  else {
    // Here `space_dim == 0'.
    if (cs.num_columns() > 0)
      // See if an inconsistent constraint has been passed.
      for (dimension_type i = cs.num_rows(); i-- > 0; )
	if (cs[i].is_inconsistent()) {
	  // Inconsistent constraint found: the polyhedron is empty.
	  set_empty();
	  break;
	}
  }
  assert(OK());
}

PPL::Polyhedron::Polyhedron(const Topology topol, const Generator_System& cgs)
  : con_sys(topol),
    gen_sys(topol),
    sat_c(),
    sat_g() {
  // Protecting against space dimension overflow is up to the caller.
  assert(cgs.space_dimension() <= max_space_dimension());

  // TODO: this implementation is just an executable specification.
  Generator_System gs = cgs;

  // An empty set of generators defines the empty polyhedron.
  if (gs.has_no_rows()) {
    space_dim = gs.space_dimension();
    status.set_empty();
    assert(OK());
    return;
  }

  // Non-empty valid generator systems have a supporting point, at least.
  if (!gs.has_points())
    throw_invalid_generators((topol == NECESSARILY_CLOSED)
			     ? "C_Polyhedron(gs)"
			     : "NNC_Polyhedron(gs)", "gs");

  const dimension_type gs_space_dim = gs.space_dimension();
  // Try to adapt `gs' to the required topology.
  if (!gs.adjust_topology_and_space_dimension(topol, gs_space_dim))
    throw_topology_incompatible((topol == NECESSARILY_CLOSED)
				? "C_Polyhedron(gs)"
				: "NNC_Polyhedron(gs)", "gs", gs);

  if (gs_space_dim > 0) {
    // Stealing the rows from `gs'.
    std::swap(gen_sys, gs);
    // In a generator system describing a NNC polyhedron,
    // for each point we must also have the corresponding closure point.
    if (topol == NOT_NECESSARILY_CLOSED)
      gen_sys.add_corresponding_closure_points();
    if (gen_sys.num_pending_rows() > 0) {
      // Even though `gs' has pending generators, since the constraints
      // of the polyhedron are not up-to-date, the polyhedron cannot
      // have pending generators. By integrating the pending part
      // of `gen_sys' we may loose sortedness.
      gen_sys.unset_pending_rows();
      gen_sys.set_sorted(false);
    }
    // Generators are now up-to-date.
    set_generators_up_to_date();

    // Set the space dimension.
    space_dim = gs_space_dim;
    assert(OK());
    return;
  }

  // Here `gs.num_rows > 0' and `gs_space_dim == 0':
  // we already checked for both the topology-compatibility
  // and the supporting point.
  space_dim = 0;
  assert(OK());
}

PPL::Polyhedron::Polyhedron(const Topology topol,
			    Generator_System& gs,
			    Recycle_Input)
  : con_sys(topol),
    gen_sys(topol),
    sat_c(),
    sat_g() {
  // Protecting against space dimension overflow is up to the caller.
  assert(gs.space_dimension() <= max_space_dimension());

  // An empty set of generators defines the empty polyhedron.
  if (gs.has_no_rows()) {
    space_dim = gs.space_dimension();
    status.set_empty();
    assert(OK());
    return;
  }

  // Non-empty valid generator systems have a supporting point, at least.
  if (!gs.has_points())
    throw_invalid_generators((topol == NECESSARILY_CLOSED)
			     ? "C_Polyhedron(gs, recycle)"
			     : "NNC_Polyhedron(gs, recycle)", "gs");

  const dimension_type gs_space_dim = gs.space_dimension();
  // Try to adapt `gs' to the required topology.
  if (!gs.adjust_topology_and_space_dimension(topol, gs_space_dim))
    throw_topology_incompatible((topol == NECESSARILY_CLOSED)
				? "C_Polyhedron(gs, recycle)"
				: "NNC_Polyhedron(gs, recycle)", "gs", gs);

  if (gs_space_dim > 0) {
    // Stealing the rows from `gs'.
    std::swap(gen_sys, gs);
    // In a generator system describing a NNC polyhedron,
    // for each point we must also have the corresponding closure point.
    if (topol == NOT_NECESSARILY_CLOSED)
      gen_sys.add_corresponding_closure_points();
    if (gen_sys.num_pending_rows() > 0) {
      // Even though `gs' has pending generators, since the constraints
      // of the polyhedron are not up-to-date, the polyhedron cannot
      // have pending generators. By integrating the pending part
      // of `gen_sys' we may loose sortedness.
      gen_sys.unset_pending_rows();
      gen_sys.set_sorted(false);
    }
    // Generators are now up-to-date.
    set_generators_up_to_date();

    // Set the space dimension.
    space_dim = gs_space_dim;
    assert(OK());
    return;
  }

  // Here `gs.num_rows > 0' and `gs_space_dim == 0':
  // we already checked for both the topology-compatibility
  // and the supporting point.
  space_dim = 0;
  assert(OK());
}

PPL::Polyhedron&
PPL::Polyhedron::operator=(const Polyhedron& y) {
  // Being a protected method, we simply assert that topologies do match.
  assert(topology() == y.topology());
  space_dim = y.space_dim;
  if (y.marked_empty())
    set_empty();
  else if (space_dim == 0)
    set_zero_dim_univ();
  else {
    status = y.status;
    if (y.constraints_are_up_to_date())
      con_sys.assign_with_pending(y.con_sys);
    if (y.generators_are_up_to_date())
      gen_sys.assign_with_pending(y.gen_sys);
    if (y.sat_c_is_up_to_date())
      sat_c = y.sat_c;
    if (y.sat_g_is_up_to_date())
      sat_g = y.sat_g;
  }
  return *this;
}

PPL::Polyhedron::Three_Valued_Boolean
PPL::Polyhedron::quick_equivalence_test(const Polyhedron& y) const {
  // Private method: the caller must ensure the following.
  assert(topology() == y.topology());
  assert(space_dim == y.space_dim);
  assert(!marked_empty() && !y.marked_empty() && space_dim > 0);

  const Polyhedron& x = *this;

  if (x.is_necessarily_closed()) {
    if (!x.has_something_pending() && !y.has_something_pending()) {
      bool css_normalized = false;
      if (x.constraints_are_minimized() && y.constraints_are_minimized()) {
	// Equivalent minimized constraint systems have:
	//  - the same number of constraints; ...
	if (x.con_sys.num_rows() != y.con_sys.num_rows())
	  return Polyhedron::TVB_FALSE;
	//  - the same number of equalities; ...
	dimension_type x_num_equalities = x.con_sys.num_equalities();
	if (x_num_equalities != y.con_sys.num_equalities())
	  return Polyhedron::TVB_FALSE;
	//  - if there are no equalities, they have the same constraints.
	//    Delay this test: try cheaper tests on generators first.
	css_normalized = (x_num_equalities == 0);
      }

      if (x.generators_are_minimized() && y.generators_are_minimized()) {
	// Equivalent minimized generator systems have:
	//  - the same number of generators; ...
	if (x.gen_sys.num_rows() != y.gen_sys.num_rows())
	  return Polyhedron::TVB_FALSE;
	//  - the same number of lines; ...
	const dimension_type x_num_lines = x.gen_sys.num_lines();
	if (x_num_lines != y.gen_sys.num_lines())
	  return Polyhedron::TVB_FALSE;
	//  - if there are no lines, they have the same generators.
	if (x_num_lines == 0) {
	  // Sort the two systems and check for syntactic identity.
	  x.obtain_sorted_generators();
	  y.obtain_sorted_generators();
	  if (x.gen_sys == y.gen_sys)
	    return Polyhedron::TVB_TRUE;
	  else
	    return Polyhedron::TVB_FALSE;
	}
      }

      if (css_normalized) {
	// Sort the two systems and check for identity.
	x.obtain_sorted_constraints();
	y.obtain_sorted_constraints();
	if (x.con_sys == y.con_sys)
	    return Polyhedron::TVB_TRUE;
	  else
	    return Polyhedron::TVB_FALSE;
      }
    }
  }
  return Polyhedron::TVB_DONT_KNOW;
}

bool
PPL::Polyhedron::is_included_in(const Polyhedron& y) const {
  // Private method: the caller must ensure the following.
  assert(topology() == y.topology());
  assert(space_dim == y.space_dim);
  assert(!marked_empty() && !y.marked_empty() && space_dim > 0);

  const Polyhedron& x = *this;

  // `x' cannot have pending constraints, because we need its generators.
  if (x.has_pending_constraints() && !x.process_pending_constraints())
    return true;
  // `y' cannot have pending generators, because we need its constraints.
  if (y.has_pending_generators())
    y.process_pending_generators();

#if BE_LAZY
  if (!x.generators_are_up_to_date() && !x.update_generators())
    return true;
  if (!y.constraints_are_up_to_date())
    y.update_constraints();
#else
  if (!x.generators_are_minimized())
    x.minimize();
  if (!y.constraints_are_minimized())
    y.minimize();
#endif

  assert(x.OK());
  assert(y.OK());

  const Generator_System& gs = x.gen_sys;
  const Constraint_System& cs = y.con_sys;

  if (x.is_necessarily_closed())
    // When working with necessarily closed polyhedra,
    // `x' is contained in `y' if and only if all the generators of `x'
    // satisfy all the inequalities and saturate all the equalities of `y'.
    // This comes from the definition of a polyhedron as the set of
    // vectors satisfying a constraint system and the fact that all
    // vectors in `x' can be obtained by suitably combining its generators.
    for (dimension_type i = cs.num_rows(); i-- > 0; ) {
      const Constraint& c = cs[i];
      if (c.is_inequality()) {
	for (dimension_type j = gs.num_rows(); j-- > 0; ) {
	  const Generator& g = gs[j];
	  const int sp_sign = Scalar_Products::sign(c, g);
	  if (g.is_line()) {
	    if (sp_sign != 0)
	      return false;
	  }
	  else
	    // `g' is a ray or a point.
	    if (sp_sign < 0)
	      return false;
	}
      }
      else {
	// `c' is an equality.
	for (dimension_type j = gs.num_rows(); j-- > 0; )
	  if (Scalar_Products::sign(c, gs[j]) != 0)
	    return false;
      }
    }
  else {
    // Here we have an NNC polyhedron: using the reduced scalar product,
    // which ignores the epsilon coefficient.
    for (dimension_type i = cs.num_rows(); i-- > 0; ) {
      const Constraint& c = cs[i];
      switch (c.type()) {
      case Constraint::NONSTRICT_INEQUALITY:
	for (dimension_type j = gs.num_rows(); j-- > 0; ) {
	  const Generator& g = gs[j];
	  const int sp_sign = Scalar_Products::reduced_sign(c, g);
	  if (g.is_line()) {
	    if (sp_sign != 0)
	      return false;
	  }
	  else
	    // `g' is a ray or a point or a closure point.
	    if (sp_sign < 0)
	      return false;
	}
	break;
      case Constraint::EQUALITY:
	for (dimension_type j = gs.num_rows(); j-- > 0; )
	  if (Scalar_Products::reduced_sign(c, gs[j]) != 0)
	    return false;
	break;
      case Constraint::STRICT_INEQUALITY:
	for (dimension_type j = gs.num_rows(); j-- > 0; ) {
	  const Generator& g = gs[j];
	  const int sp_sign = Scalar_Products::reduced_sign(c, g);
	  switch (g.type()) {
	  case Generator::POINT:
	    // If a point violates or saturates a strict inequality
	    // (when ignoring the epsilon coefficients) then it is
	    // not included in the polyhedron.
	    if (sp_sign <= 0)
	      return false;
	    break;
	  case Generator::LINE:
	    // Lines have to saturate all constraints.
	    if (sp_sign != 0)
	      return false;
	    break;
	  case Generator::RAY:
	    // Intentionally fall through.
	  case Generator::CLOSURE_POINT:
	    // The generator is a ray or closure point: usual test.
	    if (sp_sign < 0)
	      return false;
	    break;
	  }
	}
	break;
      }
    }
  }

  // Inclusion holds.
  return true;
}

bool
PPL::Polyhedron::bounds(const Linear_Expression& expr,
			const bool from_above) const {
  // The dimension of `expr' should not be greater than the dimension
  // of `*this'.
  const dimension_type expr_space_dim = expr.space_dimension();
  if (space_dim < expr_space_dim)
    throw_dimension_incompatible((from_above
				  ? "bounds_from_above(e)"
				  : "bounds_from_below(e)"), "e", expr);

  // A zero-dimensional or empty polyhedron bounds everything.
  if (space_dim == 0
      || marked_empty()
      || (has_pending_constraints() && !process_pending_constraints())
      || (!generators_are_up_to_date() && !update_generators()))
    return true;

  // The polyhedron has updated, possibly pending generators.
  for (dimension_type i = gen_sys.num_rows(); i-- > 0; ) {
    const Generator& g = gen_sys[i];
    // Only lines and rays in `*this' can cause `expr' to be unbounded.
    if (g.is_line_or_ray()) {
      const int sp_sign = Scalar_Products::homogeneous_sign(expr, g);
      if (sp_sign != 0
	  && (g.is_line()
	      || (from_above && sp_sign > 0)
	      || (!from_above && sp_sign < 0)))
	// `*this' does not bound `expr'.
	return false;
    }
  }
  // No sources of unboundedness have been found for `expr'
  // in the given direction.
  return true;
}

bool
PPL::Polyhedron::max_min(const Linear_Expression& expr,
			 const bool maximize,
			 Coefficient& ext_n, Coefficient& ext_d,
			 bool& included,
			 Generator& g) const {
  // The dimension of `expr' should not be greater than the dimension
  // of `*this'.
  const dimension_type expr_space_dim = expr.space_dimension();
  if (space_dim < expr_space_dim)
    throw_dimension_incompatible((maximize
				  ? "maximize(e, ...)"
				  : "minimize(e, ...)"), "e", expr);

  // Deal with zero-dim polyhedra first.
  if (space_dim == 0) {
    if (marked_empty())
      return false;
    else {
      ext_n = expr.inhomogeneous_term();
      ext_d = 1;
      included = true;
      g = point();
      return true;
    }
  }

  // For an empty polyhedron we simply return false.
  if (marked_empty()
      || (has_pending_constraints() && !process_pending_constraints())
      || (!generators_are_up_to_date() && !update_generators()))
    return false;

  // The polyhedron has updated, possibly pending generators.
  // The following loop will iterate through the generator
  // to find the extremum.
  DIRTY_TEMP0(mpq_class, extremum);

  // True if we have no other candidate extremum to compare with.
  bool first_candidate = true;

  // To store the position of the current candidate extremum.
  PPL_UNINITIALIZED(dimension_type, ext_position);

  // Whether the current candidate extremum is included or not.
  PPL_UNINITIALIZED(bool, ext_included);

  TEMP_INTEGER(sp);
  for (dimension_type i = gen_sys.num_rows(); i-- > 0; ) {
    const Generator& gen_sys_i = gen_sys[i];
    Scalar_Products::homogeneous_assign(sp, expr, gen_sys_i);
    // Lines and rays in `*this' can cause `expr' to be unbounded.
    if (gen_sys_i.is_line_or_ray()) {
      const int sp_sign = sgn(sp);
      if (sp_sign != 0
	  && (gen_sys_i.is_line()
	      || (maximize && sp_sign > 0)
	      || (!maximize && sp_sign < 0)))
	// `expr' is unbounded in `*this'.
	return false;
    }
    else {
      // We have a point or a closure point.
      assert(gen_sys_i.is_point() || gen_sys_i.is_closure_point());
      // Notice that we are ignoring the constant term in `expr' here.
      // We will add it to the extremum as soon as we find it.
      DIRTY_TEMP0(mpq_class, candidate);
      assign_r(candidate.get_num(), sp, ROUND_NOT_NEEDED);
      assign_r(candidate.get_den(), gen_sys_i[0], ROUND_NOT_NEEDED);
      candidate.canonicalize();
      const bool g_is_point = gen_sys_i.is_point();
      if (first_candidate
	  || (maximize
	      && (candidate > extremum
		  || (g_is_point
		      && !ext_included
		      && candidate == extremum)))
	  || (!maximize
	      && (candidate < extremum
		  || (g_is_point
		      && !ext_included
		      && candidate == extremum)))) {
	// We have a (new) candidate extremum.
	first_candidate = false;
	extremum = candidate;
	ext_position = i;
	ext_included = g_is_point;
      }
    }
  }

  // Add in the constant term in `expr'.
  DIRTY_TEMP0(mpz_class, n);
  assign_r(n, expr.inhomogeneous_term(), ROUND_NOT_NEEDED);
  extremum += n;

  // The polyhedron is bounded in the right direction and we have
  // computed the extremum: write the result into the caller's structures.
  assert(!first_candidate);
  ext_n = Coefficient(extremum.get_num());
  ext_d = Coefficient(extremum.get_den());
  included = ext_included;
  g = gen_sys[ext_position];

  return true;
}

void
PPL::Polyhedron::set_zero_dim_univ() {
  status.set_zero_dim_univ();
  space_dim = 0;
  con_sys.clear();
  gen_sys.clear();
}

void
PPL::Polyhedron::set_empty() {
  status.set_empty();
  // The polyhedron is empty: we can thus throw away everything.
  con_sys.clear();
  gen_sys.clear();
  sat_c.clear();
  sat_g.clear();
}

bool
PPL::Polyhedron::process_pending_constraints() const {
  assert(space_dim > 0 && !marked_empty());
  assert(has_pending_constraints() && !has_pending_generators());

  Polyhedron& x = const_cast<Polyhedron&>(*this);

  // Integrate the pending part of the system of constraints and minimize.
  // We need `sat_c' up-to-date and `con_sys' sorted (together with `sat_c').
  if (!x.sat_c_is_up_to_date())
    x.sat_c.transpose_assign(x.sat_g);
  if (!x.con_sys.is_sorted())
    x.obtain_sorted_constraints_with_sat_c();
  // We sort in place the pending constraints, erasing those constraints
  // that also occur in the non-pending part of `con_sys'.
  x.con_sys.sort_pending_and_remove_duplicates();
  if (x.con_sys.num_pending_rows() == 0) {
    // All pending constraints were duplicates.
    x.clear_pending_constraints();
    assert(OK(true));
    return true;
  }

  const bool empty = add_and_minimize(true, x.con_sys, x.gen_sys, x.sat_c);
  assert(x.con_sys.num_pending_rows() == 0);

  if (empty)
    x.set_empty();
  else {
    x.clear_pending_constraints();
    x.clear_sat_g_up_to_date();
    x.set_sat_c_up_to_date();
  }
  assert(OK(!empty));
  return !empty;
}

void
PPL::Polyhedron::process_pending_generators() const {
  assert(space_dim > 0 && !marked_empty());
  assert(has_pending_generators() && !has_pending_constraints());

  Polyhedron& x = const_cast<Polyhedron&>(*this);

  // Integrate the pending part of the system of generators and minimize.
  // We need `sat_g' up-to-date and `gen_sys' sorted (together with `sat_g').
  if (!x.sat_g_is_up_to_date())
    x.sat_g.transpose_assign(x.sat_c);
  if (!x.gen_sys.is_sorted())
    x.obtain_sorted_generators_with_sat_g();
  // We sort in place the pending generators, erasing those generators
  // that also occur in the non-pending part of `gen_sys'.
  x.gen_sys.sort_pending_and_remove_duplicates();
  if (x.gen_sys.num_pending_rows() == 0) {
    // All pending generators were duplicates.
    x.clear_pending_generators();
    assert(OK(true));
    return;
  }

  add_and_minimize(false, x.gen_sys, x.con_sys, x.sat_g);
  assert(x.gen_sys.num_pending_rows() == 0);

  x.clear_pending_generators();
  x.clear_sat_c_up_to_date();
  x.set_sat_g_up_to_date();
}

void
PPL::Polyhedron::remove_pending_to_obtain_constraints() const {
  assert(has_something_pending());

  Polyhedron& x = const_cast<Polyhedron&>(*this);

  // If the polyhedron has pending constraints, simply unset them.
  if (x.has_pending_constraints()) {
    // Integrate the pending constraints, which are possibly not sorted.
    x.con_sys.unset_pending_rows();
    x.con_sys.set_sorted(false);
    x.clear_pending_constraints();
    x.clear_constraints_minimized();
    x.clear_generators_up_to_date();
  }
  else {
    assert(x.has_pending_generators());
    // We must process the pending generators and obtain the
    // corresponding system of constraints.
    x.process_pending_generators();
  }
  assert(OK(true));
}

bool
PPL::Polyhedron::remove_pending_to_obtain_generators() const {
  assert(has_something_pending());

  Polyhedron& x = const_cast<Polyhedron&>(*this);

  // If the polyhedron has pending generators, simply unset them.
  if (x.has_pending_generators()) {
    // Integrate the pending generators, which are possibly not sorted.
    x.gen_sys.unset_pending_rows();
    x.gen_sys.set_sorted(false);
    x.clear_pending_generators();
    x.clear_generators_minimized();
    x.clear_constraints_up_to_date();
    assert(OK(true));
    return true;
  }
  else {
    assert(x.has_pending_constraints());
    // We must integrate the pending constraints and obtain the
    // corresponding system of generators.
    return x.process_pending_constraints();
  }
}

void
PPL::Polyhedron::update_constraints() const {
  assert(space_dim > 0);
  assert(!marked_empty());
  assert(generators_are_up_to_date());
  // We assume the polyhedron has no pending constraints or generators.
  assert(!has_something_pending());

  Polyhedron& x = const_cast<Polyhedron&>(*this);
  minimize(false, x.gen_sys, x.con_sys, x.sat_c);
  // `sat_c' is the only saturation matrix up-to-date.
  x.set_sat_c_up_to_date();
  x.clear_sat_g_up_to_date();
  // The system of constraints and the system of generators
  // are minimized.
  x.set_constraints_minimized();
  x.set_generators_minimized();
}

bool
PPL::Polyhedron::update_generators() const {
  assert(space_dim > 0);
  assert(!marked_empty());
  assert(constraints_are_up_to_date());
  // We assume the polyhedron has no pending constraints or generators.
  assert(!has_something_pending());

  Polyhedron& x = const_cast<Polyhedron&>(*this);
  // If the system of constraints is not consistent the
  // polyhedron is empty.
  const bool empty = minimize(true, x.con_sys, x.gen_sys, x.sat_g);
  if (empty)
    x.set_empty();
  else {
    // `sat_g' is the only saturation matrix up-to-date.
    x.set_sat_g_up_to_date();
    x.clear_sat_c_up_to_date();
    // The system of constraints and the system of generators
    // are minimized.
    x.set_constraints_minimized();
    x.set_generators_minimized();
  }
  return !empty;
}

void
PPL::Polyhedron::update_sat_c() const {
  assert(constraints_are_minimized());
  assert(generators_are_minimized());
  assert(!sat_c_is_up_to_date());

  // We only consider non-pending rows.
  const dimension_type csr = con_sys.first_pending_row();
  const dimension_type gsr = gen_sys.first_pending_row();
  Polyhedron& x = const_cast<Polyhedron&>(*this);

  // The columns of `sat_c' represent the constraints and
  // its rows represent the generators: resize accordingly.
  x.sat_c.resize(gsr, csr);
  for (dimension_type i = gsr; i-- > 0; )
    for (dimension_type j = csr; j-- > 0; ) {
      const int sp_sign = Scalar_Products::sign(con_sys[j], gen_sys[i]);
      // The negativity of this scalar product would mean
      // that the generator `gen_sys[i]' violates the constraint
      // `con_sys[j]' and it is not possible because both generators
      // and constraints are up-to-date.
      assert(sp_sign >= 0);
      if (sp_sign > 0)
	// `gen_sys[i]' satisfies (without saturate) `con_sys[j]'.
	x.sat_c[i].set(j);
      else
	// `gen_sys[i]' saturates `con_sys[j]'.
	x.sat_c[i].clear(j);
    }
  x.set_sat_c_up_to_date();
}

void
PPL::Polyhedron::update_sat_g() const {
  assert(constraints_are_minimized());
  assert(generators_are_minimized());
  assert(!sat_g_is_up_to_date());

  // We only consider non-pending rows.
  const dimension_type csr = con_sys.first_pending_row();
  const dimension_type gsr = gen_sys.first_pending_row();
  Polyhedron& x = const_cast<Polyhedron&>(*this);

  // The columns of `sat_g' represent generators and its
  // rows represent the constraints: resize accordingly.
  x.sat_g.resize(csr, gsr);
  for (dimension_type i = csr; i-- > 0; )
    for (dimension_type j = gsr; j-- > 0; ) {
      const int sp_sign = Scalar_Products::sign(con_sys[i], gen_sys[j]);
      // The negativity of this scalar product would mean
      // that the generator `gen_sys[j]' violates the constraint
      // `con_sys[i]' and it is not possible because both generators
      // and constraints are up-to-date.
      assert(sp_sign >= 0);
      if (sp_sign > 0)
	// `gen_sys[j]' satisfies (without saturate) `con_sys[i]'.
	x.sat_g[i].set(j);
      else
	// `gen_sys[j]' saturates `con_sys[i]'.
	x.sat_g[i].clear(j);
    }
  x.set_sat_g_up_to_date();
}

void
PPL::Polyhedron::obtain_sorted_constraints() const {
  assert(constraints_are_up_to_date());
  // `con_sys' will be sorted up to `index_first_pending'.
  Polyhedron& x = const_cast<Polyhedron&>(*this);
  if (!x.con_sys.is_sorted()) {
    if (x.sat_g_is_up_to_date()) {
      // Sorting constraints keeping `sat_g' consistent.
      x.con_sys.sort_and_remove_with_sat(x.sat_g);
      // `sat_c' is not up-to-date anymore.
      x.clear_sat_c_up_to_date();
    }
    else if (x.sat_c_is_up_to_date()) {
      // Using `sat_c' to obtain `sat_g', then it is like previous case.
      x.sat_g.transpose_assign(x.sat_c);
      x.con_sys.sort_and_remove_with_sat(x.sat_g);
      x.set_sat_g_up_to_date();
      x.clear_sat_c_up_to_date();
    }
    else
      // If neither `sat_g' nor `sat_c' are up-to-date,
      // we just sort the constraints.
      x.con_sys.sort_rows();
  }

  assert(con_sys.check_sorted());
}

void
PPL::Polyhedron::obtain_sorted_generators() const {
  assert(generators_are_up_to_date());
  // `gen_sys' will be sorted up to `index_first_pending'.
  Polyhedron& x = const_cast<Polyhedron&>(*this);
  if (!x.gen_sys.is_sorted()) {
    if (x.sat_c_is_up_to_date()) {
      // Sorting generators keeping 'sat_c' consistent.
      x.gen_sys.sort_and_remove_with_sat(x.sat_c);
      // `sat_g' is not up-to-date anymore.
      x.clear_sat_g_up_to_date();
    }
    else if (x.sat_g_is_up_to_date()) {
      // Obtaining `sat_c' from `sat_g' and proceeding like previous case.
      x.sat_c.transpose_assign(x.sat_g);
      x.gen_sys.sort_and_remove_with_sat(x.sat_c);
      x.set_sat_c_up_to_date();
      x.clear_sat_g_up_to_date();
    }
    else
      // If neither `sat_g' nor `sat_c' are up-to-date, we just sort
      // the generators.
      x.gen_sys.sort_rows();
  }

  assert(gen_sys.check_sorted());
}

void
PPL::Polyhedron::obtain_sorted_constraints_with_sat_c() const {
  assert(constraints_are_up_to_date());
  assert(constraints_are_minimized());
  // `con_sys' will be sorted up to `index_first_pending'.
  Polyhedron& x = const_cast<Polyhedron&>(*this);
  // At least one of the saturation matrices must be up-to-date.
  if (!x.sat_c_is_up_to_date() && !x.sat_g_is_up_to_date())
    x.update_sat_c();

  if (x.con_sys.is_sorted()) {
    if (x.sat_c_is_up_to_date())
      // If constraints are already sorted and sat_c is up to
      // date there is nothing to do.
      return;
  }
  else {
    if (!x.sat_g_is_up_to_date()) {
      // If constraints are not sorted and sat_g is not up-to-date
      // we obtain sat_g from sat_c (that has to be up-to-date)...
      x.sat_g.transpose_assign(x.sat_c);
      x.set_sat_g_up_to_date();
    }
    // ... and sort it together with constraints.
    x.con_sys.sort_and_remove_with_sat(x.sat_g);
  }
  // Obtaining sat_c from sat_g.
  x.sat_c.transpose_assign(x.sat_g);
  x.set_sat_c_up_to_date();
  // Constraints are sorted now.
  x.con_sys.set_sorted(true);

  assert(con_sys.check_sorted());
}

void
PPL::Polyhedron::obtain_sorted_generators_with_sat_g() const {
  assert(generators_are_up_to_date());
  // `gen_sys' will be sorted up to `index_first_pending'.
  Polyhedron& x = const_cast<Polyhedron&>(*this);
  // At least one of the saturation matrices must be up-to-date.
  if (!x.sat_c_is_up_to_date() && !x.sat_g_is_up_to_date())
    x.update_sat_g();

  if (x.gen_sys.is_sorted()) {
    if (x.sat_g_is_up_to_date())
      // If generators are already sorted and sat_g is up to
      // date there is nothing to do.
      return;
  }
  else {
    if (!x.sat_c_is_up_to_date()) {
      // If generators are not sorted and sat_c is not up-to-date
      // we obtain sat_c from sat_g (that has to be up-to-date)...
      x.sat_c.transpose_assign(x.sat_g);
      x.set_sat_c_up_to_date();
    }
    // ... and sort it together with generators.
    x.gen_sys.sort_and_remove_with_sat(x.sat_c);
  }
  // Obtaining sat_g from sat_c.
  x.sat_g.transpose_assign(sat_c);
  x.set_sat_g_up_to_date();
  // Generators are sorted now.
  x.gen_sys.set_sorted(true);

  assert(gen_sys.check_sorted());
}

bool
PPL::Polyhedron::minimize() const {
  // 0-dim space or empty polyhedra are already minimized.
  if (marked_empty())
    return false;
  if (space_dim == 0)
    return true;

  // If the polyhedron has something pending, process it.
  if (has_something_pending()) {
    const bool not_empty = process_pending();
    assert(OK());
    return not_empty;
  }

  // Here there are no pending constraints or generators.
  // Is the polyhedron already minimized?
  if (constraints_are_minimized() && generators_are_minimized())
    return true;

  // If constraints or generators are up-to-date, invoking
  // update_generators() or update_constraints(), respectively,
  // minimizes both constraints and generators.
  // If both are up-to-date it does not matter whether we use
  // update_generators() or update_constraints():
  // both minimize constraints and generators.
  if (constraints_are_up_to_date()) {
    // We may discover here that `*this' is empty.
    const bool ret = update_generators();
    assert(OK());
    return ret;
  }
  else {
    assert(generators_are_up_to_date());
    update_constraints();
    assert(OK());
    return true;
  }
}

bool
PPL::Polyhedron::strongly_minimize_constraints() const {
  assert(!is_necessarily_closed());

  // From the user perspective, the polyhedron will not change.
  Polyhedron& x = const_cast<Polyhedron&>(*this);

  // We need `con_sys' (weakly) minimized and `gen_sys' up-to-date.
  // `minimize()' will process any pending constraints or generators.
  if (!minimize())
    return false;

  // If the polyhedron `*this' is zero-dimensional
  // at this point it must be a universe polyhedron.
  if (x.space_dim == 0)
    return true;

  // We also need `sat_g' up-to-date.
  if (!sat_g_is_up_to_date()) {
    assert(sat_c_is_up_to_date());
    x.sat_g.transpose_assign(sat_c);
  }

  // These Bit_Row's will be later used as masks in order to
  // check saturation conditions restricted to particular subsets of
  // the generator system.
  Bit_Row sat_all_but_rays;
  Bit_Row sat_all_but_points;
  Bit_Row sat_all_but_closure_points;

  const dimension_type gs_rows = gen_sys.num_rows();
  const dimension_type n_lines = gen_sys.num_lines();
  for (dimension_type i = gs_rows; i-- > n_lines; )
    switch (gen_sys[i].type()) {
    case Generator::RAY:
      sat_all_but_rays.set(i);
      break;
    case Generator::POINT:
      sat_all_but_points.set(i);
      break;
    case Generator::CLOSURE_POINT:
      sat_all_but_closure_points.set(i);
      break;
    default:
      // Found a line with index i >= n_lines.
      throw std::runtime_error("PPL internal error: "
			       "strongly_minimize_constraints.");
    }
  Bit_Row sat_lines_and_rays;
  set_union(sat_all_but_points, sat_all_but_closure_points,
	    sat_lines_and_rays);
  Bit_Row sat_lines_and_closure_points;
  set_union(sat_all_but_rays, sat_all_but_points,
	    sat_lines_and_closure_points);
  Bit_Row sat_lines;
  set_union(sat_lines_and_rays, sat_lines_and_closure_points,
	    sat_lines);

  // These flags are maintained to later decide if we have to add the
  // eps_leq_one constraint and whether or not the constraint system
  // was changed.
  bool changed = false;
  bool found_eps_leq_one = false;

  // For all the strict inequalities in `con_sys', check for
  // eps-redundancy and eventually move them to the bottom part of the
  // system.
  Constraint_System& cs = x.con_sys;
  Bit_Matrix& sat = x.sat_g;
  dimension_type cs_rows = cs.num_rows();
  const dimension_type eps_index = cs.num_columns() - 1;
  for (dimension_type i = 0; i < cs_rows; )
    if (cs[i].is_strict_inequality()) {
      // First, check if it is saturated by no closure points
      Bit_Row sat_ci;
      set_union(sat[i], sat_lines_and_closure_points, sat_ci);
      if (sat_ci == sat_lines) {
	// It is saturated by no closure points.
	if (!found_eps_leq_one) {
	  // Check if it is the eps_leq_one constraint.
	  const Constraint& c = cs[i];
	  bool all_zeroes = true;
	  for (dimension_type k = eps_index; k-- > 1; )
	    if (c[k] != 0) {
	      all_zeroes = false;
	      break;
	    }
	  if (all_zeroes && (c[0] + c[eps_index] == 0)) {
	    // We found the eps_leq_one constraint.
	    found_eps_leq_one = true;
	    // Consider next constraint.
	    ++i;
	    continue;
	  }
	}
	// Here `cs[i]' is not the eps_leq_one constraint,
	// so it is eps-redundant.
	// Move it to the bottom of the constraint system,
	// while keeping `sat_g' consistent.
	--cs_rows;
	std::swap(cs[i], cs[cs_rows]);
	std::swap(sat[i], sat[cs_rows]);
	// The constraint system is changed.
	changed = true;
	// Continue by considering next constraint,
	// which is already in place due to the swap.
	continue;
      }
      // Now we check if there exists another strict inequality
      // constraint having a superset of its saturators,
      // when disregarding points.
      sat_ci.clear();
      set_union(sat[i], sat_all_but_points, sat_ci);
      bool eps_redundant = false;
      for (dimension_type j = 0; j < cs_rows; ++j)
	if (i != j && cs[j].is_strict_inequality()
	    && subset_or_equal(sat[j], sat_ci)) {
	  // Constraint `cs[i]' is eps-redundant:
	  // move it to the bottom of the constraint system,
	  // while keeping `sat_g' consistent.
	  --cs_rows;
	  std::swap(cs[i], cs[cs_rows]);
	  std::swap(sat[i], sat[cs_rows]);
	  eps_redundant = true;
	  // The constraint system is changed.
	  changed = true;
	  break;
	}
      // Continue with next constraint, which is already in place
      // due to the swap if we have found an eps-redundant constraint.
      if (!eps_redundant)
	++i;
    }
    else
      // `cs[i]' is not a strict inequality: consider next constraint.
      ++i;

  if (changed) {
    // If the constraint system has been changed, we have to erase
    // the epsilon-redundant constraints.
    assert(cs_rows < cs.num_rows());
    cs.erase_to_end(cs_rows);
    // The remaining constraints are not pending.
    cs.unset_pending_rows();
    // The constraint system is no longer sorted.
    cs.set_sorted(false);
    // The generator system is no longer up-to-date.
    x.clear_generators_up_to_date();

    // If we haven't found an upper bound for the epsilon dimension,
    // then we have to check whether such an upper bound is implied
    // by the remaining constraints (exploiting the simplex algorithm).
    if (!found_eps_leq_one) {
      MIP_Problem lp;
      // KLUDGE: temporarily mark the constraint system as if it was
      // necessarily closed, so that we can interpret the epsilon
      // dimension as a standard dimension. Be careful to reset the
      // topology of `cs' even on exceptional execution path.
      cs.set_necessarily_closed();
      try {
	lp.add_space_dimensions_and_embed(cs.space_dimension());
	lp.add_constraints(cs);
	cs.set_not_necessarily_closed();
      }
      catch (...) {
	cs.set_not_necessarily_closed();
	throw;
      }
      // The objective function is `epsilon'.
      lp.set_objective_function(Variable(x.space_dim));
      lp.set_optimization_mode(MAXIMIZATION);
      MIP_Problem_Status status = lp.solve();
      assert(status != UNFEASIBLE_MIP_PROBLEM);
      // If the epsilon dimension is actually unbounded,
      // then add the eps_leq_one constraint.
      if (status == UNBOUNDED_MIP_PROBLEM)
	cs.insert(Constraint::epsilon_leq_one());
    }
  }

  assert(OK());
  return true;
}

bool
PPL::Polyhedron::strongly_minimize_generators() const {
  assert(!is_necessarily_closed());

  // From the user perspective, the polyhedron will not change.
  Polyhedron& x = const_cast<Polyhedron&>(*this);

  // We need `gen_sys' (weakly) minimized and `con_sys' up-to-date.
  // `minimize()' will process any pending constraints or generators.
  if (!minimize())
    return false;

  // If the polyhedron `*this' is zero-dimensional
  // at this point it must be a universe polyhedron.
  if (x.space_dim == 0)
    return true;

  // We also need `sat_c' up-to-date.
  if (!sat_c_is_up_to_date()) {
    assert(sat_g_is_up_to_date());
    x.sat_c.transpose_assign(sat_g);
  }

  // This Bit_Row will have all and only the indexes
  // of strict inequalities set to 1.
  Bit_Row sat_all_but_strict_ineq;
  const dimension_type cs_rows = con_sys.num_rows();
  const dimension_type n_equals = con_sys.num_equalities();
  for (dimension_type i = cs_rows; i-- > n_equals; )
    if (con_sys[i].is_strict_inequality())
      sat_all_but_strict_ineq.set(i);

  // Will record whether or not we changed the generator system.
  bool changed = false;

  // For all points in the generator system, check for eps-redundancy
  // and eventually move them to the bottom part of the system.
  Generator_System& gs = const_cast<Generator_System&>(gen_sys);
  Bit_Matrix& sat = const_cast<Bit_Matrix&>(sat_c);
  dimension_type gs_rows = gs.num_rows();
  const dimension_type n_lines = gs.num_lines();
  const dimension_type eps_index = gs.num_columns() - 1;
  for (dimension_type i = n_lines; i < gs_rows; )
    if (gs[i].is_point()) {
      // Compute the Bit_Row corresponding to the candidate point
      // when strict inequality constraints are ignored.
      Bit_Row sat_gi;
      set_union(sat[i], sat_all_but_strict_ineq, sat_gi);
      // Check if the candidate point is actually eps-redundant:
      // namely, if there exists another point that saturates
      // all the non-strict inequalities saturated by the candidate.
      bool eps_redundant = false;
      for (dimension_type j = n_lines; j < gs_rows; ++j)
	if (i != j && gs[j].is_point() && subset_or_equal(sat[j], sat_gi)) {
	  // Point `gs[i]' is eps-redundant:
	  // move it to the bottom of the generator system,
	  // while keeping `sat_c' consistent.
	  --gs_rows;
	  std::swap(gs[i], gs[gs_rows]);
	  std::swap(sat[i], sat[gs_rows]);
	  eps_redundant = true;
	  changed = true;
	  break;
	}
      if (!eps_redundant) {
	// Let all point encodings have epsilon coordinate 1.
	Generator& gi = gs[i];
	if (gi[eps_index] != gi[0]) {
	  gi[eps_index] = gi[0];
	  // Enforce normalization.
	  gi.normalize();
	  changed = true;
	}
	// Consider next generator.
	++i;
      }
    }
    else
      // Consider next generator.
      ++i;

  // If needed, erase the eps-redundant generators (also updating
  // `index_first_pending').
  if (gs_rows < gs.num_rows()) {
    gs.erase_to_end(gs_rows);
    gs.unset_pending_rows();
  }

  if (changed) {
    // The generator system is no longer sorted.
    x.gen_sys.set_sorted(false);
    // The constraint system is no longer up-to-date.
    x.clear_constraints_up_to_date();
  }

  assert(OK());
  return true;
}

void
PPL::Polyhedron::refine_no_check(const Constraint& c) {
  assert(!marked_empty());
  assert(space_dim >= c.space_dimension());

  // Dealing with a zero-dimensional space polyhedron first.
  if (space_dim == 0) {
    if (c.is_inconsistent())
      set_empty();
    return;
  }

  // The constraints (possibly with pending rows) are required.
  if (has_pending_generators())
    process_pending_generators();
  else if (!constraints_are_up_to_date())
    update_constraints();

  const bool adding_pending = can_have_something_pending();

  if (c.is_necessarily_closed() || !is_necessarily_closed())
    // Since `con_sys' is not empty, the topology and space dimension
    // of the inserted constraint are automatically adjusted.
    if (adding_pending)
      con_sys.insert_pending(c);
    else
      con_sys.insert(c);
  else {
    // Here we know that the system of constraints has at least a row.
    // However, by barely invoking `con_sys.insert(c)' we would
    // cause a change in the topology of `con_sys', which is wrong.
    // Thus, we insert a "topology corrected" copy of `c'.
    Linear_Expression nc_expr = Linear_Expression(c);
    if (c.is_equality())
      if (adding_pending)
        con_sys.insert_pending(nc_expr == 0);
      else
        con_sys.insert(nc_expr == 0);
    else
      if (adding_pending)
        con_sys.insert_pending(nc_expr >= 0);
      else
        con_sys.insert(nc_expr >= 0);
  }

  if (adding_pending)
    set_constraints_pending();
  else {
    // Constraints are not minimized and generators are not up-to-date.
    clear_constraints_minimized();
    clear_generators_up_to_date();
  }

  // Note: the constraint system may have become unsatisfiable, thus
  // we do not check for satisfiability.
  assert(OK());
}

void
PPL::Polyhedron::throw_runtime_error(const char* method) const {
  std::ostringstream s;
  s << "PPL::";
  if (is_necessarily_closed())
    s << "C_";
  else
    s << "NNC_";
  s << "Polyhedron::" << method << "." << std::endl;
  throw std::runtime_error(s.str());
}

void
PPL::Polyhedron::throw_invalid_argument(const char* method,
					const char* reason) const {
  std::ostringstream s;
  s << "PPL::";
  if (is_necessarily_closed())
    s << "C_";
  else
    s << "NNC_";
  s << "Polyhedron::" << method << ":" << std::endl
    << reason << ".";
  throw std::invalid_argument(s.str());
}

void
PPL::Polyhedron::throw_topology_incompatible(const char* method,
					     const char* ph_name,
					     const Polyhedron& ph) const {
  std::ostringstream s;
  s << "PPL::";
  if (is_necessarily_closed())
    s << "C_";
  else
    s << "NNC_";
  s << "Polyhedron::" << method << ":" << std::endl
    << ph_name << " is a ";
  if (ph.is_necessarily_closed())
    s << "C_";
  else
    s << "NNC_";
  s << "Polyhedron." << std::endl;
  throw std::invalid_argument(s.str());
}

void
PPL::Polyhedron::throw_topology_incompatible(const char* method,
					     const char* c_name,
					     const Constraint&) const {
  assert(is_necessarily_closed());
  std::ostringstream s;
  s << "PPL::C_Polyhedron::" << method << ":" << std::endl
    << c_name << " is a strict inequality.";
  throw std::invalid_argument(s.str());
}

void
PPL::Polyhedron::throw_topology_incompatible(const char* method,
					     const char* g_name,
					     const Generator&) const {
  assert(is_necessarily_closed());
  std::ostringstream s;
  s << "PPL::C_Polyhedron::" << method << ":" << std::endl
    << g_name << " is a closure point.";
  throw std::invalid_argument(s.str());
}

void
PPL::Polyhedron::throw_topology_incompatible(const char* method,
					     const char* cs_name,
					     const Constraint_System&) const {
  assert(is_necessarily_closed());
  std::ostringstream s;
  s << "PPL::C_Polyhedron::" << method << ":" << std::endl
    << cs_name << " contains strict inequalities.";
  throw std::invalid_argument(s.str());
}

void
PPL::Polyhedron::throw_topology_incompatible(const char* method,
					     const char* gs_name,
					     const Generator_System&) const {
  std::ostringstream s;
  s << "PPL::C_Polyhedron::" << method << ":" << std::endl
    << gs_name << " contains closure points.";
  throw std::invalid_argument(s.str());
}

void
PPL::Polyhedron::throw_dimension_incompatible(const char* method,
					      const char* other_name,
					      dimension_type other_dim) const {
  std::ostringstream s;
  s << "PPL::"
    << (is_necessarily_closed() ? "C_" : "NNC_")
    << "Polyhedron::" << method << ":\n"
    << "this->space_dimension() == " << space_dimension() << ", "
    << other_name << ".space_dimension() == " << other_dim << ".";
  throw std::invalid_argument(s.str());
}

void
PPL::Polyhedron::throw_dimension_incompatible(const char* method,
					      const char* ph_name,
					      const Polyhedron& ph) const {
  throw_dimension_incompatible(method, ph_name, ph.space_dimension());
}

void
PPL::Polyhedron::throw_dimension_incompatible(const char* method,
					      const char* e_name,
					      const Linear_Expression& e) const {
  throw_dimension_incompatible(method, e_name, e.space_dimension());
}

void
PPL::Polyhedron::throw_dimension_incompatible(const char* method,
					      const char* c_name,
					      const Constraint& c) const {
  throw_dimension_incompatible(method, c_name, c.space_dimension());
}

void
PPL::Polyhedron::throw_dimension_incompatible(const char* method,
					      const char* g_name,
					      const Generator& g) const {
  throw_dimension_incompatible(method, g_name, g.space_dimension());
}

void
PPL::Polyhedron::throw_dimension_incompatible(const char* method,
					      const char* cg_name,
					      const Congruence& cg) const {
  throw_dimension_incompatible(method, cg_name, cg.space_dimension());
}

void
PPL::Polyhedron::throw_dimension_incompatible(const char* method,
					      const char* cs_name,
					      const Constraint_System& cs) const {
  throw_dimension_incompatible(method, cs_name, cs.space_dimension());
}

void
PPL::Polyhedron::throw_dimension_incompatible(const char* method,
					      const char* gs_name,
					      const Generator_System& gs) const {
  throw_dimension_incompatible(method, gs_name, gs.space_dimension());
}

void
PPL::Polyhedron::throw_dimension_incompatible(const char* method,
					      const char* cgs_name,
					      const Congruence_System& cgs) const {
  throw_dimension_incompatible(method, cgs_name, cgs.space_dimension());
}

void
PPL::Polyhedron::throw_dimension_incompatible(const char* method,
					      const char* var_name,
					      const Variable var) const {
  std::ostringstream s;
  s << "PPL::";
  if (is_necessarily_closed())
    s << "C_";
  else
    s << "NNC_";
  s << "Polyhedron::" << method << ":" << std::endl
    << "this->space_dimension() == " << space_dimension() << ", "
    << var_name << ".space_dimension() == " << var.space_dimension() << ".";
  throw std::invalid_argument(s.str());
}

void
PPL::Polyhedron::
throw_dimension_incompatible(const char* method,
			     dimension_type required_space_dim) const {
  std::ostringstream s;
  s << "PPL::";
  if (is_necessarily_closed())
    s << "C_";
  else
    s << "NNC_";
  s << "Polyhedron::" << method << ":" << std::endl
    << "this->space_dimension() == " << space_dimension()
    << ", required space dimension == " << required_space_dim << ".";
  throw std::invalid_argument(s.str());
}

void
PPL::Polyhedron::throw_space_dimension_overflow(const Topology topol,
						const char* method,
						const char* reason) {
  std::ostringstream s;
  s << "PPL::";
  if (topol == NECESSARILY_CLOSED)
    s << "C_";
  else
    s << "NNC_";
  s << "Polyhedron::" << method << ":" << std::endl
    << reason << ".";
  throw std::length_error(s.str());
}

void
PPL::Polyhedron::throw_invalid_generator(const char* method,
					 const char* g_name) const {
  std::ostringstream s;
  s << "PPL::";
  if (is_necessarily_closed())
    s << "C_";
  else
    s << "NNC_";
  s << "Polyhedron::" << method << ":" << std::endl
    << "*this is an empty polyhedron and "
    << g_name << " is not a point.";
  throw std::invalid_argument(s.str());
}

void
PPL::Polyhedron::throw_invalid_generators(const char* method,
					  const char* gs_name) const {
  std::ostringstream s;
  s << "PPL::";
  if (is_necessarily_closed())
    s << "C_";
  else
    s << "NNC_";
  s << "Polyhedron::" << method << ":" << std::endl
    << "*this is an empty polyhedron and" << std::endl
    << "the non-empty generator system " << gs_name << " contains no points.";
  throw std::invalid_argument(s.str());
}
