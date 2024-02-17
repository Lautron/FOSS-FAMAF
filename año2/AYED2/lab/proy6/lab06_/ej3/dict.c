#include <assert.h>
#include "dict.h"
#include "key_value.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

static bool invrep(dict_t d) {
    return  (d == NULL) || (d->left==NULL && d->right == NULL) ||              // arbol nulo  
            (   (d->left == NULL || key_less(d->left->key, d->key)) &&     // arbol no nulo
                (d->right  == NULL || key_less(d->key, d->right->key)) &&
                invrep(d->right) &&
                invrep(d->left)
            );
    
}

//implementacion para ultimos nodos
static struct _node_t *last_node(key_t key, value_t value) {
  struct _node_t *node = malloc(sizeof(struct _node_t));
  node->key = key;
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

dict_t dict_empty(void) {
    dict_t dict = NULL;
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    assert(invrep(dict));
    
    if(dict == NULL) {
        dict = last_node(word, def);
    }
    else if(key_less(word, dict->key)) {
        dict->left = dict_add(dict->left, word, def);
    }
    else if(key_less(dict->key, word)){
        dict->right = dict_add(dict->right, word, def);
    }else{
        value_t tmp = dict->value;
        dict->value = def;
        value_destroy(tmp);
    }

    assert(invrep(dict) && dict_exists(dict, word));
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    assert(invrep(dict));
    key_t def=NULL;
    
    if(dict!=NULL){
        if(key_eq(dict->key,word)){
            def = dict->value;
        }else{
            if(key_less(dict->key,word)){
                def = dict_search(dict->right,word);
            }else if(key_less(word, dict->key)){
                def = dict_search(dict->left,word);
            }
        }  
    }

    return def;
}

bool dict_is_empty(dict_t dict) {
    return dict == NULL;
}

bool dict_exists(dict_t dict, key_t word) {
    bool exists=false;
    
    assert(invrep(dict));
    
    if(dict!=NULL){
        if(key_less(dict->key,word)){
            exists = dict_exists(dict->right,word);
        }else{
            exists = key_eq(dict->key,word) || dict_exists(dict->left,word);
        }   
    }

    return exists;
}

unsigned int dict_length(dict_t dict) {
    unsigned int length=0;
    assert(invrep(dict));
    
    if(!dict_is_empty(dict)){
        length = 1 + dict_length(dict->left) + dict_length(dict->right);
    }

    assert(invrep(dict) && (dict_is_empty(dict) || length > 0));
    return length;
}

key_t dict_min(dict_t dict) {
    key_t min_k;
    assert(invrep(dict));
    
    struct _node_t *p = dict;
    while(p->left!=NULL){
        p = p->left;
    }
    min_k = p->key;

    assert(invrep(dict) && dict_exists(dict, min_k));
    return min_k;
}

dict_t dict_remove(dict_t dict, key_t word){
    assert(invrep(dict));
    dict_t r = dict;
    
    // caso base
    if (dict != NULL){

        // key < dict
        if (key_less(word, dict->key))
            dict->left = dict_remove(dict->left, word);
    
        // key > dict
        else if (key_less(dict->key, word))
            dict->right = dict_remove(dict->right, word);
    
        // key = dict
        // entonces es el nodo que quiero eliminar

        else {
            // un hijo o sin hijo
            if (dict->left == NULL) {
                r = dict->right;
                free(dict);
                dict = NULL;
            }
            else if (dict->right == NULL) {
                r = dict->left;
                free(dict);
                dict = NULL;
            }else{    // dos hijos
                key_t temp_key = dict_min(dict->right);
                value_t temp_value = dict_search(dict->right, temp_key);
                dict->key = temp_key;
                dict->value = temp_value;
                dict->right = dict_remove(dict->right, temp_key);
                r = dict;
            }
        }
    }    
    assert(invrep(r) && !dict_exists(r,word));
    return r;
}

dict_t dict_remove_all(dict_t dict) {
    assert(invrep(dict));
    if(dict != NULL) {
      dict_remove_all(dict->left);
      dict_remove_all(dict->right);
      key_destroy(dict->key);
      value_destroy(dict->value);
      free(dict);
      dict = NULL;
    }
    assert(dict == NULL);
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
    assert(invrep(dict));
    if (dict != NULL) {
        dict_dump(dict->left, file);
        // fprintf(file, "%c: %c\n", dict->key, dict->value);
        key_dump(dict->key, file);
        value_dump(dict->value, file);
        dict_dump(dict->right, file);
    }
}

// void dict_print(dict_t dict) {
//     assert(invrep(dict));
//     if (dict != NULL) {
//         dict_print(dict->left);
//         key_dump(dict->key, stdout);
//         value_dump(dict->value, stdout);
//         // printf("%c: %c\n", dict->key, dict->value);
//         dict_print(dict->right);
//     }
// }

dict_t dict_destroy(dict_t dict) {
    return dict_remove_all(dict);
}

