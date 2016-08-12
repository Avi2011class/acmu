import random

def get(n):
	start = 0
	stop = 10 ** 1500 + 1

	while start != stop:
		k = (stop + start + (stop + start) % 2) // 2
		if k * k == n:
			start = k
			stop = k
			break
		elif k * k > n:
			stop = k - 1
		else:
			start = k
	return start

'''
for _ in range(100):
	n = random.randint(0, 10 ** 3000)
	t = get(n)
	if not (t * t <= n and (t + 1) * (t + 1) > n):
		print("Err")
		print(n)
	else:
		print("OK")
'''
print(get(int(input())))