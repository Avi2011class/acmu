n, k = map(int, input().split())
l = (0, k - 1)
for i in range(0, n - 1):
  l = (l[1], (l[1]+l[0]) * (k - 1))
print(l[0] + l[1])