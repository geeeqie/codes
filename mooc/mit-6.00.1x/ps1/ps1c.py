s = 'azcbobobegghakl'
s = 'abcbcd'
s = 'abcdefghijklmnopqrstuvwxyz'
s = 'rqlzgslrcbfdary'
longest_index = 0
longest_len = 0
length = 1
for i in range(len(s) - 1):
    if ord(s[i]) <= ord(s[i+1]):
        length += 1
        if i == len(s) - 2 and length > longest_len:
            longest_len = length
            longest_index = i - length + 2
    else:
        if length > longest_len:
            longest_len = length
            longest_index = i - length + 1
        length = 1
print "Longest substring in alphabetical order is: ", s[longest_index:longest_index+longest_len]
