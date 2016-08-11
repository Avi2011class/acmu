n = int(input())
res = 2
for i in range(1, n):
	if (1 * (10 ** n) + res) % (2 ** (i + 1)):
		res = 1 * (10 ** i) + res
	else:
		res = 2 * (10 ** i) + res
print(res)