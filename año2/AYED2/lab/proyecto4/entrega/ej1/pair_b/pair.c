#include "pair.h"
#include <stdlib.h>

pair_t pair_new(int x, int y)
{
  pair_t res;
  res = malloc(sizeof(pair_t));
  res->fst = x;
  res->snd = y;
  return res;
}

int pair_first(pair_t p)
{
  return p->fst;
}

int pair_second(pair_t p)
{
  return p->snd;
}

pair_t pair_swapped(pair_t p)
{
  pair_t q;
  q = malloc(sizeof(pair_t));
  q->fst = p->snd;
  q->snd = p->fst;
  return q;
}

pair_t pair_destroy(pair_t p)
{
  free(p);
  return NULL;
}
