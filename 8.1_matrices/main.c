/**
 * @file
 * @brief   Задача 378-Б
 * @author  Николай Ковалев
 * @details Даны действительные числа x1, ..., x8.
 *          Получить действительную квадратную матрицу порядка 8:
 *           1    1   ...  1
 *          x1   x2   ... x8
 *          .... .... ... ....
 *          x1^7 x2^7 ... x8^7
 * Ссылка:  https://ivtipm.github.io/Programming/Glava11/index11.htm#z378
 */

#include <stdio.h>    // printf, scanf
#include <locale.h>   // setlocale
#include "arrays.h"


/**
 * @brief Главная процедура
 * 
 * @return `EXIT_SUCCESS` (или 0) при успешном завершении
 * 
 *         `EXIT_FAILURE` при ошибке (напр. нехватка памяти)
 */
int main() {
    // Установить кодировку UTF-8
    // Локаль США (для разделителя-точки)
    setlocale(LC_ALL, "en_US.UTF8");

    /// Порядок матрицы
    int mat_order;
    printf("Порядок матрицы (n): ");
    scanf_s("%i", &mat_order);

    /// Первая линейка матрицы (после единиц)
    array_of_float x = new_array_of_float(mat_order);
    
    printf("Введите %d действительных чисел через пробел:\n", mat_order);    
    
    // Считываем `n` целых чисел в массив
    for(size_t i = 0; i < mat_order; i++) {
        scanf_s("%f", &x[i]);
    }
    
    matrix_of_float m = new_matrix_of_float(mat_order, mat_order);

    // Заполнить первую строку матрицы единицами
    // По условиям задачи
    for(size_t i = 0; i < mat_order; i++)
        m[0][i] = 1.0;

    // Каждая строка, начиная со второй, равна
    // предыдущей, поэлементно умноженной на x
    for(size_t i = 1; i < mat_order; i++) {
        for(size_t j = 0; j < mat_order; j++) {
            m[i][j] = m[i-1][j] * x[j];
        }
    }

    putchar('\n');  // Отделить вывод пустой строкой

    // Вывод матрицы
    for(size_t i = 0; i < mat_order; i++) {
        for(size_t j = 0; j < mat_order; j++) {
            printf("%8.2f ", m[i][j]);
        }
        putchar('\n');
    }

    delete_matrix_of_float(m, mat_order);

    return EXIT_SUCCESS;
}