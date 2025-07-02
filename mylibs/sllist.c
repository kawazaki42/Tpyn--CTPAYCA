/**
 * @file
 * @brief   Односвязный список. Реализация
 * @author  Николай Ковалев
 */

#include <stdlib.h>  // malloc, free, NULL
#include "sllist.h"


/**
 * @brief Добавить элемент в начало списка (перед головой).
 * @param old_head текущая голова списка
 *                 (`NULL`, если требуется создать список)
 * @param data вещественное число (`float`) для добавления
 * @return Новую голову списка
 * 
 * @note
 *   Следует сохранить новую голову списка, например:
 *   ```c
 *       head = SLList_new_head(head, 3.14);
 *   ```
 *   Иначе она будет потеряна.
 */
struct SLList_node *SLList_new_head(
    struct SLList_node *old_head,
    float data
) {
    // Создание узла
    struct SLList_node *result = malloc(sizeof *result);
    result->data = data;
    result->next = old_head;  // Возможно, NULL

    return result;
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
 *       tail = SLList_new_tail(tail, 3.14);
 *   ```
 *   Его можно будет получить при помощи цикла, но делать это
 *   несколько раз, например в цикле, будет затратно по времени.
 */
struct SLList_node *SLList_new_tail(
    struct SLList_node *old_tail,
    float data
) {
    // Создание узла
    struct SLList_node *result = malloc(sizeof *result);
    result->data = data;
    result->next = NULL;

    if(old_tail != NULL)
        old_tail->next = result;
    // Иначе список был пуст.

    return result;
}


/**
 * @brief Очистить всю память, занимаемую списком.
 * @param head голова (первый элемент) списка.
 *             Если `NULL`, список пуст; действий не производится.
 * @details Итеративная (не рекурсивная) реализация
 */
void SLList_delete(struct SLList_node *head) {
    if(!head)  // пустой список
        return;

    /// Итератор цикла
    struct SLList_node *cur;

    /// Сохраненное значение `cur->next`.
    ///
    /// После `free(cur)` `cur->next` недоступен напрямую
    /// (ошибка доступа к освобожденной памяти).
    struct SLList_node *next;

    for(cur = head; cur != NULL; cur = next) {
        next = cur->next;
        free(cur);
    }
}