from decimal import *
getcontext().prec = 1000;
a = int(input())
cur = 1
res = 0
for i in range(1, a + 1):
	cur *= i
	res += cur
print(res)