n,m = map(int, raw_input().split())
pas = []
for i in range(0, m):
    pas.append(map(int, raw_input().split()))
pas.sort()

fee = 0
while n > 0:
    pa = pas.pop(0)
    if n >= pa[1]:
        fee += pa[0]*pa[1]
        n -= pa[1]
    else:
        fee += n * pa[0]
        n = 0
print fee
