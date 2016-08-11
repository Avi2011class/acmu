m = 650
n = int(input())
l = [0] * m
l[0] = 1
for i in range(0, m):
    for j in range(m-1,-1,-1):
        if j >= i:
            l[j] += l[j - i]
    if i == n:
        print(l[n] // 2)
        exit(0)