import math
n = int(input())
q = [2 ** i for i in range(0, 30)]
if q.count(n) > 0:
  print('YES')
else:
  print('NO')