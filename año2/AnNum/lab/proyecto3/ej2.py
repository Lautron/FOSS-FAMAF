from functools import reduce 
from ej1 import ilagrange
import graph

def dif_div(xs, ys):
    n = len(xs)
    c = [ [y] + [0]*n for y in ys]
    for j in range(1, n+1):
        for i in range(n-j):
            c[i][j] = (c[i+1][j-1] - c[i][j-1])/(xs[i+j] - xs[i])
            #print(f"c[{i}][{j}] = (c[{i+1}][{j-1}] - c[{i}][{j-1}])/(xs[{i+j}] - x[{i}]")
    
    __import__('pprint').pprint(c)
    return c

def inewton(xs: list[float] | list[int], ys: list[float] | list[int], zs: list[float] | list[int]) -> list[float] | list[int]:
    """Funcion que devuelve una lista con el polinomio interpolante de newton evaluado en cada zs

    :xs: lista de puntos x
    :ys: lista de puntos y
    :zs: lista de puntos a evaluar
    :returns: lista de puntos zs evaluados en el polinomio interpolante de newton
    """
    assert len(xs) == len(ys)
    result = []
    res = 0.0
    n = len(xs)
    difs = dif_div(xs, ys)
    coefs = [dif for dif in difs[0] if dif]
    result = [horn(zj,xs,coefs) for zj in zs]
    return result

def horn(x, xs, coefs):
    res = coefs[-1]
    for coef, xi in zip(coefs[1::-1], xs[1::-1]):
        res =  coef + res*(x - xi)
    return res

def newt_func(xs, ys):
    difs = dif_div(xs, ys)
    coefs = [dif for dif in difs[0] if dif]
    return lambda x: horn(x,xs,coefs)
    

def main():
    f = lambda x: 1/x
    xy = [(x, f(x)) for x in [2, 2.5, 4]]
    x, y = zip(*xy)
    I = [0,5]
    zx = [3, 5, 6]
    #zy = inewton(x, y, zx)
    print("inewton:", inewton(x, y, zx))
    print("ilagrange:", ilagrange(x, y, zx))
    func = newt_func(x, y)
    graph.graph_func(f, I, '1/x')
    graph.graph_func(func, I, 'p2(x)')
    graph.stetic()
    #graph.show()

if __name__ == "__main__":
    main()
