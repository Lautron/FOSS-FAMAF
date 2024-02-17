from math import isinf
def overflow():
    i = 0
    a = 0
    while True:
        try: isinf(2**i)
        except OverflowError: 
            print(i-1)
            break
        i += 1
    
def underflow():
    a = 1
    i = 0
    while True:
        if a/2 == 0.0:
            print(a)
            break
        a = a/2
        i += 1

def main():
    overflow()
    underflow()
if __name__ == "__main__":
    main()



