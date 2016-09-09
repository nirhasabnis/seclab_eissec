
/* 
 * EISSEC (Extracting Instruction Semantics via Symbolic Execution of Code
 * Generators) is a symbolic execution based system for automatically extracting
 * assembly to IR translators from code generators of modern compilers.
 * 
 * Copyright (C) 2012 - 2016 by Niranjan Hasabnis and R.Sekar in Secure Systems
 * Lab, Stony Brook University, Stony Brook, NY 11794.
 *
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 2 of the License, or 
 * (at your option) any later version. 
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * GNU General Public License for more details. 
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */
#define POW_2(pow) ((uint64_t) 1 << pow)


int gen_type_constraint(uint64_t lhsgc, uint64_t rhsgc, size_t lhs_size, int lhs_sign)
{
    if (lhs_sign == 1) {
        /* Result of operation is assigned to signed type */
        /* Let D = MAX - MIN + 1
           Let X = R mod D
           Let Q = X/(D/2) (Q is expected to be either 0 or 1)
           Let T = Q*D
           Let L = X - T
         */
#ifdef USE_TRYONE
        int X = nv();
        if (tryone(ie1v1c(X, CSMODE, rhsgc, POW_2(lhs_size))) == 1)
            GOTO_NEXT_CHOICE_POINT;

        int Q = nv();
        if (tryone(ie1v1c(Q, CSDIV, X, POW_2(lhs_size-1))) == 1)
            GOTO_NEXT_CHOICE_POINT;

        int T = nv();
        if (tryone(ie1v1c(T, CSMULT, Q, POW_2(lhs_size))) == 1)
            GOTO_NEXT_CHOICE_POINT;

        if (tryone(ie2v(lhsgc, CSMINUS, X, T)) == 1)
            GOTO_NEXT_CHOICE_POINT;
#else
        int X = nv();
        if (tryboth(ie1v1c(X, CSMODE, rhsgc, POW_2(lhs_size))) >= 1)
            GOTO_NEXT_CHOICE_POINT;

        int Q = nv();
        if (tryboth(ie1v1c(Q, CSDIV, X, POW_2(lhs_size-1))) >= 1)
            GOTO_NEXT_CHOICE_POINT;

        int T = nv();
        if (tryboth(ie1v1c(T, CSMULT, Q, POW_2(lhs_size))) >= 1)
            GOTO_NEXT_CHOICE_POINT;

        if (tryboth(ie2v(lhsgc, CSMINUS, X, T)) >= 1)
            GOTO_NEXT_CHOICE_POINT;
#endif
    } else {
        /* Result of operation is assigned to unsigned type */
        /* L = R mod MAX + 1 */
#ifdef USE_TRYONE
        if (tryone(ie1v1c(lhsgc, CSMOD, rhsgc, POW_2(lhs_size))) == 1)
            GOTO_NEXT_CHOICE_POINT;
#else
        if (tryone(ie1v1c(lhsgc, CSMOD, rhsgc, POW_2(lhs_size))) >= 1)
            GOTO_NEXT_CHOICE_POINT;
#endif
    }
}
