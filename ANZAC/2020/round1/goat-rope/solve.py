from math import sqrt

def x(p):
    return p.real
def y(p):
    return p.imag

def dist(p1, p2):
    return sqrt((x(p2)-x(p1))**2+(y(p2)-y(p1))**2)

X,Y,x1,y1,x2,y2 = map(int, input().split())

fence = X + Y*1j
p1 = x1 + y1*1j
p2 = x2 + y1*1j
p3 = x2 + y2*1j
p4 = x1 + y2*1j
corners = [p1,p2,p3,p4]

l = 0
if (all(x(fence) > x(p) for p in corners) and (all(y(fence) < y(p) for p in corners) or all(y(fence) > y(p) for p in corners))) or (all(x(fence) < x(p) for p in corners) and (all(y(fence) < y(p) for p in corners) or all(y(fence) > y(p) for p in corners))):
    l = min(dist(fence, p) for p in corners) 
else:
    if all(x(fence) < x(p) for p in corners) or all(x(fence) > x(p) for p in corners):
        l = min(abs(x(p) - x(fence)) for p in corners)
    else:
        l = min(abs(y(p) - y(fence)) for p in corners)
print(f'%.3f'%l)
