#include "list.h"
#include "printing.h"

#include <stdlib.h>


typedef struct lnode lnode_t;
struct lnode {
    lnode_t *next;
    lnode_t *prev;
    void *item;
};

struct list {
    lnode_t *head;
    lnode_t *tail;
    size_t length;
    cmp_fn cmpfn;
};

struct list_iter {
    list_t *list;
    lnode_t *node;
};



list_t *list_create(cmp_fn cmpfn) {
    list_t *list = malloc(sizeof(list_t));    
}

main(){
    printf("yo \n");
    return 0;
}