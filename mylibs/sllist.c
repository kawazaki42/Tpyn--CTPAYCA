#include <stdlib.h>  // malloc, free, NULL
#include "sllist.h"

struct SLList_node *SLList_new_head(struct SLList_node *old_head, float data) {
    struct SLList_node *result = malloc(sizeof *result);
    result->data = data;
    result->next = NULL;
    return result;
}


struct SLList_node *SLList_new_tail(struct SLList_node *old_tail, float data) {
    struct SLList_node *result = malloc(sizeof *result);
    result->data = data;
    result->next = NULL;
    if(old_tail != NULL)
        old_tail->next = result;
    return result;
}


void SLList_delete(struct SLList_node *head) {
    if(!head) return;

    struct SLList_node *cur, *next;

    // for(cur = head; cur != NULL; cur = next)  // не подходит.
    
    cur = head;
    while(cur != NULL) {
        next = cur->next;
        free(cur);

        cur = next;
    }
}