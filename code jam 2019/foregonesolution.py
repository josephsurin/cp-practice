T = int(input())
for i in range(T):
	N = int(input())
	A = N-1
	B = 1
	while('4' in str(A) or '4' in str(B)):
		ri = str(A).rfind('4')
		if ri == -1:
			A, B = B, A
		else:
			l = len(str(A))
			A -= 10 ** (l-ri-1)
			B += 10 ** (l-ri-1)
	print("Case #{}: {} {}".format(i+1, A, B))