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

typedef struct {
  int fahrenheit;
  int kelvin;
} temperatura_t;

temperatura_t conversor(int x)
{
  temperatura_t res;
  res.fahrenheit = (x * 9 / 5) + 32;
  res.kelvin = x + 273.15;
  return res;
}

int main(void)
{
  int celsius = pedirEntero("celsius");
  temperatura_t res = conversor(celsius);
  imprimeEntero("res.fahrenheit", res.fahrenheit);
  imprimeEntero("res.kelvin", res.kelvin);
  return 0;
}
