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

int sumatoria(int a[], int tam)
{
  int i = 0;
  int res = 0;
  while (i < tam) {
    res += a[i];
    i++;
  }
  return res;
}

int main(void)
{
  int tamañoArreglo = pedirEntero("tamañoArreglo");
  int a[tamañoArreglo];
  pedirArreglo(a, tamañoArreglo);
  int resultado = sumatoria(a, tamañoArreglo);
  imprimeEntero("resultado", resultado);
  return 0;
}
