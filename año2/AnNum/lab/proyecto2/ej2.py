#!./venv/bin/python
import math
import matplotlib.pyplot as plt
import numpy as np
from ej1 import rbisec

def a():
    # 2x = tan(x) => tan(x) - 2x = 0
    lab2ej2a = lambda x: math.tan(x) - 2*x
    I = [0.8, 1.4]
    err = 1e-5
    mit = 100
    return rbisec(lab2ej2a, I, err, mit)

def b():
    # 2x = tan(x) => tan(x) - 2x = 0
    lab2ej2b = lambda x: x**2 - 3
    I = [1, 2]
    err = 1e-5
    mit = 100
    return rbisec(lab2ej2b, I, err, mit)

def c():
    lab2ej2a = lambda x: math.tan(x) - 2*x
    lab2ej2b = lambda x: x**2 - 3
    nums = np.linspace(0, 2, 200)
    plt.plot(nums, [lab2ej2a(i) for i in nums], label='a: tan(x) - 2x')
    plt.plot(nums, [lab2ej2b(i) for i in nums], label='b: x² - 3')
    plt.scatter(*a(), label='rbisec(a)')
    plt.scatter(*b(), label='rbisec(b)')
    plt.legend()
    plt.grid()
    plt.show()


if __name__ == "__main__":
    #a()
    c()
