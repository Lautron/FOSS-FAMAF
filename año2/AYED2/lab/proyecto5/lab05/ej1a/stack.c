#include "stack.h"
#include <assert.h>
#include <stdlib.h>

struct _s_stack {
  stack_elem elem;
  stack next;
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
  p->elem = e;
  p->next = s;
  s = p;
  return s;
}

stack stack_pop(stack s)
{
  stack p;
  p = s;
  s = s->next;
  free(p);
  p = NULL;
  return s;
}

unsigned int stack_size(stack s)
{
  stack p;
  p = s;
  unsigned int length = 0;
  while (p != NULL && p->next != NULL) {
    p = p->next;
    length++;
  }
  return length;
}

stack_elem stack_top(stack s)
{
  assert(!stack_is_empty(s));
  return s->elem;
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
    while (p->next != NULL) {
      res[i] = p->elem;
      p = p->next;
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
