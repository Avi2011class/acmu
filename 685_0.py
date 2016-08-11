s = input().split(' ')
a = [int(x) for x in s[:3]]
b = [int(x) for x in s[3:]]
a.sort()
b.sort()
c = 0
for i in [0, 1, 2]:
	c += a[i] * b[i] 
print(c)

  