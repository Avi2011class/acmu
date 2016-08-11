def gcd(a, b):
	while b != 0:
		a, b = b, a % b
	return a

x1, y1, x2, y2 = map(int, input().split())
vx = abs(x2 - x1)
vy = abs(y2 - y1)
if vx * vy == 0:
	print(vx + vy + 1)
else:
	gc = gcd(vx, vy)
	print(vx // (vx // gc) + 1)