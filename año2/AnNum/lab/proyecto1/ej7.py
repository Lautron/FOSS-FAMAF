def pot(x, n):
    r = 1
    for _ in range(n): 
        r *= x
    print(r)

def print_pow(x):
    for i in range(1, 5+1):
        pot(x, i)

if __name__ == "__main__":
    print_pow(3)
