#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    struct s_node** array;
    unsigned int size;
    priority_t min_priority;
};

struct s_node {
    pqueue_elem elem;
    struct s_node* next;
};

static struct s_node * create_node(pqueue_elem e) {
    struct s_node* new_node=NULL;
    new_node = malloc(sizeof(struct s_node));
    new_node->elem = e;
    new_node->next = NULL;
    assert(new_node!=NULL);
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    free(node);
    node = NULL;
    return node;
}


static bool invrep(pqueue q) {
    return q==q;
}

pqueue pqueue_empty(priority_t min_priority) {
    pqueue q = malloc(sizeof(struct s_pqueue));
    q->array = calloc(min_priority + 1, sizeof(struct s_node));
    q->size = 0;
    q->min_priority = min_priority;
    assert(invrep(q) && pqueue_is_empty(q));
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, priority_t priority) {
    assert(invrep(q));
    // TODO: completar
    assert(invrep(q) && !pqueue_is_empty(q));
    return q;
}

bool pqueue_is_empty(pqueue q) {
    assert(invrep(q));
    return (q->size == 0);
}

pqueue_elem pqueue_peek(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    priority_t ind;
    // TODO: revisar
    for (priority_t i = 0; q->array[i] == NULL; i++){
        ind = i;
    }
    
    return q->array[ind]->elem;
}

priority_t pqueue_peek_priority(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    // TODO: revisar
    priority_t ind;
    for (priority_t i = 0; q->array[i] == NULL; i++){
        ind = i;
    }
    return ind;
}

size_t pqueue_size(pqueue q) {
    assert(invrep(q));
    return q->size;
}

pqueue pqueue_dequeue(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    struct s_node *tmp;

    priority_t ind;
    for (priority_t i = 0; q->array[i] == NULL; i++){
        ind = i;
    }

    tmp = q->array[ind];
    q->array[ind] = q->array[ind]->next;
    tmp = destroy_node(tmp);

    assert(invrep(q));
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));
    struct s_node *tmp;
    for (priority_t i = 0; i< q->min_priority && q->array[i] == NULL; i++)
    {
        while (q->array[i] != NULL)
        {
            tmp = q->array[i];
            q->array[i] = q->array[i]->next;
            tmp = destroy_node(tmp);
        }
    }
    return q;
}

