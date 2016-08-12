fib = [1, 1] # 1, 1, 2, 3, 5
k, t = 1, 1
for i in range(300):
	k, t = k + t, k
	fib.append(k)

def from_fib(st):
	global fib
	res = 0
	sq = [ch for ch in st]
	sq.reverse()
	for index, item in enumerate(sq):
		if item == '1':
			res += fib[index + 1]
	return res

def to_fib(x):
	global fib
	index = 1
	while fib[index + 1] <= x:
		index += 1
	res = ""
	while index >= 1:
		if x >= fib[index]:
			x -= fib[index]
			res = res + '1'
		else:
			res = res + '0'
		index -= 1
	return res

s1 = input()
s2 = input()
print(to_fib(from_fib(s1) + from_fib(s2)))
