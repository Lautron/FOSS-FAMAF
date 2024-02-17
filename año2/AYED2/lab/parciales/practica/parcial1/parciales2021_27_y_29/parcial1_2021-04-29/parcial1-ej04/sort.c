/*
  @file sort.c
  @brief sort functions implementation
*/
#include <stdbool.h>
#include <assert.h>
#include "helpers.h"
#include "sort.h"
#include "movie.h"


bool goes_before(movie_t s1, movie_t s2) {
    // -- Completar --
    return false;
}

bool array_is_sorted(movie_t movielist[], unsigned int size) {
    bool sorted=true;
    unsigned int i=0u;
    while (sorted && i + 1 < size) {
        sorted = goes_before(movielist[i], movielist[i+1]);
        ++i;
    }
    return sorted;
}

