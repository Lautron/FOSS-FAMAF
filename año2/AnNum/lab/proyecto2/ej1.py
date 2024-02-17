import math
import graph
sign = lambda x: (x>=0) - (x<0)


def rbisec(fun, I, err, mit):
    hx = []
    hf = []
    a, b = I
    u, v = fun(a), fun(b)
    if sign(u) == sign(v): 
        return (hx, hf)
    for k in range(mit):
        c = a + (b-a)/2
        #print(f"c = {a} + ({b}-({a}))/2 = {c}")
        w = fun(c)
        hx.append(c)
        hf.append(w)
        if abs(w) < err: 
            return (hx, hf)
        if sign(w) != sign(u):
            b = c
            v = w
        else:
            a = c
            u = w
    return (hx, hf)

def func(x):
    if x<0:
        return math.sqrt(-x)
    elif 0 <= x <= 3:
        return -x*(x-1)*(x-2)
    elif x > 3:
        return 1

if __name__ == "__main__":
    err = 10**-5
    mit = 10
    I = [-1/2, 3]
    data = rbisec(func, I, err, mit)
    graph.scatter(data, "bisec")
    graph.graph_func(func, [-1/2, 2.5], "f(x)")
    graph.show()
