import ej1, ej2, graph

# Funcion que devuelve 1 si el numero es positivo y -1 si el numero es negativo
sign = lambda x: (x>=0) - (x<0)

def rbisec(fun, I, err, mit) -> tuple[list, list]:
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

def main():
    err = 1e-5
    mit = 100
    I1 = [2, 4]
    I2 = [4, 6]
    hx1, hf1 = rbisec(ej1.f, I1, err, mit)
    graph.scatter(hx1, hf1, 'raiz 1', color='purple')
    hx2, hf2 = rbisec(ej1.f, I2, err, mit)
    graph.scatter(hx2, hf2, 'raiz 2', color='g')
    xs, ys = ej2.get_points()
    graph.graph(xs, ys, 'f(x)')
    graph.show()
    
if __name__ == "__main__":
    main()
