
one = 0
two = 0
three, n = map(int, input().split())
for i in range(n - 1):
	s = one + two + three
	one = two
	two = three
	three = 0
	three = max(three, ((s) // 5) * 9)
	if s >= 3:
		three = max(three, 5 + ((s-3) // 5) * 9)
	if s >= 6:
		three = max(three, 10 + ((s-6) // 5) * 9)
	if s >= 9:
		three = max(three, 15 + ((s-9) // 5) * 9)
	if s >= 12:
		three = max(three, 20 + ((s-12) // 5) * 9)
	if s >= 15:
		three = max(three, 25 + ((s-15) // 5) * 9)
print(one + two + three)