#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  stack s = stack_empty();

  int e = 57;
  s = stack_push(s, e);
  printf("Stack length: %u\n", stack_size(s));
  stack n = stack_pop(s);
  printf("Stack length: %u\n", stack_size(n));
  // stack_pop funciona en listas de 1 elemento

  n = stack_push(n, e);
  printf("Stack n is empty? %s\n", stack_is_empty(n) ? "Yes" : "No");
  printf("Stack length: %u\n", stack_size(n));
  // se puede volver a agregar elementos si la lista queda vacia

  e = 99;
  s = stack_push(s, e);
  e = 14;
  s = stack_push(s, e);
  e = 27;
  s = stack_push(s, e);

  stack_elem* array = stack_to_array(s);
  printf("[");
  for (unsigned int i = 0; i < stack_size(s) - 1; i++) {
    printf("%d, ", array[i]);
  }
  printf("%d]\n", array[stack_size(s) - 1]);
  // expected output: [57,99,14,27]

  stack s2 = stack_empty();
  stack_elem* arr = stack_to_array(s2);
  printf("Array arr is empty? %s\n", (arr == NULL) ? "Yes" : "No");
  // stack_to_array no devuelve NULL cuando lo hacemos sobre un stack vacío

  return EXIT_SUCCESS;
}
