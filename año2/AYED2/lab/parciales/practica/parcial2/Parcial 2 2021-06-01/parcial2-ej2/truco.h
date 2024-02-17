#ifndef _TRUCO_H_
#define _TRUCO_H_

#include <stdbool.h>

typedef struct _s_truco_card * truco_card;


truco_card truco_card_new(int num, char p);
/*
 * Creates a new card for a Truco game match. The number of the card is given
 * by `num` and `p` indicates the suit (espada, oro, copa, basto).
 *
 * The value for `num` must verify: 1 <= num <= 12 /\ num != 8 /\ num != 9
 *
 * The value for `p` must verify  : p=='e' \/ p=='o' \/ 'p=='c' \/ p=='b'
 *
 * The character stored in `p` means:  'e' ---> Espada
 *                                     'o' ---> Oro
 *                                     'c' ---> copa
 *                                     'b' ---> Basto
 *
 *
 **/

bool truco_card_win(truco_card a, truco_card b);

bool truco_card_tie(truco_card a, truco_card b);

void truco_card_dump(truco_card c);

truco_card truco_card_destroy(truco_card c);

#endif
