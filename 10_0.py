a, b, c, d = map(int, input().split())
for i in range(-100, 101):
  if i * i * i * a + i * i * b + i * c + d == 0:
    print(i, end=' ')