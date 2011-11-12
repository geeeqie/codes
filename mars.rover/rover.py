#!/usr/bin/python
dirs = "NESW"                   # Notations for directions
shifts=[(0,1),(1,0),(0,-1),(-1,0)] # delta vector for each direction
# One letter function names corresponding to each robot instruction
r = lambda x, y, a: (x, y, (a + 1) % 4)
l = lambda x, y, a: (x, y, (a - 1 + 4) % 4)
m = lambda x, y, a: (x + shifts[a][0], y + shifts[a][1], a)
raw_input()                     # Ignore the grid size
while 1:
# parse initial position triplet
	x, y, dir = raw_input().split()
	pos = (int(x),int(y),dirs.find(dir))
# parse instructions
	instrns = raw_input().lower() 
# Invoke the corresponding functions passing prev position
	for i in instrns: pos = eval('%s%s' % (i, str(pos)))
	print pos[0], pos[1], dirs[pos[2]]
