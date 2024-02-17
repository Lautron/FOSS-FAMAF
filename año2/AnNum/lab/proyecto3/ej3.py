from ej2 import inewton
import graph

def main():
  f = lambda x: 1/x
  xs = list(range(1, 6))
  ys = [f(i) for i in xs]
  zs = [24/25 + j/25 for j in range(1, 102)]
  res = inewton(xs, ys, zs)
  print()
  print(res)
  graph.basic(zs, [f(i) for i in zs], 'f(x)')
  graph.basic(zs, res, 'p(x)')
  #graph.show()
  

if __name__ == '__main__':
  main()
