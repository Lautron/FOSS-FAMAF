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
  int x = pedirEntero("x");
  int y = pedirEntero("y");
  int z;
  z = x;
  x = x + 1;
  y = z + y;
  imprimeEntero("x", x);
  imprimeEntero("y", y);
  return 0;
}
