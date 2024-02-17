#include "pair.h" /* TAD Par         */

pair_t pair_new(int x, int y)
{
  pair_t res;
  res.fst = x;
  res.snd = y;
  return res;
}

int pair_first(pair_t p)
{
  return p.fst;
}
int pair_second(pair_t p)
{
  return p.snd;
}
pair_t pair_swapped(pair_t p)
{
  int tmp;
  tmp = p.fst;
  p.fst = p.snd;
  p.snd = tmp;
  return p;
}

pair_t pair_destroy(pair_t p)
{
  return p;
}
