s = input().replace('\n', '')
r, l = 0, len(s)
x, y, hb, he = 1, 1, ord(s[0]), ord(s[l - 1])
i = 0
while i < l - 1:
	if hb == ((he * x) % 100000007): 
		r = i + 1
	x, y, i = (x * 7) % 100000007, (y * 42857146) % 100000007, i + 1
	hb, he = (hb + x * ord(s[i])) % 100000007, (he + y * ord(s[l - 1 - i])) % 100000007
print(l - r)