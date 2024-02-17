#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "counter.h"

struct _counter {
  unsigned int count;
};

counter counter_init(void)
{
  /*
      Needs implementation.
  */
  counter p;
  p = malloc(sizeof(counter));
  p->count = 0;
  return p;
}

void counter_inc(counter c)
{
  /*
      Needs implementation.
  */
  c->count++;
}

bool counter_is_init(counter c)
{
  /*
      Needs implementation.
  */
  return (c->count == 0);
}

void counter_dec(counter c)
{
  /*
      Needs implementation.
  */
  assert(!counter_is_init(c));
  c->count = c->count - 1;
}

counter counter_copy(counter c)
{
  /*
      Needs implementation.
  */
  counter q;
  q = malloc(sizeof(counter));
  q->count = c->count;
  return q;
}

void counter_destroy(counter c)
{
  /*
     Needs implementation.
  */
  free(c);
  c = NULL;
}
