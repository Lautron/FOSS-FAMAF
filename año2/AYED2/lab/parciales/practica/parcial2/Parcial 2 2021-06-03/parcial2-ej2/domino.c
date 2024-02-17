#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "domino.h"

struct _s_domino {
  /*
   * COMPLETAR
   */
  unsigned int up;
  unsigned int down;
};

/* auxiliary functions for dumping */

static char mark(bool b)
{
  return b ? 'O' : ' ';
}

static void dump_num(int num)
{
  printf("      | %c     %c |\n",
      mark(num > 1), mark(num > 3));
  printf("      | %c  %c  %c |\n",
      mark(num > 5), mark(num % 2 == 1), mark(num > 5));
  printf("      | %c     %c |\n",
      mark(num > 3), mark(num > 1));
}

static void dump_double_num(int num)
{
  printf(" --------------------- \n");
  printf(" | %c  %c  %c ", mark(num > 3), mark(num > 5), mark(num > 1));
  printf("| %c  %c  %c |\n", mark(num > 3), mark(num > 5), mark(num > 1));

  printf(" |    %c    ", mark(num % 2 == 1));
  printf("|    %c    |\n", mark(num % 2 == 1));

  printf(" | %c  %c  %c ", mark(num > 1), mark(num > 5), mark(num > 3));
  printf("| %c  %c  %c |\n", mark(num > 1), mark(num > 5), mark(num > 3));
  printf(" --------------------- \n");
}

void dump(int num_up, int num_down)
{
  /* Pretty dump funcion for cool visualization :) */
  if (num_up != num_down) {
    printf("      ----------- \n");
    dump_num(num_up);
    printf("      |---------| \n");
    dump_num(num_down);
    printf("      ----------- \n");
  } else {
    dump_double_num(num_up);
  }
}

/* Representation invariant */

static bool invrep(domino p)
{
  bool valid_domino = false;
  /*
   * COMPLETAR
   */
  valid_domino = p != NULL	    //
      && (p->up >= 1 && p->up <= 6) //
      && (p->down >= 1 && p->down <= 6);

  return valid_domino;
}

/* Public functions */

domino domino_new(int num_up, int num_down)
{
  domino p;
  p = malloc(sizeof(struct _s_domino));
  p->up = num_up;
  p->down = num_down;
  /*
   * COMPLETAR
   */
  assert(invrep(p));
  return p;
}

bool domino_is_double(domino p)
{
  assert(invrep(p));
  bool is_double = false;
  /*
   * COMPLETAR
   */
  is_double = (p->up == p->down);
  return is_double;
}

bool domino_eq(domino p1, domino p2)
{
  assert(invrep(p1) && invrep(p2));
  bool equals = false;
  /*
   * COMPLETAR
   */
  equals = ((p1->up == p2->up) && (p1->down == p2->down)) //
      || ((p1->up == p2->down) && (p1->down == p2->up));

  return equals;
}

bool domino_matches(domino p_top, domino p_bottom)
{
  assert(invrep(p_top) && invrep(p_bottom));
  bool is_match = false;
  /*
   * COMPLETAR
   */
  is_match = p_top->down == p_bottom->up;
  return is_match;
}

domino domino_flip(domino p)
{
  /*
   * COMPLETAR
   */
  unsigned int aux = p->up;
  p->up = p->down;
  p->down = aux;
  assert(invrep(p));
  return p;
}

void domino_dump(domino p)
{
  /*
   * COMPLETAR ( llamar a la función local dump() )
   */
  dump(p->up, p->down);
}

domino domino_destroy(domino p)
{
  /*
   * COMPLETAR
   */
  free(p);
  p = NULL;
  return p;
}
