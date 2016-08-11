a = 1
b = 1
i = 2
n = int(input())
while b < n:
  a, b = b, a + b
  i += 1
if b == n:
  print(1)
  print(i)
else:
  print(0)
