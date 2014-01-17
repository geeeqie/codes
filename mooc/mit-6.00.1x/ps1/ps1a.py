s = 'azcbobobegghakl'
count = 0
for i in range(len(s)):
    if s[i] in 'aeiou':
        count += 1
print "Number of vowels:",count
