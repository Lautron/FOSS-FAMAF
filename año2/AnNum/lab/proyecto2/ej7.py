import math, ej1, ej3, ej4, ej5
import graph
import matplotlib.pyplot as plt

def ej7(x):
    func = lambda y: math.exp(-(1-x*y)**2)
    n_func = ej4.make_func(
            func,
            lambda y: 1 - math.exp(-1+2*y*x-y**2 * x**2) * (-2 * x**2 * y + 2*x)
        )
    I = [0, 1.5]
    err = 1e-5
    mit = 100
    x0 = x
    data = [
        (ej1.rbisec(func, I, err, mit), 'rbisec', 'r'),
        (ej3.rnewton(n_func, x0, err, mit), 'rnewton', 'g'),
        (ej5.ripf(func, x0, err, mit), 'ripf', 'b')
    ]
    for res, label, color in data:
        if res[0]:
            graph.scatter(res, label, color=color)
    graph.graph_func(func, [0, x, 500], 'u(x)', color="magenta")

    #__import__('pprint').pprint(data)
    graph.show()
    #graph.save(f'imgs/{x}.png')


def main():
    ej7(3)
    #for num in range(1, 6):
    #    try:
    #        ej7(num)
    #    except Exception as e:
    #        print(e)

if __name__ == "__main__":
    main()
