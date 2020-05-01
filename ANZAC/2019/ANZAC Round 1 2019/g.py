def inc_g(g):
	for r in g:
		for c in range(10): r[c] += 1

def cut_r(g, r):
	for c in range(10): g[r][c] = 1

def cut_c(g, c):
	for r in range(10): g[r][c] = 1

k = int(input())
g = [[1]*10 for _ in range(10)]
for w in range(k):
	inc_g(g)
	inp = list(map(int, input().split()))
	R, C = inp[:3], inp[3:]
	for r in R:
		cut_r(g, r-1)
	for c in C:
		cut_c(g, c-1)

print('\n'.join([' '.join([str(c) for c in r]) for r in g]))