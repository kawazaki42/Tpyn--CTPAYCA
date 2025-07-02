/**
 * @file
 * @author  Николай Ковалев
 * 
 * @details
 *     (533) Даны натуральное число n, действительные числа x1, ...xn.
 *           Вычислить:
 *        Б) (x[1] + x[n])(x[2] + x[n-1])...(x[n] + x[1])
 * 
 * Ссылка:
 *     https://ivtipm.github.io/Programming/Glava14/index14.htm#z533
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
    head = tail = NULL;  // изначально пусты

    printf_s("Введите %zu вещественных чисел через пробел:\n", n);

    // Заполнение списка
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
        float x = cur->data;
        sum += x*x;
    }

    printf_s("Сумма квадратов посл-ти: %.2f\n", sum);

    SLList_delete(head);
    head = tail = NULL;  // Избегаем висячих указателей
    return EXIT_SUCCESS;
}