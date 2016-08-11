a, b, c, d = input(), input(), input(), input()
if b > c:
	b, c = c, b
if c > d:
	d, c = c, d
if b > c:
	b, c = c, b
print('{0}: {1}, {2}, {3}'.format(a, b, c, d))