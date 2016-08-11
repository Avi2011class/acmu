n = input()
for i in range(100, -1, -1):
  if n.count('0' * i) > 0:
    print(i)
    exit(0)