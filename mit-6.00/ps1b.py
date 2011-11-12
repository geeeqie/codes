# Problem Set 1
# Name: Qiu Ying
# Time 1:00
#
# Problem 2:
#   Evaluate:
#
#           n
#         _____ 
#   lim    | |  prime(k)  == e**n
# n->inf   | |  
#
#          k=1
#

#import math
from math import *

p = 4
product = log(2*3)
i = 3
while True:
	half = int(sqrt(p))
	for j in range(2, half +1):
		if p%j == 0: break
	if j == int(sqrt(p)) and p%(int(sqrt(p))) != 0:
		# p is a prime
		product = product + log(p)
		print i, p, product / p
		i = i + 1
	p = p + 1

