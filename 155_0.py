import decimal
import math
import os
import sys

def step(vector, result):
    if len(vector) == 0:
        return False
    
    for k in vector:
        if abs(k - result) <= 0.01:
            return True

    for i in range(0, len(vector) - 1):
        for j in range(i + 1, len(vector)):
            buffer = vector[:]
            buffer[i] = buffer[i] + buffer[j]
            del buffer[j]
            if step(buffer, result):
                return True

    for i in range(0, len(vector) - 1):
        for j in range(i + 1, len(vector)):
            buffer = vector[:]
            buffer[i] = (buffer[i] * buffer[j]) / (buffer[i] + buffer[j])
            del buffer[j]
            if step(buffer, result):
                return True

    return False



k, t = map(float, input().split())
k = int(k)
arr = list(map(float, input().split()))

if step(arr, t):
    print("YES")
else:
    print("NO")


