#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _list {
  list_elem elem;
  list next;
} _list;

// Constructors
list empty_list(void)
{
  list p;
  p = NULL;
  return p;
}

list list_addl(list_elem e, list l)
{
  list p;
  p = malloc(sizeof(_list));
  p->elem = e;
  p->next = l;
  l = p;
  return l;
}

// Operators
bool list_is_empty(list l)
{
  return (l == NULL);
}

list_elem list_head(list l)
{
  assert(!list_is_empty(l));
  return l->elem;
}

list list_tail(list l)
{
  list p;
  p = l;
  assert(!list_is_empty(l));
  l = l->next;
  free(p);
  p = NULL;
  return l;
}

list list_addr(list_elem e, list l)
{
  if (!list_is_empty(l)) {
    list p, q;
    q = malloc(sizeof(_list));
    q->elem = e;
    q->next = NULL;
    p = l;
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = q;
  } else {
    l = list_addl(e, l);
  }
  return l;
}

unsigned int list_length(list l)
{
  list p;
  unsigned int length = 0;
  p = l;
  while (p->next != NULL) {
    p = p->next;
    length++;
  }
  length++;
  return length;
}

list list_concat(list l1, list l2)
{
  list p;
  p = l1;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = l2;
  // free(p);
  // p = NULL;
  return l1;
}

list_elem list_index(list l, unsigned int n)
{
  assert(list_length(l) > n);
  list p;
  unsigned int length = 0;
  list_elem res;
  p = l;
  while (p->next != NULL && length < n) {
    p = p->next;
    length++;
  }
  res = p->elem;
  // free(p);
  // p = NULL;
  return res;
}

list list_take(list l, unsigned int n)
{
  list p, q;
  unsigned int length = 1;
  p = l;
  while (p->next != NULL) {
    if (length < n) {
      p = p->next;
      length++;
    } else if (length == n) {
      p->next = NULL;
    } else {
      q = p;
      p = p->next;
      free(q);
      q = NULL;
    }
  }
  return l;
}

list list_drop(list l, unsigned int n)
{
  list p, q;
  unsigned int length = 0;
  unsigned int l_length = list_length(l);
  p = l;
  while (p->next != NULL) {
    if (length < n) {
      q = p;
      p = p->next;
      l = p;
      free(q);
      q = NULL;
      length++;
    } else {
      p = p->next;
      length++;
    }
  }
  if (n >= l_length) {
    l = NULL;
  }
  return l;
}

list list_copy(list l)
{
  list p;
  p = l;
  list l2 = empty_list();
  while (p->next != NULL) {
    l2 = list_addr(p->elem, l2);
    p = p->next;
  }
  l2 = list_addr(p->elem, l2);
  return l2;
}

list destroy_list(list l)
{
  return list_drop(l, list_length(l));
}

void list_dump(list l)
{
  if (!list_is_empty(l)) {
    list p;
    p = l;
    printf("[ ");
    while (p->next != NULL) {
      printf("%d, ", p->elem);
      p = p->next;
    }
    printf("%d", p->elem);
    printf(" ]\n");
  } else {
    printf("[]\n");
  }
}
