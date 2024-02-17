#ifndef _ARRAY_HELPERS_H
#define _ARRAY_HELPERS_H

#include <stdlib.h>
#include <stdbool.h>

void array_dump(int a[], size_t length);
/*
    Write the content of the array 'a' into stdout. The array 'a' must have
    exactly 'length' elements.
*/

int *array_from_file(const char *filepath, size_t *length);
/*
    Each element is read from the file located at 'filepath'.
    The file must exist in disk and must have its contents in the following
    format:

    <array_length>
    <array_elem_1> <array_elem_2> <array_elem_3> ... <array_elem_N>

    In other words, the first line must be the array length, and the next line
    must contain '<array_length>' amount of elements separated by one or more
    blank characters.



    Returns a pointer to dynamic memory that holds the loaded array (pointer
    must be free by caller).

    The function store in *length the amount of elements of the array

*/

#endif
