#include "stack.h"
#include <stdio.h>

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
  stack s = stack_empty();
  s = stack_push(s, 5);
  // Pilas de tamaño 1
  s = stack_pop(s);
  //  Si la pila queda vacia puedo volver a insertar elementos?
  s = stack_push(s, 6);
  //  Stack_to_array devuelve null para una pila vacia?
  s = stack_pop(s);
  stack_elem* res = stack_to_array(s);

  if (res == NULL) {
    printf("Array is null\n");
  }
  return 0;
}
