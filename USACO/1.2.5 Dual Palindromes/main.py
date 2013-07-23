def repr_base(n, base):
    repr_str = []
    while n >= base:
        repr_str.append(chr(n%base))
        n /= base
    else:
        repr_str.append(chr(n))
    repr_str.reverse()
    return repr_str

def isvalid(n):
    cnt = 0
    for base in range(2, 10+1):
        rp = repr_base(n, base)
        if rp == list(reversed(rp)):
            cnt += 1
            if cnt >= 2: return True
    return cnt >= 2

n,s = map(int, raw_input().split())

while True:
    if n == 0:
        break
    s += 1
    if isvalid(s):
        print s
        n -= 1


