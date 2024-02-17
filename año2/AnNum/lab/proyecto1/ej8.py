import math
from random import randint

def mala(a, b, c):
    det = b**2 - 4*a*c
    if det == 0: 
        res1, res2 = [-b/(2*a)]*2
    elif det > 0:
        res1 = (-b + math.sqrt(det))/(2*a)
        res2 = (-b - math.sqrt(det))/(2*a)
    else: 
        print("No hay raices reales")
        res1, res2 = [None]*2

    return res1, res2

def buena(a, b, c):
    det = b**2 - 4*a*c
    if det == 0: 
        res1, res2 = [-b/(2*a)]*2
    elif det > 0:
        res1 = (-b + math.sqrt(det))/(2*a)
        res2 = -res1 - (b/a)
    else: 
        print("No hay raices reales")
        res1, res2 = [None]*2

    return res1, res2


if __name__ == "__main__":
    tests = [
        (randint(-50, 51), randint(-50, 51), randint(-50, 51))
        for _ in range(10)
        ]
    print(tests)
    for a, b, c in tests:
        print(f"a: {a}, b: {b}, c: {c}\n")
        print(*mala(a, b, c))
        print(*buena(a, b, c))
        print('-'*50)


