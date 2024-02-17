#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pstack.h"

struct s_pstack
{
    // TODO: revisar
    struct s_node *front;
    unsigned int size;
};

struct s_node
{
    // TODO: revisar
    pstack_elem elem;
    priority_t priority;
    struct s_node *next;
};

static struct s_node *create_node(pstack_elem e, priority_t priority)
{
    struct s_node *new_node = NULL;
    // TODO: revisar
    new_node = malloc(sizeof(struct s_node));
    new_node->elem = e;
    new_node->priority = priority;
    new_node->next = NULL;
    assert(new_node != NULL);
    return new_node;
}

static struct s_node *destroy_node(struct s_node *node)
{
    // TODO: revisar
    assert(node != NULL);
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}

static bool invrep(pstack s)
{
    // TODO: Revisar
    bool res = true;
    if (s->front != NULL)
    {
        struct s_node *p = s->front->next;
        priority_t prev_p = s->front->priority;

        // Propiedad funamental: p1 >= p2 >= ... >= pn
        while (p != NULL && res)
        {
            res = res && (prev_p >= p->priority);
            prev_p = p->priority;
            p = p->next;
        }
    }

    return res;
}

pstack pstack_empty(void)
{
    // TODO: revisar
    pstack s = NULL;
    s = malloc(sizeof(struct s_pstack));
    s->size = 0;
    s->front = NULL;
    return s;
}

pstack pstack_push(pstack s, pstack_elem e, priority_t priority)
{
    // TODO: Revisar
    assert(invrep(s));
    struct s_node *new_node = create_node(e, priority);
    struct s_node *prev, *post;
    // stack vacio
    if (pstack_is_empty(s))
    {
        s->front = new_node;
    }
    else
    {
        prev = s->front;
        post = s->front->next;
        // Encontrar posicion para insertar el nodo
        while (post != NULL && (post->priority > priority))
        {
            prev = post;
            post = post->next;
        }
        // Prioridad >= prev->p
        // Insertar nodo
        if (priority >= prev->priority)
        {
            s->front = new_node;
            new_node->next = prev;
        }
        else
        {
            prev->next = new_node;
            new_node->next = post;
        }
    }

    s->size++;
    return s;
}

bool pstack_is_empty(pstack s)
{
    // TODO: revisar
    return (s->front == NULL);
}

pstack_elem pstack_top(pstack s)
{
    // TODO: revisar
    return s->front->elem;
}

priority_t pstack_top_priority(pstack s)
{
    // TODO: revisar
    return s->front->priority;
}

unsigned int pstack_size(pstack s)
{
    // TODO: revisar
    assert(invrep(s));
    return s->size;
}

pstack pstack_pop(pstack s)
{
    // TODO: revisar
    struct s_node *tmp = s->front;
    s->front = s->front->next;
    tmp = destroy_node(tmp);
    return s;
}

pstack pstack_destroy(pstack s)
{
    struct s_node *p, *tmp;
    p = s->front;
    // TODO: revisar
    assert(invrep(s));
    while (p != NULL)
    {
        tmp = p;
        p = p->next;
        tmp = destroy_node(tmp);
    }
    free(s);
    s = NULL;

    assert(s == NULL);
    return s;
}
