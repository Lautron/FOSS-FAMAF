def test1(n):
    t = 0
    for i in range(1, n+1):
        for j in range(1, n**2 +1):
            for k in range(1, n**3 +1):
                t = t+1
    return t

def test2(n):
    t = 0
    for i in range(1, n+1):
        for j in range(1, i+1):
            for k in range(j, j+3 +1):
                t = t+1
    return t

if __name__ == "__main__":
    #print(test1(2) + 1)
    print(test2(2) + 1)
