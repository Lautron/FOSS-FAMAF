/*
  @file sort.h
  @brief Sort functions declarations
*/
#ifndef _SORT_H
#define _SORT_H
#include <stdbool.h>
#include "movie.h"

/**
 * @brief Returns true if movie 's1' goes before movie 's2'.
 *
 * @param[in]  s1 Song 's1'
 * @param[in]  s2 Song 's2'
 *
 * @return true if movie 's1' goes before movie 's2' in a sorted array of movies.
 */
bool goes_before(movie_t s1, movie_t s2);

/**
 * @brief    Checks if the array 'movielist' is in ascending order according
 *           to the goes_before() function
 *
 * @param[in]  movielist  The Movie array
 * @param[in]  length     Length of movie array
 *
 * @return True if array is sorted in ascendirng order according to goes_before() function, false otherwise
 */
bool array_is_sorted(movie_t movielist[], unsigned int size);


#endif
