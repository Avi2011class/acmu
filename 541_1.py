# ----------------
s = input()
it = 0
while s[it] == '0':
	it += 1
s = s[it:] + s[:it]

n = int(s)
l = [int(x) for x in list(str(n))]
max_pow = 10 ** (len(l) - 1)

min_1 = n
max_1 = n
for i in range(len(l)):
	n = (n - l[i] * max_pow) * 10 + l[i]
	if l[(i + 1) % len(l)] != 0:
		min_1 = min(min_1, n)
		max_1 = max(max_1, n)
# ----------------
t = input()
it = 0
while t[it] == '0':
	it += 1
t = t[it:] + t[:it]

n = int(t)

l = [int(x) for x in list(str(n))]
max_pow = 10 ** (len(l) - 1)

min_2 = n
max_2 = n
for i in range(len(l)):
	n = (n - l[i] * max_pow) * 10 + l[i]
	if l[(i + 1) % len(l)] != 0:
		min_2 = min(min_2, n)
		max_2 = max(max_2, n)
# ----------------		
print(max_1 - min_2)
	