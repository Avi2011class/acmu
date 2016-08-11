s = input()
r=''
if ord(s[1]) % 2 == ord(s[0]) % 2:
  r='BLACK'
else:
  r='WHITE'
print(r)