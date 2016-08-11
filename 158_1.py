import math
x, k = map(int, input().split())
x = x // 5;
res = math.factorial(x + k) // math.factorial(x) // math.factorial(k)
print(res)