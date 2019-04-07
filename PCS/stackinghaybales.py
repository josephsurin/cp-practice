from bisect import bisect_left
from itertools import combinations
def bsearch(a, x):
	p = bisect_left(a, x)
	return p != len(a) and x == a[p]
T = int(input())
for _ in range(T):
	yay = False
	N, H = [int(s) for s in input().split()]
	Hs = [int(s) for s in input().split()]
	A, B = Hs[:N//2], Hs[N//2:]
	As = [0]
	Bs = [0]
	for n in range(1, 1+len(A)):
		As += [sum(c) for c in combinations(A, n)]
	for n in range(1, 1+len(B)):
		Bs += [sum(c) for c in combinations(B, n)]
	Bs.sort()
	for a in As:
		if a > H: continue
		if bsearch(Bs, H - a):
			yay = True
			break
	print("YAY") if yay else print("NAY")