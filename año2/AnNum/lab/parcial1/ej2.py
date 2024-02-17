import ej1, graph

def get_float_range(start: int, stop: float) -> list[float]:
    """funcion auxiliar para obtener un rango de floats equidistantes

    :start: start of range
    :stop: stop of range
    :returns: lista de puntos equidistantes con una distancia de 0.01 (1/100)
    """
    return [i * 1/100 for i in range(start, int(stop*100)+1)]

def get_points() -> tuple[list, list]:
    """funcion auxiliar para obtener puntos xs y ys
    :returns: tupla que continene las listas de puntos xs e ys
    """
    I = [0, 6.4]
    xs = get_float_range(I[0], I[1])
    ys = [ ej1.f(x) for x in xs ]
    return xs, ys

def main():
    xs, ys = get_points()
    graph.graph(xs, ys, 'f(x)')
    graph.show()

if __name__ == "__main__":
    main()
