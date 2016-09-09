m4_divert(-1)

dnl This m4 file includes macro definitions for:
dnl - application independent helper macros used here and by other m4 files.
dnl - defining the main code generation macro m4_all_code.

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

dnl =====================================================================
dnl ====== The following are application independent helper macros ======
dnl =====================================================================

dnl m4_forloop(Iteration_Var, From_Value, To_Value, Loop_Body)
dnl
dnl Code copied from m4 documentation.
m4_define(`m4_forloop',
  `m4_pushdef(`$1', `$2')_m4_forloop(`$1', `$2', `$3', `$4')m4_popdef(`$1')')
m4_define(`_m4_forloop',
  `$4`'m4_ifelse($1, `$3', ,
    `m4_define(`$1', m4_incr($1))_m4_forloop(`$1', `$2', `$3', `$4')')')


dnl m4_upcase(String), m4_downcase(String)
dnl
dnl Code copied from m4 documentation.
dnl Examples: m4_upcase(`abCd')   ==> ABCD
dnl           m4_downcase(`abCd') ==> abcd
m4_define(`m4_upcase', `m4_translit(`$*', `a-z', `A-Z')')
m4_define(`m4_downcase', `m4_translit(`$*', `A-Z', `a-z')')

dnl m4_capfirstletter(String)
dnl
dnl Capitalises first letter of words that can have letters and underscores.
dnl Example: m4_capfirstletter(`xyz_abc') ==> Xyz_abc
m4_define(`m4_capfirstletter',
  `m4_regexp(`$1', `^\(\w\)\([\w_]*\)',
     m4_upcase(`\1')`\2')')

dnl m4_capfirstletters(String)
dnl
dnl Capitalises first letter of subwords that can have letters only.
dnl Example: m4_capfirstletter(`xyz_abc') ==> Xyz_Abc
m4_define(`m4_capfirstletters',
  `m4_ifelse(m4_index(`$1', `_'), -1,
     `m4_regexp(`$1', `^\(\w\)\(\w*\)',
       `m4_upcase(`\1')`\2'')',
         m4_regexp(`$1', `^\(\w\)\(\w*_\)\(\w\)\(\w*\)',
           `m4_upcase(`\1')`\2'm4_upcase(`\3')`\4''))')

dnl m4_add_one_after_underscore(String)
dnl
dnl Adds a 1 after any underscore (needed for Java interface code)..
dnl Example: m4_capfirstletter(`xyz_abc') ==> xyz_1abc
m4_define(`m4_add_one_after_underscore', `m4_patsubst(`$1', `_', `_1')')

dnl m4_ifndef(Macro, Default Definition)
dnl
dnl If Macro is defined, use that definition;
dnl otherwise use the Default Definition.
m4_define(`m4_ifndef', `m4_ifdef(`$1', $1, $2)')

dnl m4_nargs expands to the number of arguments.
dnl
dnl Code copied from m4 documentation.
m4_define(`m4_nargs', `$#')

dnl m4_arg(Ind, Arg1, Arg2, ...)
dnl
dnl m4_arg expands to Arg`'Ind
m4_define(`m4_arg',
`m4_ifelse($1, 0, , $1, 1, $2, `m4_arg(m4_decr($1), m4_shift(m4_shift($@)))')')

dnl m4_arg_counter(String, Arg1, Arg2, ...)
dnl
dnl If String = Arg`'Counter, m4_arg_counter expands to Counter
dnl where Counter is the least index for which this holds.
dnl Otherwise it expands to the empty string.
m4_define(`m4_arg_counter', `m4_arg_counter_aux(1, $@)')

m4_define(`m4_arg_counter_aux', `dnl
m4_ifelse($#, 0, ,$#, 1, , $#, 2, ,
  $2, $3, $1,
  $#, 3, ,
  `m4_arg_counter_aux(m4_incr($1), $2, m4_shift(m4_shift(m4_shift($@))))')`'dnl
')

dnl m4_echo_unquoted(Args)
dnl
dnl Code copied from m4 documentation where it is called echo1.
m4_define(`m4_echo_unquoted', `$*')
dnl m4_echo_quoted(Args)
dnl
dnl Code copied from m4 documentation where it is called echo2.
m4_define(`m4_echo_quoted', `$@')

dnl ----------------------------------------------------------------------
dnl m4_two_seq_intersection,
dnl m4_three_seq_intersection and helper macros
dnl
dnl These find the intersection of two and three sequences, respectively.
dnl ----------------------------------------------------------------------
dnl
dnl m4_seq_intersection
dnl
dnl This macro with its helper macros below,
dnl intersects two or three sequences that must be previously defined
dnl as `m4_1st_sequence', `m4_2nd_sequence' and, if there is a third,
dnl `m4_3rd_sequence'. The number of sequences (2 or 3) must also be defined
dnl by the macro `m4_number_of_sequences'. The order of the
dnl intersected sequence is that of m4_1st_sequence.
dnl
dnl For example, if m4_1st_sequence is defined to be `a, b, c, d' and
dnl m4_2nd_sequence is defined to be `b, d, e, a, f',
dnl this macro is defined to be `a, b, d'.
m4_define(`m4_seq_intersection', `dnl
m4_define(`m4_add_one_first', 1)`'dnl
m4_patsubst(m4_seq_intersection_aux(m4_1st_sequence),
            @COMMA@, `, ')`'dnl
')

dnl m4_seq_intersection_aux(...)
dnl
dnl The arguments are the first sequence to be intersected.
dnl It calls either the helper macro for 3 sequences or the helper
dnl macro for 2 sequences (depending on the number of sequences).
dnl It calls itself recursively with the tail of the sequence.
m4_define(`m4_seq_intersection_aux', `dnl
m4_ifelse($#, 0, , $#, 1,
  m4_`'m4_num_of_sequences`'_seq_intersection_aux($1, m4_2nd_sequence),
  m4_`'m4_num_of_sequences`'_seq_intersection_aux($1, m4_2nd_sequence)`'dnl
`m4_seq_intersection_aux(m4_shift($@))')`'dnl
')

dnl m4_3_seq_intersection_aux(String, ...)
dnl
dnl This is defined to be `String' if `String' also occurs
dnl in the 2nd or in a later argument position
dnl as well as in m4_3rd_sequence.
dnl It calls itself recursively with the tail of the sequence.
m4_define(`m4_3_seq_intersection_aux', `dnl
m4_ifelse($#, 0, , $#, 1, , $#, 2,
  `m4_ifelse($1, $2, `m4_2_seq_intersection_aux($1, m4_3rd_sequence)')',
  `m4_ifelse($1, $2, `m4_2_seq_intersection_aux($1, m4_3rd_sequence)',
`m4_3_seq_intersection_aux($1, m4_shift(m4_shift($@)))')')`'dnl
')

dnl m4_2_seq_intersection_aux(String, ...)
dnl
dnl This is defined to be `String' if `String' also occurs
dnl in the 2nd or in a later argument position.
dnl It calls itself recursively with the tail of the sequence.
m4_define(`m4_2_seq_intersection_aux', `dnl
m4_ifelse($#, 0, , $#, 1, , $#, 2,
  `m4_ifelse($1, $2, `m4_add_one($1)')',
  `m4_ifelse($1, $2, `m4_add_one($1)',
`m4_2_seq_intersection_aux($1, m4_shift(m4_shift($@)))')')`'dnl
')

dnl m4_add_one(String)
dnl
dnl This separates the new sequence temporarily with @COMMA@ to avoid
dnl the `,' being mis-interpreted by m4.
m4_define(`m4_add_one', `dnl
m4_ifelse(m4_add_one_first, 1,
  $1`'m4_undefine(`m4_add_one_first'), @COMMA@$1)`'dnl
')


dnl ----------------------------------------------------------------------
dnl m4_seq_difference and helper macros
dnl
dnl This finds the difference of two sequences.
dnl ----------------------------------------------------------------------
dnl
dnl m4_seq_difference
dnl
dnl This macro with its helper macros below,
dnl finds the difference of two sequences that must be previously defined
dnl as `m4_1st_sequence', `m4_2nd_sequence'. The order of the
dnl intersected sequence is that of m4_1st_sequence.
dnl
dnl For example, if m4_1st_sequence is defined to be `a, b, c, d' and
dnl m4_2nd_sequence is defined to be `d, e, a, f',
dnl this macro is defined to be `b, c'.
m4_define(`m4_seq_difference', `dnl
m4_patsubst(m4_seq_difference_aux(m4_1st_sequence),
            `^@COMMA@', `')`'dnl
')
m4_define(`m4_seq_differencexx', `dnl
m4_patsubst(m4_patsubst(m4_seq_difference_aux(m4_1st_sequence),
            `^@COMMA@', `'),
            @COMMA@, `, ')`'dnl
')

dnl m4_seq_difference_aux(...)
dnl
dnl The arguments are the first sequence to be intersected.
dnl It calls either the helper macro for 3 sequences or the helper
dnl macro for 2 sequences (depending on the number of sequences).
dnl It calls itself recursively with the tail of the sequence.
m4_define(`m4_seq_difference_aux', `dnl
m4_ifelse($#, 0, , $#, 1,
  m4_2_seq_difference_aux($1, m4_2nd_sequence),
  `m4_2_seq_difference_aux($1, m4_2nd_sequence)`'dnl
m4_seq_difference_aux(m4_shift($@))')`'dnl
')

dnl m4_2_seq_difference_aux(String, ...)
dnl
dnl This is defined to be `String' if `String' does not occur
dnl in the 2nd or in a later argument position.
dnl It calls itself recursively with the tail of the sequence.
m4_define(`m4_2_seq_difference_aux', `dnl
m4_ifelse($#, 0, , $#, 1, `m4_add_one($1)', $#, 2,
  `m4_ifelse($1, $2, , `m4_add_one($1)')',
  `m4_ifelse($1, $2, ,
`m4_2_seq_difference_aux($1, m4_shift(m4_shift($@)))')')`'dnl
')

dnl =====================================================================
dnl ====== The following are application dependent macros: their meaning
dnl ====== is influenced by the overall interface generator architecture.
dnl =====================================================================

dnl =====================================================================
dnl ====== The next group of macros process the patterns in the code ====
dnl =====================================================================

dnl m4_pattern_delimiter
dnl
dnl In case the pattern delimiter needs to be changed,
dnl this is defined as a global variable
m4_define(`m4_pattern_delimiter', `@')

dnl m4_expand_pattern_by_one_replacement(Pattern, Index)
dnl
dnl Pattern       - is the pattern;
dnl Index         - is the index of the replacement.
dnl The delimited PATTERN is replaced by the Index'th argument in
dnl m4_replacements.
dnl Additional codes help provide the right form of the replacmement:
dnl - alt_ means that the alternative replacement in m4_alt_replacements
dnl must be used if one exists.
dnl - cppx_ means that the alternative replacement in m4_cppx_replacements
dnl must be used if one exists.
dnl - when the alt_replace is NONE, then the code is replaced by the
dnl   the empty string.
dnl - U means that the alt_actual string must be capitalised at start
dnl   of word and after "_".
m4_define(`m4_expand_pattern_by_one_replacement', `dnl
dnl
dnl m4_replace is the replacement for pattern
m4_define(`m4_replace', `m4_arg($2, m4_replacements)')`'dnl
dnl
dnl m4_alt_replace is the replacement for alt_pattern
m4_define(`m4_alt_replace', `m4_arg($2, m4_alt_replacements)')`'dnl
dnl m4_alt_replace is the replacement for alt_pattern
m4_define(`m4_cppx_replace', `m4_arg($2, m4_cppx_replacements)')`'dnl
dnl
m4_ifelse(m4_replace, NONE, `',
          m4_alt_replace, NONE, `',
m4_patsubst(m4_patsubst(m4_patsubst(m4_patsubst(
            m4_patsubst(m4_patsubst(m4_patsubst(m4_patsubst(
            m4_patsubst(m4_patsubst(m4_patsubst(m4_patsubst(
            m4_patsubst(m4_patsubst(m4_patsubst(m4_patsubst(
            m4_patsubst(m4_patsubst($1,
  m4_pattern_delimiter`'1U`'PATTERN`'m4_pattern_delimiter,
    m4_add_one_after_underscore(m4_capfirstletters(m4_replace))),
  m4_pattern_delimiter`'1L`'PATTERN`'m4_pattern_delimiter,
    m4_add_one_after_underscore(m4_downcase(m4_replace))),
  m4_pattern_delimiter`'U`'PATTERN`'m4_pattern_delimiter,
    m4_capfirstletters(m4_replace)),
  m4_pattern_delimiter`'L`'PATTERN`'m4_pattern_delimiter,
    m4_downcase(m4_replace)),
  m4_pattern_delimiter`'1`'PATTERN`'m4_pattern_delimiter,
    m4_add_one_after_underscore(m4_replace)),
  m4_pattern_delimiter`'1UALT_`'PATTERN`'m4_pattern_delimiter,
    m4_add_one_after_underscore(m4_capfirstletters(m4_alt_replace))),
  m4_pattern_delimiter`'UALT_`'PATTERN`'m4_pattern_delimiter,
    m4_capfirstletters(m4_alt_replace)),
  m4_pattern_delimiter`'1LALT_`'PATTERN`'m4_pattern_delimiter,
    m4_add_one_after_underscore(m4_downcase(m4_alt_replace))),
  m4_pattern_delimiter`'LALT_`'PATTERN`'m4_pattern_delimiter,
    m4_downcase(m4_alt_replace)),
  m4_pattern_delimiter`'1ALT_`'PATTERN`'m4_pattern_delimiter,
    m4_add_one_after_underscore(m4_alt_replace)),
  m4_pattern_delimiter`'ALT_`'PATTERN`'m4_pattern_delimiter,
    m4_alt_replace),
  m4_pattern_delimiter`'1UCPPX_`'PATTERN`'m4_pattern_delimiter,
    m4_add_one_after_underscore(m4_capfirstletters(m4_alt_replace))),
  m4_pattern_delimiter`'UCPPX_`'PATTERN`'m4_pattern_delimiter,
    m4_capfirstletters(m4_alt_replace)),
  m4_pattern_delimiter`'1LCPPX_`'PATTERN`'m4_pattern_delimiter,
    m4_add_one_after_underscore(m4_downcase(m4_alt_replace))),
  m4_pattern_delimiter`'LCPPX_`'PATTERN`'m4_pattern_delimiter,
    m4_downcase(m4_alt_replace)),
  m4_pattern_delimiter`'1CPPX_`'PATTERN`'m4_pattern_delimiter,
    m4_add_one_after_underscore(m4_alt_replace)),
  m4_pattern_delimiter`'CPPX_`'PATTERN`'m4_pattern_delimiter,
    m4_cppx_replace),
  m4_pattern_delimiter`'PATTERN`'m4_pattern_delimiter,
    m4_replace)`'dnl
)`'dnl
dnl
m4_undefine(`m4_replace')`'dnl
m4_undefine(`m4_alt_replace')`'dnl
')

dnl m4_expand_pattern_by_replacements(Pattern, Index)
dnl
dnl Pattern       - is the pattern;
dnl Index         - is the index of the replacement.
dnl This iteratively calls m4_expand_pattern_by_one_replacement/2 to replace
dnl a delimited form of PATTERN by the Index'th argument in m4_replacements
dnl or m4_alt_replacements.
m4_define(`m4_expand_pattern_by_replacements', `dnl
m4_ifelse($2, m4_nargs(m4_replacements),
  `m4_expand_pattern_by_one_replacement($1, $2)',
  `dnl
m4_expand_pattern_by_one_replacement($1, $2)`'dnl
m4_expand_pattern_by_replacements($1, m4_incr($2))')`'dnl
')

dnl m4_replace_one_pattern_in_string(Class_Number, String, Pattern)
dnl
dnl Class_Number  - is the index to Class in Class_List;
dnl String        - is the code to be changed;
dnl Pattern       - is the pattern to be replaced;
dnl Replaces all occurrences of the capitalised form of Pattern
dnl in String by the required replacement
dnl (determined both by the class kind of Class and Pattern).
m4_define(`m4_replace_one_pattern_in_string', `dnl
dnl
dnl the PATTERN (in uppercase) is the string to be replaced.
m4_define(`PATTERN', m4_upcase($3))`'dnl
dnl
dnl m4_replacements is the replacement list for the pattern.
m4_define(`m4_replacements', `dnl
m4_class_pattern_replacement($1, $3, `')')`'dnl
dnl
dnl m4_alt_replacements is the alternative replacement list for pattern.
m4_define(`m4_alt_replacements', `dnl
m4_class_pattern_replacement($1, $3, `_alt')')`'dnl
dnl
dnl m4_cppx_replacements is the cplusplus replacement list for pattern.
m4_define(`m4_cppx_replacements', `dnl
m4_class_pattern_replacement($1, $3, `_cppx')')`'dnl
dnl
m4_ifelse(m4_index(`$2', PATTERN), `-1', $2, `dnl
m4_expand_pattern_by_replacements($2, 1)')`'dnl
dnl
m4_undefine(`PATTERN')`'dnl
m4_undefine(`m4_replacements')`'dnl
m4_undefine(`m4_alt_replacements')`'dnl
m4_undefine(`m4_cppx_replacements')`'dnl
')

dnl m4_replace_all_patterns_in_string(
dnl    Class_Number, String, Pattern1, Pattern2, ...)
dnl
dnl A (recursive) macro to replace, inside the second argument String,
dnl all of the patterns listed from the third argument onwards.
m4_define(`m4_replace_all_patterns_in_string', `dnl
m4_ifelse($3, `', ``$2'',
       `m4_replace_all_patterns_in_string($1,
                                m4_replace_one_pattern_in_string($1, $2, $3),
                                m4_shift(m4_shift(m4_shift($@))))')`'dnl
')

dnl =====================================================================
dnl ====== The next macros deal with instantiating the schematic code ===
dnl ====== and also generates lists of names augmented with extensions. =
dnl =====================================================================


dnl m4_get_arity(Procedure_Flags)
dnl
dnl Procedure_Flags - The schematic code flags;
dnl If the substring "/Arity" is found in the Procedure_Flags,
dnl this macro expands to Arity.
m4_define(`m4_get_arity', `m4_regexp(`$1', `/\([0-9]*\)', \1)')

dnl m4_get_attribute(Procedure_Flags)
dnl
dnl Procedure_Flags - The schematic code flags;
dnl If the substring "*nofail" is found in the Procedure_Flags,
dnl this macro expands to "nofail"
dnl This is only needed for the Ciao system code.
m4_define(`m4_get_attribute', `m4_regexp(`$1', `\*\(nofail\)', \1)')

dnl m4_extension(Procedure_Name, [Arity, Attribute], Start_Flag)
dnl
dnl Procedure_Name - The schematic name;
dnl Arity          - The arity of the procedure;
dnl Attribute      - The attribute `nofail' or `';
dnl Start_Flag     - 0 suppresses any separator.
dnl                  (Needed for expanding Prolog lists of atoms etc.).
dnl
dnl The default definition.
dnl Appends "_code" to Procedure_Name so that it can match the name
dnl of one of the macros defined (if ever) in file *_code.m4 and get
dnl therefore expanded to the corresponding code schema.
dnl
dnl Here arguments Arity and Attribute are ignored.
dnl This macro is redefined when a different extension is needed.
dnl (e.g., in the Prolog system files).
dnl
dnl Note: the macro `$1_code' has to be called using builtin `indir'
dnl because it is not a legal m4 identifier (it contains `@').
m4_define(`m4_default_code', `')
m4_define(`m4_extension', `m4_ifdef(`$1_code', `m4_indir(`$1_code')',
  `m4_default_code($1)')`'dnl
')

dnl m4_get_schematic_code(Procedure_Spec, Start_Flag, Class_Kind)
dnl
dnl Procedure_Spec - The schematic procedure name, complete with any flags;
dnl Start_Flag     - 0 suppresses any separator.
dnl                  (Needed for expanding Prolog lists of atoms etc.).
dnl Class_Kind     - The current class kind;
dnl Procedure_Spec has the flags removed and expanded to
dnl the extended code.
m4_define(`m4_get_schematic_code', `dnl
m4_patsubst(`$1',
         `[ ]*\(ppl_[^ /]+\)\(.*\)',
         `m4_extension(\1, m4_get_arity(\2), m4_get_attribute(\2), $2, $3)')')

dnl m4_replace_procedure_spec_by_code(Class_Number, Procedure_Spec)
dnl
dnl Class_Number   - The current class counter.
dnl Procedure_Spec - The schematic procedure name, complete with any flags;
dnl The procedure specification is replaced with the code and then
dnl the patterns in the code are replaced by the required replacements.
dnl
dnl Note: one schematic specification will replaced by a single
dnl matching schematic code item; which is then replaced by several
dnl instances.
m4_undefine(`m4_replace_procedure_spec_by_code')
m4_define(`m4_replace_procedure_spec_by_code', `dnl
m4_patsubst(`$2', `\(.*\)', `dnl
m4_replace_all_patterns_in_string($1,
  m4_get_schematic_code(\1, 1, $1),
    m4_pattern_list)')`'dnl
')

dnl m4_replace_all_procedure_specs_by_code(Class_Number,
dnl                            Procedure_Spec1, Procedure_Spec2, ...)
dnl
dnl Class_Number    - The current class counter.
dnl Procedure_Spec1 - A schematic procedure name;
dnl ...
dnl Procedure_Speck - A schematic procedure name
dnl Each name from the second argument onwards is replaced
dnl with the code and then the schema patterns in the code
dnl are replaced by the various instances.
m4_define(`m4_replace_all_procedure_specs_by_code', `dnl
m4_ifelse($#, 0, , $#, 1, ,
       $#, 2, `m4_replace_procedure_spec_by_code($1, $2)',
       `dnl
m4_replace_procedure_spec_by_code($1, $2)`'dnl
m4_replace_all_procedure_specs_by_code($1, m4_shift(m4_shift($@)))`'dnl
')dnl
')

dnl =====================================================================
dnl ====== The next set of macros filter the procedure specifications   =
dnl ====== according to the +/-group names in the extra flags in the    =
dnl ====== procedure specification.                                     =
dnl =====================================================================

dnl m4_keep_or_throw_for_one_group(
dnl     Class__Counter, Procedure_Spec, +_or_-, Group)
dnl
dnl Class_Counter   - The current class counter;
dnl Procedure_Spec  - A schematic procedure name with flags still attached;
dnl +_or_-          - + or -;
dnl Group           - A group name.
dnl This checks if Class_Kind is in the list of class kinds defined
dnl by Group (in ppl_interface_generator_common_dat.m4);
dnl if it is, it checks if +Group or -Group
dnl (depending if +_or_- is + or -) is included in the Procedure_Spec;
dnl if it is, then it expands to 1, otherwise, expands to 0.
m4_define(`m4_keep_or_throw_for_one_group', `dnl
m4_ifelse(m4_arg_counter($1, m4_$4_group), `', 0,
  `m4_ifelse(m4_index($2, $3$4), -1, 0, 1)')`'dnl
')

dnl m4_keep_or_throw(
dnl     Class_Counter, Procedure_Spec, +_or_-, Group1, Group2, ...)
dnl
dnl Class_Counter   - The current class counter;
dnl Procedure_Spec  - A schematic procedure name with flags still attached;
dnl +_or_-          - + or -;
dnl Group1          - A group name;
dnl ....
dnl Groupk          - A group name.
m4_define(`m4_keep_or_throw', `dnl
m4_ifelse($#, 0, 0, $#, 1, 0, $#, 2, 0, $#, 3, 0,
  $#, 4, `m4_keep_or_throw_for_one_group($1, $2, $3, $4)',
    `m4_ifelse(m4_keep_or_throw_for_one_group($1, $2, $3, $4), 1, 1,
      `m4_keep_or_throw($1, $2, $3,
                       m4_shift(m4_shift(m4_shift(m4_shift($@)))))')')`'dnl
')

dnl m4_filter_one_procedure(Class_Counter, Procedure_Spec)
 dnl
dnl Class_Counter   - The current class counter;
dnl Procedure_Spec  - A schematic procedure name with flags still attached;
dnl Keeps just those procedures that are wanted for the given class kind.
dnl It first checks if there is a group in Procedure_Spec, whose
dnl definition includes the Class_Kind, preceded by a "-",
dnl if so, it expands to the empty string;
dnl otherwise, it checks if there is a group in Procedure_Spec, whose
dnl definition includes the Class_Kind, preceded by a "+",
dnl if so, it expands to Procedure_Spec.
m4_define(`m4_filter_one_procedure', `dnl
m4_define(`m4_proc_info_string',
       `m4_patsubst(`$2', `[ ]*ppl_[^ ]+ \(.*\)', \1)')`'dnl
m4_ifelse(m4_keep_or_throw(m4_class_kind$1,
                           m4_proc_info_string, -,
                           m4_group_names),
  1, 0,
  m4_keep_or_throw(m4_class_body_kind$1,
                             m4_proc_info_string, \,
                             m4_group_names),
  1, 0,
  m4_keep_or_throw(m4_class_body_2nd_kind$1,
                             m4_proc_info_string, ?,
                             m4_group_names),
  1, 0,
  `m4_keep_or_throw(m4_class_kind$1,
                   m4_proc_info_string, +,
                   m4_group_names)')`'dnl
m4_undefine(m4_proc_info_string)`'dnl
')

dnl m4_filter_all_procedures(Class_Counter, keep_or_throw_flag,
dnl                         Procedure_Spec1, ProcedureSpec2, ...)
dnl
dnl Class_Counter   - The current class kind;
dnl keep_or_throw_flag
dnl                 - has value 1 or 0;
dnl Procedure_Spec1 - A schematic procedure name with flags still attached;
dnl ...
dnl Procedure_Speck - A schematic procedure name with flags still attached;
dnl Keeps just those procedure names that are needed for the given class kind.
dnl The classes to be kept or filtered away are determined by extra info
dnl included with each Procedure_Name
dnl The keep_or_throw_flag determines if the filtered procedures
dnl are the wanted (value 1) procedures or the unwanted ones (value 0);
dnl Here we only use the wanted procedures list.
dnl The unwanted list is used when generating the Prolog tests.
m4_define(`m4_filter_all_procedures', `dnl
m4_ifelse($#, 0, , $#, 1, , $#, 2, ,
  $#, 3,
    `m4_ifelse(m4_filter_one_procedure($1, $3), $2,
       `$3')',
    `m4_ifelse(m4_filter_one_procedure($1, $3), $2,
       `$3,
')`'dnl
m4_filter_all_procedures($1, $2, m4_shift(m4_shift(m4_shift($@))))`'dnl
')`'dnl
')

dnl =====================================================================
dnl ====== The next set of macros process a single class.   =============
dnl =====================================================================

dnl m4_pre_extra_class_code(Class_Counter)
dnl m4_post_extra_class_code(Class_Counter)
dnl
dnl Class_Counter   - The index for the current class;
dnl Default (empty) definitions for pre- and post- code for each class.
dnl These should be redefined as needed.
m4_define(`m4_pre_extra_class_code', `')
m4_define(`m4_post_extra_class_code', `')

dnl m4_one_class_code(Class_Counter)
dnl
dnl Class_Counter   - The index for the current class;
dnl First, any necessary prefix code for the procedures in
dnl that class is added.
dnl Then, the main procedure input list is filtered according to
dnl the current class kind and the +/- codes included with the procedure.
dnl Each procedure that is not filtered away is checked to see if
dnl there is a macro with "_code" extension that defines the code.
dnl Then a macro sets the class and other schematic components.
dnl Finally, any necessary postfix code for the procedures in
dnl that class is added.
m4_define(`m4_one_class_code', `dnl
m4_pre_extra_class_code($1)`'dnl
m4_define(`m4_filtered_proc_list',
       `m4_filter_all_procedures($1, 1, m4_procedure_list)')`'dnl
m4_replace_all_procedure_specs_by_code($1, m4_filtered_proc_list)`'dnl
m4_undefine(`m4_filtered_proc_list')`'dnl
m4_post_extra_class_code($1)`'dnl
')

dnl =====================================================================
dnl === The final set of macros process all the classes, one at a time. =
dnl =====================================================================

dnl m4_all_classes_code(Class_Counter)
dnl
dnl Class_Counter   - The index for the current class;
dnl This iterates through the classes to generate the code.
dnl The actual code for each class is generated by m4_one_class_code.
dnl The generated code then has the pattern "@COMMA@" replaced by ",".
m4_define(`m4_all_classes_code', `dnl
m4_ifdef(m4_interface_class`'$1,
`m4_patsubst(m4_one_class_code($1), @COMMA@, `,')`'dnl
m4_all_classes_code(m4_incr($1))')`'dnl
')

dnl m4_pre_all_classes_code
dnl
dnl Default (empty) definitions for code that must be placed before all
dnl the generated code.
dnl This is required for code that depends on the instantiated classes
dnl (so must be generated from a schema) but has to be included before
dnl all classes (as in ppl_prolog_icc.m4).
m4_define(`m4_pre_all_classes_code', `')

dnl m4_class_definitions_initialized/0
dnl
dnl Avoids initializing the class macro definitions more than once
dnl when the main macro m4_all_code/0 is called more than once in a
dnl file generation.
m4_define(`m4_class_definitions_initialized', `false')

dnl m4_all_code
dnl
dnl This initializes the macros for the classes requested by the user
dnl (which is determined by the configuration).
dnl
dnl The macros for names of the classes are first initialized:
dnl The interface class names are m4_interface_class`'Class_Counter;
dnl the class kind by m4_class_kind`'Class_Counter;
dnl the cplusplus class name by m4_cplusplus_class`'Class_Counter.
dnl
dnl The main loop macro m4_all_classes_loop is called to generate
dnl code for all the required classes.
m4_define(`m4_all_code', `dnl
dnl
dnl Provides the class name macro definitions if not
dnl already initialized
m4_ifelse(m4_class_definitions_initialized, `false',
  `m4_init_class_definitions', `')`'dnl
dnl
dnl then adds the extra code for all classes
m4_pre_all_classes_code`'dnl
dnl and then generates code for each class.
m4_all_classes_code(1)`'dnl
')
