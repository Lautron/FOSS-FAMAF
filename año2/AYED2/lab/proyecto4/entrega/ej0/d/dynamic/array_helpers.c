#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void array_dump(int a[], size_t length)
{
  fprintf(stdout, "length: %lu\n", length);
  fprintf(stdout, "[ ");
  for (size_t i = 0u; i < length; ++i) {
    fprintf(stdout, "%i", a[i]);
    if (i < length - 1) {
      fprintf(stdout, ", ");
    }
  }
  fprintf(stdout, "]\n");
}

int* array_from_file(const char* filepath, size_t* length)
{
  FILE* file = NULL;
  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }
  unsigned int i = 0u;
  unsigned int size = 0u;
  int res = 0;
  res = fscanf(file, " %u ", &size);
  if (res != 1) {
    fprintf(stderr, "Invalid array.\n");
    exit(EXIT_FAILURE);
  }
  int* array = NULL;
  //
  // COMPLETAR: - Reservar memoria para array
  //            - Cambiar el valor de *length para que contenga el tamaño del
  //              arreglo.
  //
  array = malloc(size * sizeof(int));
  *length = size;
  if (size > 0 && array == NULL) {
    fprintf(stderr, "Not enough memory\n");
    exit(EXIT_FAILURE);
  }
  while (i < size) {
    res = fscanf(file, " %d ", &(array[i]));
    if (res != 1) {
      fprintf(stderr, "Invalid array.\n");
      exit(EXIT_FAILURE);
    }
    ++i;
  }
  fclose(file);
  return array;
}
