S = int(input())
for _ in range(S):
    H = int(input())
    P = [int(x) for x in input().split()]
    maxp = 0
    sum = 0
    for p in P:
        if p < 0:
            if sum > maxp:
                maxp = sum
        if sum + p < 0:
            sum = 0
        else:
            sum += p
    maxp = max(sum, maxp)
    print(maxp)