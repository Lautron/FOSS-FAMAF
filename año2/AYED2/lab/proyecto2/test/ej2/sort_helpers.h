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

unsigned int partition(int a[], unsigned int izq, unsigned int der);
/* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
*/

#endif
