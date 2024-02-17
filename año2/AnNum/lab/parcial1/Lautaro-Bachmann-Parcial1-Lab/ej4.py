import math

def rsteffensen(fun, x0, err, mit):
    print(f"Iteraciones para x0={x0}:")
    v = fun(x0)
    hx, hf = [x0], [v]
    if abs(v) < err: return hx, hf
    for k in range(mit):
        x1 = x0 - math.pow(fun(x0), 2)/(fun(x0 + fun(x0)) - fun(x0))
        v = fun(x1)
        hx.append(x1)
        hf.append(v)
        if abs(v) < err: 
            print("abs(v) < err")
            break
        if (abs(x1-x0) / abs(x1)) < err: 
            print(f"{abs(x1-x0)} / {abs(x1)} < {err}")
            break
        x0 = x1
    print(k+1, '\n')
    print(hx, hf)
    return hx, hf

