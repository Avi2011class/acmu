s = list(input())
b = True
i = 0
j = len(s) - 1
while i < j:
  if s[i] != s[j]:
    b = False
  i += 1
  j -= 1
if b:
  print('YES')
else:
  print('NO')