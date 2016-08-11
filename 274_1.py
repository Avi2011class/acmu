n = int(input())
for _ in range(n):
  a, b = input().split()
  a, b = set(a), set(b)
  if a == b:
    print("YES")
  else:
  	print("NO")