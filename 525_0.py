n = int(input())
l = [0] * (n + 1)
l[0] = 1
j = 1
while j <= n:
	for i in range(n, -1, -1):
		k = 1
		while k * j <= i:
			l[i] += l[i - k * j]
			k += 1
	j *= 2
print(l[n])