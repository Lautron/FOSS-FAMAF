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

typedef struct {
  int cociente;
  int resto;
} div_t;

div_t division(int x, int y)
{
  div_t res;
  res.cociente = x / y;
  res.resto = x % y;
  return res;
}

int main(void)
{
  int x = pedirEntero("x");
  int y = pedirEntero("y");
  if (y == 0) {
    printf("Error: Division por 0");
  } else {
    div_t res = division(x, y);
    imprimeEntero("res.cociente", res.cociente);
    imprimeEntero("res.resto", res.resto);
  }
  return 0;
}
