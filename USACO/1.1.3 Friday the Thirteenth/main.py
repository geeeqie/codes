#USACO 1.1.3, friday the thirteenth

def leap(year):
    if year%400 == 0:
        return True
    if year%100 == 0:
        return False
    if year%4 == 0:
        return True

def days_of_month(year, month):
    days = [0, 31, leap(year),  31,30,31,30,31,31,30,31,30,31]
    if leap(year):
        days[2] = 29
    else:
        days[2] = 28
    return days[month]

def next_date(year, month, day, whatday):
    if day == days_of_month(year, month):
        day = 1
        if month == 12:
            month = 1
            year += 1
        else:
            month += 1
    else:
        day += 1
    whatday = (whatday+1)%7
    return (year, month, day, whatday)

date = (1900, 1, 1, 1)

n = input()
n13ofweek = [0]*7

while True:
    if date[0:3] == (1900+n, 1, 1):
        break
    date = next_date(*date)
    y,m,d,w = date
    if d == 13:
        n13ofweek[w] += 1

print ' '.join(map(str, n13ofweek[6:] + n13ofweek[:6]))
