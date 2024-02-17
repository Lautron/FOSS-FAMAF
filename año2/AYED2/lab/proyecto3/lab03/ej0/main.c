#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length)
{
  printf("\"");
  for (unsigned int j = 0u; j < length; j++) {
    printf("%c", a[j]);
  }
  printf("\"");
  printf("\n\n");
}

unsigned int data_from_file(const char* path,
    unsigned int indexes[],
    char letters[],
    unsigned int max_size)
{
  FILE* file = fopen(path, "r");
  unsigned int elems;
  unsigned int i = 0;
  while (!feof(file)) {
    fscanf(file, "%u \'%c\'\n", &indexes[i], &letters[i]);
    // printf("%u\n%c\n", indexes[i], letters[i]);
    i++;
  }
  fclose(file);
  elems = i + 1 < max_size ? i + 1 : max_size;
  return elems;
}

static void parse_letters(unsigned int indexes[], char letters[], char sorted[], unsigned int length)
{
  for (unsigned int i = 0u; i < length - 1; ++i) {
    sorted[indexes[i]] = letters[i];
    // printf("index: %u\nletter:%c\n\n", indexes[i], letters[i]);
  }
}

int main(int argc, char* argv[])
{
  // FILE *file;
  if (argc > 2) {
    printf("Invalid arguments\n");
  }
  unsigned int indexes[MAX_SIZE];
  char letters[MAX_SIZE];
  char sorted[MAX_SIZE];
  unsigned int length = data_from_file(argv[1], indexes, letters, MAX_SIZE);
  //  .----------^
  //  :
  // Debe guardarse aqui la cantidad de elementos leidos del archivo

  /* -- completar -- */
  parse_letters(indexes, letters, sorted, length);

  dump(sorted, length);

  return EXIT_SUCCESS;
}
