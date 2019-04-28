n = int(input())
a = 3 if n % 2 == 0 else -3
b = pow(3, n, 10**9 + 7)
s = ((a+b)%(10**9 + 7))//4
print(s)