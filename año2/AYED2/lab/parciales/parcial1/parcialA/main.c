/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char* program_name)
{
  /* Print the usage help of this program. */
  printf("Usage: %s <input file path>\n\n"
	 "Load flight data from a given file in disk.\n"
	 "\n"
	 "The input file must exist in disk and every line in it must have the following format:\n\n"
	 "<code> <flight type> <hour> <passengers> <flight type> <hour> <passengers>\n\n"
	 "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
	 "\n\n",
      program_name);
}

/**
 * @brief reads file path from command line
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return An string containing read filepath
 */
char* parse_filepath(int argc, char* argv[])
{
  /* Parse the filepath given by command line argument. */
  char* result = NULL;

  if (argc < 2) {
    print_help(argv[0]);
    exit(EXIT_FAILURE);
  }

  result = argv[1];

  return (result);
}

/**
 * @brief Main program function
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(int argc, char* argv[])
{
  char* filepath = NULL;

  /* parse the filepath given in command line arguments */
  filepath = parse_filepath(argc, argv);

  /* create an array with the type of flight */
  LayoverTable array;

  /* parse the file to fill the array and obtain the actual length */
  array_from_file(array, filepath);

  /* shows the data on the screen */
  array_dump(array);
  unsigned int passengers = passengers_amount_in_airport(array, 10);
  printf("\nAmount of passengers at %u:00 : %u\n", 10, passengers);

  return (EXIT_SUCCESS);
}
