from functools import reduce
from math import ceil

R, C = map(int, input().split())
reactor_map = []
for r in range(R):
	reactor_map.append(list(input()))

get_adj = lambda p, R, C: filter(lambda a: 0 <= a[0] < R and 0 <= a[1] < C,
	[(p[0]+1, p[1]), (p[0]-1, p[1]), (p[0], p[1]+1), (p[0], p[1]-1)])

def can_link_e(reactor_map, s):
	def can_link_r(p):
		reactor_map[p[0]][p[1]] = 'X'
		adj = get_adj(p, R, C)
		to_check = []
		for a in adj:
			ao = reactor_map[a[0]][a[1]]
			if ao == 'O': return True
			elif ao == '.': to_check.append(a)
		if not to_check: return False
		return any(map(can_link_r, to_check))

def can_link(imm, s):
	m = [r[::] for r in imm]
	def can_link_r(p, c):
		if m[p[0]][p[1]] == 'O': c.append(p)
		m[p[0]][p[1]] = 'X'
		adj = get_adj(p, R, C)
		to_check = []
		print('\n'.join(map(''.join, m)))
		print()
		for a in adj:
			ao = m[a[0]][a[1]]
			if ao == 'A' and len(c) % 2 == 0: return (True, len(c) // 2 + 1)
			elif ao == 'A' and len(c)% 2 == 1:
				rm_c = [r[::] for r in reactor_map]
				rm_c[s[0]][s[1]] = 'X'
				for o in c[:-1]:
					rm_c[o[0]][o[1]] = '.'
				if can_link_e(rm_c, c[-1]): return (True, ceil(len/2) + 1)
				else: return (False, 0)
			elif ao in ['.', 'O']: to_check.append(a)
		if not to_check: return (False, 0)
		t = list(filter(lambda s: s[0], [can_link_r(t, c) for t in to_check]))
		if t: return min(t, key = lambda s: s[1])
		return (False, 0)

	return can_link_r(s, [])
			
A = next((ri, r.index('A')) for ri, r in enumerate(reactor_map) if 'A' in r)

ans = can_link(reactor_map, A)
print(ans[1]) if ans[0] else print('-1')

# d = [(ri, ci) for ri, r in enumerate(reactor_map) for ci, c in enumerate(r) if c == 'O']

# if len(d) is 1:
# 	dp = d[0]
# 	rm_c = [r[::] for r in reactor_map]
# 	rm_c[dp[0]][dp[1]] = '#'
# 	print('1') if can_link(rm_c, A)[0] else print('-1')
# elif len(d)%2 == 1:
# 	ts = []
# 	for dp in d:
# 		rm_c = [r[::] for r in reactor_map]
# 		rm_c[dp[0]][dp[1]] = '#'
# 		t = can_link(rm_c, A)
# 		if t[0]: ts.append(t)
# 	print(ceil(min([t[1] for t in ts])/2) + 1) if ts else print('-1')
# elif len(d)%2 == 0:
# 	t = can_link(reactor_map, A)
# 	print(ceil(t[1]/2) + 1) if t[0] else print('-1')