/*
  @file main.c
  @brief Main program function implementation
*/
/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Then, this project's includes, alphabetically ordered */
#include "helpers.h"
#include "song.h"
#include "sort.h"

#define MAX_SONGS 100u

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
    song_t playlist[MAX_SONGS];


    /* parse the file to load de players */
    unsigned int length = process_file(filepath, playlist, MAX_SONGS);

    /* show the playlist in the screen */
    playlist_dump(playlist, length);

    if (array_is_sorted(playlist, length)) {
        printf("the playlist is sorted\n");
    } else {
        printf("the playlist is scrambled\n");
    }
    return (EXIT_SUCCESS);
}

