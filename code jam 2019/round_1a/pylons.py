from collections import defaultdict

def print_hamiltonian(graph):
	def hamiltonian_path(graph, node, path=[]):
		if node not in path:
			path.append(node)
			if len(path) == len(graph):
				return path
			for neighbour in graph[node]:
				rpath = path[::]
				c = hamiltonian_path(graph, neighbour, rpath)
				if c: return c
	hp = hamiltonian_path(graph, (1,1))
	for p in hp:
		print(*p)

T = int(input())
for tc in range(1, T+1):
	R, C = [int(i) for i in input().split()]
	impossible = False
	graph = defaultdict(list)
	for (r, c) in [(i, j) for i in range(1, 1+R) for j in range(1, 1+C)]:
		for (r_, c_) in [(i, j) for i in range(1, 1+R) for j in range(1, 1+C)]:
			if not ((r == r_) or (c == c_) or (r - c == r_ - c_) or (r + c == r_ + c_)):
				graph[(r, c)].append((r_, c_)) 
		if (r, c) not in graph:
			impossible = True
			break
	if not impossible:
		if any([len(v) == 1 for v in graph.values()]):
			impossible = True
	if impossible:
		print('Case #{}: IMPOSSIBLE'.format(tc))
	else:
		print('Case #{}: POSSIBLE'.format(tc))
		print_hamiltonian(graph)