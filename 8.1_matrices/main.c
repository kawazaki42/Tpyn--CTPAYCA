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
#include <stdlib.h>   // malloc, free, exit
#include <stdbool.h>  // bool, true, false
#include <locale.h>   // setlocale
#include "arrays.h"


/**
 * @brief Находится ли элемент матрицы над главной диагональю?
 * @param i индекс строки матрицы
 * @param j индекс столбца матрицы
 * @return `true` - если элемент над главной диагональю
 * 
 *         `false` - в противном случае
 */
bool above_diag_main(size_t i, size_t j) {
    if(j > i) {
        return true;
    }

    return false;
}


/**
 * @brief Находится ли элемент квадратной матрицы над побочной диагональю?
 * @param i индекс строки матрицы
 * @param j индекс столбца матрицы
 * @param order порядок квадратной матрицы
 * @return `true` - если элемент над побочной диагональю
 * 
 *         `false` - в противном случае
 */
bool above_diag_anti(size_t i, size_t j, size_t order) {
    // i: 0..order-1
    // order-1 - 0 == order-1
    // ...
    // order-1 - (order-1) == 0
    if(j < order-1 - i) {
        return true;
    }
    
    return false;
}


/**
 * @brief Находится ли элемент матрицы в области, указанной в задаче?
 * @param i индекс строки матрицы
 * @param j индекс столбца матрицы
 * @param order порядок квадратной матрицы
 * @return `true` - если элемент в области
 * 
 *         `false` - в противном случае
 */
bool in_area(size_t i, size_t j, size_t order) {
    if (i == j)
        // На главной диагонали
        return true;

    if (order-1 - i == j)
        // На побочной диагонали
        return true;

    bool main = above_diag_main(i, j);
    bool anti = above_diag_anti(i, j, order);
    return !(main ^ anti);
    // `^` - операция исключающего ИЛИ (XOR)
    // Другими словами, элемент _не_ входит в область если
    // он выше только одной из диагоналей
}

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

    matrix_of_float m = new_matrix_of_float(mat_order, mat_order);
    /// Первая линейка матрицы (после единиц)
    array_of_float x = new_array_of_float(mat_order);

    // printf("Введите %dx%d (%d) действительных чисел через пробел:\n",
    //        mat_order, mat_order, mat_order*mat_order);

    printf("Введите %d действительных чисел через пробел:\n", mat_order);    

    // Считываем `n` целых чисел в массив
    for(size_t i = 0; i < mat_order; i++) {
        scanf_s("%f", &x[i]);
    }

    // float tempmax = m[0][0];
    // for(size_t i = 0; i < mat_order; i++) {
    //     for(size_t j = 0; j < mat_order; j++) {
    //         if( in_area(i, j, mat_order) ) {
    //             // Для каждого элемента матрицы, входящего в область,
    //             // сравниваем с временным максимумом.
    //             // Сохраняем в `tempmax` тот, что окажется больше.
    //             if(m[i][j] > tempmax) {
    //                 tempmax = m[i][j];
    //             }
    //         }
    //     }
    // }

    // Заполнить первую строку матрицы единицами
    // По условиям задачи
    for(size_t i = 0; i < mat_order; i++)
        m[0][i] = 1.0;

    // Начиная со второй строки, умножать на x[j]
    for(size_t i = 1; i < mat_order; i++) {
        for(size_t j = 0; j < mat_order; j++) {
            m[i][j] = m[i-1][j] * x[j];
        }
    }

    putchar('\n');
    // printf("%f\n", tempmax);

    for(size_t i = 0; i < mat_order; i++) {
        for(size_t j = 0; j < mat_order; j++) {
            printf("%8.2f ", m[i][j]);
        }
        putchar('\n');
    }

    delete_matrix_of_float(m, mat_order);

    return EXIT_SUCCESS;
}