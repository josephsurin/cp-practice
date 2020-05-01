def sign(x):
    if x == 0: return 0
    return 1 if x > 0 else -1

def read_vec():
    A = list(map(int, input().split()))[1:]
    return A

def print_vec(A):
    A.insert(0, len(A))
    print(' '.join(map(str, A)))

def myin(x, A):
    # A is sorted
    for a in A:
        if abs(a) == abs(x):
            return True, a
        elif abs(a) > abs(x):
            return False, 0
    return False, 0

def add(vec1, vec2):
    o = []
    vec1 = vec1[::]
    vec2 = vec2[::]
    s = vec1 if abs(vec1[0]) < abs(vec2[0]) else vec2
    b = vec2 if abs(vec1[0]) < abs(vec2[0]) else vec1
    while s or b:
        cc = s.pop(0)
        e, v2 = myin(cc, b)
        if e:
            if (v2 < 0 and cc < 0) or (v2 > 0 and cc > 0):
                o.append(cc)
            b.remove(v2)
        else:
            o.append(cc)
        if not vec1:
            s = vec2
            b = vec1
        elif not vec2:
            s = vec1
            b = vec2
        else:
            s = vec1 if abs(vec1[0]) < abs(vec2[0]) else vec2
            b = vec2 if abs(vec1[0]) < abs(vec2[0]) else vec1
    return o

def mult(vec1, vec2):
    o = []
    vec1 = vec1[::]
    vec2 = vec2[::]
    s = vec1 if abs(vec1[0]) < abs(vec2[0]) else vec2
    b = vec2 if abs(vec1[0]) < abs(vec2[0]) else vec1
    while s or b:
        cc = s.pop(0)
        e, v2 = myin(cc, b)
        if e:
            o.append(cc*sign(v2))
            b.remove(v2)
        if not vec1:
            s = vec2
            b = vec1
        elif not vec2:
            s = vec1
            b = vec2
        else:
            s = vec1 if abs(vec1[0]) < abs(vec2[0]) else vec2
            b = vec2 if abs(vec1[0]) < abs(vec2[0]) else vec1
    return o

def rot(vec, k, n):
    o = []
    for v in vec:
        if abs(v) == k:
            o.append(sign(v)*n)
        else:
            o.append(sign(v)*((abs(v)-k)%n))
    o.sort(key=abs)
    return o

n, k = map(int, input().split())
vec1 = read_vec()
vec2 = read_vec()
print_vec(add(vec1, vec2))
print_vec(mult(vec1, vec2))
print_vec(rot(vec1, k, n))
print_vec(rot(vec2, k, n))
