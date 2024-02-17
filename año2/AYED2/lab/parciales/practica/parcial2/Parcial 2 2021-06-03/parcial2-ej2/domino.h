#ifndef _DOMINO_H
#define _DOMINO_H

#include <stdbool.h>

typedef struct _s_domino * domino;

domino domino_new(int num_up, int num_down);

bool domino_is_double(domino p);

bool domino_eq(domino p1, domino p2);

bool domino_matches(domino p_top, domino p_botton);

domino domino_flip(domino p);


void domino_dump(domino p);

domino domino_destroy(domino p);



#endif
