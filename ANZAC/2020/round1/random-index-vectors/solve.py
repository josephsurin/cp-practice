def read_vec(maxn):
    A = list(map(int, input().split()))[1:]
    vec = [0]*maxn
    for a in A:
        c = 1 if a > 0 else -1
        i = abs(a) - 1
        vec[i] = c
    return vec

def print_vec(vec):
    print(' '.join(map(str, vec)))

def add(vec1, vec2):
    o = []
    for x,y in zip(vec1, vec2):
        if x == y:
            o.append(x)
        else:
            o.append(x+y)
    return o

def mult(vec1, vec2):
    return [x*y for x,y in zip(vec1, vec2)]

def rot(vec, k):
    return vec[k:] + vec[:k]

def to_comp(vec):
    c = vec.count(1) + vec.count(-1)
    o = [c]
    for i,v in enumerate(vec):
        if v != 0:
            o.append(v * (i+1))
    return o

n, k = map(int, input().split())
vec1 = read_vec(n)
vec2 = read_vec(n)
print_vec(to_comp(add(vec1, vec2)))
print_vec(to_comp(mult(vec1, vec2)))
print_vec(to_comp(rot(vec1, k)))
print_vec(to_comp(rot(vec2, k)))
