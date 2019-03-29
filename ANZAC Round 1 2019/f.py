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
	to_exec = [(imm, s, [])]
	res = []
	while len(to_exec):
		imm, p, cmm = to_exec.pop()
		m = [r[::] for r in imm]
		# m = imm
		c = cmm[::]
		if m[p[0]][p[1]] == 'O': c.append(p)
		m[p[0]][p[1]] = 'X'
		adj = get_adj(p, R, C)
		for a in adj:
			ao = m[a[0]][a[1]]
			if ao == 'A' and len(c) % 2 == 0:
				res.append(len(c) // 2 + 1)
			elif ao == 'A' and len(c)% 2 == 1:
				rm_c = [r[::] for r in reactor_map]
				rm_c[s[0]][s[1]] = 'X'
				for o in c[1:]:
					rm_c[o[0]][o[1]] = '.'
				if can_link_e(rm_c, c[0]):
					res.append(ceil(len/2) + 1)
			elif ao in ['.', 'O']: to_exec.append((m, a, c))
	if res:
		return min(res)
	else:
		return -1
			
A = next((ri, r.index('A')) for ri, r in enumerate(reactor_map) if 'A' in r)

ans = can_link(reactor_map, A)

print(ans)