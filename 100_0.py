n = int(input()) // 2
v = [[0 for _ in range(10 * n)] for _ in range(n)]
for i in range(10):
	v[0][i] = 1
for i in range(1, n):
	for j in range(0, 10 * n):
		for k in range(0, 10):
			if j - k >= 0:
				v[i][j] += v[i - 1][j - k]

result = sum([i * i for i in v[n - 1]])
print(result)