# Probelm Set 2
# Name: Geeeqie
# Timer 1:00
#
# Problem 3
#

n = 1
consecutive = 0
answer = ()
while consecutive < 6:
	found = False
	for a in range(0, n/6+1):
		for b in range(0, n/9+1):
			for c in range(0, n/20+1):
				if 6*a+9*b+20*c == n:
					consecutive += 1
					found = True
					break
			if found: break
		if found: break
	if not found:
		consecutive = 0
		answer += (n,)
	n += 1
print 'Largest number of McNuggets that cannot be bought in exact quantity:',answer[-1]
