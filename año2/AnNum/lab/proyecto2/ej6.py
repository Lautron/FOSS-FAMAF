from ej5 import ripf
import graph

def main():
    fun = lambda: lambda x: 2**(x-1)
    x0 = 1.5
    hx, hf = ripf(fun, x0, 1e-5, 100)
    #test =[hx, [0 for y in hx]]
    print(hf)
    graph.scatter([hx, hf], "ripf()") 
    I = [0, 2.5, 500]
    graph.graph_func(fun(), I, "2**(x-1)", color="magenta")
    graph.graph_func(lambda x: 2*x, I, "2*x")
    graph.graph_func(lambda x: 2**x, I, "2**x")
    graph.show()

if __name__ == "__main__":
    main()
