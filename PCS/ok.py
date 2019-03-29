T = int(input())
for _ in range(T):
	s = input()
	o = s.index('O') + 1
	print('YES') if s[o:].find('K') != -1 else print('NO')