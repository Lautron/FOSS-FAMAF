#include "stack.h"
#include <assert.h>
#include <stdlib.h>
#define START_CAPACITY 20

struct _s_stack {
  stack_elem* elems;	 // Arreglo de elementos
  unsigned int size;	 // Cantidad de elementos en la pila
  unsigned int capacity; // Capacidad actual del arreglo elems
};

stack stack_empty()
{
  stack s;
  s = malloc(sizeof(stack));
  stack_elem* arr = calloc(START_CAPACITY, sizeof(stack_elem));
  s->elems = arr;
  s->size = 0;
  s->capacity = START_CAPACITY;
  return s;
}

stack stack_push(stack s, stack_elem e)
{
  s->size++;
  if (s->capacity > s->size) {
    s->capacity = s->capacity * 2;
    s->elems = realloc(s->elems, sizeof(stack_elem) * s->capacity);
  }
  s->elems[s->size - 1] = e;
  return s;
}

stack stack_pop(stack s)
{
  assert(!stack_is_empty(s));
  s->size--;
  return s;
}

unsigned int stack_size(stack s)
{
  return s->size;
}

stack_elem stack_top(stack s)
{
  assert(!stack_is_empty(s));
  return s->elems[s->size - 1];
}

bool stack_is_empty(stack s)
{
  return (s->size == 0);
}

stack_elem* stack_to_array(stack s)
{
  stack_elem* res = calloc(s->size, sizeof(stack_elem));
  for (unsigned int i = 0; i < s->size; ++i) {
    res[i] = s->elems[i];
  }
  return res;
}

stack stack_destroy(stack s)
{
  free(s->elems);
  free(s);
  s = NULL;
  return s;
}
