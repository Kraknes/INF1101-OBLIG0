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


// funker
list_t *list_create(cmp_fn cmpfn) {
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    list->cmpfn = cmpfn;
    return list;
}
// funker, men bør ha en itererings funksjon for hver node istedenfor list->length
size_t list_length(list_t *list) {
    if (list->length == 0) {
        return 0;
    }
    return list->length;
}

// funker kanskje? 
void list_destroy(list_t *list, free_fn item_free) {

    free(list);
    free(item_free);
    printf("list destroyed \n");

}

// funker
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

// funker
int list_addlast(list_t *list, void *item) {
    lnode_t *last_node = malloc(sizeof(lnode_t));
    last_node->item = item;
    last_node->next = NULL;
    list->tail->next = last_node;
    list->tail = last_node;
    
    list->length++;
    return 0;
}


int main(){
    printf("yo \n");

    list_t *list = list_create((cmp_fn) strcmp);
    printf("List length before nodes is: %lu \n", list->length);
    list_addfirst(list, "dette er første node lagt til head");
    list_addfirst(list, "dette er andre node lagt til head");
    printf("List length after two head nodes added is: %lu \n", list->length);

    printf("Memory adress for head is: %p \n", list->head);
    printf("Item for head is: %s \n", (char *)list->head->item);
    printf("Memory adress for node nr.2 is: %p \n", list->head->next);
    printf("Item for tail si: %s \n", (char *)list->head->next->item);

    list_addlast(list, "tredje node lagt til listen til tail");
    printf("Memory adress for tail is: %p \n", list->tail);
    printf("Item for tail si: %s \n", (char *)list->tail->item);
    printf("List length after two head nodes and one tail added is: %lu \n", list->length);

    printf("size of list before destruction: %lu \n", sizeof(list));
    list_destroy(list, NULL);
    printf("size of list after destruction: %lu \n", sizeof(list));
    // printf("Does list exist? Testing head item: %s", (char *)list->head->item);
    printf("Does list exist?: %p \n", list);
    return 0;
}