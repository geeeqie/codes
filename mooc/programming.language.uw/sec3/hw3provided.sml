(* Coursera Programming Languages, Homework 3, Provided Code *)

exception NoAnswer

datatype pattern = Wildcard
		 | Variable of string
		 | UnitP
		 | ConstP of int
		 | TupleP of pattern list
		 | ConstructorP of string * pattern

datatype valu = Const of int
	      | Unit
	      | Tuple of valu list
	      | Constructor of string * valu

fun g f1 f2 p =
    let 
	val r = g f1 f2 
    in
	case p of
	    Wildcard          => f1 ()
	  | Variable x        => f2 x
	  | TupleP ps         => List.foldl (fn (p,i) => (r p) + i) 0 ps
	  | ConstructorP(_,p) => r p
	  | _                 => 0
    end

(**** for the challenge problem only ****)

datatype typ = Anything
	     | UnitT
	     | IntT
	     | TupleT of typ list
	     | Datatype of string

(**** you can put all your code here ****)
fun only_capitals sl = List.filter (fn s => Char.isUpper(String.sub(s, 0))) sl

fun longest_string1 sl =
    foldl (fn (s1,s2) => if String.size(s1) > String.size(s2) then s1 else s2) "" sl
		      
fun longest_string2 sl =
    foldl (fn (s1,s2) => if String.size(s1) >= String.size(s2) then s1 else s2) "" sl

fun longest_string_helper f sl = 
    foldl (fn (s1,s2) => if f(s1,s2) then s1 else s2) "" sl

val longest_string3 = longest_string_helper (fn (s1,s2) => String.size(s1) > String.size(s2))

val longest_string4 = longest_string_helper (fn (s1,s2) => String.size(s1) >= String.size(s2))

val longest_capitalized = longest_string1 o only_capitals
    
val rev_string = String.implode o List.rev o String.explode

fun first_answer f l = 
    case l of 
	[] => raise NoAnswer
     | x::xs => case f(x) of
		    SOME v => v
		 | NONE => first_answer f xs

fun all_answers f l = 
    let fun aux(l,acc) =
	    case l of
		[] => SOME acc
	      | x::xs => case f x of
			     SOME v => aux(xs, acc@v)
			   | NONE => NONE
    in
	aux(l, [])
    end

val count_wildcards = g (fn () => 1) (fn x => 0)
    
val count_wild_and_variable_lengths = g (fn () => 1) String.size

fun count_some_var (s, p) = g (fn () => 0) (fn x => if x = s then 1 else 0) p

fun check_pat p =
    let fun all_variables (p) = 
	    case p of
		Wildcard          => []
	      | Variable x        => [x]
	      | TupleP ps         => List.foldl (fn (p,i) => (all_variables p) @ i) [] ps
	      | ConstructorP(_,p) => all_variables p
	      | _                 => []
	fun check_variables (sl) =
	    case sl of
		[] => true
	     | x::xs => if List.exists (fn x' => x'=x) xs
			then false
			else check_variables(xs)
    in
	check_variables(all_variables(p))
    end

fun match (v, p) =
    case (v, p) of
	(_, Wildcard) => SOME []
      | (Const c1, ConstP c2)   => if c1 = c2 then SOME [] else NONE
      | (Unit, UnitP)         => SOME []
      | (Tuple vs, TupleP ps)  => if List.length(vs) = List.length(ps)
				  then all_answers match (ListPair.zip(vs, ps))
				  else NONE
      | (Constructor(s2, v), ConstructorP(s1, p)) => if s1 = s2
						     then match(v, p)
						     else NONE
      | (v, Variable s) => SOME [(s, v)]
      | _                 => NONE

fun first_match v ps = (
     SOME(first_answer (fn p => match(v,p)) ps)
) handle NoAnswer => NONE
