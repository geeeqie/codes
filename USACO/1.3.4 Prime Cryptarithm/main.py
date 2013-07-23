n = int(raw_input())
d = map(int, raw_input().split())

def valid(x, length):
    return len(str(x))==length and set(map(int, list(str(x)))) <= set(d)

count = 0
for i1 in range(n):
    for i2 in range(n):
        for i3 in range(n):
            for i4 in range(n):
                for i5 in range(n):
                    a = d[i1]*100 + d[i2]*10 + d[i3]
                    b = d[i4]*10 + d[i5]
                    m1 = a * d[i5]
                    m2 = a * d[i4]
                    p = m2*10 + m1
                    if valid(m1, 3) and valid(m2, 3) and valid(p, 4):
                        count += 1
print count
