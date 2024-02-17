def sonOrtogonales(v1, v2):
    res1 = v1[0]* v2[0]
    res2 = v1[1]* v2[1]
    result = res1 + res2
    print(res1, res2)
    if result == 0:
        return True
    return False

if __name__ == "__main__":
    x = [1, 1.1024074512658109]
    y = [-1, 1/x[1]]
    if not sonOrtogonales(x,y):
        print("Algo salio mal...")

