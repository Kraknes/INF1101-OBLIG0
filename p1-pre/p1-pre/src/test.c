#include "common.h"
#include "futil.h"
#include "printing.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <string.h>
#include <errno.h>
#include <ctype.h>




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
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    list->cmpfn = cmpfn;
    return list;
}

size_t list_length(list_t *list) {
    if (list->length == 0) {
        return 0;
    }
    return list->length;
}

int main(){
    printf("yo \n");

    list_t *words = list_create((cmp_fn) strcmp);
    

    printf("%lu \n", words->length);
    printf("%p \n", words->tail);
    return 0;
}