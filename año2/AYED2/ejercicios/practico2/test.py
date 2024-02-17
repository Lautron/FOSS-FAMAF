def ej2(i, n):
    j = 0
    print(i)
    while j < 2**(n-i):
        print(f"merge(a, {j * 2**i + 1}, {(j+1) * 2**i}, {(j+2) * 2**i})")
        j = j+2
    print()

if __name__ == "__main__":
    n = 4
    for i in range(0, n): ej2(i, n)
