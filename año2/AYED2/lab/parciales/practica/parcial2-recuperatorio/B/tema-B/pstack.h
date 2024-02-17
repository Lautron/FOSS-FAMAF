#ifndef _PQUEUE_H_
#define _PQUEUE_H_

#include <stdbool.h>

typedef struct s_pstack * pstack;

typedef unsigned int pstack_elem;

typedef enum {worst, low, normal, high, best} priority_t;

pstack pstack_empty(void);
/*
 * DESC: Creates a new instance of pstack
 *
 * PRE: {true}
 *  s = pstack_empty();
 * POS: {s --> pstack && pstack_is_empty(s)}
 *
 */

pstack pstack_push(pstack s, pstack_elem e, priority_t priority);
/*
 * DESC: Adds element 'e' into the pstack 's' with the given 'priority'
 *
 * PRE: {s --> pstack}
 *  s = pstack_push(s, e, priority);
 * POS: {s --> pstack && !pstack_is_empty(s)}
 *
 */

bool pstack_is_empty(pstack s);
/*
 * DESC: Indicates whether the pstack 's' is empty or not
 *
 */

unsigned int pstack_size(pstack s);
/*
 * DESC: Return the number of elements inside the pstack 's'
 *
 */

pstack_elem pstack_top(pstack s);
/*
 * DESC: Return the element with the most urgent prioritiy of the pstack 's'
 *
 * PRE: {s --> pstack && !pstack_is_empty(s)}
 *  e = pstack_top(s);
 * POS: {s --> pstack}
 */

priority_t pstack_top_priority(pstack s);
/*
 * DESC: Return the priority that is most urgent from the pstack 's'
 *
 * PRE: {s --> pstack && !pstack_is_empty(s)}
 *  priority = pstack_top_priority(q);
 * POS: {s --> pstack}
 */

pstack pstack_pop(pstack s);
/*
 * DESC: Remove the element with the most urgent priority of the pstack 's'
 *
 * PRE: {s --> pstack && !pstack_is_empty(s)}
 *  q = pstack_pop(q);
 * POS: {s --> pstack}
 *
 */

pstack pstack_destroy(pstack s);
/*
 * DESC: Destroy instance of pstack, freeing all memory used by 's'.
 *
 * PRE: {s --> pstack}
 *  s = pstack_destroy(s);
 * POS: {s == NULL}
 *
 */

#endif
