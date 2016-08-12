def get(n):
	max_pow = 1
	while max_pow * 3 <= n:
		max_pow *= 3

	res = 0

	while n > 0:
		# print(n, max_pow)
		if (n >= 2 * max_pow):
			n -= 2 * max_pow
			res = 1 - res
		elif n >= max_pow:
			n -= max_pow
		max_pow //= 3
	return res

n = int(input())
print(get(n - 1))