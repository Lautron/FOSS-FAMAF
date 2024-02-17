#include "array_helpers.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Recordar remover librearias innecesarias

unsigned int array_from_file(int array[], unsigned int max_size, const char* filepath)
{
  // your code here!!!
  FILE* file = fopen(filepath, "r");
  unsigned int elems;
  fscanf(file, "%u", &elems);
  elems = elems < max_size ? elems : max_size;
  for (unsigned int i = 0; i < elems; ++i) {
    fscanf(file, "%d", &array[i]);
  }
  fclose(file);
  return elems;
}

void array_dump(int a[], unsigned int length)
{
  // your code here!!!!!
  unsigned int i = 0;
  while (i < length) {
    printf("%d ", a[i]);
    i++;
  }
  printf("\n");
}

bool array_is_sorted(int a[], unsigned int length)
{
  bool res = true;
  for (unsigned int i = 0; i < (length - 1); ++i) {
    res = res && (a[i] < a[i + 1]);
  }
  return res;
}
