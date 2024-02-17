#include <assert.h>
#include "dict.h"
#include "key_value.h"

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

static bool invrep(dict_t d) {
    /* needs implementation */
    return true;
}

dict_t dict_empty(void) {
    dict_t dict = NULL;
    /* needs implementation */
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    /* needs implementation */
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    key_t def=NULL;
    /* needs implementation */
    return NULL;
}

bool dict_exists(dict_t dict, key_t word) {
    /* needs implementation */
    return false;
}

unsigned int dict_length(dict_t dict) {
    /* needs implementation */
    return 0u;
}

dict_t dict_remove(dict_t dict, key_t word) {
    /* needs implementation */
    return dict;
}

dict_t dict_remove_all(dict_t dict) {
    /* needs implementation */
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
    /* needs implementation */
}

dict_t dict_destroy(dict_t dict) {
    /* needs implementation */
    return dict;
}

