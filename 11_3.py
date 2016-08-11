k, n = map(int, input().split(' '))
v = [0 for i in range(0, n + 1)]
v[0] = 1
for i in range(1, n + 1):
    for j in range(1, min(k, i) + 1):
        v[i] += v[i - j]
print(v[n])