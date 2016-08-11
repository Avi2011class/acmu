n = int(input())
l = [0] * (n + 1)
l[0] = 1
j = 0
while 2 ** j <= n:
	for i in range(n, -1, -1):
		k = 1
		while k * (2**j) <= i:
			l[i] += l[i - k * (2**j)]
			k += 1
	j += 1
print(l[n])