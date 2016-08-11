import math
x, k = map(int, input().split())
print(math.factorial(x // 5 + k) // math.factorial(x // 5) // math.factorial(k))