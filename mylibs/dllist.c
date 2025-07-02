/**
 * @file
 * @brief   Двусвязный список. Реализация
 * @author  Николай Ковалев
 */

#include <stdlib.h>  // malloc, free, NULL
#include <assert.h>  // assert
#include "dllist.h"


/**
 * @brief Добавить элемент в начало списка (перед головой).
 * @param old_head текущая голова списка
 *                 (`NULL`, если требуется создать список)
 * @param data вещественное число (`float`) для добавления
 * @return Новую голову списка
 * @note
 *   Для дальнейшей работы с началом списка рекомендуется
 *   сохранить новую голову, например:
 *   ```c
 *       head = DLList_new_head(head, 3.14);
 *   ```
 *   Ее можно будет получить при помощи цикла, но делать это
 *   несколько раз, например в цикле, будет затратно по времени.
 */
struct DLList_node *DLList_new_head(
    struct DLList_node *old_head,
    float data
) {
    // Создание узла
    struct DLList_node *new_head = malloc(sizeof *new_head);
    // Заполнение полей
    new_head->data = data;
    new_head->next = old_head;
    new_head->prev = NULL;  // у головы нет предыдущего
    
    if(old_head != NULL) {
        // old_head->data;  // не меняем
        // old_head->next;  // не меняем

        assert(old_head->prev == NULL);  // у головы нет предыдущего
        old_head->prev = new_head;
    }

    return new_head;
}


/**
 * @brief Добавить элемент в конец списка (после хвоста).
 * @param old_tail текущий хвост списка
 *                 (`NULL`, если требуется создать список)
 * @param data вещественное число (`float`) для добавления
 * @return Новый хвост списка
 * @note
 *   Для дальнейшей работы с концом списка рекомендуется
 *   сохранить новый хвост, например:
 *   ```c
 *       tail = DLList_new_tail(tail, 3.14);
 *   ```
 *   Его можно будет получить при помощи цикла, но делать это
 *   несколько раз, например в цикле, будет затратно по времени.
 */
struct DLList_node *DLList_new_tail(
    struct DLList_node *old_tail,
    float data
) {
    // Создание узла
    struct DLList_node *new_tail = malloc(sizeof *new_tail);
    // Заполнение полей
    new_tail->data = data;
    new_tail->next = NULL;  // у хвоста нет следующего
    new_tail->prev = old_tail;
    
    if(old_tail != NULL) {
        // old_tail->data;  // не меняем
        // old_tail->prev;  // не меняем
        
        assert(old_tail->next == NULL);  // у хвоста нет следующего
        old_tail->next = new_tail;
    }

    return new_tail;
}


/**
 * @brief Очистить всю память, занимаемую списком.
 * @param head голова (первый элемент) списка.
 *             Если `NULL`, список пуст; действий не производится.
 * @details Итеративная (не рекурсивная) реализация
 */
void DLList_delete(struct DLList_node *head) {
    if(!head)
        // Пустой список
        return;

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
}