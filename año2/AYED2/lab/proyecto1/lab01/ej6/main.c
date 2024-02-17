/* First, the standard lib includes, alphabetically ordered */
#include "array_helpers.h"
#include "mybool.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

void print_help(char* program_name)
{
  /* Print the usage help of this program. */
  printf("Usage: %s <input file path>\n\n"
      "Loads an array given in a file in disk and prints it on the screen."
      "\n\n"
      "The input file must have the following format:\n"
      " * The first line must contain only a positive integer,"
      " which is the length of the array.\n"
      " * The second line must contain the members of the array"
      " separated by one or more spaces. Each member must be an integer."
      "\n\n"
      "In other words, the file format is:\n"
      "<amount of array elements>\n"
      "<array elem 1> <array elem 2> ... <array elem N>\n\n",
      program_name);
}

char* parse_filepath(int argc, char* argv[])
{
  /* Parse the filepath given by command line argument. */
  char* result = NULL;
  // Program takes exactly two arguments
  // (the program's name itself and the input-filepath)
  mybool valid_args_count = (argc == 2);

  if (!valid_args_count) {
    print_help(argv[0]);
    exit(EXIT_FAILURE);
  }

  result = argv[1];

  return result;
}

void imprimeEntero(char* nombre, int x)
{
  printf("\n%s --> %d", nombre, x);
}

void invertir_array(int a[], unsigned int length)
{
  for (unsigned int i = 0; i < length / 2; ++i) {
    //printf("%d\n", length / 2);
    array_swap(a, i, length - 1 - i);
  }
}

int main(int argc, char* argv[])
{
  char* filepath = NULL;

  /* parse the filepath given in command line arguments */
  filepath = parse_filepath(argc, argv);

  /* create an array of MAX_SIZE elements */
  int array[MAX_SIZE];

  /* parse the file to fill the array and obtain the actual length */
  unsigned int length = array_from_file(array, MAX_SIZE, filepath);

  /*dumping the array*/

  invertir_array(array, length);

  array_dump(array, length);

  if (array_is_sorted(array, length)) {
    printf("El array está ordenado\n");
  } else {
    printf("El array está desordenado\n");
  }

  return EXIT_SUCCESS;
}
