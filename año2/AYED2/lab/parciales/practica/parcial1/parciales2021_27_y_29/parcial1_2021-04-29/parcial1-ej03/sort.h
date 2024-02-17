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
 * @brief    Returns the position until array 'movielist' is sorted according to
 *           the goes_before() function
 *
 * @param[in]  movielist  The Song array
 * @param[in]  size       Length of movie array
 *
 * @return m  where m is the position until array is sorted according to
 *            goes_before() function.
 *
 */
unsigned int array_sorted_until(movie_t movielist[], unsigned int size);


#endif
