import math
from functools import reduce

def a():
    res = 1
    for i in range(1, 7):
        res *= i
    print(res)

def b(n):
    print(math.factorial(n))

def c(n):
    res = 1
    for i in range(1, n+1):
        res *= i
    print(res)

fact = lambda n: reduce(lambda x,y: x*y, range(1, n+1))

if __name__ == "__main__":
    a()
    b(6)
    c(6)
    print(fact(6))


