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


    // Ввод данных

    /// Порядок матрицы, размерность векторов
    int mat_order;
    // printf("Размерность линейного пространства (n): ");
    printf("Порядок матрицы (n): ");
    scanf_s("%i", &mat_order);

    putchar('\n');
    printf("Введите %d действительных чисел (%dx%d).\n",
           mat_order*mat_order, mat_order, mat_order);

    printf("(Разделители - пробел и перевод строки)\n");
    putchar('\n');
    printf("Матрица A:\n");
    matrix_of_float A = read_matrix_of_float(mat_order, mat_order);

    putchar('\n');
    printf("Для каждого вектора введите n действительных чисел\n");

    printf("(Разделитель - пробел)\n");
    
    printf("(n = %d)\n", mat_order);

    putchar('\n');
    printf("Вектор x: ");
    array_of_float x = read_array_of_float(mat_order);

    printf("Вектор y: ");   
    array_of_float y = read_array_of_float(mat_order);
    

    // Вычисления
    vec_add_inplace(x, y, mat_order);
    free(y);
    y = multiply_mat_vec(A, x, mat_order);


    // Вывод

    putchar('\n');
    printf("A(x + y) = (");

    // Все элементы, кроме последнего, через запятую
    for(size_t i = 0; i < mat_order-1; i++)
        printf("%.2f, ", y[i]);

    printf("%.2f)", y[mat_order-1]);  // последний
    putchar('\n');
    

    // Завершение
    free(x);
    free(y);
    delete_matrix_of_float(A, mat_order);
    x = y = NULL;
    A = NULL;

    return EXIT_SUCCESS;
}