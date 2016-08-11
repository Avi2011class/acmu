n = int(input())
for _ in range(n):
  a, b = map(set, input().split())
  if a == b:
    print("YES")
  else:
  	print("NO")