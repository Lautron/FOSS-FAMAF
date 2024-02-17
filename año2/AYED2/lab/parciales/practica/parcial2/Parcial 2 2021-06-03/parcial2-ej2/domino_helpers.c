#include "domino.h"
#include <assert.h>
#include <stdio.h>

domino scan_domino(void)
{
  int up, down, readed;
  printf("Ingrese los valores de un domino (up:down): ");
  readed = scanf("%d:%d", &up, &down);
  return readed == 2 ? domino_new(up, down) : NULL;
}

unsigned int chain_dominoes(domino pieces[], unsigned int size)
{
  bool is_match = true;
  unsigned int match_count = 1; // Counts how many matches were made
  unsigned int i = 0;
  assert(size > 0 && domino_is_double(pieces[0]));
  while (is_match && i + 1 < size) {
    domino p1 = pieces[i], p2 = pieces[i + 1];
    /*
     * COMPLETAR
     */
    if (domino_matches(p1, p2) || domino_matches(p1, domino_flip(p2))) {
      match_count++;
    } else {
      is_match = false;
    }
    i++;
  }
  assert(match_count <= size);
  return match_count;
}
