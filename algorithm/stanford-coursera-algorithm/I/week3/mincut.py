MAX = 200
for i in range(0, MAX):
    data = raw_input().split()
    v1 = int(data[0])
    for d in data[1:]:
        v2 = int(d)
        graph[v1][v2] = 1
