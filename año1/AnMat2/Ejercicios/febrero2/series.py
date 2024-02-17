from typing import Callable
from collections.abc import Sequence


def sigma(sucesion: Callable[[float, int], float], iteraciones: int = 1000):
    return lambda x: sum([sucesion(x, n) for n in range(iteraciones)])


def test_series(
    series: Callable[[float], float],
    original: Callable[[float], float],
    rango: Sequence[float | int],
):
    res = [(original(x), series(x)) for x in rango]
    print("[(original, serie)]")
    print(res)
    return res


def test1():
    sucesion = lambda x, n: n / 5 ** (n + 1) * x ** (n - 1)
    serie = sigma(sucesion, 500)
    test_series(serie, lambda x: 1 / (x - 5) ** 2, range(1, 5))


def test2():
    sucesion = lambda x, n: -1 / 2 ** (n + 1) * (x - 2) ** n
    serie = sigma(sucesion, 1000)
    test_series(serie, lambda x: 1 / x, range(1, 4))


def test3():
    sucesion = lambda x, n: ((-1) ** n / 2 ** (n + 1)) * (x - 2) ** n
    serie = sigma(sucesion, 1000)
    test_series(serie, lambda x: 1 / x, range(1, 4))


if __name__ == "__main__":
    test3()
