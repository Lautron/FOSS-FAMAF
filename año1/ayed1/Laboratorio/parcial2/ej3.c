#include <stdio.h>
#define N 5

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

int suma_resta(int array[], int tam, int elem)
{
  int i = 0;
  int res = 0;
  while (i < tam) {
    if (i <= elem) {
      res += array[i];
    } else {
      res -= array[i];
    }
    i++;
  }
  return res;
}

int main(void)
{
  int array[N];
  pedirArreglo(array, N);
  printf("Ingrese la posicion de algun elemento del arreglo\n");
  int elemento = pedirEntero("elemento");
  int res = suma_resta(array, N, elemento);
  imprimeEntero("res", res);
  return 0;
}
