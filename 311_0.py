n = int(input())
l = [1 for i in range(0, n + 1)]
for i in range(2, n + 1):
	l[i] = l[i - 1] * i;
print(sum(l) - 1)