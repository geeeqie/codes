# Problem Set 1
# Name: Qiu Ying
# Time 1:00
#
# Problem 1:
#   computes and prints the 1000th prime number
#

#import math
from math import *

prev_prime = 3
for i in range(3, 1001):
	#find ith prime
	p = prev_prime + 1
	while True:
		#print 'p=',p
		for j in range(2, int(sqrt(p))+1):
			if p%j == 0: 
				#print 'p%j==0',p,j
				break
		#print 'j=',j
		if j == int(sqrt(p)) and p%(int(sqrt(p))) != 0:
			print i, p
			prev_prime = p
			break
		p = p + 1

