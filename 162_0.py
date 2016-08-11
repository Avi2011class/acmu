m, n = map(int, input().split())
if m < n:
  m, n = n, m
m += 1
n += 1
if n == 2:
	print(2 * m * n - 4)
elif m % 2 == 0 and n % 2 == 0:
  print(2 * m * n - 4)
else:
  print(2 * m * n - 2)

  