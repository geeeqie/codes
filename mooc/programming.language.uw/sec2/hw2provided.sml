(* Dan Grossman, Coursera PL, HW2 Provided Code *)

(* if you use this function to compare two strings (returns true if the same
   string), then you avoid several of the functions in problem 1 having
   polymorphic types that may be confusing *)
fun same_string(s1 : string, s2 : string) =
    s1 = s2

(* put your solutions for problem 1 here *)
fun all_except_option(s:string, sl:string list) = 
    case sl of
	[] => NONE
      | x::xs' =>  if same_string(x, s)
		   then SOME(xs')
		   else case all_except_option(s, xs') of
			   NONE => NONE
			 | SOME xs => SOME(x::xs)

fun get_substitutions1(sll:string list list, s:string) = 
    case sll of
	[] => []
      | x::xs => case all_except_option(s, x) of
		     NONE => get_substitutions1(xs, s)
		   | SOME y => y@get_substitutions1(xs, s)

fun get_substitutions2(sll:string list list, s:string) = 
    let fun aux(sll, s, acc) = 
	    case sll of
		[] => acc
	      | x::xs => case all_except_option(s, x) of
			     NONE => aux(xs, s, acc)
			   | SOME y => aux(xs, s, acc@y)
    in
	aux(sll, s, [])
    end

fun similar_names(sub, fullname) = 
    let
	val {first=f,middle=m,last=l} = fullname
	fun aux(xs, acc) = 
	    case xs of
		[] => acc
	      | x::xs' => aux(xs', acc@[{first=x,middle=m,last=l}])
    in
	aux(f::get_substitutions2(sub, f), [])
    end

(* you may assume that Num is always used with values 2, 3, ..., 10
   though it will not really come up *)
datatype suit = Clubs | Diamonds | Hearts | Spades
datatype rank = Jack | Queen | King | Ace | Num of int 
type card = suit * rank

datatype color = Red | Black
datatype move = Discard of card | Draw 

exception IllegalMove

(* put your solutions for problem 2 here *)

fun card_color(card) = 
    case card of
	(Spades, _) => Black
      | (Clubs, _) => Black
      | _ => Red

fun card_value(card) =
    case card of
	(_, Num x) => x
      | (_, Ace) => 11
      | _ => 10

fun remove_card(cs, c, e) = 
    case cs of
	[] => raise e
      | d::ds => if d = c
		 then ds
		 else d::remove_card(ds, c, e)

fun all_same_color(cs) =
    case cs of
	[] => true
      | c::[] => true
      | c1::(c2::cs') => card_color(c1) = card_color(c2)

fun sum_cards(cs) = 
    let fun aux(cs, acc) = 
	    case cs of
		[] => acc
	      | c::cs' => aux(cs', card_value(c) + acc)
    in
	aux(cs, 0)
    end

fun score(cs, goal) = 
    let
	val sum = sum_cards(cs)
	val preliminary_score = if sum > goal then 3*(sum-goal)	else goal - sum
    in
	if all_same_color(cs)
	then preliminary_score div 2
	else preliminary_score
    end

fun officiate(cs, ms, goal) = 
    let fun play(cs, ms, held_cards) = 
	    case (cs, ms, held_cards) of
		(_,[],hs) => score(hs, goal) (* no more moves *)
	      | (xs, Discard c::ms', hs) => play(xs, ms', remove_card(hs, c, IllegalMove)) 
	      | ([], Draw::ms', hs) => score(hs, goal)
	      | (x::cs', Draw::ms', hs) => if sum_cards(x::hs) > goal
				       then score(x::hs, goal)
				       else play(cs', ms', x::hs)
    in
	play(cs, ms, [])
    end
