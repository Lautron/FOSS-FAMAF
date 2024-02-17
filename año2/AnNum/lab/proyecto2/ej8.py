import ej3, math, graph


def main():
    func = lambda x: math.tan(x)/x**2
    dfunc = lambda x: (x * (1 / math.cos(x))**2 - 2 * math.tan(x))/ x**3
    ddfunc = lambda x: (2*(x**2 * (1/math.cos(x))**2 * math.tan(x) - 2 * x * (1/math.cos(x))**2 + 3 * math.tan(x)))/x**4
    fun = ej3.make_func(dfunc, ddfunc)
    x0 = 1
    res = ej3.rnewton(fun, x0, 1e-5, 100)
    __import__('pprint').pprint(res)
    #I = [-1, math.pi/2, 500]
    I = [0, 1.57, 500]
    #graph.graph_func(func, I, "f(x)")
    graph.graph_func(dfunc, I, "df(x)")
    graph.scatter(res, 'newton')
    graph.show()


if __name__ == "__main__":
    main()
