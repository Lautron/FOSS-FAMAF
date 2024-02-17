/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"

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
  bool valid_args_count = (argc == 2);

  if (!valid_args_count) {
    print_help(argv[0]);
    exit(EXIT_FAILURE);
  }

  result = argv[1];

  return result;
}

int main(int argc, char* argv[])
{
  char* filepath = NULL;

  /* parse the filepath given in command line arguments */
  filepath = parse_filepath(argc, argv);

  size_t length = 0;
  // parse the file and returns the array storing the actual size in <length>
  int* array = array_from_file(filepath, &length);

  /*dumping the array*/
  array_dump(array, length);

  //
  // COMPLETAR: Liberar la memoria usada por <array>
  //
  free(array);

  return EXIT_SUCCESS;
}
