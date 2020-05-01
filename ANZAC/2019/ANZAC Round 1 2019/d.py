n, h, v, w = list(map(int, input().split()))

d_a = []
win = False

for _ in range(n):
	d_x, y_k = list(map(int, input().split()))
	d_s = (y_k + (d_x * v)) % h
	d_a.append(d_s)

d_a = sorted(d_a)
l = w * v + 1
if d_a[0] > (d_a[-1] + l) % h: win = True

if not win:
	for i in range(n-1):
		a, b = d_a[i], d_a[i+1]
		if b > a + l:
			win = True
			break

print('VICTORY') if win else print('GAME OVER')