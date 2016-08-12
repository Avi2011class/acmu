n = int(input())

k = n
arr_max = []
for i in range(2, 10):
	while k % i == 0:
		k //= i
		arr_max.append(str(i))
arr_max.reverse()

k = n
arr_min = []
for i in range(9, 1, -1):
	while k % i == 0:
		k //= i
		arr_min.append(str(i))
arr_min.reverse()

if k != 1:
	print ("-1 -1")
else:
	print ("{0} {1}".format(''.join(arr_min), ''.join(arr_max)))