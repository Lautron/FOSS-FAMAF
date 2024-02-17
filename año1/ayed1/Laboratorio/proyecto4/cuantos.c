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
  int menores;
  int iguales;
  int mayores;
} comp_t;

comp_t cuantos(int a[], int tam, int elem)
{
  comp_t res;
  res.menores = 0;
  res.mayores = 0;
  res.iguales = 0;
  int i = 0;
  while (i < tam) {
    if (a[i] < elem) {
      res.menores++;
    } else if (a[i] > elem) {
      res.mayores++;
    } else {
      res.iguales++;
    }
    i++;
  }
  return res;
}

int main(void)
{
  int tamArr = pedirEntero("tamArr");
  int a[tamArr];
  pedirArreglo(a, tamArr);
  printf("Elija un elemento para compararlo con el contenido del arreglo\n");
  int elem = pedirEntero("elem");
  comp_t res = cuantos(a, tamArr, elem);
  imprimeEntero("res.menores", res.menores);
  imprimeEntero("res.mayores", res.mayores);
  imprimeEntero("res.iguales", res.iguales);
  return 0;
}
