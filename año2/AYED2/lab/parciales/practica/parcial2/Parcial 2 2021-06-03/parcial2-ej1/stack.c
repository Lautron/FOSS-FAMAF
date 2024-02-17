#include <stdlib.h>
#include "assert.h"
#include "stack.h"

struct _s_stack {
    stack_elem elem;
    stack next;
};

stack stack_empty() {
    return NULL;
}

stack stack_push(stack s, stack_elem e) {
    stack new = calloc(1, sizeof(struct _s_stack));
    assert(new != NULL);
    new->next = s;
    new->elem = e;
    return new;
}

stack stack_pop(stack s) {
    assert(s != NULL);
    stack next = s->next;
    free(s);
    return next;
}

unsigned int stack_size(stack s) {
    unsigned int count = 0;
    stack aux = s;
    while (aux != NULL) {
        aux = aux->next;
        ++count;
    }
    return count;
}

stack_elem stack_top(stack s) {
    assert(s != NULL);
    return (s->elem);
}

bool stack_is_empty(stack s) {
    return (s == NULL);
}

stack stack_destroy(stack s) {
    stack aux = s;
    while (!stack_is_empty(aux)) {
        aux = stack_pop(aux);
    }
    return NULL;
}
