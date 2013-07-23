# 3
# @-@
# ---
# @@-
# @-@
# @--
# --@

def rotate_square(square, rotate_func):
    new_square = []
    for i in range(len(square)):
            x, y = rotate_func(i/n, i%n)
            new_square.append(square[x*n+y])
    return new_square

def getsquare(n):
    square = []
    for i in range(n):
        square.extend(list(raw_input().strip()))
    return square

n = input()
square1 = getsquare(n)
square2 = getsquare(n)

rotate90 = lambda x, y: (n-1-y, x)
mirror = lambda x,y: (x,n-1-y)
f = lambda square: rotate_square(square, rotate90)
g = lambda square: rotate_square(square, mirror)

transforms = ((f,1), (lambda x:f(f(x)), 2), (lambda x:f(f(f(x))),3), (lambda x:g(x),4),
        (lambda x:f(g(x)),5), (lambda x:f(f(g(x))),5), (lambda x:f(f(f(g(x)))),5), (lambda x:x,6))

for func, val in transforms:
    if func(square1) == square2:
        print val
        break
else:
    print 7
