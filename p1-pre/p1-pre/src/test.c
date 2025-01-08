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

void list_destroy(list_t *list, free_fn item_free) {
    free(list);
    free(item_free);
    printf("list destroyed \n");

}

int list_addfirst(list_t *list, void *item) {
    lnode_t *first_node = malloc(sizeof(lnode_t));
    first_node->item = item;

    if (list->length == 0) {
        list->tail = first_node;
        list->head = first_node;
    }
    else {
        first_node->next = list->head;
        list->head = first_node;
    }

    list->length++;
    return 0;
}

int main(){
    printf("yo \n");

    list_t *list = list_create((cmp_fn) strcmp);
    printf("List length before nodes is: %lu \n", list->length);
    list_addfirst(list, "hello");
    list_addfirst(list, "world");
    printf("List length after nodes is: %lu \n", list->length);

    printf("Memory adress for head is: %p \n", list->head);
    printf("Item for head is: %s \n", (char *)list->head->item);
    printf("Memory adress for tail is: %p \n", list->tail);
    printf("Item for tail si: %s \n", (char *)list->tail->item);

    printf("size of list before destruction: %lu \n", sizeof(list));
    list_destroy(list, NULL);
    printf("size of list after destruction: %lu \n", sizeof(list));
    // printf("Does list exist? Testing head item: %s", (char *)list->head->item);
    printf("Does list exist?: %p \n", list);
    return 0;
}