#ifndef _DOMINO_HELPERS_H_
#define _DOMINO_HELPERS_H_

#include "domino.h"

domino scan_domino(void);
/*
 * Gets a domino from user input. Spects the followinf format:
 *
 * <num_up>:<num_down>
 *
 * if an error occurs, it returns a NULL value.
 *
 */

unsigned int chain_dominoes(domino pieces[], unsigned int size);
/*
 * Try to chain all domino pieces of a (non-empty) array, fliping pieces
 * when necesary.
 *
 * The first element must be a double domino piece, in other words
 * domino_is_double(pieces[0]) must be true.
 *
 * Returns how many pieces has the chain of matching dominoes
 *
 */

#endif

