n = int(input())
W = list(map(int, input().split()))
out = [W[0]]
for i in range(1, n):
	out.append(min(W[i], out[i-1]+1))
print(' '.join([str(o) for o in out]))