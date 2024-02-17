def horn(coefs, x):
    res = coefs[0]
    for coef in coefs[1:]:
        #print(f"{res}*{x} + {coef}")
        res = res*x + coef
    return res

if __name__ == "__main__":
    print(horn([1, 2, 3, 4], 2))
