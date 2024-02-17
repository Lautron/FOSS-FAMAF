#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

/* counter as a pointer to structs to guarantee encapsulation */
typedef struct _list * list;
typedef int list_elem;

/* Constructors */
list empty_list(void);

list list_addl(list_elem e, list l);

/* Operations */
bool list_is_empty(list l);

list_elem list_head(list l);
// PRE: !list_is_empty(l)

list list_tail(list l);
// PRE: !list_is_empty(l)

list list_addr(list_elem e, list l);

unsigned int list_length(list l);

list list_concat(list l1, list l2);

list_elem list_index(list l, unsigned int n);
// PRE: list_length(l) > n

list list_take(list l, unsigned int n);

list list_drop(list l, unsigned int n);

list list_copy(list l);

/* Destroy */
list destroy_list(list l);

void list_dump(list l);
#endif
