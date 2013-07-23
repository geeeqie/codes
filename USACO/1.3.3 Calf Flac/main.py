# -*- coding:utf8 -*-
# TODO
# ignore lower/upper case
# ignore \n
#
# 目前只想到中心向两边扩展的方法，O(n^2)，还待改进。

import sys
import string

def maxPalindromePositionAtIndex(pure_letter_list, index):
    start1 = index
    end1 = index

    while start1 > 0 and end1 < len(pure_letter_list) - 1:
        if pure_letter_list[start1-1] != pure_letter_list[end1+1]:
            break
        else:
            start1 -= 1
            end1 += 1

    if index < len(pure_letter_list) - 1 and pure_letter_list[index] == pure_letter_list[index+1]:
        start2 = index
        end2 = index+1

        while start2 > 0 and end2 < len(pure_letter_list) - 1:
            if pure_letter_list[start2-1] != pure_letter_list[end2+1]:
                break
            else:
                start2 -= 1
                end2 += 1
        if end2-start2 > end1 - start1:
            return (start2, end2);

    return (start1, end1)

def maxPalindromePosition(pure_letter_list):
    maxlen = maxstart = maxend = 0
    for i in range(len(pure_letter_list)):
        start, end = maxPalindromePositionAtIndex(pure_letter_list, i)
        #print i, start, end
        if (end - start) > maxlen:
            maxlen = end - start
            maxstart = start
            maxend = end
    return (maxstart, maxend)

def recordOriginPosition(raw_str):
    origin_position = []
    pure_letter_list = []
    for index, character in enumerate(raw_str):
        if character in string.ascii_letters:
            pure_letter_list.append(character.lower())
            origin_position.append(index)

    return (origin_position, pure_letter_list)

raw_str = sys.stdin.readlines()
raw_str = ''.join(raw_str)
#print raw_str
origin_position, pure_letter_list = recordOriginPosition(raw_str)
#print origin_position
#print pure_letter_list

start, end = maxPalindromePosition(pure_letter_list)
print end - start + 1
print raw_str[origin_position[start]:origin_position[end]+1]

