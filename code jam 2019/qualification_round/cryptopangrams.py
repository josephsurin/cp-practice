from fractions import gcd

alph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

T = int(input())
for tc in range(1, T+1):
	N, L = [int(a) for a in input().split()]
	c = [int(a) for a in input().split()]
	p = [None]*(L+1)
	for j in range(L-1):
		if c[j] != c[j+1]:
			g = gcd(c[j], c[j+1])
			p[j+1] = g
			break
			
	for i in range(j+1, 0, -1):
		p[i-1] = c[i-1]//p[i]
	for i in range(j+1, len(p)-1):
		p[i+1] = c[i]//p[i]

	sp = sorted(set(p))
	k = dict(zip(sp, alph))
	print("Case #{}: {}".format(tc, ''.join([k[a] for a in p])))