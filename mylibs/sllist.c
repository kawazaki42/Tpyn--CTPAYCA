#include <stdlib.h>  // malloc, free, NULL
#include "sllist.h"


/**
 * @brief Добавить элемент в начало списка (перед головой).
 * @param old_head текущая голова списка
 * @param data вещественное число (`float`) для добавления
 * @return Новую голову списка
 * 
 * Следует сохранить новую голову списка, например:
 * 
 * ```c
 *     head = SLList_new_head(head, 3.14);
 * ```
 * 
 *     Иначе она будет потеряна.
 */
struct SLList_node *SLList_new_head(
    struct SLList_node *old_head,
    float data
) {
    struct SLList_node *result = malloc(sizeof *result);
    result->data = data;
    result->next = old_head;  // Возможно, NULL

    return result;
}


/**
 * @brief Добавить элемент в конец списка (после хвоста).
 *   ```c
 *       tail = SLList_new_tail(tail, 3.14);
 *  ```
 * @param old_tail текущий хвост списка
 * @param data вещественное число (`float`) для добавления
 * @return Новый хвост списка
 * @note
 *     Следует сохранить новый хвост списка, например:
 * 
 *     Иначе придется искать 
 */
struct SLList_node *SLList_new_tail(
    struct SLList_node *old_tail,
    float data
) {
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