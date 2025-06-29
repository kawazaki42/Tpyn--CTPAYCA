/**
 * @file
 * @brief   Задача 339-Б
 * @author  Николай Ковалев
 * Задача: Даны целые числа a[1..n]
 *         (в этой последовательности могут быть повторяющиеся члены).
 *         Б) Получить числа, взятые по одному из каждой группы равных членов.
 * Ссылка: https://ivtipm.github.io/Programming/Glava10/index10.htm#z339
 */

#include <stdio.h>    // printf, scanf
#include <stdlib.h>   // malloc, free, exit
#include <stdbool.h>  // bool, true, false
#include <locale.h>   // setlocale


// Псевдонимы типов

/**
 * @brief Элемент массива
 * 
 * (`float`)
 */
typedef float elem;
/**
 * @brief Динамический массив из элементов
 * 
 * `array` = `elem *` = `float *`
 */
typedef elem *array;


/**
 * @brief Выделить новый динамический массив из `size` элеметнов типа `elem`
 * @param size кол-во элементов в массиве
 * @return Указатель на выделенную память (динамический массив)
 */
array new_array(size_t size) {
    array result = calloc(size, sizeof(elem));
    if (result == NULL) {
        // Если не удалось выделить память, завершить программу с ошибкой.
        puts("Не удалось выделить память.");
        exit(EXIT_FAILURE);
    }
    
    // Иначе вернуть указатель.
    return result;
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

    int a_size;  ///< Кол-во элементов в `a`
    printf("Кол-во элементов (n): ");
    scanf("%i", &a_size);

    array a = new_array(a_size);  // Выделяем память

    printf("Введите %d чисел через пробел:\n", a_size);

    // Считываем `n` целых чисел в массив
    for(size_t i = 0; i < a_size; i++) {
        scanf("%f", &a[i]);
    }

    /// Массив для уникальных элементов из `a`
    array uniq = new_array(a_size); 
    // выделим столько же памяти, сколько для `a`.
    // NOTE: избыточно, но гарантированно достаточно.                                 

    /// @brief Действительное кол-во элементов, хранимых в массиве.
    /// 
    /// uniq_realsize <= a_size
    size_t uniq_realsize = 0;

    // Обрабатываем каждый элемент в `a`
    for(size_t i = 0; i < a_size; i++) {
        /// Найден ли пока дубликат `a[i]` в uniq?
        bool found_copy_of_a_i = false;

        // Пытаемся найти a[i] в uniq.
        for(size_t j = 0; j < uniq_realsize; j++) {
            // Каждый элемент в `uniq` сравниваем с текущим `a[i]`.
            if (a[i] == uniq[j]) {
                // Если в `uniq` он уже есть, то...
                found_copy_of_a_i = true;  // ...запоминаем это...
                // ...и прекращаем проверку на вхождение,
                // т.к. результат уже ясен.
                break;                     
            }
        }

        // Если `a[i]` уже входит в `uniq`, прекратить проверку и пропустить
        if (!found_copy_of_a_i) {
            uniq[uniq_realsize] = a[i];
            uniq_realsize++;
        }
    }

    // Вывод уникальных элементов

    for(size_t j = 0; j < uniq_realsize; j++) {
        // Через пробел, 2 знака после запятой (точки)
        printf("%.2f ", uniq[j]);
    }

    putchar('\n');  // перевод строки в конце файла

    // Освобождение памяти

    // free - Системный вызов для освобождения
    // Присваиваем NULL для избежания висячих указателей

    free(a);
    a = NULL;

    free(uniq);
    uniq = NULL;

    return EXIT_SUCCESS;
}