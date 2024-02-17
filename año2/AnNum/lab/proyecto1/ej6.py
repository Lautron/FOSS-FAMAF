def reales(a, b):
    if a > b:
        print(a)
    elif b > a:
        print(b)
    else:
        print("Los numeros son iguales")

if __name__ == "__main__":
    reales(float(input()), float(input()))
