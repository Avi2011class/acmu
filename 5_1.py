input()
l = list(map(int, input().split()))
ne = list(filter(lambda x: x % 2 == 1, l))
ch = list(filter(lambda x: x % 2 == 0, l))
print(' '.join(map(str, ne)))
print(' '.join(map(str, ch)))
if len(ch) >= len(ne):
  print('YES')
else:
  print('NO')