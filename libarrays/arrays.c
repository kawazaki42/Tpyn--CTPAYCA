#include "arrays.h"

#include <stdio.h>
#include <stdlib.h>  // free, calloc

/**
 * @brief Выделить новый динамический массив из `size` элеметнов типа `float`
 * @param size кол-во элементов в массиве
 * @return Указатель на выделенную память (динамический массив)
 */
array_of_float new_array_of_float(size_t size) {
    array_of_float result = calloc(size, sizeof(float));
    if (result == NULL) {
        // Если не удалось выделить память, завершить программу с ошибкой.
        puts("Не удалось выделить память.");
        exit(EXIT_FAILURE);
    }
    
    // Иначе вернуть указатель.
    return result;
}

/**
 * @brief Выделить новый динамический массив из `size` элеметнов типа `int`
 * @param size кол-во элементов в массиве
 * @return Указатель на выделенную память (динамический массив)
 */
array_of_int new_array_of_int(size_t size) {
    array_of_int result = calloc(size, sizeof(int));
    if (result == NULL) {
        // Если не удалось выделить память, завершить программу с ошибкой.
        puts("Не удалось выделить память.");
        exit(EXIT_FAILURE);
    }
    
    // Иначе вернуть указатель.
    return result;
}


/**
 * @brief Выделить новый динамический двумерный массив (матрицу)
 *        из элеметнов типа `elem`
 * @param nrows кол-во строк
 * @param ncols кол-во столбцов
 * @return Указатель на выделенную память (динамический двумерный массив)
 */
matrix_of_float new_matrix_of_float(size_t nrows, size_t ncols) {
    // Выделяем массив указателей
    matrix_of_float result = calloc(nrows, sizeof(array_of_float));
    if(result == NULL) {
        // Если не удалось выделить память, завершить программу с ошибкой.
        puts("Не удалось выделить память.");
        exit(EXIT_FAILURE);
    }

    // Заполняем массив указателями на память других массивов
    for(size_t i = 0; i < nrows; i++) {
        // result[i] = calloc(ncols, sizeof(elem));
        result[i] = new_array_of_float(ncols);
    }

    return result;
}


/**
 * @brief Очистить матрицу
 * @param m матрица
 * @param nrows кол-во строк в матрице
 */
void delete_matrix_of_float(matrix_of_float m, size_t nrows) {
    for(size_t i = 0; i < nrows; i++) {
        // Очистить память каждой строки
        free(m[i]);
        m[i] = NULL;  // Избегаем висячих указателей
    }

    free(m);  // Очищаем массив указателей
}
