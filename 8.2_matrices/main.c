/**
 * @file
 * @brief   Задача 703
 * @author  Николай Ковалев
 * @details Даны квадратная матрица `A` порядка `n`,
 *          векторы `x` и `у` с `n` элементами.
 *          Получить вектор `A(x+y)`.
 * Ссылка:  https://ivtipm.github.io/Programming/Glava21/index21.htm#z703
 */

#include <stdio.h>   // printf, scanf
#include <locale.h>  // setlocale
#include <stdlib.h>  // EXIT_SUCCESS
#include "arrays.h"  // arrays, matrices


array_of_float read_array_of_float(size_t size) {
    array_of_float result = new_array_of_float(size);
    for(size_t i = 0; i < size; i++) {
        scanf_s("%f", &result[i]);
    }
    return result;
}


matrix_of_float read_matrix_of_float(size_t nrows, size_t ncols) {
    matrix_of_float result = new_matrix_of_float(nrows, ncols);
    for(size_t i = 0; i < nrows; i++) {
        for(size_t j = 0; j < ncols; j++) {
            scanf_s("%f", &result[i][j]);
        }
    }
    return result;
}


float dot_product(array_of_float a, array_of_float b, size_t size) {
    float sum = 0.0;
    for(size_t i = 0; i < size; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}


array_of_float multiply_mat_vec(matrix_of_float m, array_of_float x, size_t size) {
    array_of_float result = new_array_of_float(size);
    for(size_t i = 0; i < size; i++) {
        result[i] = dot_product(m[i], x, size);
    }
    return result;
}


void vec_add_inplace(array_of_float a, array_of_float b, size_t size) {
    for(size_t i = 0; i < size; i++) {
        a[i] += b[i];
    }
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

    printf("Для каждого вектора введите %d"
           " действительных чисел через пробел:\n",
           mat_order);

    printf("Вектор x: ");
    array_of_float x = read_array_of_float(mat_order);

    printf("Вектор y: ");   
    array_of_float y = read_array_of_float(mat_order);
    
    putchar('\n');
    printf("Матрица A (%dx%d)\n", mat_order, mat_order);
    printf("Введите действительне числа через пробел.\n");
    matrix_of_float A = read_matrix_of_float(mat_order, mat_order);


    vec_add_inplace(x, y, mat_order);
    free(y);

    y = multiply_mat_vec(A, x, mat_order);


    putchar('\n');

    printf("A(x + y) = (");

    for(size_t i = 0; i < mat_order-1; i++)
        printf("%8.2f, ", y[i]);

    printf("%8.2f)\n", y[mat_order-1]);
    

    free(x);
    free(y);
    delete_matrix_of_float(A, mat_order);
    x = y = NULL;
    A = NULL;

    return EXIT_SUCCESS;
}