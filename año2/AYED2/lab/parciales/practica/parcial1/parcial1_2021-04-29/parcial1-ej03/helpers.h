/*
  @file helpers.h
  @brief movie helper functions declaration
*/
#ifndef _HELPERS_H
#define _HELPERS_H
#include <stdbool.h>
#include "movie.h"

/**
 * @brief Loads the contents of the file into the array of movies.
 *
 * @param[in]  filepath  Filepath to movielist file
 * @param[out] movielist  Array of movies
 *
 * @return     The amount of movies read from file
 */
unsigned int process_file(const char *filepath, movie_t movielist[], unsigned int max_size);

/**
 * @brief Prints the contents of the array of movies to standard output.
 *
 * @param[in]      movielist Array of songs
 * @param[in]      length   Array length
 */
void movielist_dump(movie_t movielist[], unsigned int length);

#endif
