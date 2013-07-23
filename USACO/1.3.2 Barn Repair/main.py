### def total_length(bounds):
###     global stall_number
### 
###     prev_bound = 0
###     length = 0
###     
###     pairs = []
###     for bound in bounds:
###         pairs.append((stall_number[prev_bound], stall_number[bound - 1]))
###         prev_bound = bound
###     pairs.append((stall_number[prev_bound], stall_number[len(stall_number)-1]))
### 
###     print pairs
###     for lower, upper in pairs:
###         length += upper - lower + 1
### 
###     return length
###         
### def find_min_length(lower, upper, bounds=[]):
###     global min_length
###     global stall_number
### 
###     if lower == upper:
###         return
###     if len(bounds) >= M-1:
###         length = total_length(bounds)
###         #print bounds, '\t\t\t\t', length
###         print length
###         if length < min_length:
###             min_length = length
###         return
###     for i in range(lower+1, upper):
###         bounds.append(i)
###         find_min_length(i, upper, bounds)
###         bounds.pop()

M, S, C = map(int, raw_input().split())
stall_numbers = []
for i in range(0, C):
     stall_numbers.append(input())
stall_numbers.sort()
#print stall_numbers

if M >= C:
    min_length = C
else:
    gap_index_pairs = []
    for i in range(1, len(stall_numbers)):
        gap_index_pairs.append((stall_numbers[i] - stall_numbers[i - 1], i))
    gap_index_pairs.sort()
    gap_index_pairs.reverse()
    useful_index = map(lambda x: x[1], gap_index_pairs[:M-1])
    useful_index.sort()
    #print useful_index
    
    prev = 0
    bounds = []
    for i in range(0, len(useful_index)):
        bounds.append((stall_numbers[prev], stall_numbers[useful_index[i]-1]))
        prev = useful_index[i]
    bounds.append((stall_numbers[prev], stall_numbers[-1])) 
    #print bounds

    min_length = 0
    for lower, upper in bounds:
        min_length += upper - lower + 1

print min_length
