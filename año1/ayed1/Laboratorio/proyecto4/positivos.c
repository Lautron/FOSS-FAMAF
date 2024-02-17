#include <assert.h>
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

void pedirArreglo(int a[], int n_max)
{
  printf("Ingrese %d argumentos (separando con espacios)\n", n_max);
  int i = 0;
  while (i < n_max) {
    scanf("%d", &a[i]);
    i++;
  }
}

void imprimeArreglo(int a[], int n_max)
{
  int i = 0;
  while (i < n_max) {
    printf("%d ", a[i]);
    i++;
  }
  printf("\n");
}

int tomarInput()
{
  int res;
  printf("Elija la funcion a ejecutar:\n(1) existe_positivo()\n(2) todos_positivos()\n");
  scanf("%d", &res);
  assert(res == 1 || res == 2);
  return res;
}

bool existe_positivo(int a[], int tam)
{
  int i = 0;
  while (i < tam) {
    if (a[i] > 0) {
      return true;
    }
    i++;
  }
  return false;
}

bool todos_positivos(int a[], int tam)
{
  int i = 0;
  while (i < tam) {
    if (a[i] < 0) {
      return false;
    }
    i++;
  }
  return true;
}
int main(void)
{
  int resultado;
  int tamArr = pedirEntero("tamArr");
  int a[tamArr];
  pedirArreglo(a, tamArr);
  int funcionElegida = tomarInput();
  if (funcionElegida == 1) {
    resultado = existe_positivo(a, tamArr);
  } else {
    resultado = todos_positivos(a, tamArr);
  }
  imprimeEntero("resultado", resultado);

  return 0;
}
