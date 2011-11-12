# Probelm Set 2
# Name: Qiu Ying
# Timer 10:00
#
# Problem 4
#

bestSoFar = 0	# variable that keeps track of largest number
				# of McNuggets that cannot be bought in exact quantity
packages = (4,15,16)   # variable that contains package sizes

consecutive = 0
answer = ()
for n in range(1, 150):   	# only search for solutions up to size 150
	## complete code here to find largest size that cannot be bought
	## when done, your answer should be bound to bestSoFar
	found = False
	for a in range(0, n/packages[0]+1):
		for b in range(0, n/packages[1]+1):
			for c in range(0, n/packages[2]+1):
				if packages[0]*a+packages[1]*b+packages[2]*c == n:
					consecutive += 1
					found = True
					break
			if found: break
		if found: break
	if not found:
		consecutive = 0
		answer += (n,)
	if consecutive >= min(packages):
		break

print 'Given package size',packages,'the largest number of McNuggets that cannot be bought in exact quantity is:',answer[-1]
