#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 7

static void
print_array(int a[], size_t length)
{
  assert(length > 0);
  printf("[ %d", a[0]);
  for (size_t i = 1; i < length; i++) {
    printf(", %d", a[i]);
  }
  printf("]\n");
}

int main(void)
{
  int array[ARRAY_SIZE] = { 7, 4, 1, 3, 9, 3, 5 };
  int* p = NULL;
  printf("before: ");
  print_array(array, ARRAY_SIZE);
  /* --------------------- Modificar ---------------------- */
  p = array;
  for (unsigned int i = 0u; i < ARRAY_SIZE; i++) {
    p[i] = 0;
  }
  /* ------------------------------------------------------ */
  printf("after : ");
  print_array(array, ARRAY_SIZE);

  return EXIT_SUCCESS;
}
