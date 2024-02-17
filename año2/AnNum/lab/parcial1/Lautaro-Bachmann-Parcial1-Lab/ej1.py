import math

# Segun la interpretacion que le di al enunciado, no es necesario sumar los terminos si no solo calcularlos
# Por ello cree la funcion f(x) la cual suma los terminos generados por serie_seno(x)

def serie_seno(x) -> list[float]:
    """funcion que devuelve primeros 5 terminos de la serie de seno centrada en 0

    :x: numero para el cual se calcularan los terminos
    :returns: lista de terminos

    """
    get_term = lambda n: (math.pow(-1, n)/math.factorial(2*n + 1) ) * math.pow(x, 2*n + 1) 
    terms = [get_term(n) for n in range(5) ]
    return terms

def f(x) -> float:
    """funcion que calcula la suma de los terminos generados por serie_seno

    :x: numero en el que serán evaluados los terminos de serie_seno
    :returns: suma de los terminos generados por por serie_seno

    """
    return sum(serie_seno(x))
    

if __name__ == "__main__":
    print(serie_seno(1))
    print(f(1))
