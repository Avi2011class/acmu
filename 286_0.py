from decimal import *
getcontext().prec = 1000;
a = Decimal(input())
b = Decimal(input())
if a > b: print('>')
if a < b: print('<')
if a == b: print('=')