import random 
sonReciprocos = lambda x, y: True if x*y == 1 else False

if __name__ == "__main__":
    for _ in range(100):
        x = 1 + random.random()
        y = 1/x
        if not sonReciprocos(x,y):
            print(x)
