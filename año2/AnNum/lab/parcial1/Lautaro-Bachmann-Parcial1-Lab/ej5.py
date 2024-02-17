import ej1, ej2, ej4, graph

def main():
    err = 1e-5
    mit = 100
    h1, h2, h3 = [ej4.rsteffensen(ej1.f, x0, err, mit) for x0 in [3, 6, 4.5]]
    graph.scatter(*h1, 'x0=3', color='darkgreen')
    graph.scatter(*h2, 'x0=6', color='purple')
    graph.graph(*ej2.get_points(), 'f(x)')
    graph.show()
    graph.scatter(*h3, 'x0=4.5', color='magenta')
    graph.graph(*ej2.get_points(), 'f(x)')
    graph.show()


if __name__ == '__main__':
  main()

##################
### Respuestas ###
##################

# Las iteraciones que require cada busqueda son las siguientes:
# 
# * Iteraciones para x0=3: 1
# * Iteraciones para x0=6: 69
# * Iteraciones para x0=4.5: 3
# 
# Cuando se inicia la busqueda en 4.5, el metodo de Steffensen realiza 3 iteraciones y luego se detiene ya que se cumple que (abs(x1-x0) / abs(x1)) < err, sin embargo, no da como resultado ninguna raiz de la funcion


