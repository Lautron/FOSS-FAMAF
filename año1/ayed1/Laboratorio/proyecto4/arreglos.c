#include <stdio.h>

int pedirEntero(char* nombre)
{
  int x;
  printf("Ingrese un valor\n%s = ", nombre);
  scanf("%d", &x);
  return x;
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

int main(void)
{
  int tamArreglo = pedirEntero("tamArreglo");
  int arr[tamArreglo];
  pedirArreglo(arr, tamArreglo);
  imprimeArreglo(arr, tamArreglo);
  return 0;
}
