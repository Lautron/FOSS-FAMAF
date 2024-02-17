#include "pqueue.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

struct s_pqueue {
  /*
   * COMPLETAR
   */
  struct s_node* front;
  unsigned int size;
};

struct s_node {
  /*
   * COMPLETAR
   */
  pqueue_elem elem;
  unsigned int priority; // prioridad maxima es 0
  struct s_node* next;
};

static struct s_node* create_node(pqueue_elem e, unsigned int priority)
{
  struct s_node* new_node = NULL;
  // Completar
  new_node = malloc(sizeof(struct s_node));
  assert(new_node != NULL);
  /*
   * COMPLETAR
   */
  new_node->elem = e;
  new_node->priority = priority;
  new_node->next = NULL;
  return new_node;
}

static struct s_node* destroy_node(struct s_node* node)
{
  assert(node != NULL);
  /*
   * COMPLETAR
   */
  // free(node->next);
  node->next = NULL;
  free(node);
  node = NULL;
  assert(node == NULL);
  return node;
}

static bool invrep(pqueue q)
{
  bool res = true;
  struct s_node *prev, *current; // Nodo anterior y actual
  if (q->front != NULL) {
    prev = q->front;
    current = prev->next;
    while (prev->next != NULL && current->next != NULL) {
      res = res && prev->priority <= current->priority;
      prev = current;
      current = current->next;
    }
  }
  /*
   * COMPLETAR
   */
  return res;
}

pqueue pqueue_empty(void)
{
  pqueue q = NULL;
  /*
   * COMPLETAR
   */
  q = malloc(sizeof(struct s_pqueue));
  q->front = NULL;
  q->size = 0;
  return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, unsigned int priority)
{
  assert(invrep(q));
  struct s_node* new_node = create_node(e, priority);
  struct s_node *prev, *post; // Nodo anterior y posterior al nodo a insertar

  if (q->front == NULL) {
    q->front = new_node;
  } else {
    prev = q->front;
    post = prev->next;
    while (post != NULL && post->next != NULL && post->priority < priority) {
      prev = post;
      post = post->next;
    }
    if (prev->priority < new_node->priority) {
      prev->next = new_node;
      new_node->next = post;
    } else if (prev->priority == new_node->priority && post == NULL) {
      prev->next = new_node;
      assert(q == q);
    } else {
      q->front = new_node;
      new_node->next = prev;
    }
  }
  q->size++;
  /*
   * COMPLETAR
   */
  return q;
}

bool pqueue_is_empty(pqueue q)
{
  /*
   * COMPLETAR
   */
  return (q->front == NULL);
}

pqueue_elem pqueue_peek(pqueue q)
{
  /*
   * COMPLETAR
   */
  return q->front->elem;
}

unsigned int pqueue_peek_priority(pqueue q)
{
  /*
   * COMPLETAR
   */
  return q->front->priority;
}

unsigned int pqueue_size(pqueue q)
{
  assert(invrep(q));
  // unsigned int size = 0;
  /*
   * COMPLETAR
   */
  return q->size;
}

pqueue pqueue_dequeue(pqueue q)
{
  /*
   * COMPLETAR
   */
  struct s_node* tmp = q->front;
  q->front = q->front->next;
  tmp = destroy_node(tmp);

  return q;
}

pqueue pqueue_destroy(pqueue q)
{
  assert(invrep(q));
  /*
   * COMPLETAR
   */
  struct s_node* nodo = q->front;
  while (nodo != NULL) {
    struct s_node* tmp = nodo;
    nodo = nodo->next;
    tmp = destroy_node(tmp);
  }
  free(q);
  q = NULL;

  assert(q == NULL);
  return q;
}
