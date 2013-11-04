a = [0]
while True:
    try:
        a.append(int(raw_input().strip()))
    except EOFError:
        break
print("len(a)=%d"%len(a))

s = 0
for k in range(1, len(a)):
    b = a[1:k+1]
    b.sort()
    m = (k + 1) / 2 
    s += b[m-1]
    print("k=%d, mid=%d" % (k,b[m-1]))
print("====SUM====")
print("s=%d" % s)
