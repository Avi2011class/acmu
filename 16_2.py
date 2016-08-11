n = int(input())
if n == 1:
    print(1)
    exit(0)
v = [[0 for i in range(0, n + 2)] for j in range(0, n + 2)]
s = [[0 for i in range(0, n + 2)] for j in range(0, n + 2)]
for i in range(1, n + 2):
    v[i][i] = 1
for i in range(0, n + 2):
    for j in range(1, n + 2):
        s[i][j] = s[i][j - 1] + v[i][j]
'''
for i in range(0, n + 2):
    print(v[i], '    ', s[i])
print()
'''
for i in range(2, n + 2):
    for j in range(1, i):
        v[i][j] = s[i - j][j - 1]
    for j in range(1, n + 2):
        s[i][j] = s[i][j - 1] + v[i][j]
'''
for i in range(0, n + 2):
    print(i, s[i][n + 1])
print('-' * 30)
'''
print(s[n][n + 1])