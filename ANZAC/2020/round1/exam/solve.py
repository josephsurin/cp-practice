t = int(input())
a = input()
b = input()

matches = 0
for i in range(len(a)):
    if a[i] == b[i]:
        matches += 1

mismatch = len(a) - matches
print(min(mismatch, len(a)-t) + min(matches, t))
