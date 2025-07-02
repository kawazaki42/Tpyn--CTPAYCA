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
#include <stdio.h>   // printf, scanf
#include <locale.h>  // setlocale
#include <assert.h>  // assert
#include "dllist.h"

int main() {
    // Установить кодировку UTF-8
    // Локаль США (для разделителя-точки)
    setlocale(LC_ALL, "en_US.UTF8");

    /// Кол-во элементов
    size_t n;
    printf_s("Кол-во элементов (n): ");
    scanf_s("%zu", &n);  // u - беззнаковый,
                         // z - длиной с size_t

    struct DLList_node *head, *tail;
    head = tail = NULL;  // изначально пусты

    printf_s("Введите %zu вещественных чисел через пробел:\n", n);

    // Заполнение списка
    for(size_t i = 0; i < n; i++) {
        float data;
        scanf_s("%f", &data);

        tail = DLList_new_tail(tail, data);

        if(i == 0)
            head = tail;
    }

    
    /// Итераторы цикла
    struct DLList_node *a, *b;
    float prod = 1.0;
    for(
        a = head, b = tail;
        a != NULL;
        a = a->next, b = b->prev
    ) {
        prod *= a->data + b->data;
    }
    assert(a == NULL);
    assert(b == NULL);

    printf_s("Произведение сумм: %.2f\n", prod);

    DLList_delete(head);
    head = tail = NULL;  // Избегаем висячих указателей
    return EXIT_SUCCESS;
}