alph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

T = int(input())
for tc in range(1, T+1):
	N, L = [int(a) for a in input().split()]
	c = [int(a) for a in input().split()]
	pp3 = [c[n]*c[n+2]/c[n+1] for n in range(L-2)]
	minn, minpp3 = min(enumerate(pp3), key=lambda x: x[1])
	p = [None]*(L+1)
	i=2
	while i*i <= minpp3:
		if(minpp3%i == 0):
			pf1 = i
			pf2 = int(minpp3//i)
			break
		i+=1
	try:
		p[minn+3] = pf1
		p[minn] = pf2
		for i in range(minn, 0, -1):
			if c[i-1]/p[i] != c[i-1]//p[i]: raise ""
			p[i-1] = c[i-1]//p[i]
		for i in range(minn, len(p)-1):
			if c[i]/p[i] != c[i]//p[i]: raise ""
			p[i+1] = c[i]//p[i]
		sp = sorted(set(p))
		k = dict(zip(sp, alph))
		print("Case #{}: {}".format(tc, ''.join([k[a] for a in p])))
	except:
		p[minn+3] = pf2
		p[minn] = pf1
		for i in range(minn, 0, -1):
			p[i-1] = c[i-1]//p[i]
		for i in range(minn, len(p)-1):
			p[i+1] = c[i]//p[i]
		sp = sorted(set(p))
		k = dict(zip(sp, alph))
		print("Case #{}: {}".format(tc, ''.join([k[a] for a in p])))