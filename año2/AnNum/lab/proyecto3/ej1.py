#####################
##### Corregir ######
#####################
def l(i, z, xs):
    n = len(xs)
    res = 1.0
    for j in range(n):
        if j != i:
            res *= (z - xs[j])/(xs[i] - xs[j])
    return res

def ilagrange(xs, ys, zs):
    assert len(xs) == len(ys)
    result = []
    n = len(xs)
    for zi in zs:
        res = 0.0
        for i, yi in enumerate(ys):
            l_i = l(i, zi, xs)
            res += yi * l_i
        result.append(res)

    return result
    
def main():
    f = lambda x: 1/x
    xy = [(x, f(x)) for x in [2, 2.5, 4]]
    x, y = zip(*xy)
    zx = [3, 5, 6]
    w = ilagrange(x, y, zx)
    print(w)


if __name__ == "__main__":
    main()
