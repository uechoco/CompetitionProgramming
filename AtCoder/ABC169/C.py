import math
from sys import stdin

A, B = [float(x) for x in stdin.readline().rstrip().split()]
print(int(math.floor(A * B)))
