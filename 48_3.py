s = input()
d = len(s) - 1
while s[d] == '0': d -= 1
print(pow(10, len(s) - 1 - d))