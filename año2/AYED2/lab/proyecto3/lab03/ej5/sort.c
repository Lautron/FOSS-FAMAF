/*
  @file sort.c
  @brief sort functions implementation
*/

#include "sort.h"
#include "helpers.h"
#include "player.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool goes_before(player_t x, player_t y)
{
  // completar aquí
  if (y != NULL) {
    return (x->rank <= y->rank);
  } else {
    return true;
  }
}

bool array_is_sorted(player_t atp[], unsigned int length)
{
  unsigned int i = 1u;
  while (i < length && goes_before(atp[i - 1u], atp[i])) {
    i++;
  }
  return (i == length);
}

void sort(player_t a[], unsigned int length)
{
  for (unsigned int i = 1; i < length; i++) {
    player_t key = a[i];
    int j = i - 1;

    while (goes_before(key, a[j]) && j >= 0) {
      a[j + 1] = a[j];
      --j;
    }
    a[j + 1] = key;
  }
}
