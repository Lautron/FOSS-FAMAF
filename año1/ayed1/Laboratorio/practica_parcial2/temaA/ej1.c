#include <assert.h>
#include <stdio.h>

int pedirEntero(char* nombre)
{
  int x;
  printf("Ingrese un valor\n%s = ", nombre);
  scanf("%d", &x);
  return x;
}

void imprimeEntero(char* nombre, int x)
{
  printf("\n%s --> %d", nombre, x);
}

int main(void)
{
  int X = pedirEntero("x");
  int Y = pedirEntero("y");
  assert(X * Y != 0);
  int x = Y * X;
  int y = X * Y;
  assert(x == X * Y && x == y);
  imprimeEntero("x", x);
  imprimeEntero("y", y);
  return 0;
}
