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
#include <stdio.h>   // scanf, printf
#include <locale.h>  // setlocale
#include "sllist.h"  // SLList_* (односвязные списки)

int main() {
    // Установить кодировку UTF-8
    // Локаль США (для разделителя-точки)
    setlocale(LC_ALL, "en_US.UTF8");

    /// Кол-во элементов
    size_t n;
    printf_s("Кол-во элементов (n): ");
    scanf_s("%zu", &n);  // u - беззнаковый,
                         // z - длиной с size_t


    // Односвязный список из вещественных чисел

    /// Голова (первый элемент)
    struct SLList_node *head;
    /// Хвост (последний элемент)
    struct SLList_node *tail;
    head = tail = NULL;  // изначально список пуст

    printf_s("Введите %zu вещественных чисел через пробел:\n", n);

    // Заполнение списка
    for(size_t i = 0; i < n; i++) {
        float data;
        scanf_s("%f", &data);

        // Добавление в конец (append)
        tail = SLList_new_tail(tail, data);

        if(i == 0)
            // иначе голова останется NULL
            head = tail;
    }

    
    /// Итератор цикла
    struct SLList_node *cur;
    float sum = 0.0;
    for(
        cur = head;
        cur != NULL;
        cur = cur->next
    ) {
        float x = cur->data;
        sum += x*x;  // x^2
    }

    printf_s("Сумма квадратов посл-ти: %.2f\n", sum);

    SLList_delete(head);
    head = tail = NULL;  // Избегаем висячих указателей
    return EXIT_SUCCESS;
}