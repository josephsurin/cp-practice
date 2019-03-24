from math import acos

n, T, v, d = map(int, input().split())
def z(x, y, s):
	q = 1-x**2-y**2 
	return 0 if q < 0 else s*(q)**0.5

ac_t = 0
a = list(map(float, input().split()))
a_x, a_y, a_z = a[0], a[1], z(a[0], a[1], a[2])
for _ in range(n-1):
	b = list(map(float, input().split()))
	b_x, b_y, b_z = b[0], b[1], z(b[0], b[1], b[2])
	dot = a_x*b_x + a_y*b_y + a_z*b_z
	if dot > 1: dot = 1
	elif dot < -1: dot = -1
	ac_t += acos(dot)
	a_x, a_y, a_z = b_x, b_y, b_z

t_d = lambda t_f: l(t_f) / d

def l(t_f):
	r = (1 + (3*v*t_f)/(4*acos(-1)))**(1/3)
	return ac_t * r

t_l, t_h = 1, T
while t_h - t_l > 0.000000001:
	t_f = (t_l + t_h)/2
	if t_f + t_d(t_f) > T: t_h = t_f
	else: t_l = t_f
print(l(t_f))