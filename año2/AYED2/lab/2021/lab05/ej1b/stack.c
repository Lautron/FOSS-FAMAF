#include "stack.h"
#include <assert.h>
#include <stdlib.h>

struct _s0_stack {
  stack_elem elem;
  stack next;
} _s0_stack;

struct _s_stack {
  struct _s0_stack elems;
  unsigned int size;
} _s_stack;

stack stack_empty()
{
  stack s;
  s = NULL;
  return s;
}

stack stack_push(stack s, stack_elem e)
{
  stack p;
  p = malloc(sizeof(_s_stack));
  p->elems.elem = e;
  p->elems.next = s;
  if (!stack_is_empty(s)) {
    p->size++;
  } else {
    p->size = 1;
  }
  s = p;
  return s;
}

stack stack_pop(stack s)
{
  stack p;
  p = s;
  s = s->elems.next;
  if (!stack_is_empty(s)) {
    s->size--;
  }
  free(p);
  p = NULL;
  return s;
}

unsigned int stack_size(stack s)
{
  return s->size;
}

stack_elem stack_top(stack s)
{
  assert(!stack_is_empty(s));
  return s->elems.elem;
}

bool stack_is_empty(stack s)
{
  return (s == NULL);
}

stack_elem* stack_to_array(stack s)
{
  stack_elem* res;
  if (!stack_is_empty(s)) {
    unsigned int s_length = stack_size(s);
    res = calloc(s_length, sizeof(stack_elem));
    stack p;
    p = s;
    unsigned int i = s_length - 1;
    while (p->elems.next != NULL) {
      res[i] = p->elems.elem;
      p = p->elems.next;
      i--;
    }
  } else {
    res = NULL;
  }
  return res;
}

stack stack_destroy(stack s)
{
  unsigned int len = stack_size(s);
  for (unsigned int i = 0; i < len; ++i) {
    s = stack_pop(s);
  }
  return s;
}
