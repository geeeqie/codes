# USACO 1.1.4 Broken Necklace

def collect(necklace, broken_pos):
    newlace = necklace[broken_pos:] + ''.join(list(reversed(necklace[:broken_pos])))
    ncollect = 0

    base = 'w'
    for left_pos, ball in enumerate(newlace):
        if ball=='w':
            ncollect += 1
        elif base == 'w':  #in case of start with 'w'
            base = ball
            ncollect += 1
        elif  ball == base:
            ncollect += 1
        else:
            left_pos -= 1
            break
    base = 'w'
    for right_pos, ball in reversed(list(enumerate(newlace))):
        if left_pos == right_pos:
            break
        if ball == 'w':
            ncollect += 1
        elif base == 'w':
            base = ball
            ncollect += 1
        elif ball == base:
            ncollect += 1
        else:
            break
    return ncollect

n = input()
necklace = raw_input().strip()
max_collect = 0
for i in range(n):
    ncollect = collect(necklace, i)
    #print i, ncollect
    if ncollect > max_collect:
        max_collect = ncollect

print max_collect
