#include <stdlib.h>
#include <stdbool.h>            /* Definition of bool      */
#include <assert.h>
#include "mini_set.h"
#include "type_elem.h"          /* Definition of type_elem */

struct s_set {
    type_elem elem;
    struct s_set *next;
};

static set new_node(type_elem e) {
    set new=calloc(1, sizeof(struct s_set));
    new->elem =e;
    return new;
}

/* CONSTRUCTORS */

set set_empty(void) {
    set s = NULL;
    return s;
}

set set_add(set s, type_elem e) {
    if (s != NULL) {
        set node=s;
        while (node->elem != e && node->next != NULL) {
            node = node->next;
        }
        if (node->elem!=e) {
            node->next = new_node(e);
        }
    } else {
        s = new_node(e);
    }
    assert(s != NULL);
    return s;
}


/* OPERATIONS   */
unsigned int set_cardinal(set s) {
    unsigned int cardinal=0;
    while (s != NULL) {
        cardinal++;
        s = s->next;
    }
    return cardinal;
}

bool set_is_empty(set s) {
    return s==NULL;
}

bool set_member(type_elem e, set s) {
    set node=s;
    bool member=false;
    while (node!=NULL && !member) {
        member = node->elem == e;
        node = node->next;
    }
    return member;
}


set set_elim(set s, type_elem e) {
    if (s != NULL) {
        if (s->elem==e) {
            set aux=s;
            s = s->next;
            free(aux);
        } else {
            set node=s->next, father=s;
            while (node != NULL && node->elem != e) {
                father = node;
                node = node->next;
            }
            if (node !=NULL) {
                assert(node->elem == e);
                set aux=father->next;
                father->next = node->next;
                free(aux);
            }
        }
    }
    return s;
}

type_elem set_get(set s) {
    assert(s != NULL);
    return s->elem;
}

set set_destroy(set s) {
    while (s != NULL) {
        set aux=s;
        s = s->next;
        free(aux);
    }
    return s;
}
