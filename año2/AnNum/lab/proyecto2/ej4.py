import math, graph
from ej3 import rnewton

sign = lambda x: (x>=0) - (x<0)

make_func = lambda f, g: lambda: (f, g)

#def make_fun(f,g):
#    def fun():
#        return (f,g)
#    return fun

def cube_root(a):
    fun = make_func(lambda x: x**3 - a, lambda x: 3 * x**2)
    x0 = a
    err = 1e-6
    mit = 100
    res = rnewton(fun, x0, err, mit)
    __import__('pprint').pprint(res)
    graph.scatter(res, "cube_root")
    graph.graph_func(fun()[0], [-a, a, 500], f"x³ - {a}")
    graph.show()

if __name__ == "__main__":
    #a()
    #b()
    cube_root(8)
