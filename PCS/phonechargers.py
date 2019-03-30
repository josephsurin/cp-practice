T = int(input())
while(T):
    m = []
    for _ in range(3):
        m.append([int(c) for c in input().split()])
    m = list(map(list, zip(*m)))
    print(min(map(max, [
        (m[0][0],m[1][1],m[2][2]),
        (m[0][0],m[1][2],m[2][1]),
        (m[0][1],m[1][0],m[2][2]),
        (m[0][1],m[1][2],m[2][0]),
        (m[0][2],m[1][0],m[2][1]),
        (m[0][2],m[1][1],m[2][0])
    ])))
    T -= 1