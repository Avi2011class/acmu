def gcd(a, b):
	while b != 0:
		a, b = b, a % b
	return a

x1, y1, x2, y2, x3, y3 = map(int, input().split())
res = -3

vx = abs(x2 - x1)
vy = abs(y2 - y1)
if vx * vy == 0:
	res += vx + vy + 1
else:
	gc = gcd(vx, vy)
	res += vx // (vx // gc) + 1

vx = abs(x3 - x1)
vy = abs(y3 - y1)
if vx * vy == 0:
	res += vx + vy + 1
else:
	gc = gcd(vx, vy)
	res += vx // (vx // gc) + 1
	
vx = abs(x2 - x3)
vy = abs(y2 - y3)
if vx * vy == 0:
	res += vx + vy + 1
else:
	gc = gcd(vx, vy)
	res += vx // (vx // gc) + 1
print(res)