a = 1
b = 0
n = int(input())
for i in range(n):
  a, b = b, a + b
print(b)