#include <math.h>
#include <stdbool.h>
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

bool esPrimo(int n)
{
  int i = 2;
  float raiz = sqrt(n);
  while (i <= raiz) {
    if (n % i == 0) {
      return false;
    }
    i++;
  }

  return true;
}

int nesimo_primo(int N)
{
  int primo = 1;
  int cant_primos = 0;
  while (cant_primos < N) {
    if (esPrimo(primo + 1)) {
      cant_primos++;
    }
    primo++;
  }
  return primo;
}
int main(void)
{
  int n = pedirEntero("n");
  if (n <= 0) {
    printf("ERROR: argumento negativo");
    return 0;
  }
  int res = nesimo_primo(n);
  imprimeEntero("res", res);
  return 0;
}
