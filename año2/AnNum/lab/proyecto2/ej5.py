from ej4 import graph

def ripf(fun, x0, err, mit):
    p0 = x0
    g = fun
    hx, hf = [], []
    for i in range(1, mit):
        p = g(p0)
        hx.append(p0)
        hf.append(p)
        if abs(p-p0) < err: break
        p0 = p
    return hx, hf

