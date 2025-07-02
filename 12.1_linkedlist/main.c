/**
 * @file
 * @author  Николай Ковалев
 * 
 * @details (136) Даны натуральное число n, действительные числа a1,..., an.
 *                Вычислить:
 *             Д) a1^2 + ... + an^2;
 * 
 * Ссылка:
 *     https://ivtipm.github.io/Programming/Glava06/index06.htm#z136
 */

#include <stdlib.h>  // EXIT_SUCCESS
#include <stdio.h>
#include <locale.h>  // setlocale
#include "sllist.h"

int main() {
    // Установить кодировку UTF-8
    // Локаль США (для разделителя-точки)
    setlocale(LC_ALL, "en_US.UTF8");

    /// Кол-во элементов
    size_t n;
    printf_s("Кол-во элементов (n): ");
    scanf_s("%zu", &n);  // u - беззнаковый,
                         // z - длиной с size_t

    struct SLList_node *head, *tail;
    head = tail = NULL;

    for(size_t i = 0; i < n; i++) {
        float data;
        scanf_s("%f", &data);

        tail = SLList_new_tail(tail, data);

        if(i == 0)
            head = tail;
    }

    
    float sum = 0.0;
    for(
        struct SLList_node *cur = head;
        cur != NULL;
        cur = cur->next
    ) {
        sum += cur->data * cur->data;
    }

    printf_s("%.2f\n", sum);

    SLList_delete(head);
    return EXIT_SUCCESS;
}