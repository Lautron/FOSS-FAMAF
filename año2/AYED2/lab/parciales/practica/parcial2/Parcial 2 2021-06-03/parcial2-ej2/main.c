#include <stdio.h>
#include <stdlib.h>

#include "domino.h"
#include "domino_helpers.h"

int main(void)
{
  unsigned int n_pieces = 0u;
  int readed = 0;
  bool wrong_answer = true;
  // Getting amount of pieces to use (>0)
  while (wrong_answer) {
    printf("¿Cuantas fichas vas a usar?\n");
    readed = scanf("%u", &n_pieces);
    if (readed != 1) {
      printf("ERROR DE LECTURA\n\n");
      exit(EXIT_FAILURE);
    }
    wrong_answer = n_pieces < 1;
    if (wrong_answer) {
      printf("ERROR: Se deben usar más de una ficha\n\n");
    }
  }
  // Create array for pieces
  domino* pieces = calloc(n_pieces, sizeof(domino));
  /*
   * Read pieces from user
   */
  // The first piece must be double
  domino piece;
  bool is_double = false;
  while (!is_double) {
    piece = scan_domino();
    if (piece == NULL) {
      printf("ERROR DE LECTURA\n\n");
      exit(EXIT_FAILURE);
    }
    is_double = domino_is_double(piece);
    if (!is_double) {
      printf("La primer ficha debe ser doble!!\n\n");
      piece = domino_destroy(piece);
    }
  }
  // Read the rest of the pieces from user
  pieces[0] = piece;
  for (unsigned int i = 1; i < n_pieces; i++) {
    piece = scan_domino();
    if (piece == NULL) {
      printf("ERROR DE LECTURA\n\n");
      exit(EXIT_FAILURE);
    }
    pieces[i] = piece;
  }
  // Try to chain all pieces
  unsigned int matches = chain_dominoes(pieces, n_pieces);
  // Show chained pieces
  for (unsigned int i = 0; i < matches; i++) {
    domino_dump(pieces[i]);
  }
  // Free memory
  for (unsigned int i = 0; i < n_pieces; i++) {
    pieces[i] = domino_destroy(pieces[i]);
  }
  free(pieces);
  return EXIT_SUCCESS;
}
