N = int(input())
M = int(input())
r_e = {}
r_d = {}
for _ in range(N):
	f, t = input().split()
	r_e[f] = t
	r_d[t] = f
for _ in range(M):
	t, m = input().split()
	if t == 'E':
		print(''.join([r_e[c] if c in r_e else c for c in m]))
	elif t == 'D':
		print(''.join([r_d[c] if c in r_e else c for c in m]))