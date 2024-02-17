#include <limits.h>
#include <stdio.h>

#include "cost.h"

cost_t cost_inf()
{
    return INT_MAX;
}

bool cost_is_inf(cost_t cost)
{
    return cost == cost_inf();
}

bool cost_le(cost_t c1, cost_t c2)
{
    return c1 <= c2;
}

bool cost_lt(cost_t c1, cost_t c2)
{
    return c1 < c2;
}

cost_t cost_sum(cost_t c1, cost_t c2)
{
    if (cost_is_inf(c1) || cost_is_inf(c2)) {
        return cost_inf();
    } else {
        return c1 + c2;
    }
}

void cost_print(cost_t cost)
{
    if (cost_is_inf(cost)) {
        printf("#");
    } else {
        printf("%d", cost);
    }
}
