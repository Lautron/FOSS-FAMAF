/*
  @file sort.h
  @brief Sort functions declarations
*/
#ifndef _SORT_H
#define _SORT_H
#include <stdbool.h>
#include "song.h"

/**
 * @brief Returns true if song 's1' goes before song 's2'.
 *
 * @param[in]  s1 Song 's1'
 * @param[in]  s2 Song 's2'
 *
 * @return true if song 's1' goes before song 's2' in a sorted array of songs.
 */
bool goes_before(song_t s1, song_t s2);

/**
 * @brief    Checks if the array 'a' is in ascending order according
 *           to the goes_before() function
 *
 * @param[in]  playlist  The Song array
 * @param[in]  length    Length of song array
 *
 * @return True if array is sorted in ascendirng order according to goes_before() function, false otherwise
 */
bool array_is_sorted(song_t playlist[], unsigned int length);

/**
 * @brief    Checks if the array 'a' is in ascending order according to
 *           the goes_before() function considering only odd positions
 *           of the array songs[]
 *
 * @param[in]  playlist  The Song array
 * @param[in]  length    Length of song array
 *
 * @return True if array is sorted in ascendirng order according to goes_before()
 *              function considering only odd positions, false otherwise.
 */
bool array_is_odd_sorted(song_t playlist[], unsigned int length);


#endif
