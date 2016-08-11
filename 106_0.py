n = int(input())
l = []
for i in range(0, n):
  a = int(input())
  l.append(a)
print(min(l.count(0), l.count(1)))