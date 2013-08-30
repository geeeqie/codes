a = dict()
while True:
    try:
        v = int(raw_input().strip())
        a[v] = a.get(v, 0) + 1
    except EOFError:
        break

def satisfy(t):
    for x in a.keys():
        y = t - x
        if a.has_key(y):
            return True
    return False

count = 0
for t in range(-10000, 10000+1):
    print(t)
    if satisfy(t):
        count += 1
print("==COUNT==")
print(count)
