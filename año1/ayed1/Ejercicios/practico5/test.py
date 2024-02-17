def test(N):
   i, r = 1, 1
   while i <= N:
       r = r*i
       i = i + 1
   print("\n",r)

def test1(N):
   i, r = 1, 1
   while i <= N:
       i = i + 1
       r = r*i
   print("\n",r)

def test2(N,M):
   i, p, m = N, 0, 0
   while i < M:
       if i % 2 == 0:
           p = p + i
       if i % 3 == 0:
           m = m + i
       i = i + 1
   print(p,m)

if __name__ == "__main__":
    test1(3)
