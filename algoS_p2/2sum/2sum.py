m = {}
with open('2sum.txt', 'r') as infile:
    for line in infile:
        v = int(line.strip('\n'))
        if v not in m:
            m[v] = 1

d = {}
counter = 0
for t in range(-10000, 10001):
    for x in m:
        if t - x in m:
            counter += 1
            print(counter)

print(counter)


