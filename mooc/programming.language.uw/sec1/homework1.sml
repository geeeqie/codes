fun is_older(date1:int*int*int, date2:int*int*int) = 
    if (#1 date1) < (#1 date2)
    then true
    else
	if (#1 date1) = (#1 date2)
	then
	    if (#2 date1) < (#2 date2)
	    then true
	    else
		if (#2 date1) = (#2 date2)
		then
		    if (#3 date1) < (#3 date2)
		    then true
		    else false			     
		else false
	else false

fun number_in_month(dates:(int*int*int) list, month:int) = 
    if null(dates)
    then 0
    else
	let val n = number_in_month(tl(dates), month)
	in
	    if #2(hd(dates)) = month
	    then 1 + n
	    else n
	end

fun number_in_months(dates:(int*int*int) list, months:int list) = 
    if null months
    then 0
    else
	number_in_month(dates, hd(months)) + number_in_months(dates,tl(months)) 

fun dates_in_month(dates:(int*int*int) list, month:int) = 
    if null dates
    then []
    else
	let val date = hd(dates)
	    val rest = dates_in_month(tl(dates), month)
	in
	    if #2(date) = month
	    then date :: rest
	    else rest
	end

fun dates_in_months(dates:(int*int*int) list, months:int list) = 
    if null months
    then []
    else
	dates_in_month(dates, hd(months)) @ dates_in_months(dates, tl(months))

fun get_nth(strs:string list, n:int) = 
    if n = 1
    then hd(strs)
    else get_nth(tl(strs), n-1)

fun date_to_string(date:int*int*int) = 
    let val month_names = ["January", "February", "March", "April","May", "June", "July", "August", "September", "October", "November", "December"]
    in
	get_nth(month_names, #2(date)) ^ " " ^ Int.toString(#3(date)) ^ ", " ^ Int.toString(#1(date))
    end

fun number_before_reaching_sum(sum:int, xs:int list) = 
    let val h = hd(xs)
    in
	if sum <= h
	then 0
	else
	    1 + number_before_reaching_sum(sum - hd(xs), tl(xs))
    end

fun what_month(day:int) = 
    let val days_of_month = [31,28,31,30,31,30,31,31,30,31,30,31]
    in
	1+number_before_reaching_sum(day, days_of_month)
    end

fun month_range(day1:int, day2:int) = 
    if day1 > day2
    then []
    else
	what_month(day1) :: month_range(day1+1, day2)

fun oldest(dates:(int*int*int) list) = 
    if null dates
    then NONE
    else
	let val h = hd(dates)
	    val t = oldest(tl(dates))
	in
	    if isSome(t) andalso is_older(valOf(t), h)
	    then t
	    else SOME(h)
	end

fun find(xs:int list, n:int) = 
    if null xs
    then false
    else hd(xs)=n orelse find(tl(xs), n)

fun remove_dup(months:int list) =
    if null months
    then []
    else
	if find(tl(months), hd(months))
	then remove_dup(tl(months))
	else hd(months) :: remove_dup(tl(months))

fun number_in_months_challenge(dates:(int*int*int) list, months:int list) = 
    number_in_months(dates, remove_dup(months))

fun dates_in_months_challenge(dates:(int*int*int) list, months:int list) = 
    dates_in_months(dates, remove_dup(months))

fun reasonable_date(date:(int*int*int)) = 
    let val y = #1(date)
	val m = #2(date)
	val d = #3(date)
	fun leapyear() = 
	    ((y mod 400) = 0) orelse ((y mod 4)=0 andalso (y mod 100)<>0)
	fun nth(xs:int list, n:int) = 
	    if n = 1
	    then hd(xs)
	    else nth(tl(xs), n-1)
	fun reasonable_day() = 
	    let val days_of_month = [31,28,31,30,31,30,31,31,30,31,30,31]
	    in
		if m = 2 andalso leapyear()
		then d <= 29
		else d <= nth(days_of_month, m)
	    end
    in
	y >= 1 andalso m >= 1 andalso m <= 12 andalso d >= 1 andalso reasonable_day()
    end
