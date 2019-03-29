from math import pi
T = int(input())
for _ in range(T):
	R, C = map(int, input().split())
	h = R - (R**2 - ((C**2)/4))**0.5
	A = pi*(R-h)**2
	print(A)