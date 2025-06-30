/**
 * @file
 * @brief   Задача 692-Д
 * @author  Николай Ковалев
 * Задача: Дана действительная квадратная матрица порядка n.
 *         Найти наибольшее из значений элементов,
 *         расположенных в заштрихованной части матрицы.
 *         ('песочные часы', см. рисунок в задачнике)
 * Ссылка: https://ivtipm.github.io/Programming/Glava20/index20.htm#z692
 */

#include <stdio.h>    // printf, scanf
#include <stdlib.h>   // malloc, free, exit
#include <stdbool.h>  // bool, true, false
#include <locale.h>   // setlocale
#include "arrays.h"   // matrices


/**
 * @brief Находится ли элемент матрицы над главной диагональю?
 * 
 * @param i индекс строки матрицы
 * @param j индекс столбца матрицы
 * 
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
 * 
 * @param i индекс строки матрицы
 * @param j индекс столбца матрицы
 * @param order порядок квадратной матрицы
 * 
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
 * 
 * @param i индекс строки матрицы
 * @param j индекс столбца матрицы
 * 
 * @param order порядок квадратной матрицы
 * 
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
 * @brief Найти наибольший элемент заштрихованной области квадратной матрицы
 *        (см. `in_area`, задачник)
 * @param m квадратная матрица из действительных чисел
 * @param mat_order порядок квадратной матрицы `m`
 * @return Наибольший вещественный элемент заштрихованной области
 */
float max_conditioned(matrix_of_float m, size_t mat_order) {
    float tempmax = m[0][0];
    
    for(size_t i = 0; i < mat_order; i++) {
        for(size_t j = 0; j < mat_order; j++) {
            if( in_area(i, j, mat_order) ) {
                // Для каждого элемента матрицы, входящего в область,
                // сравниваем с временным максимумом.
                // Сохраняем в `tempmax` тот, что окажется больше.
                if(m[i][j] > tempmax) {
                    tempmax = m[i][j];
                }
            }
        }
    }

    return tempmax;
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


    // Ввод данных

    /// Порядок матрицы
    int mat_order;
    printf("Порядок матрицы (n): ");
    scanf_s("%i", &mat_order);

    matrix_of_float m = new_matrix_of_float(mat_order, mat_order);
    printf("Введите %dx%d (%d) действительных чисел через пробел:\n",
           mat_order, mat_order, mat_order*mat_order);

    // Считываем `n` x `n` целых чисел в массив
    for(size_t i = 0; i < mat_order; i++) {
        for(size_t j = 0; j < mat_order; j++) {
            scanf_s("%f", &m[i][j]);
        }
    }


    // Вывод

    // Вывести входную матрицу (для лучшей читаемости)
    putchar('\n');
    print_matrix_of_float(m, mat_order, mat_order);
    putchar('\n');

    // Ответ на задачу
    printf("Наибольший элемент в области: %8.2f\n", max_conditioned(m, mat_order) );


    // Завершение

    delete_matrix_of_float(m, mat_order);

    return EXIT_SUCCESS;
}