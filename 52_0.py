n = int(input())
a, n = n % 10, n // 10
b, n = n % 10, n // 10
c, n = n % 10, n // 10
d, n = n % 10, n // 10
e, n = n % 10, n // 10
f, n = n % 10, n // 10
if a + b + c == d + e + f: print('YES')
else: print('NO')