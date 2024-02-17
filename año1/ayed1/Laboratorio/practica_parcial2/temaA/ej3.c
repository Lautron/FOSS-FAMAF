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

typedef struct {
  int inferior;
  int superior;
} sum_t;

sum_t suma_acotada(int cota, int array[], int tam)
{
  sum_t res;
  res.inferior = 0;
  res.superior = 0;
  int i = 0;
  while (i < tam) {
    if (array[i] < cota) {
      res.inferior += array[i];
    } else if (array[i] >= cota) {
      res.superior += array[i];
    }
    i++;
  }
  return res;
}

int main(void)
{
  int cota = pedirEntero("cota");
  int tamArray = pedirEntero("tamArray");
  int array[tamArray];
  pedirArreglo(array, tamArray);

  sum_t res = suma_acotada(cota, array, tamArray);
  imprimeEntero("res.inferior", res.inferior);
  imprimeEntero("res.superior", res.superior);
  return 0;
}
