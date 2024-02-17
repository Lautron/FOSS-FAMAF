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

void intercambiar(int a[], int tam, int i, int j)
{
  assert(i > 0 && i < tam && j > 0 && j < tam);
  int z = a[i];
  a[i] = a[j];
  a[j] = z;
}
int main(void)
{
  int tamArr = pedirEntero("tamArr");
  int a[tamArr];
  pedirArreglo(a, tamArr);
  printf("Ingrese las posiciones a intercambiar:\n");
  int i = pedirEntero("i");
  int j = pedirEntero("j");
  intercambiar(a, tamArr, i, j);
  imprimeArreglo(a, tamArr);

  return 0;
}
