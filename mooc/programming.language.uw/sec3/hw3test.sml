(* Homework3 Simple Test*)
(* These are basic test cases. Passing these tests does not guarantee that your code will pass the actual homework grader *)
(* To run the test, add a new line to the top of this file: use "homeworkname.sml"; *)
(* All the tests should evaluate to true. For example, the REPL should say: val test1 = true : bool *)

val test1 = only_capitals ["A","B","C"] = ["A","B","C"]
val test1_1 = only_capitals ["American","BBC","China"] = ["American","BBC","China"]
val test1_2 = only_capitals ["a sheep","blink","lamp"] = []

val test2 = longest_string1 ["A","bc","C"] = "bc"
val test2_1 = longest_string1 ["A","bc","ac"] = "bc"

val test3 = longest_string2 ["A","bc","C"] = "bc"
val test3_1 = longest_string2 ["A","bc","ac"] = "ac"

val test4a= longest_string3 ["A","bc","C"] = "bc"
val test4a_1 = longest_string3 ["A","bc","CC"] = "bc"

val test4b= longest_string4 ["A","B","C"] = "C"

val test5 = longest_capitalized ["A","bc","C"] = "A"
val test5_1 = longest_capitalized ["A","B","CC"] = "CC"
val test5_3 = longest_capitalized ["a", "b", "c"] = ""
val test5_4 = longest_capitalized [] = ""

val test6 = rev_string "abc" = "cba";
val test6_1 = rev_string "" = "";

val test7 = first_answer (fn x => if x > 3 then SOME x else NONE) [1,2,3,4,5] = 4

val test8 = all_answers (fn x => if x = 1 then SOME [x] else NONE) [2,3,4,5,6,7] = NONE
val test8_1 = all_answers (fn x => if x = 1 then SOME [x] else NONE) [] = SOME []

val test9a = count_wildcards Wildcard = 1
val test9a_1 = count_wildcards (TupleP [Wildcard, ConstructorP("a", Wildcard)]) = 2;

val test9b = count_wild_and_variable_lengths (Variable("a")) = 1
val test9b_1 = count_wild_and_variable_lengths(TupleP [Wildcard, Variable("aaa")]) = 4;

val test9c = count_some_var ("x", Variable("x")) = 1;
val test9c_1 = count_some_var ("x", TupleP [Wildcard, Variable("x"), Variable("xx")]) = 1;

val test10 = check_pat (Variable("x")) = true
val test10_1 = check_pat (TupleP [Variable("x"), Variable("x")]) = false
val test10_2 = check_pat (TupleP [Variable("x"), Wildcard, ConstructorP("d", Variable("xx"))]) = true
val test10_3 = check_pat (TupleP [Variable("x"), Wildcard, ConstructorP("d", Variable("x"))]) = false

val test11 = match (Const(1), UnitP) = NONE

val test12 = first_match Unit [UnitP] = SOME []

