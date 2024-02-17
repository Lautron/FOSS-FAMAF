#ifndef _COUNTER_H
#define _COUNTER_H

#include <stdbool.h>

/* counter as a pointer to structs to guarantee encapsulation */
typedef struct _counter * counter;


/* Constructors */
counter counter_init(void);
/*
    Create a new counter with initial value. Allocates new memory.
    Being c the returned counter, counter_is_init(c) should be true.
*/

void counter_inc(counter c);
/*
    Increments the counter c.
*/


/* Operations */
bool counter_is_init(counter c);
/*
    Return whether the counter c has the initial value.
*/

void counter_dec(counter c);
/*
    Decrements the counter c.
    PRECONDITION: !counter_is_init(c)
*/

counter counter_copy(counter c);
/*
    Makes a copy of counter c. Allocates new memory.
*/

void counter_destroy(counter c);
/*
   Frees memory for c.
*/

#endif
