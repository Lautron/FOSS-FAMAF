/*
  @file main.c
  @brief Main program function implementation
*/
/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


/* Then, this project's includes, alphabetically ordered */
#include "helpers.h"
#include "sort.h"
#include "movie.h"

#define MAX_MOVIES 50u

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
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
char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

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
int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array of MAX_SIZE elements */
    movie_t movielist[MAX_MOVIES];


    /* parse the file to load de players */
    unsigned int length = process_file(filepath, movielist, MAX_MOVIES);

    /* show the movielist in the screen */
    movielist_dump(movielist, length);

    /* check if it is sorted */
    if (array_is_sorted(movielist, length)) {
        printf("Movielist is sorted\n");
    } else {
        printf("Movielist is scrambled\n");
    }

    return (EXIT_SUCCESS);
}

