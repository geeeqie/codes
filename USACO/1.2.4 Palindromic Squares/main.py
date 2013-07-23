def nchr(n):
    if n < 10:
        return str(n)
    else:
        return chr(ord('A')+(n-10))

def repr_base(n, base):
    repr_str = []
    while n >= base:
        repr_str.append(nchr(n%base))
        n /= base
    else:
        repr_str.append(nchr(n))
    repr_str.reverse()
    return repr_str

base = input()
for i in range(1,300+1):
    rpstr = repr_base(i*i, base)
    if rpstr == list(reversed(rpstr)):
        print ''.join(repr_base(i, base)), ''.join(rpstr)
