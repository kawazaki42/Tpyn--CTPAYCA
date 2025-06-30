/**
 * @file
 * 
 * @brief   Задача 447
 * 
 * @author  Николай Ковалев
 * 
 * @details Дано натуральное число n, целые числа a[1..n].
 * 
 *          Рассмотреть все отрезки последовательности a[1..n]
 *          (см. задачу 440), состоящие из совершенных чисел.
 *          (Определить процедуру, позволяющую распознавать
 *           совершенные числа).
 * 
 *          Отрезки последовательности - подпоследовательности идущих подряд членов.
 * 
 * Ссылка: https://ivtipm.github.io/Programming/Glava12/index12.htm#z447
 */

#include <stdio.h>    // printf, scanf
#include <stdlib.h>   // malloc, free, exit
#include <stdbool.h>  // bool, true, false
#include <locale.h>   // setlocale
#include "arrays.h"


// Псевдонимы типов

// /**
//  * @brief Элемент массива
//  * 
//  * (`float`)
//  */
// typedef int elem;


/**
 * @brief   Проверить, совершенное ли число.
 * 
 * @details Совершенное число - натуральное число, равное
 *          сумме всех cвоих положительных делителей,
 *          включая 1, но не включая само число.
 * 
 *          Например,  6 = 1 + 2 + 3
 *                    28 = 1 + 2 + 4 + 7 + 14
 * 
 * @param   x число для проверки
 * 
 * @return  `true`  - если `x` совершенное
 * 
 *          `false` - в противном случае
 */
bool is_perfect(int x) {
    // Ненатуральное
    if(x < 1) return false;

    int sum = 0;
    for(int i = 1; i < x; i++) {  // [1, x) (не включая x !)
        if(x % i == 0) {
            // Добавляем i в сумму только если x делится на i
            // т.е. i - делитель x
            sum += i;
        }
    }

    if(sum == x) {
        return true;
    }

    return false;
}


/**
 * @brief Главная процедура
 * @return `EXIT_SUCCESS` (или 0) при успешном завершении
 * 
 *         `EXIT_FAILURE` при ошибке (напр. нехватка памяти)
 */
int main() {
    // Установить кодировку UTF-8
    // Локаль США (для разделителя-точки)
    setlocale(LC_ALL, "en_US.UTF8");

    /// Кол-во элементов в `a`
    int a_size;
    printf("Кол-во элементов (n): ");
    scanf_s("%i", &a_size);

    array_of_int a = new_array_of_int(a_size);  // Выделяем память

    printf("Введите %d целых чисел через пробел:\n", a_size);

    // Считываем `n` целых чисел в массив
    for(size_t i = 0; i < a_size; i++) {
        scanf_s("%i", &a[i]);
    }

    /// Находимся ли мы внутри отрезка?
    bool in_subseq = false;
    for(size_t i = 0; i < a_size; i++) {
        if(!in_subseq && is_perfect(a[i])) {
            // Вошли в отрезок
            printf("{ %i ", a[i]);
            in_subseq = true;
        } else
        if( in_subseq && !is_perfect(a[i]) ) {
            // Вышли из отрезка
            printf("} %i ", a[i]);
            in_subseq = false;
        } else {
            // Внутри / вне отрезка
            printf("%i ", a[i]);
        }
    }

    // Конец последовательности подразумевает конец отрезка
    if(in_subseq) printf("}");
    in_subseq = false;

    putchar('\n');

    free(a);
    a = NULL;

    return EXIT_SUCCESS;
}