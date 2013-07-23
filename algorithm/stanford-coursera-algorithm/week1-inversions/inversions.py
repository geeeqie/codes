a = []
count = 0
for line in file("IntegerArray.txt"):
    a.append(int(line.strip()))
for i in range(len(a)):
    print(("round " + str(i)))
    for j in range(i+1, len(a)):
        if a[i] > a[j]:
            count += 1
print(count)
