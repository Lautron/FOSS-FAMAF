/*
 *
 * Author   2017 Daniel Fridlender
 *
 * Revision 2018 Sergio Canchi
 *
 *
 */


#ifndef _SORT_HELPERS_H
#define _SORT_HELPERS_H

#include <stdbool.h>

bool goes_before(int x, int y);
/* Abstract total order for sorting algorithms */

bool array_is_sorted(int a[], unsigned int length);
/* Checks if the array 'a' is in ascending order */

void swap(int a[], unsigned int i, unsigned int j);
/* Exchanges elements of array 'a' in the given positions 'i' and 'j'
   Array remains the same if the two positions are the same
*/

void reset_comparisons_counter();
/* Resets the comparisons_counter */

unsigned int comparisons_number();
/* Returns value of comparisons_counter
*/

void reset_swaps_counter();
/* Resets the counter of swaps */

unsigned int swaps_number();
/* Returns value of swaps_counter
*/

void set_current_time();
/* Initialize the current time */

double calculate_elapsed_time();
/* Calculate the time elapsed in milliseconds */


#endif
