# Problem Set 2
# Name: Qiu Ying
# Time: 00:30
#
# Problem 4
#

from string import *

def constrainedMatchPair(firstMatch, secondMatch, length):
	match = ()
	m = length
	for n in firstMatch:
		for k in secondMatch:
			if n+m+1 == k:
				match += (n,)
	return match


def subStringMatchOneSub(key,target):
    """search for all locations of key in target, with one substitution"""
    allAnswers = ()
    for miss in range(0,len(key)):
        key1 = key[:miss]
        key2 = key[miss+1:]
        match1 = subStringMatchExact(target,key1)
        match2 = subStringMatchExact(target,key2)
        filtered = constrainedMatchPair(match1,match2,len(key1))
        allAnswers = allAnswers + filtered
    return tuple(set(allAnswers))

def subStringMatchExact(target, key):
	answer = ()
	i = 0

	while True:
		i = find(target, key, i)
		if i == -1:
			return answer
		answer += (i,)
		if len(key) == 0:
			i += 1
		else:
			i += len(key)


target1 = 'atgacatgcacaagtatgcat'
target2 = 'atgaatgcatggatgtaaatgcag'

key10 = 'a'
key11 = 'atg'
key12 = 'atgc'
key13 = 'atgca'

def subStringMatchExactOneSub(target, key):
	s1 = set(subStringMatchOneSub(key, target))
	s2 = set(subStringMatchExact(target, key))
	return tuple(s1 - s2)

print subStringMatchExactOneSub(target1, key11)
