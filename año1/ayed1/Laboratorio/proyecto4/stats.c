#include <math.h>
#include <stdio.h>

int pedirEntero(char nombre[])
{
  int x;
  printf("Ingrese un valor\n%s = ", nombre);
  scanf("%d", &x);
  return x;
}

void imprimeFloat(char* nombre, float x)
{
  printf("\n%s --> %f", nombre, x);
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
  float maximo;
  float minimo;
  float promedio;
} datos_t;

datos_t stats(int a[], int tam)
{
  datos_t res;
  res.maximo = -INFINITY;
  res.minimo = INFINITY;
  int sum = 0;
  int i = 0;
  while (i < tam) {
    if (a[i] < res.minimo) {
      res.minimo = a[i];
    }
    if (a[i] > res.maximo) {
      res.maximo = a[i];
    }
    sum += a[i];
    i++;
  }
  res.promedio = sum / tam;
  return res;
}

int main(void)
{
  int tamArr = pedirEntero("tamArr");
  int a[tamArr];
  pedirArreglo(a, tamArr);
  datos_t res = stats(a, tamArr);
  imprimeFloat("maximo", res.maximo);
  imprimeFloat("minimo", res.minimo);
  imprimeFloat("promedio", res.promedio);

  return 0;
}
