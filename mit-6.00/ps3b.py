# Problem Set 3
# Name: Geeeqie
# Timer: 00:10
#

from string import *

def subStringMatchExact(target, key):
	answer = ()
	i = 0
	while True:
		i = find(target, key, i)
		if i == -1:
			return answer
		answer += (i,)
		i += len(key)

target = raw_input("target: ")
key = raw_input("key: ")
print subStringMatchExact(target, key)
