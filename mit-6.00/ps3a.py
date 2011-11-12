# Problem Set 3 (Part I)
# Name: Qiu Ying
# Time: 00:15
#

from string import *

def countSubStringMatch(target, key):
	i = 0
	c = 0
	while True:
		i = find(target, key, i)
		if i == -1: break;
		i += len(key)
		c += 1
	return c

def countSubStringMatchRecursive(target, key):
	i = find(target, key)
	if i == -1: 
		return 0
	else: 
		return countSubStringMatchRecursive(target[i+1:-1], key)+1

target = raw_input("target: ")
key = raw_input("key: ")
print countSubStringMatchRecursive(target, key)
