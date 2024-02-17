#include <assert.h>
#include <stdio.h>

int pedirEntero(char* nombre)
{
  int x;
  printf("Ingrese un entero\n%s = ", nombre);
  scanf("%d", &x);
  return x;
}

void imprimeEntero(char* nombre, int x)
{
  printf("\n%s --> %d", nombre, x);
}

int main(void)
{
  int X = pedirEntero("X");
  int Y = pedirEntero("Y");
  int Z = pedirEntero("Z");
  int x, y;
  assert((Y != 0) && ((X - Y) != 0));
  x = (Z + Y + X) / Y;
  y = Z % (X % Y);
  assert(x == ((Z + Y + X) / Y) && y == (Z % (X % Y)));
  imprimeEntero("x", x);
  imprimeEntero("y", y);
  imprimeEntero("z", Z);
  return 0;
}
