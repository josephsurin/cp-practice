r, c = map(int, input().split())
grid = []
out = []
for _ in range(r):
    col = list(map(int, input().split()))
    out.append([0]*c)
    grid.append(col)
for x in range(0, r):
    for y in range(0, c):
        if x == 0 or y == 0 or x == r-1 or y == c-1:
            continue
        v = grid[x][y]
        if v < grid[x-1][y] and v < grid[x+1][y] and v < grid[x][y-1] and v < grid[x][y+1]:
            out[x][y] = 1
print('\n'.join(' '.join(map(str, R)) for R in out))
