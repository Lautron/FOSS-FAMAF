import math
import matplotlib.pyplot as plt
import numpy as np

sign = lambda x: (x>=0) - (x<0)

def rnewton(fun, x0, err, mit):
    f, df = fun() 
    v = f(x0)
    hx, hf = [x0], [v]
    if abs(v) < err: return hx, hf
    for k in range(1, mit):
       x1 = x0 - v/df(x0)
       v = f(x1)
       hx.append(x1)
       hf.append(v)
       if abs(v) < err: break
       if (abs(x1-x0) / abs(x1)) < err: break
       x0 = x1
    return hx, hf

make_func = lambda f, g: lambda: (f, g)

def b():
    # 2x = tan(x) => tan(x) - 2x = 0
    func_list = [
        [ lambda x: x**2, lambda x: 2*x],
    ]
    funcs = [make_func(f, g) for f, g in func_list] 
    err = 1e-5
    mit = 100
    x0 = 0
    hx, hf = rnewton(funcs[0], 1, err, mit)
    xs = np.linspace(-2, 2, 100)
    ys = [funcs[0]()[0](x) for x in xs]
    plt.plot(xs, ys, label='func')
    plt.scatter(hx[:-1], hf[:-1], label='rnewton')
    plt.scatter(hx[-1], hf[-1], label='last')
    plt.legend()
    plt.grid()
    plt.show()
    print(f"{hx}\n{hf}")

if __name__ == "__main__":
    #a()
    b()
