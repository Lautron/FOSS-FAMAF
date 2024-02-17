#a2 = [
#        {'enero': [ # 1980
#            {'Temp': 15, 'Prec': 20} # 1
#            # ...
#            {'Temp': 30, 'Prec': 15} # 28
#        ],
#        # ...
#        'diciembre': [ 
#            {'Temp': 15, 'Prec': 20} # 1
#            # ...
#            {'Temp': 30, 'Prec': 15} # 28
#        ]}
#        # ...
#        {'enero': "..."} #2016
#]

def matrixMult(A: list[list[int]], B: list[list[int]]):
  C = [[None for _ in range(len(B))] for _ in range(len(A))]
  for i,_ in enumerate(A):
    for j,_ in enumerate(B):
      suma = 0
      for k,_ in enumerate(B):
        suma = suma + A[i][k] * B[k][j]
      C[i][j] = suma
  for i in C: print(i)

def main():
  A = [
    [1, 2],
    [3, 4]
  ]

  B = [
    [5, 6],
    [7, 8]
]
  matrixMult(A,B)

if __name__ == "__main__":
    main()

