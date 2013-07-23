big_month=[1,3,5,7,8,10,12]
little_month=[4,6,9,11]
week=[0,0,0,0,0,0,0]

def is_leap_year(year):
	if year%4==0 and year%100!=0:
		return True
	if year%400==0 :
		return True
	return False

 
N=input()

next_thirteenth=0

for i in range(N):
	year=1900+i
	if is_leap_year(year):
		month_two=29
	else:
		month_two=28
	for month in range(1,13):
		week[next_thirteenth]+=1
		if month in big_month:
			next_thirteenth=(next_thirteenth+3)%7
		elif month in little_month:
			next_thirteenth=(next_thirteenth+2)%7
		else:
			next_thirteenth=(next_thirteenth+month_two%7)%7
#string = ''
#for e in week:
#	string+=str(e)+' '
print ' '.join(map(str, week))
