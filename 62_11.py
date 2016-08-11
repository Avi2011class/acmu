s = input()
k = ord(s[0]) - ord('0') + ord(s[1]) - ord('A')
if k % 2 == 1:
  print('BLACK')
else:
  print('WHITE')