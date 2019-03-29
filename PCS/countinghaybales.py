# time limit exceeds
N, Q = map(int, input().split())
b = sorted(list(map(int, input().split())))
def bsearch_l(a, x):
	l, r = 0, len(a)
	while l < r:
		m = (l+r)//2
		if a[m] < x: l = m+1
		else: r = m
	return l
d = {}
for _ in range(Q):
	A, B = map(int, input().split())
	if A in d: A_L = d[A]
	else:
		A_L = bsearch_l(b, A)
		d[A] = A_L
	if B in d: B_L = d[B]
	else:
		B_L = bsearch_l(b, B)
		if len(b) > B_L and b[B_L] == B: B_L += 1
		d[B] = B_L
	print(B_L - A_L)