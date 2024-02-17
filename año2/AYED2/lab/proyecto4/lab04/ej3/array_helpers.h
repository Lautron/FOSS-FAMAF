#ifndef _ARRAY_HELPERS_H
#define _ARRAY_HELPERS_H

void array_dump(int a[], unsigned int length);
/*
    Write the content of the array 'a' into stdout. The array 'a' must have
    exactly 'length' elements.
*/

unsigned int array_from_file(int a[], unsigned int max_size, const char *filepath);
/*
    Each element is read from the file located at 'filepath'.
    The file must exist in disk and must have its contents in the following
    format:

    <array_length>
    <array_elem_1> <array_elem_2> <array_elem_3> ... <array_elem_N>

    In other words, the first line must be the array length, and the next line
    must contain 'length' amount of elements separated by one or more
    blank characters.

    Those elements are copied into the array 'a'.
    The array_length must be lower or equal to 'max_size'.

    Returns the length of the array.
*/

#endif
