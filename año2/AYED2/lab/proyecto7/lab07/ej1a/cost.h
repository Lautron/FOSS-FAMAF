#ifndef _COST_H_
#define _COST_H_

#include <stdbool.h>

typedef int cost_t;

/**
Returns an infinite cost
*/
cost_t cost_inf();

/** Checks if a cost is infinite 
@param cost
@return true if cost is infinite, false otherwise 
*/
bool cost_is_inf(cost_t cost);

/** Cost Less or Equal relation
@param c1 first cost
@param c2 second cost
*/
bool cost_le(cost_t c1, cost_t c2);

/** Cost Less Than relation
@param c1 first cost
@param c2 second cost
*/
bool cost_lt(cost_t c1, cost_t c2);

/** Cost Sum (addition) operation
@param c1 first cost
@param c2 second cost
*/
cost_t cost_sum(cost_t c1, cost_t c2);

/**
Prints a cost in stdout 
*/
void cost_print(cost_t cost);

#endif
