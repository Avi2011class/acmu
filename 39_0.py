# your code goes here
input()
n = list(map(int, input().split()))
s = 0
while len(n) > 0:
	for i in range(len(n)-1, -1, -1):
		if n[i] == max(n):
			s += (i + 1) * max(n)
			n = n[i + 1:]
			break
print(s)