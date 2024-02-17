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

typedef struct {
  int clave;
  int valor;
} asoc_t;

void pedirArreglo(asoc_t a[], int n_max)
{
  printf("Ingrese %d pares de claves y valores (separando con espacios)\n", n_max);
  int i = 0;
  while (i < n_max) {
    scanf("%d %d", &a[i].clave, &a[i].valor);
    i++;
  }
}

bool hay_asoc(int key, asoc_t a[], int tam)
{
  int i = 0;
  while (i < tam) {
    if (a[i].clave == key) {
      return true;
    }
    i++;
  }
  return false;
}

int main(void)
{
  int tamArray = pedirEntero("tamArray");
  asoc_t array[tamArray];
  pedirArreglo(array, tamArray);
  int clave_a_buscar = pedirEntero("clave_a_buscar");
  bool res = hay_asoc(clave_a_buscar, array, tamArray);
  imprimeEntero("res", res);
  return 0;
}
