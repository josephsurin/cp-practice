from math import ceil

n, t = map(int, input().split())

def get_m(n, t, d):
	if n < 4 + d or d == 7: 
		print(-1)
	else:
		s = 0
		for i in range(0, d+1):
			l = n - 4 - i - d
			rc = 9 * (10 ** i)
			s += rc*l
		if s >= t:
			t1 = t
			m = 0
			for i in range(0, d):
				rc = 9 * (10 ** i)
				l = n - 4 - i - d
				m += rc
				t1 -= rc*l
			l_d = n - 4 - 2*d
			m += ceil(t1/l_d)
			print(m)
		else:
			get_m(n, t, d+1)
			
get_m(n, t, 0)