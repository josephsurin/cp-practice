# by chsh
from collections import defaultdict
d = defaultdict(int)
for T in range(int(input())):
    a, b = map(int, input().split())
    for i in range(a, b+1):
        d[i] += 1

k = list(d.keys())

possible = -1

for i in k[::-1]:
    if i == d[i]:
        if i > possible:
            possible = i

print(possible)
