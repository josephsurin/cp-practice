from math import ceil
n, s = map(int, input().split())
M = list(map(int, input().split()))

print(max(ceil(s*m/1000) for m in M))
