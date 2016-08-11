s = input()
r=''
if (ord(s[0]) + ord(s[1])) % 2 == 0:
  r='BLACK'
else:
  r='WHITE'
print(r)