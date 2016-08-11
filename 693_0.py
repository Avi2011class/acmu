a, b = input().split()
a = list(a.lower())
b = list(b.lower())
a.sort()
b.sort()
if a == b:
  print('Yes')
else:
  print('No')