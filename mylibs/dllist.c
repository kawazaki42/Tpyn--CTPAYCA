#include <stdlib.h>  // malloc, free, NULL
#include <assert.h>  // assert
#include "dllist.h"

struct DLList_node *DLList_new_head(struct DLList_node *old_head, float data) {
    struct DLList_node *new_head = malloc(sizeof *new_head);
    new_head->data = data;
    new_head->next = old_head;
    new_head->prev = NULL;  // у головы нет предыдущего
    
    if(old_head != NULL) {
        // old_head->data = old_head->data;  // не меняем
        // old_head->next = old_head->next;  // не меняем
        assert(old_head->prev == NULL);  // у головы нет предыдущего
        old_head->prev = new_head;
    }

    return new_head;
}


struct DLList_node *DLList_new_tail(struct DLList_node *old_tail, float data) {
    struct DLList_node *new_tail = malloc(sizeof *new_tail);
    new_tail->data = data;
    new_tail->next = NULL;  // у хвоста нет следующего
    new_tail->prev = old_tail;
    
    if(old_tail != NULL) {
        // old_tail->data = old_tail->data;  // не меняем
        assert(old_tail->next == NULL);  // у хвоста нет следующего
        old_tail->next = new_tail;
        // old_tail->prev = old_tail->prev;  // не меняем
    }

    return new_tail;
}


void DLList_delete(struct DLList_node *head) {
    if(!head) return;  // Пустой список

    assert(head->prev == NULL);  // у головы нет предыдущего

    /// Итератор цикла
    struct DLList_node *cur;

    /// Сохраненное значение `cur->next`.
    ///
    /// После `free(cur)` он недоступен напрямую
    /// (`cur->next` вызовет ошибку).
    struct DLList_node *cur_next_saved;

    for(cur = head; cur != NULL; cur = cur_next_saved) {
        cur_next_saved = cur->next;  // сохранить cur->next 
        free(cur);        
    }
    
    // cur = head;
    // while(cur != NULL) {
    //     cur_next_saved = cur->next;
    //     free(cur);

    //     cur = cur_next_saved;
    // }
}