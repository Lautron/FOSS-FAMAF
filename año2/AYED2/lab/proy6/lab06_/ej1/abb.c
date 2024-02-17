#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *lft;
    struct _s_abb *rgt;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb t) {
    return  (t == NULL) || (t->lft==NULL && t->rgt == NULL) ||              // arbol nulo  
            (   (t->lft == NULL || elem_less(t->lft->elem, t->elem)) &&     // arbol no nulo
                (t->rgt  == NULL || elem_less(t->elem, t->rgt->elem)) &&
                invrep(t->rgt) &&
                invrep(t->lft)
            );
    
}

abb abb_empty(void) {
    abb tree;

    tree = NULL;

    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    assert(!abb_exists(tree, e));
    
    if(tree == NULL) {
        tree = malloc(sizeof(struct _s_abb));
        tree->elem = e;
        tree->lft = NULL;
        tree->rgt = NULL;
    }
    else if(e < tree->elem) {
      tree->lft = abb_add(tree->lft, e);
    } 
    else if(e > tree->elem) {
      tree->rgt = abb_add(tree->rgt, e);
    }

    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    assert(invrep(tree));
    return (tree == NULL);
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    
    if(tree!=NULL){
        if(elem_less(tree->elem,e)){
            exists = elem_eq(tree->elem,e) || abb_exists(tree->rgt,e);
        }else{
            exists = elem_eq(tree->elem,e) || abb_exists(tree->lft,e);
        }   
    }

    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    
    if(!abb_is_empty(tree)){
        length = 1 + abb_length(tree->lft) + abb_length(tree->rgt);
    }

    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

struct _s_abb *pabb_max(abb tree) {
    struct _s_abb *p = tree;
    while(p->rgt!=NULL){
        p = p->rgt;
    }
    return p;
}

struct _s_abb *padreabb_max(abb tree) {
    struct _s_abb *p = tree;
    while(p->rgt->rgt!=NULL){
        p = p->rgt;
    }
    return p;
}

// abb abb_remove(abb tree, abb_elem e) {
//     assert(invrep(tree));
//     if(abb_exists(tree, e)){
//         struct _s_abb *pelim = tree;
//         struct _s_abb *padre;
//         while(pelim->elem!=e){                 //busco el elemento a elimiar
//             if(elem_less(e,pelim->elem)){
//                 padre = pelim;
//                 pelim = pelim->lft;
//             }else{
//                 padre = pelim;
//                 pelim = pelim->rgt;
//             }
//         }

//         if(pelim->lft==NULL){

//         }

//         //busco el maximo elemento de la rama de la izquierda para remplazar
//         struct _s_abb *padremaxmin = pabb_max(pelim->lft);
        
//         struct _s_abb *elim = padremaxmin->rgt;     

//         pelim->elem = padremaxmin->rgt->elem;         
//         padremaxmin->rgt = padremaxmin->rgt->lft;

//         free(elim);                // libero el elemento

//         assert(invrep(tree) && !abb_exists(tree, e));
//     }
//     return tree;
// }

abb abb_remove(abb tree, abb_elem e){
    assert(invrep(tree));
    abb r = tree;
    
    // caso base
    if (tree != NULL){

        // key < tree
        if (e < tree->elem)
            tree->lft = abb_remove(tree->lft, e);
    
        // key > tree
        else if (e > tree->elem)
            tree->rgt = abb_remove(tree->rgt, e);
    
        // key = tree
        // entonces es el nodo que quiero eliminar

        else {
            // un hijo o sin hijo
            if (tree->lft == NULL) {
                r = tree->rgt;
                free(tree);
                tree = NULL;
            }
            else if (tree->rgt == NULL) {
                r = tree->lft;
                free(tree);
                tree = NULL;
            }else{    // dos hijos
                abb_elem temp = abb_min(tree->rgt);
                tree->elem = temp;
                tree->rgt = abb_remove(tree->rgt, temp);
                r = tree;
            }
        }
    }    
    assert(invrep(r) && !abb_exists(r,e));
    return r;
}

abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    
    root = tree->elem;

    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));

    struct _s_abb *p = pabb_max(tree);
    max_e = p->elem;
    
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    
    struct _s_abb *p = tree;
    while(p->lft!=NULL){
        p = p->lft;
    }
    min_e = p->elem;

    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        abb_dump(tree->lft);
        printf("%d ", tree->elem);
        abb_dump(tree->rgt);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    
    struct _s_abb *l = tree->lft;
    struct _s_abb *r = tree->rgt;
    if(l!=NULL){
        abb_destroy(l);
    }
    if(r!=NULL){
        abb_destroy(r);
    }

    free(tree); 
    tree=NULL;

    assert(tree == NULL);
    return tree;
}

