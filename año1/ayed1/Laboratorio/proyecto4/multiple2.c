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
  int X = pedirEntero("X");
  int Y = pedirEntero("Y");
  int Z = pedirEntero("Z");
  int x, y, z;
  x = Y;
  y = Y + X + Z;
  z = Y + X;
  imprimeEntero("x", x);
  imprimeEntero("y", y);
  imprimeEntero("z", z);
  return 0;
}
