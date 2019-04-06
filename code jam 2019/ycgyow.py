opp = lambda d: 'S' if d=='E' else 'E'

T = int(input())
for tc in range(1, T+1):
	N = int(input()) #going to need (N-1) E's and (N-1) S's
	P = input()
	mypath = [opp(m) for m in P]
	print("Case #{}: {}".format(tc, ''.join(mypath)))