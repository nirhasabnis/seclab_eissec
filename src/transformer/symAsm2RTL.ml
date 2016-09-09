(*
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
 *)

open Cil
open Hashtbl
open Cfg


(*  ======================================================================== *)
(*            All configuration parameters                                   *)
(*  ======================================================================== *)

(*
 * A variable that guides if this cilly
 * feature is enabled by default
 *)
let doSymAsm2RTL = ref false

(*  ======================================================================== *)
(*            All global defines (variables, types, etc)                     *)
(*  ======================================================================== *)

(* Names of various functions, elements, variables that are
 * referred in C files *)
(* local symbolic variables list *)
let varSymVarList = "_symVarList"

(* Names of variables added to the formal param list *)
let varCilArg = "__cil__arg"
let varCilArgAddrSuffix = "__addr" 
let varCilArgNameSuffix = "__name"
let varCallerName = "callerName"
let varCallerSymVarList = "callerSymVarList"

(* Fields of element_t: defined in symVarList.h *)
let fldAddress = "address"
let fldIsSymbolic = "isSymbolic"
let fldNext = "next"

(* Type *)
let typElement = "element"
let typElement_t = "element_t"
(* Currently symbolic type is represented using integer *)
let symbolicType = intType
(* uint64_t *)
let symIDType = (TInt(IULongLong,[]))
(* Defined in limits.h as ULLONG_MAX, represents the maximum possible value of
 * uint64_t type. *)
let concreteVarGcountVal = Lval(var (makeVarinfo true "gConcreteVarGcount"
                           (TInt(IULongLong, []))))

(* Functions *)
let constAddOpCons_nop = "ADDOPCONS_NOP"
let funAddOpCons_nop = emptyFunction constAddOpCons_nop
let funAddOpCons_unop = emptyFunction "ADDOPCONS_UNOP"
let funAddOpCons_binop = emptyFunction "ADDOPCONS_BINOP"
let funGetGenCount = emptyFunction "GET_GENCOUNT"
let funSetGenCount = emptyFunction "SET_GENCOUNT"
let funGetSymValType = emptyFunction "GET_SYMVAL_TYPE"
let funSetSymValType = emptyFunction "SET_SYMVAL_TYPE"
let funDeleteRecord = emptyFunction "deleteRecord"
let funDeleteRecord1 = emptyFunction "deleteRecord1"
let funAddNewRecord = emptyFunction "addNewRecord"
let funSetSymbolic = emptyFunction "SET_SYMBOLIC"
let funProcReturn = emptyFunction "PROC_RETURN"
let funNegateCond = emptyFunction "NEGATE_CONDITION"
let funTryNopConsOp = emptyFunction "TRY_NOPCONS_OP"
let funTryUnopConsOp = emptyFunction "TRY_UNOPCONS_OP"
let funTryBinConsOp = emptyFunction "TRY_BINCONS_OP"
let funNegNopCond = emptyFunction "NEGATE_NOP_CONDITION"
let funNegUnopCond = emptyFunction "NEGATE_UNARY_CONDITION"
let funNegBinopCond = emptyFunction "NEGATE_BINARY_CONDITION"
let funGetElemCons = emptyFunction "GET_ELEM_CONS"
let funGetFieldCons = emptyFunction "GET_FIELD_CONS"
let funPutElemConsHelper = emptyFunction "PUT_ELEM_CONS_HELPER"
let funPutFieldConsHelper = emptyFunction "PUT_FIELD_CONS_HELPER"
let funMyLogPrintf = emptyFunction "mylogprintf"
let funMyDebugPrintf = emptyFunction "DEBUG_PRINTF"

(* Suffix for the transformed functions *)
let transformed_func_suffix = "_trans"
let cons_func_suffix = "_CONS"

(* Attribute *)
let attrSymbolic = "Symbolic"

(* Constraints *)
let consEq = "="
(* Constraint string for equality *)
let consstrEq = Const(CStr(consEq))

(* Heder file names *)
let hdrSymHelperH = "#include <symHelper.h>"
let hdrSymVarListH = "#include <symVarList.h>"
let hdrSymVarStackH = "#include <symVarStack.h>"
let hdrRtlAccH = "#include <rtl-accessors.h>"
let hdrConsSolveH = "#include <cons_solve.h>"
let hdrCommonH = "#include <common.h>"

(* names of command line arguments *)
let argSymFunctionsFile = ref ""

(* Name of file that contaings list of system directories
 * to be excluded from transformation. *)
let sysDirsFile = ref " "

(* The name of the file that contains name of the functions
 * for which their return needs to be converted into backTrack() 
 * and addOutput *)
let funcRetProcFile = ref " "

(* The name of the file that contains name of the functions the
 *  calls to which are not to be transformed.
 *)
let dontTransFunccallFile = ref " "

(* Exceptions *)
(* Input is incorrect. It does not match the
 * expected specification. *)
exception Incorrect_Input of string

(* This particular case should not be reached. *)
exception Unreachable_Case of string

(* This case is unexpected. This should not happen generally. *)
exception Unexpected_Case of string

(*
 * The list of functions for which we have defined symbolic version
 *)
let sym_func_list = ref []

(*  The file that contains the list of system directories. Any C function that has 
 *  any of these directories as prefix in its location, will not be
 *  instrumented.
 *  E.g., If the list contains "/usr/include/" then any function that belongs
 *  to the file /usr/include/stddef.h will not be instrumented
 * *)
let sys_dirs_list = ref []

(* Refer to funcRetProc comment. *)
let func_ret_proc_list = ref []

(* Refer to dontTransFunccall comment *)
let dont_trans_funccall_list = ref []

(*
 * Global hash table which maintains the mapping between function name
 * and its goto labels. By goto labels, we mean the labels associated with
 * the targets of goto. Note that the order in which gotos are encounterd
 * determine the order of labels in the list. This order *IS* important.
 * Even though Cil allows a statement to have a list of labels as opposed 
 * to a single label, we consider only the first label in the list. 
 * This won't create any problem because, internally, Cil does not refer 
 * to the target using a label, but instead uses 'ref' to it.
 *
 * This table is then used to patch gotos once the target statement of
 * goto is updated. We need to do all this because Cil defines goto as
 * "statement ref, location". That is why when the target is updated
 * we need to update goto statement for that target also.
 *)
let varGotoLabelsTbl : (string, string list) Hashtbl.t = (Hashtbl.create 20)

(*  ======================================================================== *)
(*            Some generic and useful functions                              *)
(*  ======================================================================== *)

(* Checks if element e is present in the list, 
 * if it does, then returns the position of that
 * element in the list. Otherwise, raises Not_found
 * exception.
 *)
let elemidx e l : int =
    let rec iterlist e l (idx : int) : int =
        match l with
          e'::es -> if ((compare e e') = 0) then idx
                    else iterlist e es (idx+1)
         | [] -> raise Not_found
    in
    iterlist e l 0


(*  ======================================================================== *)
(*            Some Cil data type manipulation functions                      *)
(*  ======================================================================== *)

let printLocation : string = (Pretty.sprint 80 (d_thisloc ()))
let printMyLocation (l: location) : string = (Pretty.sprint 80 (d_loc () l))
let printStmt (s: stmt) : string = (Pretty.sprint 80 (d_stmt () s))
let printExp (e : exp) : string = (Pretty.sprint 80 (d_exp () e))
let printType (t : typ) : string = (Pretty.sprint 80 (d_type () t))
let printGlobal (g : global) : string = (Pretty.sprint 80 (d_global () g))
let printInstr (i : instr) : string = (Pretty.sprint 80 (d_instr () i))
let printLval (lv : lval) : string = (Pretty.sprint 80 (d_lval () lv))

(* If there something in 'i' *)
let isSome (i) : bool =
  match i with
    Some(_) -> true
   | None -> false

let removeOption (i) =
  match i with
    Some(s) -> s
   | _ -> raise (Unexpected_Case ("[removeOption] unexpected input"))

let rec getLvalFromExp (e : exp) : lval = 
  match e with
    Lval(lval) -> lval
   | CastE(_, e1) -> getLvalFromExp e1
   | _ -> raise (Unexpected_Case ("[getLvalFromExp] incorrect " ^
                       "expression " ^ (printExp e) ^ " at " ^ 
                       printLocation))
   
let getVarNameFromLval (lv : lval) : string =
  match lv with
    (Var(vinfo),_) -> vinfo.vname
   | _ -> raise (Unexpected_Case ("[getVarNameFromLval] incorrect " ^
                       "lvalue" ^ " at " ^ printLocation ))

let varToLval (v : varinfo) : exp = Lval(var v)

let isStatic (v : varinfo) : bool =
    match v.vstorage with
     Static -> true
    | _ -> false

(*
 * Get name of the function being called from
 * the expression
 *)
let getCalleeName (f : exp) : string = 
  match f with
    Lval(Var(vinfo),_) -> vinfo.vname
    | _ -> raise (Unexpected_Case ("[getCalleeName] unexpected" ^
                    " input expression " ^ printExp f ^ " at " ^ printLocation ))

(*
 * Given a function type, return the return type of the function, 
 * and the list of formal parameters
 *)
let getFuncComponents (t : typ) : typ * ((string * typ * attributes)
list option) =
  match t with 
    TFun(rettype,fplistopt,_,_) -> rettype,fplistopt
    | _ -> raise (Incorrect_Input("[getFuncComponents] Expecting function " ^
      "type, but received other." ^ " at " ^ printLocation ))

(* Generate function type from argument and return value *)
let genFuncType (lvopt : lval option) (args : exp list) : typ = 
    let resType = 
        match lvopt with
        None -> TVoid([])
        | Some(lv) -> typeOfLval lv
    in
    let getArgType (arg : exp) : (string * typ * attributes) =
        (" ", typeOf arg, [])
    in
    let argsType = Some(List.map getArgType args) 
    in
    TFun(resType, argsType, false, [])

(* Get array length from array type *)
let getArrayLenFromType (t : typ) : exp = 
    match t with
      TArray(_,Some(e),_) -> e
      | TArray(_,None,_) -> zero
      | _ -> raise (Unexpected_Case("[getArrayLenFromType] Was expecting" ^
                    " array type, but received " ^ printType t ^ " at " ^
                    printLocation))

(* Get name of structure type from the type *)
let getStructNameFromType (t : typ) : string =
    match t with
     TComp(ci,_) -> ci.cname
    | _ -> raise (Unexpected_Case("[getStructNameFromType] was expecting to get" ^
                    " structure type, but received " ^ printType t ^ " at " ^
                    printLocation))

(* Get the number of the field from structure type *)
let getFieldNumFromStruct (fi : fieldinfo) : int =
    elemidx fi fi.fcomp.cfields
        
(*
(*
 * Given an expression return an expression representing
 * the address of that expression.
 *)
let getAddrOfExp (e : exp) : exp = 
  match e with
    Lval(v) -> mkAddrOf v
   | Const(_) -> zero
   | _ -> 
      let wrong_expr = Pretty.sprint 80 (d_exp () e)
      in
      raise (Incorrect_Input("[getAddrOfExp] " ^
        "after we simplify statements, we do not " ^
        "expect to see " ^ wrong_expr))

(*
 * Given an expression, return an expression representing
 * the name of that expression.
 *)
let getNameOfExp (e : exp) : exp =
  match e with
    Lval(v) -> Const(CStr(Pretty.sprint 80 (d_lval () v)))
   | Const(c) -> Const(CStr(Pretty.sprint 80 (d_const () c)))
   | _ -> 
      let wrong_expr = Pretty.sprint 80 (d_exp () e)
      in
      raise (Incorrect_Input("[getNameOfExp] " ^
        "after we simplify statements, we do not " ^
        "expect to see " ^ wrong_expr))
*)

(*  ======================================================================== *)
(*            Some global utility functions for transformation               *)
(*  ======================================================================== *)

(*
 * String comparison, but instead of returning int, returns bool.
 *)
let scompare (s1 : string) (s2 : string) : bool =
  if ((compare s1 s2) = 0) then true
  else false

let isUnaryOprt (o : string) : bool = 
   (scompare o "-") ||
   (scompare o "~") ||
   (scompare o "!")

(*  The objective of this method is to check whether the element specified by
 *  the location should be undergo transformation.
 * *)
let permitTransformation (loc : location) : bool =
    begin
        (*  Note that in this function we will iterate over all files 
         *  in the system directories list to see if any one of them is the
         *  prefix of file name given to us.
         *  For this purpose of "matching" we will use the match_file_name 
         *  function
         *)  
        let is_sys_file (file_name : string) : bool =
            (*  Note that here file_name is location of the global 
             *  element while dir_name is name of the directory in the 
             *  list that we have been supplied at the start of the 
             *  transformation *)
            let match_file_name (file_name : string ) 
                                (dir_name : string ) : bool =

                (*  Note that this regular expression is basically to
                 *  check if the dir_name is the prefix of supplied file
                 *  name    *)
                let prefix_regexp = Str.regexp 
                                    ((Str.quote dir_name) ^ ".*")
                in
                (Str.string_match prefix_regexp file_name 0)
            in

            try (
                ignore (List.find (match_file_name file_name) !sys_dirs_list);
                true
            ) with 
            |   Not_found ->    false
        in
        not (is_sys_file loc.file)
    end

(* Function to check if the call to the function specified
   by fname is to be transformed. *)
let permitFuncTransform (fname: string) : bool =
    not (List.exists (scompare fname) !dont_trans_funccall_list)


(* Is the return of this function needs to be processed specially? *)
let permitSpecialRetProcessing (fname : string) : bool =
    List.exists (scompare fname) !func_ret_proc_list

(* Verifies it the input expression is a variable *)
let verifyVar (e : exp) : bool =
  match e with
    Lval(Var(_),NoOffset) -> true
   | _ -> false

(* This function checks if the condition of if-else
* statement satisfies the grammer of our language.
* Remember that our language only allows only a variable or
* variable involving conditional operators 
* in the if-else condition. We do not
* expect to get SizeOf, SizeOfE, AlignOf, AlignOfE here as
* doSimplify pass of cilly must have done this for us already.
*)
let validateIfCondition (e : exp) : bool = 
   (* Allow comparison operators as condition in if *)
   let allowBinOpinIfStmt (bop : binop) : bool =
       match bop with
        Lt | Gt | Le | Ge | Eq | Ne -> true
      | _ -> raise (Incorrect_Input ("[allowBinOpinIfStmt] Received " ^
                    "unexpected binary operator in if-else statement" ^
                    " at " ^ printLocation ))
   in
   match e with
     Lval(Var(_), NoOffset) -> true
   | UnOp(uop,_,_) -> true
   | BinOp(bop,_,_,_) -> allowBinOpinIfStmt bop
   | _ -> raise (Incorrect_Input ("[validateIfCondition] Received " ^
             "unexpected condition (" ^ printExp e ^ ") in if-else statement" ^ 
             " at " ^ printLocation ))

(* Is this assignment to memory? *)
let isAssignmentToMem (l : lval) : bool =
match l with
(Var(_),_) -> false   (* simple var: no assignment to mem *)
| (Mem(_),_) -> true  (* pointer dereference: assignment to mem *)

(* A list to store function prototypes that are to be added
 * to this file *)
let gFuncProto = ref []

(* Queue the prototype of a function for later addition *)
let queueFuncProto (g: global) : unit = 
    (gFuncProto := (List.append !gFuncProto [g]);)

(* Insert the gathered function prototypes before the
 * start of function definitions. We want to skip any
 * system-defined function definitions and hence we use
 * permitTransformation below.
 *)
let insertProtos (protos : global list) (globals : global list) 
    : global list = 
    let isGFun (g : global) : bool = 
        match g with
         GFun(_,_) -> true
        | _ -> false
    in
    let rec iterGlobals (gs : global list) (finGbls : global
    list) : global list = 
    match gs with
       g::gs' when permitTransformation (get_globalLoc g) && isGFun g -> finGbls @ protos @ gs
       | g::gs' -> iterGlobals gs' (finGbls @ [g])
       | [] -> finGbls
    in
    iterGlobals globals []

(*
(*
* Function to create fields of element_t structure
*)
let create_element_t_typ_fields (cinfo : compinfo) =
[
(* First field is uintptr_t address *)
(fldAddress, TInt(IULong,[]), None, [], locUnknown);

(* Second field is bool isSymbolic *)
(fldIsSymbolic, TInt(IBool,[]), None, [], locUnknown);

(* Third field is struct element* next *)
(fldNext, TPtr(TComp(cinfo, []),[]), None, [], locUnknown);
]

(*
* Function for creating element_t type
*)
let element_t_typ = TNamed({tname = typElement_t; 
                        ttype = (TComp ((Cil.mkCompInfo true typElement
                        create_element_t_typ_fields []), [])); 
                        treferenced = true}, [])
(*
* Function for creating element_t* and element_t** type
*)
let element_t_ptr_typ = TPtr (element_t_typ, [])
*)

(*
* OCaml boolean to C boolean conversion
*)
let getBoolExp (b : bool) : exp = 
if (b) then
    Const(CInt64 ((Int64.of_int 1), IBool, None)) 
else
    Const(CInt64 ((Int64.of_int 0), IBool, None)) 

(*
* Function to print hash table contents. Debugging purpose.
*)
let printGotoLabelsTbl (func : string) (labelList : string list) : unit =
    let print (s : string) : unit =
        print_string (s ^ " ");
    in
    begin
    print "\n *** Printing one key value pair *** \n ";
    print func;
    print " --> ";
    List.iter print labelList;
    print "\n";
    end

(* Check if attribute is symbolic *)
let searchAttrListForSymAttr (Attr(name, _) : attribute) : bool = 
scompare name attrSymbolic

(* Search the attribute list for Symbolic attribute *)
let rec searchTypeAttrList (t : typ) : bool =
if (List.exists searchAttrListForSymAttr (typeAttrs t)) then
true
else
match t with
  TPtr(t',_) ->  searchTypeAttrList t'
 | _ -> false

(* Generate the name for the transformed function *)
let getTransFuncName (fname : string) : string =
fname ^ transformed_func_suffix

(* Is this the transformed function ? *)
let isTransFuncName (fname : string) : bool =
let trans_func_suffix_len = (String.length transformed_func_suffix)
in

if((String.length fname) <= trans_func_suffix_len)
then false
else
((String.sub fname ((String.length fname) - trans_func_suffix_len)
  trans_func_suffix_len) = transformed_func_suffix)

(* 
* Will the given function transformed?
*
* If its prototype has atleast one parameter which
* is marked as symbolic, then it will be transformed.
* Otherwise, it won't be transformed. 
*
* If transformed, it also returns the number of formal
* parameters which are marked as symbolic. If not to be
* transformed, then it returns 0.
*
* We also check if the function that we are checking for
* is a system function such as memset, strcpy. If it is
* then we do not want to transform it.
*)
let willFuncTransformed (func : varinfo) : bool * int =
    if (permitTransformation func.vdecl)
    then true,0
    else false,0

(* Get the list of formal parameters of this function *)
(*let rettype,formalparamlistopt = getFuncComponents funcType 
in

(* Search attribute list of a formal parameter to see
* it has "symbolic" attribute to it. *)
let searchFormalParamAttrList ((_,type',_) : (string * typ * 
  attributes)) : bool =
List.exists searchAttrListForSymAttr (typeAttrs type')
in

(* Get the list of formal parameters that are marked as
* symbolic *)
let symFormalParams = List.filter
searchFormalParamAttrList (argsToList formalparamlistopt)
in

(* Is return type marked as symbolic? The idea here is that
* if return type is marked as symbolic, then we transform
* the function (even if no argument is marked as symbolic)
*)
let isRettypeSymbolic = searchTypeAttrList rettype in

if ((List.length symFormalParams) = 0) then
(* If return type is symbolic, then we want to
 * transform the function. *)
if (isRettypeSymbolic) then
  true,0
else
  false,0
else
true,(List.length symFormalParams)*)


(*  ======================================================================== *)
(*            All transformers                                               *)
(*  ======================================================================== *)

(*
* This class transforms the code for symbolic execution.
*
* The transformations described are as per following
*
* (P stands for program, S for statement, A for assignment statement,
* I for if-then-else, and W for compound statement, L and R for lhs and 
* rhs of assignments, V for a variable (not a memory location),
* and C for a constant.)
* 
* P ::= S+
* S ::= A | I(V, S1, S2) | W(V, S) | S1; S
* A ::= R | V = R | *V = V
* R ::= O op O | op O | f(V1,...,Vn)
* O ::= V | C
* 
* We will define a function "T" that takes two input parameters: a C-program
* statement S and an abstract environment E. While the abstract environment
* could hold any type of information about variables, for now, we will
* settle for the case that E says whether a variable is possibly symbolic,
* or definitely not. The output of T is a pair (S', E), where S' is the
* transformed version of the input statement S, and E' is the new abstract
* environment.
* 
* /*************** Handle assignment statements first *********************/
* 
* A ::= R | V = R | *V = V
* R ::= O op O | op O | f(V1,...,Vn)
* O ::= V | C
* 
* //
* // Note: Quotes are used to delineate code that is emitted by T.
* //
* T(V = O1 op O2, E) = 
* 	if sym(O1, E) || sym(O2, E) // One of O1 or O2 is possibly symbolic
* 	   ("addOpCons(eq, op, V, O1, O2)", E[V <-- sym])
* 	else ("V = O1 op O2", E)
* 
* //
* // As is to be expected, handling of function calls in assignments, as 
* // described below, is almost the same as the operator case above. Yet,
* // we separate it below just to be clearer about manually defined replcements
* // for functions. Of course, this idea of manually defined constrained 
* // versions of operations, can be extended to operators as well, and may be
* // particularly relevant for relational operators.
* //
* T(V = f(V1,...,Vn), E) =
* 	if sym(Vi, E) for any i
* 	   if f_cons is defined      // f_cons is a manually defined version of f
* 	      (f_cons(V1,...,Vn, V), // that can handle symbolic arguments. We will
* 	                E[V <- sym]) // selectively define such functions, e.g., for
* 	                             // RTX accessor functions
* 	   else if transformed(f)    
* 	      ("f(V1,...,Vn)", E[V <- sym])
* 	   else // Obviously, we want to avoid this explosion. So, we should
* 	        // make sure that this is done only if a f is marked as "not to 
 * 	        // be transformed." Otherwise, any function that is potentially
 * 	        // called with symbolic variables should be transformed.
 * 	      ("for_each_concrete_value v1 of V1
 * 	          ...
 * 	              for_each_concrete_value vn of Vn
 * 	                 fork_and_continue();
 * 	                 V1 = v1; ... ; Vn = vn;", E)
 * 	else ("f(V1,...,Vn)", E)
 * 
 * T( *V1=V2, E) =
 *    if (sym(V2))
 * 	  ("for_each_concrete_value v2 of V2
 * 	      fork_and_continue();
 * 	      *V1 = v2;", E) // Need to think carefully if we shd E <-- nonsym(V2)
 *    else ("*V1=V2", E);
 * 
 * /****************** Handle other statements *************************/
 * 
 * S ::= S1; S | I(V, S1, S2) | W(V, S) 
 * 
 * T(S1; S2, E) =
 *    let (S1n, E1) = T(S1, E),
 * 	   (S2n, E2) = T(S2, E1) in
 *    ("S1n; S2n;", E2)
 * 
 * T(I(V, S1, S2), E) =
 *    if sym(V, E)
 *    ("if (fork() == 0) 
 * 	   addBoolCons(V, true); // Boolean constraints may need special handling
 * 	   T(S1,E); // Again, shd we update E to indicate V is nonsym?
 * 	 else
 * 	   addBoolCons(V, false);
 * 	   T(S2,E);",
 * 	E) 
 * 
 * T(W(V, S)) = TBD
 * 
 * 
 * /************************* Helper functions **********************/
 * addOpCons(cons, op, V, O1, O2) {
 *    if sym(O1) || sym(O2)  // Runtime check, requires metadata maintenance
 * 	                      // Since variables (and not storage) can hold symbolic
 * 	                      // values, metadata can be maintained using variables,
 * 	                      // i.e., for a variable X, we introduce X_meta to
 * 	                      // hold metadata.
 * 	  if supported_op(op) // Check if we support op in constraints
 * 	     addCons(cons, op, V, O1, O2);
 * 	     mark_sym(V);
 * 	  else
 *       V = O1 op O2
 *  // Treatment of unary ops and moves (V1 = V2 or V1 = C) can be handled
 *  // by the above code by defining appropriate operators and with some
 *  // checks on number of operands 
 * }
 *)
class transformFuncsForSymbolicExe (fi:file) (file_name:string) =
  object (self)
    inherit nopCilVisitor

  (* =============================================================== *)

	(* Compile time table maintaining the list of
	 * symbolic variables of a current function.
	 *)
    val symbolicVarsTbl = (Hashtbl.create 10)
 
	(* Since Cil does not provide a way to 
	 * access current function inside a method like
	 * vstmt, we need to do this trick.
	 *)
	  val mutable currFuncRef = dummyFunDec

    val mutable retGenCount = makeVarinfo false "ret_gencount"
    (TPtr(symIDType,[]))

    (* Reference to symVarList *)
    val mutable symVarListVinfoRef = makeVarinfo 
                      false "symVarListVinfoRef" voidType 

    (* Enum for TermType *)
    val termType = {ename = "TermType"; eitems = [
        ("ICONST",    Const(CInt64 ((Int64.of_int 0), IInt, None)), locUnknown);
        ("CCONST",    Const(CInt64 ((Int64.of_int 1), IInt, None)), locUnknown);
        ("SCONST",    Const(CInt64 ((Int64.of_int 2), IInt, None)), locUnknown);
        ("FCONST",    Const(CInt64 ((Int64.of_int 3), IInt, None)), locUnknown);
        ("VAR",       Const(CInt64 ((Int64.of_int 4), IInt, None)), locUnknown);
        ("LIST",      Const(CInt64 ((Int64.of_int 5), IInt, None)), locUnknown);
        ("LISTT",     Const(CInt64 ((Int64.of_int 6), IInt, None)), locUnknown);
        ("MAX_TTYPE",   Const(CInt64 ((Int64.of_int 7), IInt, None)), locUnknown);
        ]; eattr = []; ereferenced = true; ekind = IInt; }

    (* Given a type returns if that a variable of that type can be possibly
     * symbolic. We use this function in primararily deciding if some formal
     * parameters can be symbolic. We do not use annotations for that. *)
    method private canBeSymbolicType (t : typ) : bool =
        match t with
        TVoid(_) -> false
        | TInt(_,_)
        | TFloat(_,_) 
        | TEnum(_,_) -> true
        (* Since we want to allow rtl pointers (rtx) to be symbolic,
         * we need to handle TPtr and TNamed case *)
        | TPtr(t',_) -> self#canBeSymbolicType t'
        | TNamed(ti,_) -> if ((scompare ti.tname "rtx") ||
                             (scompare ti.tname "const_rtx"))
                          then true
                          else false
        (* For structures and arrays, our current policy is to make
         * them symbolic only if either one of the following 2 is
         * satisfied:
         *    (1) - it is an rtl structure with name rtx_def
         *    (2) - it is annotated as symbolic.
         *)
        | TComp(ci,attrs) -> (scompare (compFullName ci) "struct rtx_def") ||
                                List.exists searchAttrListForSymAttr attrs
        | TArray(_,_,attrs) -> List.exists searchAttrListForSymAttr attrs
        | _ -> false

    (* Returns if an input expression can be possibly symbolic.
     *
     * This is important point: We want fields of RTL structure to be symbolic.
     * But we want such fields to be accessed ONLY by RTL accessor functions.
     * We manually define such accessor functions for RTL. In our transformation,
     * only variables (including structures and arrays which are annotated as
     * symbolic) can be symbolic. Also variables
     * whose addresses are not taken can be symbolic.
     *)
    method private canBeSymbolic (e : exp) : bool =
        match e with
        (* Non-scalar and non-array type variables whose address is
         * taken could not symbolic. *)
        Lval(Var(v),NoOffset) when (not (isArrayType (typeOf e))) &&
                                   (isScalarType (typeOf e))
                -> (not v.vaddrof) && self#canBeSymbolicType v.vtype
        | Lval(Var(v),NoOffset)
        | Lval(Var(v),Index(_,_))
        | Lval(Var(v),Field(_,_)) -> self#isSymbolic e || 
                                List.exists searchAttrListForSymAttr v.vattr
        | Const(_) -> false
        | CastE(_, e1) -> (* TODO: *) (*self#canBeSymbolic e1*) true
        | _ -> raise (Incorrect_Input ("[canBeSymbolic] Unexpected input expression "  ^
                      printExp e ^ " for symbolic test" ^ " at " ^ printLocation ))

    (* Checks if the given variable is symbolic or not at compile time.
     * We maintain runtime metadata for symbolic variables also. So a variable
     * that is symbolic at compile time may not be symbolic at run time.
     * The following function tells if a variable is symbolic at compile
     * time. If a variable is not symbolic at compile time, then it is 
     * definitely not going to be symbolic at run time as COMPILE-TIME INFO
     * IS OVER-APPROXIMATION OF RUN-TIME INFO.
     *)
    method private isSymbolic (e : exp) : bool = 
      match e with
      (* simple variables as well as array and struct type variables
       * can be symbolic *)
        Lval(Var(v),_) -> (Hashtbl.mem symbolicVarsTbl v.vname)
	    | Lval(Mem(_),_) 
        | Const(_) 
	    | AddrOf(_)
	    | StartOf(_) -> false
	    | CastE(_, e1) -> self#isSymbolic e1
		    (* We do not allow UnOp and BinOp to be the part of our 'e' after
		     * we use --dosimplify. CIL should already break these down.
		     * So is the case with arrays. In case, it does not, then we can catch 
		     * these errors here. That is why we raise exception rather than 
		     * returning false. Debugging is easier with exceptions. *)
        | _ -> raise (Incorrect_Input ("[isSymbolic] Received unexpected " ^
                        "expression." ^ " at " ^ printLocation ))


    (* Make given variable symbolic. These are compile-time symbolic
     * variables. Some of these may not be symbolic at run time. *)
    method private setSymbolic (v : varinfo) : unit =
        try(if (self#canBeSymbolic (varToLval v))
            then Hashtbl.add symbolicVarsTbl v.vname 1
            else ()
           ) with error -> ()

    (*
     * Given an expression return an expression representing
     * the address of that expression.
     *)
    method private genAddrExp (e : exp) : exp = 
      begin
      try (if (self#canBeSymbolic e) then
             mkAddrOf (getLvalFromExp e) 
           else
             (* If it is not a symbolic variable, then we
              * return zero. This is consistent with the
              * implementation of macros in symHelper.h.
              * If you modify that implementation, then
              * update here also. *)
             zero
          )
      with error -> zero
      end

    (* Since we expect statements to be in 3 address code, there will be
     * only 3 parts of the right hand side expression i.e., 2 operands, and
     * one operator. Now all of the 3 parts may not be present all the time,
     * e.g., in case of statement like x = 5;. So in such case, we return
     * expression for None to indicate which part is present and which one 
     * is not. 
     *)
    method private getPartsOfRHSExp (e : exp) : exp * string * exp option =
      match e with
        Const(_) 
      | Lval(_)
      | CastE(_,_)
      | AddrOf(_)
      | StartOf(_) -> (e, "Nop", None)
      | UnOp(uop,e1,_) -> let opstr = Pretty.sprint 80 (d_unop () uop) in
                            (e1, opstr, None)
      | BinOp(binop,e1,e2,_) -> let opstr = Pretty.sprint 80 (d_binop () binop) 
                                in
                            (e1, opstr, Some(e2))
      | _ -> raise (Incorrect_Input ("[getPartsOfRHSExp] Received unexpected " ^
                          "expression on right hand side." ^ " at " 
                          ^ printLocation))

    (* Find the type of the term from original type *)
    method private getTermTypeFrmOrigType (t : typ) : exp =
      match t with
      TInt(IInt,_) | TInt(IUInt,_) | TInt(IShort,_) | 
      TInt(IUShort,_) | TInt(ILong,_) | TInt(IULong,_) |
      TInt(ILongLong,_) | TInt(IULongLong,_) -> 
        Const(CEnum(Const(CInt64 ((Int64.of_int 5), IInt, None)),"ICONST", termType))
      | TInt(IChar,_) | TInt(ISChar,_) | TInt(IUChar,_) -> 
        Const(CEnum(Const(CInt64 ((Int64.of_int 1), IInt, None)),"CCONST", termType))
      | TFloat(FFloat,_) -> 
        Const(CEnum(Const(CInt64 ((Int64.of_int 3), IInt, None)),"FCONST", termType))
      | TPtr(t,_) -> begin match t with
        | TNamed(ti,_) -> if ((scompare ti.tname "rtx") ||
                             (scompare ti.tname "const_rtx"))
                          then Const(CEnum(Const(CInt64 ((Int64.of_int 5), 
                                IInt, None)),"ICONST", termType))
                          else Const(CEnum(Const(CInt64 ((Int64.of_int 7), 
                                IInt, None)),"MAX_TTYPE", termType))
        | TComp(ci,_) when (scompare (compFullName ci) "struct rtx_def") ->
                Const(CEnum(Const(CInt64 ((Int64.of_int 5), 
                                IInt, None)),"ICONST", termType))
        | _ -> Const(CEnum(Const(CInt64 ((Int64.of_int 7), 
                                IInt, None)),"MAX_TTYPE", termType))
        end
      | TNamed(ti,_) when ((scompare ti.tname "rtx") ||
                           (scompare ti.tname "const_rtx")) ->
          Const(CEnum(Const(CInt64 ((Int64.of_int 5), IInt, None)),"ICONST", termType))          
      | _ -> 
        Const(CEnum(Const(CInt64 ((Int64.of_int 7), IInt, None)),"MAX_TTYPE", termType))

    (*
     * Find the type of the term from the input expression. This function is
     * closely tied to TermType enum defined in cons_solve.h.
     *)
    method private getTermTypeFrmExp (e : exp) : exp =
      match e with
        Const(CInt64(_,_,_)) -> 
            Const(CEnum(Const(CInt64 ((Int64.of_int 0), IInt, None)),"ICONST",
            termType))
        | Const(CChr(_)) -> 
            Const(CEnum(Const(CInt64 ((Int64.of_int 1), IInt, None)),"CCONST",
            termType))
        | Const(CStr(_)) 
        | Const(CWStr(_)) ->
            Const(CEnum(Const(CInt64 ((Int64.of_int 2), IInt, None)),"SCONST",
            termType))
        | Const(CReal(_,_,_)) -> 
            Const(CEnum(Const(CInt64 ((Int64.of_int 3), IInt, None)),"FCONST",
            termType))
        | Lval(Var(_),NoOffset) -> 
            (* In this case, we need to check if the variable is symbolic,
             * in that case we return "VAR" as type. If it is not symbolic,
             * then we need to check the type of that variable. If it is
             * of type integer, then we return "ICONST" and so on for
             * remaining types.
             *
             * This is to handle the case of
             * i = j where j is not symbolic.
             *
             * In our constraint language symbolic variables are recognized by
             * IDs and besides them, we have constants such as integer, float,
             * etc. In constraint language, there is no notion of non-symbolic
             * variable. *)
            if (self#isSymbolic e)
            then Const(CEnum(Const(CInt64 ((Int64.of_int 4), IInt, None)),"VAR",
                 termType))
            else (self#getTermTypeFrmOrigType (typeOf e))
        | CastE(t,e) -> (self#getTermTypeFrmExp e)
        | _ -> Const(CEnum(Const(CInt64 ((Int64.of_int 7), IInt, None)),"MAX_TTYPE",
            termType))
                (*raise (Unexpected_Case ("[getTermTypeFrmExp] Received " ^
                    "unexpected expression (" ^ wrong_expr ^ 
                    " to find term type at " ^ printLocation)))*)

    (* =============================================================== *)

    (* Transform every instruction *)
    method private transformInstr (currInst : instr) : instr list =
      match currInst with
        Set(v,rhs,loc) -> (* assignment instruction *) 
          (* Is it assigning to memory? If no, then it is
           * the case of V = O1 op O2. Otherwise, it is 
           * the case of *V1 = V2 *)
          if (not (isAssignmentToMem v)) then
            let o1,oprt,o2opt = (self#getPartsOfRHSExp rhs) in
            let oprtstr = Const(CStr(oprt)) in
            let call_version =
              match (v,o2opt) with
               (* lhs is array or structure access, and 
                * rhs is simple variable with no operator *)
                ((Var(v'),Index(_,_)) as lv, None)
               | ((Var(v'),Field(_,_)) as lv, None) 
                  when (self#canBeSymbolic (varToLval v') &&
                        scompare oprt "Nop")-> begin
                    match o1 with
                        Lval(_,Index(_,_)) 
                        | Lval(_,Field(_,_)) ->
                                raise (Incorrect_Input ("[transformInstr] Received" ^ 
                                printExp o1 ^ " on RHS of assignment at " ^
                                printLocation ^ " and this is not expected " ^
                                " as it should have been simplified by this " ^
                                " time."))
                        | _ ->
                            let lv',lo = removeOffsetLval lv in
                            let lvt = typeOf (Lval lv') in
                            match lo with
                             Index(i,_) ->
                                Call(None, varToLval funPutElemConsHelper.svar,
                                [self#genAddrExp (Lval lv');
                                 getArrayLenFromType lvt;
                                 i; o1; self#genAddrExp o1;
                                 self#getTermTypeFrmExp o1;
                                 self#getTermTypeFrmOrigType (typeOf o1)], locUnknown)
                             | Field(f,_) ->
                                Call(None, varToLval funPutFieldConsHelper.svar,
                                [self#genAddrExp (Lval lv');
                                 Cil.integer (List.length f.fcomp.cfields);
                                 Cil.integer (getFieldNumFromStruct f);
                                 Cil.mkString (getStructNameFromType lvt);
                                 o1; self#genAddrExp o1; self#getTermTypeFrmExp o1;
                                 self#getTermTypeFrmOrigType (typeOf o1)], locUnknown)
                             | _ -> raise (Unexpected_Case ("[transformInstr]" ^
                                           "Received NoOffset: " ^ printExp o1))
                  end
                 (* lhs is a variable access and rhs is an operand with either 
                  * no operator or unary operator *)
               | ((Var(_),_),None) 
                 when (scompare oprt "Nop") -> begin
                    (* No operator case: e.g., x = 5 *)
                    match o1 with 
                        Lval((Var(v'),Index(_,_)) as lv) (* rhs is an array
                        or struct access *)
                        | Lval((Var(v'),Field(_,_)) as lv) 
                        when (self#canBeSymbolic (varToLval v')) -> begin
                            let lv',lo = removeOffsetLval lv in
                            let lvt = typeOf (Lval lv') in
                            match lo with
                             Index(i,_) ->
                                Call(None, varToLval funGetElemCons.svar,
                                [self#genAddrExp (Lval lv');
                                 getArrayLenFromType lvt;
                                 i; self#genAddrExp (Lval v)], locUnknown)
                             | Field(f,_) ->
                                Call(None, varToLval funGetFieldCons.svar,
                                [self#genAddrExp (Lval lv');
                                 Cil.integer (List.length f.fcomp.cfields);
                                 Cil.integer (getFieldNumFromStruct f);
                                 Cil.mkString (getStructNameFromType lvt);
                                 self#genAddrExp (Lval v)], locUnknown)
                             | _ -> raise (Unexpected_Case ("[transformInstr]" ^
                                        "Received NoOffset: " ^ printExp o1))
                          end
                        | AddrOf(lv) -> (* We do not allow taking an address
                            of an object other than 0th element of array. To be precise,
                            we allow taking an address of 0th element of an array irrespective
                            of if array is symbolic at compile time or not. We do not want
                            to enforce constraint that address of only symbolic array can be taken.
                            If we do that then we would break programs. *)
                            begin
                            let lv',off = removeOffsetLval lv in
                            let listexp = Const(CEnum(Const(CInt64 ((Int64.of_int 5), 
                                          IInt, None)),"LIST", termType)) in
                            match off with
                            Index(zero,_) ->
                                Call(None, varToLval funAddOpCons_nop.svar, 
                                [consstrEq; Lval(v); Lval(lv'); 
                                (self#genAddrExp (Lval v));
                                (self#genAddrExp (Lval lv'));
                                (self#getTermTypeFrmExp (Lval v)); 
                                (* We pass LIST as the type for array accesses *)
                                listexp; listexp; zero], locUnknown)
                            | _ -> raise (Unexpected_Case("[transformInstr] " ^
                             "addressOf operation detected at " ^
                             printLocation ^ " for " ^ printExp o1))
                            end
                        | StartOf(lv) -> (*TODO: May be we need to handle
                              this case? *)
                              raise (Unexpected_Case("[transformInstr] " ^
                             "StartOf operation detected at " ^
                             printLocation ^ " for " ^ printExp o1))
                        | _ -> (* rhs is not an array or structure field *)
                            Call(None, varToLval funAddOpCons_nop.svar, 
                            [consstrEq; Lval(v); o1; 
                            (self#genAddrExp (Lval v));
                            (self#genAddrExp o1);
                            (self#getTermTypeFrmExp (Lval v)); 
                            (self#getTermTypeFrmExp o1);
                            (self#getTermTypeFrmOrigType (typeOf o1)); 
                            zero], locUnknown)
                end
               (* lhs is a simple variable (not an array or structure),
                * rhs is an operand with unary operator *)
               (* Unary operator case *)
               | ((_,NoOffset), None) 
                 when (isUnaryOprt oprt) -> begin
                    match o1 with
                        Lval(_,Index(_,_)) 
                        | Lval(_,Field(_,_)) ->
                                raise (Incorrect_Input ("[transformInstr] Received" ^ 
                                printExp o1 ^ " on RHS of assignment at " ^
                                printLocation ^ " and this is not expected " ^
                                " as it should have been simplified by this " ^
                                " time."))
                        | _ ->
                            (* rhs is not an array or structure field *)
                            Call(None, varToLval funAddOpCons_unop.svar,
                            [consstrEq; oprtstr; Lval(v); o1; 
                            (self#genAddrExp (Lval v));
                            (self#genAddrExp o1);
                            (self#getTermTypeFrmExp (Lval v)); 
                            (self#getTermTypeFrmExp o1);
			                      (self#getTermTypeFrmOrigType (typeOf o1))], 
                            locUnknown)
                 end
                 (* lhs is a simple variable (not an array or structure),
                  * rhs is an operand with binary operator *)
               | ((_,NoOffset), Some(o2)) -> begin
                    match (o1,o2) with
                      (Lval(_,Index(_,_)),_) (* o1 is array access *)
                      |(Lval(_,Field(_,_)),_) (* o1 is structure access *)
                      |(_,Lval(_,Index(_,_))) (* o2 is array access *)
                      |(_,Lval(_,Field(_,_))) -> (* o2 is structure access *)
                              raise (Incorrect_Input ("[transformInstr] Received " ^ printExp o1 ^ 
                                    " and " ^ printExp o2 ^ " on RHS of assignment, at " ^ 
                                    printLocation ^ " and " ^
                                    " this is not expected as it should have " ^
                                    " been simplified by this time."))
                      | _ -> (* Non-array and non-structure binary operator case *)
                            Call(None, varToLval funAddOpCons_binop.svar,
                            [consstrEq; oprtstr; Lval(v); o1; o2; 
                            (self#genAddrExp (Lval v));
                            (self#genAddrExp o1);
                            (self#genAddrExp o2);
                            (self#getTermTypeFrmExp (Lval v)); 
                            (self#getTermTypeFrmExp o1); 
                            (self#getTermTypeFrmExp o2);
                            (self#getTermTypeFrmOrigType (typeOf o1));
                            (self#getTermTypeFrmOrigType (typeOf o2))], locUnknown)
                  end
               | _ -> raise (Unexpected_Case ("[transformInstr] Received " ^
                             "unexpected expressions in the statement " ^
                              printInstr currInst ^ ". The expressions in " ^
                              " this statement should have been simplified " ^
                              " but somehow they are not."))
          in
          let _ =
            match v with
            (Var(v),_) -> self#setSymbolic v
            | _ -> ()
          in
            [call_version]
          else
            (*TODO: Implement the case of *V1 = V2 here *)
            [currInst]

        (* If a function is called via function pointer then we leave that
         * instruction as it is *)
        | Call(lvopt,(Lval(Var(vinfo),NoOffset) as func),args,_) 
		when (permitFuncTransform vinfo.vname) -> 
	    if ((scompare vinfo.vname "putc_unlocked") ||
		(scompare vinfo.vname "fputs_unlocked") ||
		(scompare vinfo.vname "fprintf")) then
              let printFuncVar = emptyFunction (vinfo.vname ^ "_print") in
              [Call(lvopt, (varToLval printFuncVar.svar),args,locUnknown)]
	    else

            (* Check if atleast one argument is symbolic. If we do not have
             * a symbolic argument, then we just perform normal function call.
             * *)
            let atleastOneActualArgSym = (List.exists self#isSymbolic args)  in
            if (atleastOneActualArgSym = true) then

              (* Let us see if we have manually defined a symbolic
               * version of this function. *)
              let isFCons (name : string) : bool =
                try (if (scompare name ((getCalleeName func) ^ cons_func_suffix)) then
                  true
                else
                  false
                  (* getCalleeName can fail if a function is called thru
                   * function pointer. Return false in such case *)
                ) with error -> false
              in

              try (let symFuncName = List.find isFCons !sym_func_list in 
                   let symFuncVar = emptyFunction symFuncName in
                   (*let retVal = makeTempVar currFuncRef charConstPtrType in*)

                   match lvopt with
                    (* If the result of function call is assigned to some
                     * variable, then make it symbolic. Then we pass the address
                     * of that variable to that function call. This is case of GET_CODE
                     * like calls. If the result is assigned to structure or array, 
                     * then we return the original instruction because neither 
                     * structure nor array is symbolic for us. 
                     *
                     * If result of function call is not assigned to any
                     * variable, then it might be PUT_CODE kind of function in
                     * that case we just transform the call to the one that
                     * uses PUT_CODE_CONS. *)
                    Some((Var(vinfo),NoOffset) as lv) when ((self#isSymbolic
                    (Lval(Var(vinfo),NoOffset)))) -> begin
                      (Hashtbl.add symbolicVarsTbl vinfo.vname 1);
                      [Call(None, varToLval symFuncVar.svar,
                      [mkAddrOf(getLvalFromExp(List.hd args))] @ 
                      List.tl args @ [mkAddrOf lv], locUnknown)]
                      end
                    | _ -> [Call(None, (varToLval symFuncVar.svar),args,locUnknown)]
              )
              with Not_found -> begin
              (* We have not manually defined the symbolic version 
                 of this function. So now let us see if this function will be transformed.
                 The idea is that we will check the function prototype of callee.
                 We will check if the prototype specifies some arguments which
                 can be symbolic. If there is atleast one argument which can be
                 symbolic, then the function will be transformed. If function
                 will not transformed, then we do not use transformed call.

                 In case the function is transformed, then the prototype for
                 the function be modified as follows:

                 for a function "f (arg1, arg2, .. , argN)", let us say arg1 and
                 arg5 are symbolic, then transformed version of f will look like
                 this "f_trans (arg1, arg2, .. , argN, <symbolic value of arg1>, 
                 <symbolic value of arg5>)". When a non-symbolic actual argument
                 is passed to symbolic formal param then we send 0 as the
                 symbolic value of that actual arg.
              *)

              (* Search the prototype of callee *)
              let callee = findOrCreateFunc fi (getCalleeName func) (typeOf func)
              in
              (* Check if function will be transformed *)
              let isFuncTransformed, numSymFormalParam = willFuncTransformed
                callee
              in

              if (isFuncTransformed) then
                let rettype,formalparamlistopt = getFuncComponents callee.vtype
                in

                (* Now we will get the list of which formal parameters can be
                 * symbolic *)

                (* Take the formal parameter list, and return the position
                 * (1st, 2nd, etc) of the formal parameter which can be symbolic
                 * *)
                let rec getSymFormalParamPos (paramlist : (string * typ *
                  attributes) list) (poslist : int list) (currPos : int) 
                  : int list =
                  match paramlist with
                    (_,type',_)::ps -> begin
                      try(if (self#canBeSymbolicType type') then 
                        getSymFormalParamPos ps (poslist @ [currPos]) 
                        (currPos + 1)
                      else
                        getSymFormalParamPos ps poslist
                        (currPos + 1)
                      ) with error -> getSymFormalParamPos ps poslist (currPos + 1)
                    end
                    | [] -> poslist
                in
                (* A list containing position of the formal params
                 * which are marked as symbolic *)
                let symFormalParamList = getSymFormalParamPos (argsToList
                    formalparamlistopt) [] 1 
                in

                (* Get the position of symbolic actual arguments of the current
                 * function. *)
                let rec getSymArgPos (arglist : exp list) (poslist : int
                  list) (currPos : int) : int list =
                  match arglist with
                    a::as' -> begin
                      try(if (self#canBeSymbolic a) then
                        getSymArgPos as' (poslist @ [currPos]) (currPos + 1) 
                      else
                        getSymArgPos as' poslist (currPos + 1) 
                      ) with error -> getSymArgPos as' poslist (currPos + 1)
                    end
                    | [] -> poslist
                in
                (* list of positions of symbolic actual arguments *)
                let symArgList = getSymArgPos args [] 1 in

                (* Check that the arguments which can be symbolic 
                 * have corresponding formal parameter which can be 
                 * symbolic. This way we allow non-symbolic actual argument
                 * being passed to symbolic formal parameter. But if want
                 * to allow symbolic actual argument to be assigned to
                 * non-symbolic formal parameter then we have a case of
                 * explosion. *)
                (* symArgList Must be a subset of symFormalParamList, 
                 * and that both must be non-empty sets.
                 * If any of this does not hold, raise exception.
                 * symbolic. *)
                    
                (* Is actual argumet position list a subset of 
                 * formal argument position list ? *)
                let isActualArgSubsetFormalParamSet (aaSet : int list)
                  (fpSet : int list) : bool =
                  (* Is the position of actual argument in the
                   * formal param position list? *)
                   let isArgPosInFormalParamPosSet (argPos : int) : bool =
                      (* Is the position of actual argument same as 
                       * formal parameter position *)
                       let isArgPosEqFormalParamPos (fpPos : int) : bool =
                          argPos = fpPos 
                       in
                       (* Does there exist a formal parameter position that
                        * matches that of actual argument *)
                        List.exists isArgPosEqFormalParamPos fpSet
                   in
                   List.for_all isArgPosInFormalParamPosSet aaSet
                in
                let _ = 
                  if (isActualArgSubsetFormalParamSet symArgList
                        symFormalParamList)
                  then 
                    ()
                  else
                    raise (Unexpected_Case ("[transformInstr] actual " ^
                          "args list contains symbolic arguments " ^
                          "for which formal param is non symbolic. " ^
                          "Case of explosion: for " ^ (getCalleeName func) ^ " in " ^
                           currFuncRef.svar.vname ^ " at " ^ printLocation ^
                           " [fSymParams]=" ^ (string_of_int
                           (List.length symFormalParamList)) ^ 
                           " [aSymArgs]=" ^ (string_of_int (List.length
                           symArgList))))
                in

                (* Name of the transformed function *)
                let transFuncName = 
                  (* Let us see if we have manually defined a symbolic
                   * version of this function. *)
                  let isFCons (name : string) : bool =
                    if (scompare name ((getCalleeName func) ^ cons_func_suffix)) then
                      true
                    else
                      false
                  in

                  try (List.find isFCons !sym_func_list) 
                  with Not_found -> (getTransFuncName (getCalleeName func))
                in

                (* Now we will create the transformed function call. *)
                (*let transFuncVar = emptyFunction transFuncName                 
                in*)

                (* Let us now create statements to generate symbolic 
                 * value for actual arguments whose corresponding formal
                 * parameter is symbolic. *)
                let genSymValStmtForActualArg (args : exp list) (fpPos : int) 
                    : (exp * instr option) = 
                    let getGenCountStmt (arg : exp) : (exp * instr option) =
                        (*let newvar = makeTempVar currFuncRef symIDType in*)
                        let newvar = makeTempVar currFuncRef voidPtrType in
                        varToLval newvar, Some(Set(var newvar,
                        self#genAddrExp arg, locUnknown))
                        (*((varToLval newvar), Some(Call(Some(var newvar), 
                        varToLval funGetGenCount.svar,[self#genAddrExp arg], 
                        locUnknown)))*)
                    in
                    let arg = try (List.nth args (fpPos - 1))
                              with error -> raise (Unexpected_Case(" " ^
                                 "[updateArg] Exception in List.nth " ^
				 " for n = " ^ string_of_int (fpPos - 1) ^
                                 " while processing function " ^
                                 currFuncRef.svar.vname ^ " for instr " ^
				 printInstr currInst ^ " at " ^
                                 printLocation)) in
                    try(if (self#canBeSymbolic arg) then
                        getGenCountStmt arg
                    else
                        (*(concreteVarGcountVal, None)*)
                        (zero, None)
                    ) with error -> (*(concreteVarGcountVal, None)*) (zero, None)
                in
                let newArgsList,symValCallsOpt = List.split (List.map (genSymValStmtForActualArg 
                    args) symFormalParamList) in
                let symValCalls = List.map removeOption (List.filter isSome
                    symValCallsOpt) in
                match lvopt with
                  Some((Var(v),NoOffset)) when (self#canBeSymbolicType rettype) -> (* If this function call
                    returns some value and the return type of the function is
                    symbolic *)
                    let lv = (Var(v), NoOffset) in
                    (* If it is assignment to variable *)
                    if (not (isAssignmentToMem (lv))) then
                      (* Generate temporary to hold the symbolic
                       * return value of function call *)
                      let tmpvar = makeTempVar currFuncRef symIDType in
                      let finalArgs = args @ newArgsList @ [self#genAddrExp
                                      (varToLval tmpvar)] in
                      let transFuncType = genFuncType lvopt finalArgs in
                      let transFuncVar = findOrCreateFunc fi transFuncName
                      transFuncType in
                      (* Transformed call statement. *)
                      let transcall_instr = Call (lvopt, (varToLval
                                            transFuncVar), finalArgs, locUnknown)
                      in
                      let set_gencount_instr = Call(None,
                        varToLval funSetGenCount.svar, [self#genAddrExp
                        (Lval(lv)); varToLval tmpvar], locUnknown) in
                      begin
                          (* Queue function prototype for addition *)
                          queueFuncProto (GVarDecl(transFuncVar, locUnknown));
                          symValCalls @ [transcall_instr; set_gencount_instr]
                      end
                    else
                        (* This is the case of explosion. *)
                      raise (Unexpected_Case ("[transformInstr] case of explosion"  ^
                         " for " ^ (getCalleeName func) ^ " in body of a " ^ 
                          currFuncRef.svar.vname ^ " at " ^ printLocation))
                    
                    | _ -> (* If the function call returns nothing, or its
                    return value is assigned to array or structure, then we 
                    do not need to generate statement to assign lval. *)
                    let finalArgs = args @ newArgsList in
                    let transFuncType = genFuncType lvopt finalArgs in
                    let transFuncVar = findOrCreateFunc fi transFuncName
                      transFuncType in
                    begin
                        queueFuncProto (GVarDecl(transFuncVar, locUnknown));
                        symValCalls @ [Call(lvopt, varToLval transFuncVar, 
                        finalArgs, locUnknown)]
                    end

              else 
                [currInst]
                (* isFuncTransformed = false
                   This is the case of explosion. Currently, we just
                   raise an exception. *)
                (*TODO: Fix this. Temporarily commented to handle memset
                 *
                 * raise (Unexpected_Case ("[transformInstr] case of explosion"  ^
                      " for " ^ (getCalleeName func) ^ " in body of a " ^ 
                      currFuncRef.svar.vname ^ " at " ^ printLocation))*)
                    
             end (* Try catch *)

            else (* isAtleastOneActualArgSymbolic  = false *)
                begin
              (*print_string ("\n**** No symbolic args for " ^
              currFuncRef.svar.vname); *)
              (* In case, there is no symbolic variable, then
               * we return original instruction. *)
              [currInst]
                end

        | Call(_,f,_,_) -> 
            begin
                print_string ("\nThis seems to be a function call using function" ^
                      " pointer. This might need to be fixed manually after " ^
                      "transformation. " ^ printExp f ^ " " ^ printLocation);
                [currInst]
            end
        | _ ->             
             [currInst]

    (* Execute for every instruction *)
    method vinst (currInst : instr) : instr list visitAction =
      ChangeTo (self#transformInstr currInst)

    (* Execute for every statement inside a function *)
    method vstmt (currStmt : stmt) : stmt visitAction =
	    (* Transform one statement *)
	    let rec transformStmt (currStmt : stmt) : stmt = 
      	match currStmt.skind with
       	  Instr(ilist) -> 
              (* Iterator over all instructions in the list
               * and generate a new list *)
              let rec processInstrs (ilist : instr list) 
                    (newlist : instr list) =
                match ilist with
                i::is -> let i' = (self#transformInstr i) in
                          (processInstrs is (newlist @ i'))
                | [] -> newlist
              in
              let newstmt = mkStmt (Instr(processInstrs ilist [])) in
              begin
                newstmt.labels <- currStmt.labels;
                newstmt
              end

       	| If(e,s1,s2,loc) -> begin
            (* v will not be symbolic because it just stores the result
             * of try() *)
            (*try( *)if (validateIfCondition (e)) then
                (* Given a condition such as 
                 *
                 * if (i < j), we transform it as
                 *
                 * tmp = TRY_..(..)
                 * if (tmp) 
                 *
                 * and in the else part, we need to add a statement to 
                 * negate the condition. *)
			    (* Let us now create the if block of if-else *)
		        let s1'_bstmts = (List.map transformStmt s1.bstmts) in
				let if_block = mkBlock (s1'_bstmts) in
				(* Let us now create the else block of if-else *)
				let s2'_bstmts = (List.map transformStmt s2.bstmts) in
                let try_result = makeTempVar currFuncRef intType in
                let o1,oprt,o2opt = self#getPartsOfRHSExp e in
                let oprtstr = Const(CStr(oprt)) in
                let try_call, neg_cond_call = 
                   match o2opt with
                      None -> 
                          (* No operator case: e.g., if(x) *)
                          if (scompare oprt "Nop") then
                            (Call(None, varToLval funTryNopConsOp.svar, 
                            [varToLval try_result; o1; 
                            (self#genAddrExp o1);
                            (self#getTermTypeFrmExp o1);
                            (self#getTermTypeFrmOrigType (typeOf o1))], 
                            locUnknown), 
                            (* Negate condition in else *)
                            Call(None, varToLval funNegNopCond.svar,
                            [o1; self#genAddrExp o1], locUnknown))

                          (* Unary operator case *)
                          else 
                            (Call(None, varToLval funTryUnopConsOp.svar,
                            [oprtstr; varToLval try_result; o1; 
                            (self#genAddrExp o1);
                            (self#getTermTypeFrmExp o1);
                            (self#getTermTypeFrmOrigType (typeOf o1))], locUnknown), 
                            (* Negate condition in else *)
                            Call(None, varToLval funNegUnopCond.svar,
                            [oprtstr; o1; self#genAddrExp o1], locUnknown))
                 
                      | Some(o2) -> 
                          (* Binary operator case *)
                            (Call(None, varToLval funTryBinConsOp.svar,
                            [oprtstr; varToLval try_result; o1; o2; 
                            (self#genAddrExp o1);
                            (self#genAddrExp o2);
                            (self#getTermTypeFrmExp o1); 
                            (self#getTermTypeFrmExp o2);
                            (self#getTermTypeFrmOrigType (typeOf o1));
                            (self#getTermTypeFrmOrigType (typeOf o2))],
                            locUnknown),
                            (* Negate condition in else *)
                            Call(None, varToLval funNegBinopCond.svar,
                            [oprtstr; o1; o2; self#genAddrExp o1;
                            self#genAddrExp o2], locUnknown))
                 in
                let else_block = mkBlock ([mkStmtOneInstr neg_cond_call] @ s2'_bstmts) in
				(* Let us now create the composite if-else *)
				let if_else_stmt = If(BinOp(Ne, varToLval try_result, zero, 
                   TInt(IBool,[])), if_block, else_block, locUnknown) in
				(* Final transformed statement of original if-else *)
                let newstmt = mkStmt(Block(mkBlock ([mkStmtOneInstr try_call] @ [mkStmt
                if_else_stmt]))) in
                begin
                    newstmt.labels <- currStmt.labels;
                    newstmt
                end
             else currStmt
           (* with error -> currStmt *)
           end
			  
        | Block(blk) -> 
              let newstmt = mkStmt (Block (mkBlock (List.map transformStmt 
                                                blk.bstmts))) in
              begin
                newstmt.labels <- currStmt.labels;
                newstmt
              end
        | Return(Some(e),_) -> (* For return, we need to delete all symbolic
            values of current function from global symbolic variable list when we
            return. *)
            if (verifyVar (e)) then
              let storegencount_stmt = 
                try(if (self#canBeSymbolicType (typeOf e)) then
                (* Store the gencount of return variable in the passed pointer *)
                    mkStmtOneInstr (Call(Some(Mem (varToLval retGenCount),NoOffset), 
                    varToLval funGetGenCount.svar, [self#genAddrExp e], 
                    locUnknown))
                else
                    mkEmptyStmt ()
                ) with error -> mkEmptyStmt ()
              in
              let procret_stmt = 
                  if (permitSpecialRetProcessing currFuncRef.svar.vname) then
                    [mkStmtOneInstr (Call(None, varToLval 
                    funProcReturn.svar, [e], locUnknown))]
                  else
                    [mkStmtOneInstr (Call(None, varToLval 
                    funDeleteRecord.svar, [], locUnknown));
                    currStmt]
              in
              let newstmt = mkStmt (Block (mkBlock ([storegencount_stmt] @
              procret_stmt))) in
              begin
                newstmt.labels <- currStmt.labels;
                currStmt.labels <- [];
                newstmt
              end
            else
                raise (Unexpected_Case ("[transformStmt] Return statement " ^
                "containing different expression than that expected. This is " ^ 
                "not expected after we use --dosimplify. In body of " ^
                currFuncRef.svar.vname ^ " at " ^ printLocation))
	
				| Return(_,_) ->
              let procret_stmt = 
                    [(mkStmtOneInstr (Call(None, varToLval 
                    funDeleteRecord.svar, [], locUnknown)));
                    currStmt]
              in
              let newstmt = mkStmt (Block (mkBlock (procret_stmt))) in
              begin
                newstmt.labels <- currStmt.labels;
                currStmt.labels <- [];
                newstmt
              end
							
        | Switch(_,_,_,_) -> raise (Unexpected_Case ("[transformStmt] " ^
               "Switch-case statements should have been simplified to if-else" ^
               "by now." ^ " at " ^ printLocation))
        | Loop(blk,l,s1,s2) ->
              let newstmt = mkStmt (Loop (mkBlock (List.map transformStmt 
                                                blk.bstmts), l, s1, s2)) in
              begin
                newstmt.labels <- currStmt.labels;
                newstmt
              end
       	| _ -> currStmt
	    in
	  
		  let newstmt = transformStmt currStmt in
			begin
			  newstmt.labels <- currStmt.labels;
				ChangeTo newstmt
	    end
     
    method private postProcessFundec (currFunc : fundec) : fundec =
      (* Handle formal parameter if it can be symbolic. *)
      let handleSymFormal (fp : varinfo) : (varinfo * stmt) option = 
        (* If a formal parameter named say 'x' is of char type,
         * and hence can be symbolic, then we generate one more
         * formal parameter, let's say named 'x_id' for it which will contain 
         * ID (gencount) of actual symbolic variable. We generate if check for this 
         * variable as
         *
         * if (x_id != 0)
         *    setSymVarID(&x, x_id);
         *)
        let genIDCheck (fp : varinfo) (id : varinfo) : stmt = 
            let newvar = makeTempVar currFuncRef symIDType in
            let get_gcnt_call = Call(Some(var newvar), varToLval funGetGenCount.svar, 
                                 [varToLval id], locUnknown) in

            let newsymval = makeTempVar currFuncRef voidPtrType in
            let get_symtype_call = Call(Some(var newsymval), varToLval funGetSymValType.svar, 
                                 [varToLval id], locUnknown) in

            let set_gcnt_call = Call(None, varToLval funSetGenCount.svar,
              [(self#genAddrExp (varToLval fp)); varToLval newvar], locUnknown) in

            let set_symtype_call = Call(None, varToLval funSetSymValType.svar,
              [(self#genAddrExp (varToLval fp)); varToLval newsymval], locUnknown) in

            let if_block = mkBlock [mkStmt (Instr([get_gcnt_call; get_symtype_call; 
                                                set_gcnt_call;
                                                set_symtype_call]))] 
            in

            let if_exp = BinOp(Ne, varToLval id, (*concreteVarGcountVal*) zero, intType) in
            let if_kind = If(if_exp, if_block, mkBlock [], locUnknown) in
            mkStmt if_kind
        in
        try(if (self#canBeSymbolic (varToLval fp)) then
            begin
              (*let idvar = makeTempVar currFuncRef ~insert:false symIDType in*)
              let idvar = makeTempVar currFuncRef ~insert:false voidPtrType in
              Some(idvar, genIDCheck fp idvar)
            end
            else None
        ) with error -> None
      in
      begin
        let newFormalsStmts,_ = List.partition isSome (List.map handleSymFormal currFunc.sformals) in
        let newFormals,newstmts = List.split (List.map removeOption
        newFormalsStmts) in
        let rettype,_,_,_ = splitFunctionType currFunc.svar.vtype in
         (* Add a call to addNewRecord to store current
         * activation record for symbolic variables on stack. *)
        let addrcd_stmt = mkStmtOneInstr (Call(None, varToLval funAddNewRecord.svar,
            [], locUnknown)) in 
        (* Add a formal variable to return gencount only if return type can be 
         * symbolic *)
        (*try( *)if (self#canBeSymbolicType rettype) then
            currFunc.sformals <- currFunc.sformals @ newFormals @
            [retGenCount]
        else currFunc.sformals <- currFunc.sformals @ newFormals;(*)
        with error -> currFunc.sformals <- currFunc.sformals @ newFormals;*)
        currFunc.sbody.bstmts <- [addrcd_stmt] @ newstmts @ currFunc.sbody.bstmts; 
        (*currFunc.sbody.bstmts <- compactStmts currFunc.sbody.bstmts;*)
        currFunc
     end

	(* Execute for every function *)
    method vfunc (currFunc : fundec) : fundec visitAction =
      if ((isTransFuncName currFunc.svar.vname) &&
        (* We do not want to transform main *)
        not (scompare currFunc.svar.vname "main")) then
        begin
            (* Let us clear the hash table of the previous function *)
            Hashtbl.clear symbolicVarsTbl;
            currFuncRef <- currFunc;
            List.iter self#setSymbolic currFunc.sformals;
            List.iter self#setSymbolic currFunc.slocals;
            ChangeDoChildrenPost(currFunc, self#postProcessFundec)
        end
        else SkipChildren

    (* For every global, check if we need to process it *)
    method vglob (currGlob : global) : global list visitAction =
        if (permitTransformation (get_globalLoc currGlob)) then
            DoChildren
        else
            SkipChildren
  end

(* This class simplifies some expressions to make them more amenable
 * for transformation. In particular, we need to simplify following cases.
 * 
 * (1) In an assignment statement like *V1 = E2, 
 * the right hand side must be a variable. So whenever we see an
 * assignment like *V1 = E2 where E2 is an expression. We will
 * transform it into 2 statements [V_tmp = E2; *V1 = V_tmp]
 *
 * (2) In the condition for if-else like "if ( *E )", our transformation
 * allows only variable or variables involving comparison operators. 
 * So statement like if-else needs to be transformed
 * into 2 statement [V_tmp = *E; if (V_tmp) ..]
 *
 * (3) In return statement like "return x", x must be either a variable; 
 * it cannot be an expression or a constant. If it is expression, then we
 * introduce an assignment statement before it.
 *
 * (4) In an assignment statement like lhs = rhs; 
 *  4.1) rhs cannot be following expressions:
 *    - Unary operator on compound expressions like !a.b, !a[0]
 *    - Binary operator whose either operand is compound expression like
 *      a.b, a[0]
 *  4.2) lhs must confirm following rules:
 *    - if lhs is compound expression like a.b, a[0], then rhs must be
 *    a simple variable and cannot be an rhs from 4.1
 *
 * Note that transformation has more requisites such as three address code 
 * form, etc. But most of them are provided by Cil's dosimplify option. 
 * Rest are provided by this class.
 *)
class simplifyStatements (f:file) (file_name:string) =
  object (self)
    inherit nopCilVisitor

    (* Since Cil does not provide a way to 
     * access current function inside a method like
     * vstmt, we need to do this trick.
     *)
    val mutable currFuncRef = dummyFunDec

    (* Simplify every instruction *)
    method private simplifyInstr (currInst : instr) : instr list =
        (* Change the reference to compound expression
         * such as array or structure reference
         * by assigning array or structure reference to
         * a simple variable and then use that simple
         * variable in the assignment. *)
        let rec chgCompRef (e':exp) : exp * instr list =
            match e' with
               Lval(_,Field(_,_))
               | Lval(_,Index(_,_)) ->
                  let tmp_var_lval = (var (makeTempVar currFuncRef (typeOf 
                    e'))) in
                  let tmp_assignment = Set(tmp_var_lval, e', locUnknown) in
                  Lval(tmp_var_lval),[tmp_assignment]
               | BinOp(bop,e1,e2,t) ->
                  let e1',i1l = chgCompRef e1 in
                  let e2',i2l = chgCompRef e2 in
                  BinOp(bop,e1',e2',t),i1l@i2l
               | UnOp(uop,e,t) ->
                  let e',il = chgCompRef e in
                  UnOp(uop,e',t),il
               | CastE(t,e) ->
                  let e',il = chgCompRef e in
                  CastE(t,e'),il
               | _ -> e',[]
        in
      match currInst with
        (* Case (1) *)
        Set((Mem(_),_) as lv,e,_)
        (* Case 4.2 *)
        | Set((Var(_),Index(_,_)) as lv,e,_)
        | Set((Var(_),Field(_,_)) as lv,e,_) -> begin
          match e with
            Lval(Var(_),NoOffset) | Const(_) 
          | SizeOf(_) | SizeOfE(_) | SizeOfStr(_) 
          | AlignOf(_) | AlignOfE(_) -> [currInst]
          | _ -> 
		    let tmp_var_lval = (var (makeTempVar currFuncRef (typeOf e))) in
         	let tmp_assignment = Set(tmp_var_lval, e, locUnknown) in
            let new_assignment = Set(lv, Lval(tmp_var_lval),
                                      locUnknown) in
            self#simplifyInstr tmp_assignment @ [new_assignment]
          end
        (* Case 4.1 *)
        | Set((Var(_),NoOffset) as lhs,e,_) -> begin
            match e with
             BinOp(_,_,_,_) | UnOp(_,_,_)
             | CastE(_,_) ->
               let e',il = chgCompRef e in
               let new_assignment = Set(lhs,e',locUnknown) in
               il@[new_assignment]
             | _ -> [currInst]
          end

        | Call(lvopt,f,args,_) -> 
            (* We need to see if return value of a function is assigned to
             * array or structure component, and also if function's arguments
             * are components of array or structure. In that case we need to
             * follow 4.1 and 4.2. *)
            (* List.rev to handle right-to-left argument processing in C *)
            let newargs, newinstrsl = List.split (List.map chgCompRef (List.rev
            args)) in
            let newinstrs = List.flatten newinstrsl in
            let newlvopt, new_assign = 
            match lvopt with
                Some((_,Index(_,_)) as lv)
                | Some((_,Field(_,_)) as lv) ->
                    let tmp_lval = (var (makeTempVar currFuncRef 
                                    (typeOf (Lval lv)))) in
                    let new_assign = Set(lv, Lval(tmp_lval), locUnknown) in
                    Some(tmp_lval), [new_assign]
                | _ -> lvopt, []
            in
            let new_call = Call(newlvopt, f, List.rev newargs, locUnknown) in
            (List.flatten (List.map self#simplifyInstr newinstrs)) @ [new_call] @ new_assign

        (* For all others we do nothing *)
        | _ -> [currInst]

    (* Execute for every instruction *)
    method vinst (currInst : instr) : instr list visitAction =
      ChangeTo (self#simplifyInstr currInst)

    (* Execute for every statement *)
    method vstmt (currStmt : stmt) : stmt visitAction =

      (* Simplify one statement *)
      let rec simplifyStmt (currStmt : stmt) : stmt =
        match currStmt.skind with
          Instr(ilist) -> 
           (* Iterator over all instructions in the list
            * and generate a new list *)
            let rec processInstrs (ilist : instr list) 
                  (newlist : instr list) =
              match ilist with
              i::is -> let i' = (self#simplifyInstr i) in
                         (processInstrs is (newlist @ i'))
              | [] -> newlist
            in
            let newstmt = mkStmt (Instr(processInstrs ilist [])) in
            begin
              newstmt.labels <- currStmt.labels;
              newstmt
            end
          | If(e,s1,s2,_) -> begin
              try (if (validateIfCondition(e))
              then
                  (* Condition looks ok, let us check bodies of if and
                   * else *)
                  (* if block of if-else *)
                  let s1'_bstmts = (List.map simplifyStmt s1.bstmts) in
                  let if_block = mkBlock (s1'_bstmts) in

                  (* Let us now create the else block of if-else *)
                  let s2'_bstmts = (List.map simplifyStmt s2.bstmts) in
                  let else_block = mkBlock (s2'_bstmts) in

                  (* Let us now create the composite if-else *)
                  let if_else_stmt = If(e, if_block, else_block, locUnknown) in

                  (* Final transformed statement of original if-else *)
                  let newstmt = (mkStmt if_else_stmt)
                  in

                  begin
                    newstmt.labels <- currStmt.labels;
                    newstmt
                  end
                 else currStmt
               ) with error ->
                  (* Case (2) *)
			        let tmp_var_lval = (var (makeTempVar currFuncRef 
                                      (typeOf e)))  in
         	        let tmp_assignment = Set(tmp_var_lval, e, locUnknown) in
			        let assignment_stmt = (mkStmtOneInstr tmp_assignment) in
				
			        (* Let us now create the if block of if-else *)
			        let s1'_bstmts = (List.map simplifyStmt s1.bstmts) in
			        let if_block = mkBlock (s1'_bstmts) in

			        (* Let us now create the else block of if-else *)
			        let s2'_bstmts = (List.map simplifyStmt s2.bstmts) in
			        let else_block = mkBlock (s2'_bstmts) in

			        (* Let us now create the composite if-else *)
			        let if_else_stmt = If(Lval(tmp_var_lval), if_block, else_block, 
                                      locUnknown) in

			        (* Final transformed statement of original if-else *)
                    let newstmt = mkStmt (Block(mkBlock [assignment_stmt; 
                                                 (mkStmt if_else_stmt)])) 
                    in

                  begin
                    newstmt.labels <- currStmt.labels;
                    newstmt
                  end
                end

			  | Block(blk) -> 
                let newstmt = mkStmt (Block (mkBlock (List.map simplifyStmt 
                                                blk.bstmts)))
                in
                begin
                  newstmt.labels <- currStmt.labels;
                  newstmt
                end

        | Return(Some(e),_) ->
                (* Check if it is already using variable *)
                if (verifyVar (e) = false) then
                  (* If not then create a temperory, and assign it
                   * with the result of that expression *)
		          let tmp_var_lval = (var (makeTempVar currFuncRef 
                                      (typeOf e)))  in
         	      let tmp_assignment = Set(tmp_var_lval, e, locUnknown) in
				  let assignment_stmt = (mkStmtOneInstr tmp_assignment) in
                  let newstmt = mkStmt (Block(mkBlock [assignment_stmt; 
                            (mkStmt (Return(Some(Lval(tmp_var_lval)),locUnknown)))])) 
                  in

                  begin
                    newstmt.labels <- currStmt.labels;
                    newstmt
                  end
                else
                  currStmt

        | Switch(_,_,_,_) -> raise (Unexpected_Case ("[simplifyStmt] " ^
               "Switch-case statements should have been simplified to if-else" ^
               "by now." ^ " at " ^ printLocation))

        | Loop(blk,l,s1,s2) -> 
                let newstmt = mkStmt (Loop (mkBlock (List.map simplifyStmt 
                                                blk.bstmts),l,s1,s2))
                in
                begin
                  newstmt.labels <- currStmt.labels;
                  newstmt
                end
        | Goto(sref, _) -> begin
                try (match List.nth !sref.labels 0 with
                  Label(lbl,_,_) -> begin
                    let newstmt = mkStmt(Instr([Call(None, varToLval funMyDebugPrintf.svar,
                                [Const(CStr("goto " ^ lbl))], locUnknown)])) in
                    begin
                      newstmt.labels <- currStmt.labels;
                      currStmt.labels <- []; 
                      mkStmt (Block(mkBlock [newstmt; currStmt]))
                    end
                  end
                  | _ -> currStmt
                ) with error -> raise (Unexpected_Case(" " ^
                                 "[simplifyStmt::vstmt] Exception in List.nth " ^
				                         " for n = " ^ string_of_int (0) ^
                                 " while processing function " ^
                                 currFuncRef.svar.vname ^ " for Goto stmt at " ^
                                 printLocation))
          end

        | _ -> currStmt
      in

      let newstmt = simplifyStmt currStmt in
			begin
			  newstmt.labels <- currStmt.labels;
				ChangeTo newstmt
			end

    (* We need to store the current function so that
     * we can add temporary to it.
     *)
    method vfunc (currFunc : fundec) : fundec visitAction = 

      (* If function will be transformed, then only proceed. *)
			let _ = 
				if (scompare currFunc.svar.vname "recog") ||
					 (scompare currFunc.svar.vname "recog_trans")
				then
					let _ = clearCFGinfo currFunc in
					let _ = cfgFun currFunc in
					let dotname = "/tmp/" ^ currFunc.svar.vname ^ ".dot" in
					(printCfgFilename dotname currFunc)
				else
					()
			in
			
      if (isTransFuncName currFunc.svar.vname)
      then
        begin
          currFuncRef <- currFunc;
          DoChildren
        end
      else
          SkipChildren

    (* For every global, check if we need to process it *)
    method vglob (currGlob : global) : global list visitAction =
        if (permitTransformation (get_globalLoc currGlob)) then
            DoChildren
        else
            SkipChildren
  end

(*
 * The objective of this class is to patch all
 * goto statements. The idea is to find out new
 * target statements of goto, and update the reference
 * field inside goto statements to their new targets
 *)
class patchGotos (f:file) (file_name:string) =
  object (self)
    inherit nopCilVisitor

  (* Name of current function *)
  val mutable fname = " "

  (* Count of goto statements seen till now *)
  val mutable gotoCnt = 0

  (* List of statements of a function.
   * Even though it is mutable, we will not
   * update it using this variable. *)
  val mutable stmtList = []

  (* Find a statement inside the list of statement
   * with given label. *)
  method private findStmtWithLabel (sl : stmt list) 
      (explbl : string) : stmt = 

    (* Is this the expected label?? *)
    let isExpectedLabel (l : label) : bool =
      match l with
        Label(s,_,_) -> ((compare explbl s) = 0) 
       | _ -> false
    in

    (* Is atleast one statement has the label?? *)
    let rec atleastOneStmtHasLabel (s : stmt) : stmt =
      (* Check if the input statement has the expected label *)
      if (List.exists isExpectedLabel s.labels) then
        s
      else
        match s.skind with
          If(_,b1,b2,_) -> begin
              try (self#findStmtWithLabel b1.bstmts explbl)
              with error -> (self#findStmtWithLabel b2.bstmts explbl)
            end
         | Switch(_,b,sl1,_) ->  begin
              try (self#findStmtWithLabel b.bstmts explbl)
              with error -> (self#findStmtWithLabel sl1 explbl)
            end
         | Loop(b,_,so1,so2) -> begin
              try (self#findStmtWithLabel b.bstmts explbl)
              with error -> (
                  match so1 with
                    Some(so1') -> begin
                        try (atleastOneStmtHasLabel so1')
                        with error -> (
                          match so2 with
                          Some(so2') -> (atleastOneStmtHasLabel so2')
                          | _ -> raise Not_found
                        )
                    end
                   | _ -> begin
                      match so2 with
                      Some(so2') -> (atleastOneStmtHasLabel so2')
                      | _ -> raise Not_found
                   end
              )
            end
         | Block(b) ->
              self#findStmtWithLabel b.bstmts explbl
         | TryFinally(b1,b2,_) -> begin
              try (self#findStmtWithLabel b1.bstmts explbl)
              with error -> (self#findStmtWithLabel b2.bstmts explbl)
            end
         | TryExcept(b1,_,b2,_) -> begin
              try (self#findStmtWithLabel b1.bstmts explbl)
              with error -> (self#findStmtWithLabel b2.bstmts explbl)
            end
         | _ -> raise Not_found
    in

    match sl with
      s::sl' -> begin
          try (atleastOneStmtHasLabel s) 
          with error -> (self#findStmtWithLabel sl' explbl)
        end
     | [] -> raise Not_found

  (* Execute for all statements. *)
  method vstmt (currStmt : stmt) : stmt visitAction =

    let handleStmt (currStmt : stmt) : stmtkind = 
      
			(* Check if label has string type *)
      let chkStringLabel (l : label) : bool = 
        match l with
          Label(s,_,_) -> true
         | _ -> false
      in

      match currStmt.skind with
        (* The idea here is simple.
         * 1: find the label of the expected target statement
         *    of this goto.
         * 2: find the statement with that label.
         * 3: update the reference.
         * 4. update gotoCnt
         *)
        Goto(sref,_) (*when (List.exists chkStringLabel !sref.labels)*) -> 
					begin
          try (
							 let labellist = Hashtbl.find varGotoLabelsTbl fname in
               let lbl = try (List.nth labellist gotoCnt) 
                         with error -> raise (Unexpected_Case ("[handleStmt]" ^
                                  "List.nth exception" ^
				                          " for n = " ^ string_of_int (gotoCnt)))
               in
               let stm = self#findStmtWithLabel stmtList lbl in
               begin
                  sref := stm;
                  gotoCnt <- gotoCnt + 1;
                  Goto(sref, locUnknown)
               end
              )
          with 
						error -> raise (Unexpected_Case ("Function " ^fname^ " not found " ^ 
                            "in hash table, but it has a goto, " ^
                            "or a statement with an expected label " ^
                            "not found" ^ " at " ^ printLocation))
          end
        | _ -> currStmt.skind
    in

    (* We cannot create a new statment here. Otherwise,
     * we won't be able to handle a case where we have
     * cascaded gotos. i.e., one goto leading to another goto.
     *)
    let newkind = handleStmt currStmt in
    begin
      currStmt.skind <- newkind;
      DoChildren
    end

  method vfunc (currFunc : fundec) : fundec visitAction = 

    (* If function will be transformed, then only proceed. *)
    if (isTransFuncName currFunc.svar.vname)
    then
      begin
        fname <- currFunc.svar.vname;
        gotoCnt <- 0;
        stmtList <- currFunc.sbody.bstmts;
        DoChildren
      end
    else
        SkipChildren

    (* For every global, check if we need to process it *)
    method vglob (currGlob : global) : global list visitAction =
        if (permitTransformation (get_globalLoc currGlob)) then
            DoChildren
        else
            SkipChildren
  end

(*
 * The objective of this class is to collect goto 
 * labels for all the functions of the given file.
 * The labels are maintained in the global hash table
 * indexed by function name.
 *
 * NOTE: This function must be called only on the 
 * original (untransformed) copy of the input program.
 *)
class collectGotoLabels (f:file) (file_name:string) =
  object (self)
    inherit nopCilVisitor

    (* Name of current function *)
    val mutable fname = " "

    (* A function that looks for gotos and find out the
     * label of the taget statement of them. *)
    method private vstmt (currStmt : stmt) : stmt visitAction =

      (* Check if label has string type *)
      let chkStringLabel (l : label) : bool = 
        match l with
          Label(s,_,_) -> true
         | _ -> false
      in

      (* Get string part of the label *)
      let getStringLabel (l : label) : string =
        match l with
        Label(s,_,_) -> s
         | _ -> raise (Unreachable_Case ("[getStringLabel] Unexpected case " ^
                          "reached at " ^ printLocation))
      in

      (* Add pair to the hash table. If there already exists a
       * key-value pair, then append to the value. *)
      let addToHashTbl (l : string) : unit =
        let labellist = try (Hashtbl.find varGotoLabelsTbl fname) 
                        with error -> []
        in
        Hashtbl.replace varGotoLabelsTbl fname (labellist @ [l])
      in 

      match currStmt.skind with
        Goto(sref,_) -> begin
            try (let l = List.find chkStringLabel !sref.labels in
                 begin
                   addToHashTbl (getStringLabel l);
                   SkipChildren
                 end
                )
            with error -> SkipChildren
          end
        | _ -> DoChildren
        
    (* For every function, visit its statements *)
    method vfunc (currFunc : fundec) : fundec visitAction = 


      (* If function will be transformed, then only proceed. *)
      if (isTransFuncName currFunc.svar.vname) 
      then
        begin
          (* We do this to convert switch case statements into
           * if-else *)
          prepareCFG currFunc;
          fname <- currFunc.svar.vname;
          DoChildren
        end
      else
          SkipChildren

    (* For every global, check if we need to process it *)
    method vglob (currGlob : global) : global list visitAction =
        if (permitTransformation (get_globalLoc currGlob)) then
            DoChildren
        else
            SkipChildren
  end

(*
 * Generate transformed version of the function.
 *
 * The objective of this class is to visit functions
 * defined in the input file, check which ones need to
 * be transformed, and then generate duplicate of the 
 * original function with transformed version.
 *)
class genTransformedVersion (f:file) (file_name:string) =
  object (self)
    inherit nopCilVisitor

    method vglob (currGlob : global) : global list visitAction =
        if (permitTransformation (get_globalLoc currGlob)) then
            match currGlob with
            GFun(currFunc,_) -> 
                let isFuncTransformed,_ = willFuncTransformed
                  currFunc.svar
                in

                (* If this function will be transformed, then we do 
                 * following:
                 *
                 * Duplicate function body and rename function to that
                 * of transformed one.
                 *)
                if (isFuncTransformed) 
                then
                  if (isStatic currFunc.svar) then
                    ChangeTo [(*currGlob; *) GFun((copyFunction currFunc (getTransFuncName
                    currFunc.svar.vname)), locUnknown)]
                  else
                    ChangeTo [(*currGlob; *)GFun((copyFunction currFunc (getTransFuncName
                    currFunc.svar.vname)), locUnknown)]
                else
                  SkipChildren
            | _ -> SkipChildren
      else
          SkipChildren
  end

let unop_neg = ref 0
let unop_bnot = ref 0 
let unop_lnot = ref 0
let bnop_lt = ref 0
let bnop_gt =  ref 0
let bnop_le = ref 0
let bnop_ge = ref 0
let bnop_eq = ref 0
let bnop_ne = ref 0
let bnop_ne_zero = ref 0
let bnop_band = ref 0
let bnop_bxor = ref 0
let bnop_bor = ref 0
let bnop_land = ref 0
let bnop_lor = ref 0

class getConstraints (f:file) (file_name:string) =
  object (self)
    inherit nopCilVisitor

  val mutable level = 0

  method private procExp (e: exp) : unit = 
    match e with
     UnOp(Neg,e',_) -> (unop_neg := !unop_neg + 1; level <- level + 1; self#procExp e';)
     | UnOp(BNot,e',_) -> (unop_bnot := !unop_bnot + 1; level <- level + 1; self#procExp e';)
     | UnOp(LNot,e',_) -> (unop_lnot := !unop_lnot + 1; level <- level + 1; self#procExp e';)
     | BinOp(Lt,e1,e2,_) -> (bnop_lt := !bnop_lt + 1; level <- level + 1; self#procExp e1;
     self#procExp e2;)
     | BinOp(Gt,e1,e2,_) -> (bnop_gt := !bnop_gt + 1; level <- level + 1; self#procExp e1;
     self#procExp e2;)
     | BinOp(Le,e1,e2,_) -> (bnop_le := !bnop_le + 1; level <- level + 1; self#procExp e1;
     self#procExp e2;)
     | BinOp(Ge,e1,e2,_) -> (bnop_ge := !bnop_ge + 1; level <- level + 1; self#procExp e1; 
          self#procExp e2;)
     | BinOp(Eq,e1,e2,_) -> (bnop_eq := !bnop_eq + 1; level <- level + 1; self#procExp e1; 
          self#procExp e2;)
     | BinOp(Ne,e1,e2,_) -> (bnop_ne := !bnop_ne + 1; level <- level + 1; self#procExp e1; 
          self#procExp e2;)
     | BinOp(BAnd,e1,e2,_) -> (bnop_band := !bnop_band + 1; level <- level + 1; self#procExp e1; 
          self#procExp e2;)
     | BinOp(BXor,e1,e2,_) -> (bnop_bxor := !bnop_bxor + 1; level <- level + 1; self#procExp e1; 
          self#procExp e2;)
     | BinOp(BOr,e1,e2,_) -> (bnop_bor := !bnop_bor + 1; level <- level + 1; self#procExp e1; 
          self#procExp e2;)
     | BinOp(LAnd,e1,e2,_) -> (bnop_land := !bnop_land + 1; level <- level + 1; self#procExp e1; 
          self#procExp e2;)
     | BinOp(LOr,e1,e2,_) -> (bnop_lor := !bnop_lor + 1; level <- level + 1; self#procExp e1; 
          self#procExp e2;)
     | BinOp(_,e1,e2,_) -> (level <- level + 1; self#procExp e1; self#procExp e2;)
     | CastE(_,e') -> self#procExp e'
     (*| _ -> (bnop_ne := !bnop_ne + 1)*)
     | _ -> if (level == 0) then (bnop_ne_zero := !bnop_ne_zero + 1)
            else ()

  method vstmt (currStmt : stmt) : stmt visitAction =
      match currStmt.skind with
        If(e,_,_,_) -> begin
            level <- 0;
            self#procExp e;
            DoChildren
        end
        | _ -> DoChildren

  end



(*  ======================================================================== *)
(*            Some utility functions                                         *)
(*  ======================================================================== *)


(*  The basic objective of this method is to read in all the names
 *  provided in the specified file and put it into a list.
 *)
let read_file (file_name: string) : string list =
    let symbols_list = ref []
    in

    begin
        if file_name = "" then
                raise (Incorrect_Input ( "No File to read."))
        else
            begin
                try (
                    let input_channel = open_in file_name
                    in
                    begin
                      while true do
                        let symbol_name = (input_line input_channel)
                        in
                        begin
                          symbols_list := symbol_name :: !symbols_list;
                        end
                        done;
                        ()
                    end
                ) with
                |   Sys_error(message) -> raise (Incorrect_Input (file_name ^
                              " file could not be opened."))
                |   End_of_file ->  ()
            end;
        !symbols_list
    end

(*  ======================================================================== *)
(*            CFG return analysis                                         *)
(*  ======================================================================== *)

class analyseReturns (f:file) (file_name:string) =
  object (self)
    inherit nopCilVisitor
  
    method private areAllReturnsNegative (sl : stmt list) (ret: bool option) : bool option =
      match sl with
       | [] -> ret
       | s::sl' ->
          match s.skind with
            | Return(Some(Const(CInt64(_,IInt,Some("-1")))), l) -> 
                let ret' = 
                  match ret with
                    | None -> Some(true) 
                    | _ -> ret
                in
                self#areAllReturnsNegative s.succs ret'
            | Return(_,_) -> self#areAllReturnsNegative s.succs (Some(false))
            | _ -> self#areAllReturnsNegative s.succs ret

    method private vstmt (currStmt : stmt) : stmt visitAction =
      match currStmt.skind with
        | If(_,b1,b2,l) ->
            let _ = List.iter (fun s -> (print_string ((printStmt s) ^ "\n"))) currStmt.succs in 
            let ifretopt = self#areAllReturnsNegative b1.bstmts None in
            let elretopt = self#areAllReturnsNegative b2.bstmts None in
            let _ =
              match ifretopt with
                None -> print_string ("No rets found: " ^ printMyLocation l ^ "\n")
               | Some(true) -> print_string ("ifret: all rets -1: " ^ printMyLocation l ^ "\n")
               | Some(false) -> print_string ("ifret: some positive rets: " ^ printMyLocation l ^ "\n")
            in
            let _ = 
              match elretopt with
                None -> print_string ("No rets found: " ^ printMyLocation l ^ "\n")
              | Some(true) -> print_string ("elret: all rets -1: " ^ printMyLocation l ^ "\n")
              | Some(false) -> print_string ("elret: some pos rets: " ^ printMyLocation l ^ "\n")
            in
            DoChildren
        | _ -> DoChildren

    method vfunc (currFunc : fundec) : fundec visitAction = 
      let _ = print_string ("fname: " ^ currFunc.svar.vname ^ "\n") in
      if (currFunc.svar.vname = "recog_1") 
      then
        begin
          let ret = cfgFun currFunc in
          let _ = printCfgFilename "/tmp/recog_test.dot" currFunc in
          SkipChildren
        end
      else
          SkipChildren
 end
 
(*  ======================================================================== *)
(*            Interface                                                      *)
(*  ======================================================================== *)

let transform = function (f:file) ->

    let transGenerator = new genTransformedVersion f f.fileName
    and gotoLabelsCollector = new collectGotoLabels f f.fileName
    and gotoPatcher = new patchGotos f f.fileName
    and funcsTransformer = new transformFuncsForSymbolicExe f f.fileName
    and stmtSimplifier = new simplifyStatements f f.fileName
    and consCollector = new getConstraints f f.fileName
    and retAnalyzer = new analyseReturns f f.fileName
    in

    try ( 
       let inc_symhelper = GText (hdrSymHelperH) in
       let inc_symvarstack = GText (hdrSymVarStackH) in
       let inc_rtlacc = GText (hdrRtlAccH) in
       let inc_conssolve = GText (hdrConsSolveH) in
       let inc_common = GText (hdrCommonH) in

       (*  Setting the global variable sys_dirs_list to the list that we
        *  have read in from the input file specified  *)
       sys_dirs_list := read_file !sysDirsFile;

       (* Read the name of the functions into the list *)
       func_ret_proc_list := read_file !funcRetProcFile;

       (* Read the names of functions the calls of which are not to
	  be transformed. *)
       dont_trans_funccall_list := read_file !dontTransFunccallFile;

       (* First duplicate the function definitions which will
        * be transformed. This is done so that we preserve 
        * original function as it is. *)
       visitCilFile (transGenerator :> cilVisitor) f;

       (* Let's first collect labels of all targets of gotos *)
       visitCilFile (gotoLabelsCollector :> cilVisitor) f;

       (* Uncomment this if you want to dump the contents 
        * of hash table. *)
       (*Hashtbl.iter printGotoLabelsTbl varGotoLabelsTbl;*)

       (* Read the names of functions for which we have manually
        * defined the symbolic version *)
       sym_func_list := read_file !argSymFunctionsFile;

       (* Let's first simplify the language for transformation *)
       visitCilFile (stmtSimplifier :> cilVisitor) f;

       (* Let us now transform *)
       visitCilFile (funcsTransformer :> cilVisitor) f;
       (*visitCilFile (consCollector :> cilVisitor) f;*)

       (* Let's patch gotos now *)
       visitCilFile (gotoPatcher :> cilVisitor) f; 

       f.globals <- [inc_symhelper; inc_symvarstack; (*inc_rtlacc;*)
       inc_conssolve] @ f.globals;

       (* Since gFuncProto contains function prototypes which use
        * types such as rtx, enum machine_mode, we need to insert
        * them just before function definitions start. That way
        * we are sure that all such types are defined. *)
       f.globals <- insertProtos !gFuncProto f.globals;

       (* Prints CFG of the function in terms of branch points and returns. *)
       (* visitCilFile (retAnalyzer :> cilVisitor) f; *)

       (*
       print_string ("\nunop_neg: " ^ string_of_int(!unop_neg));
       print_string ("\nunop_bnot: " ^ string_of_int(!unop_bnot));
       print_string ("\nunop_lnot: " ^ string_of_int(!unop_lnot));
       print_string ("\nbnop_lt: " ^ string_of_int(!bnop_lt));
       print_string ("\nbnop_gt: " ^ string_of_int(!bnop_gt));
       print_string ("\nbnop_le: " ^ string_of_int(!bnop_le));
       print_string ("\nbnop_ge: " ^ string_of_int(!bnop_ge));
       print_string ("\nbnop_eq: " ^ string_of_int(!bnop_eq));
       print_string ("\nbnop_ne: " ^ string_of_int(!bnop_ne));
       print_string ("\nbnop_ne_zero: " ^ string_of_int(!bnop_ne_zero));
       print_string ("\nbnop_band: " ^ string_of_int(!bnop_band));
       print_string ("\nbnop_bxor: " ^ string_of_int(!bnop_bxor));
       print_string ("\nbnop_bor: " ^ string_of_int(!bnop_bor));
       print_string ("\nbnop_land: " ^ string_of_int(!bnop_land));
       print_string ("\nbnop_lor: " ^ string_of_int(!bnop_lor));
       print_string ("\n");

       print_string (string_of_int(!unop_neg) ^ "," ^
                     string_of_int(!unop_bnot) ^ "," ^
                     string_of_int(!unop_lnot) ^ "," ^
                     string_of_int(!bnop_lt) ^ "," ^
                     string_of_int(!bnop_gt) ^ "," ^
                     string_of_int(!bnop_le) ^ "," ^
                     string_of_int(!bnop_ge) ^ "," ^
                     string_of_int(!bnop_eq) ^ "," ^
                     string_of_int(!bnop_ne) ^ "," ^
                     string_of_int(!bnop_ne_zero) ^ "," ^
                     string_of_int(!bnop_band) ^ "," ^
                     string_of_int(!bnop_bxor) ^ "," ^
                     string_of_int(!bnop_bor) ^ "," ^
                     string_of_int(!bnop_land) ^ "," ^
                     string_of_int(!bnop_lor));
       print_string ("\n"); *)

    )
    with
    | error -> raise error

(* Feature descriptor required by cilly *)
let feature : featureDescr = 
    {
        fd_name = "symAsm2RTL";
        fd_enabled = doSymAsm2RTL;
        fd_description = " generation of code for symbolic execution of GCC code " ^
                       	 "\n\t\t\t\t\t" ^ 
                         " involved in Asm to RTL conversion "; 
        fd_extraopt = [("--symFunctionsFile", Arg.Set_string(argSymFunctionsFile),
                       " Full name of the file that would contain the names of" ^
                       "\n\t\t\t\t\t" ^ 
                       " manually defined versions of the functions that can" ^
                       "\n\t\t\t\t\t" ^ 
                       " handle symbolic arguments, e.g., RTL accessor" ^
                       "\n\t\t\t\t\t" ^ 
                       " functions. The name should be ORIGINAL name" ^
                       "\n\t\t\t\t\t" ^ 
                       " of the function and not the new one.");

                      ("--sysDirsFile", Arg.Set_string(sysDirsFile), 
                       " Full name of the file that would contain the names of" ^
                       " system directories. Functions" ^ 
                       "\n\t\t\t\t\t" ^ 
                       "that belongs to files in these directories will not be" ^
                       " instrumented. There must be ONLY" ^
                       "\n\t\t\t\t\t" ^ 
                       "one directory name per line. Do not forget to include" ^
                       "\n\t\t\t\t\t" ^ 
                       " the ending \"/\".");

                      ("--funcRetProcFile", Arg.Set_string(funcRetProcFile), 
                       " Full name of the file that would contain the names of" ^
                       "\n\t\t\t\t\t" ^ 
                       " functions, the returns of which need to be converted" ^
                       "\n\t\t\t\t\t" ^ 
                       " into backTrack() and addOutput()");

		      ("--dontTransFunccallFile", Arg.Set_string(dontTransFunccallFile),
		       " Full name of the file that contains names of functions the " ^
                       "\n\t\t\t\t\t" ^ 
		       " calls to which are not to be transformed.");
                      ];
        fd_doit = transform;
        fd_post_check = true;
    }

(*
 * TODO:
 * 1. a.b.c needs to be broken into a.b and b.c (Use --no-convert-field-offsets
 * option so that CIL preservs structure accesses and does not convert into
 * pointer dereferences. 
 *
 * 2. Use compactStmt to remove unnecessary nesting.
 *
 *)

(* NOTE:
 * 1. CIL Options Used
 *
 * - We are using dosimplify because it simplifies expressions such as
 * "target_flags & (1 << 1)" into 3-address code.
 * - We are using --no-convert-field-offsets because we do not want
 * CIL to convert a.b.c into pointer dereferences form.
 *)
