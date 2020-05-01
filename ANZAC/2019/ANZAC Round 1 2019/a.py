n, k = map(int, input().split())
p = map(int, input().split())
c = 1
t = 0
for d in p:
	if t+d > k:
		t = d
		c += 1
	else:
		t += d
print(c)