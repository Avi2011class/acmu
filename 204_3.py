s = input()
r, l = 0, len(s)
x, y, b, e = 1, 1, ord(s[0]), ord(s[l - 1])
i = 0
while i < l - 1:
    if b == ((e * x) % 100000007): 
        r = i + 1
    x, y, i = (x * 7) % 100000007, (y * 42857146) % 100000007, i + 1
    b, e = (b + x * ord(s[i])) % 100000007, (e + y * ord(s[l - 1 - i])) % 100000007
print(l - r)