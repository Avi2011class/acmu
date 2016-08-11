m, n = map(int, input().split())
res = 1000000
for i in range(0, m):
    res = min(res, input().count('.'))
if res == 1000000:
	res = 0
print(res)