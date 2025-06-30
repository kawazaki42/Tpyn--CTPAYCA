#pragma once

#include <stddef.h>  // size_t

// Псевдонимы типов

/**
 * @brief Динамический массив из элементов
 * 
 * `array_of_int` = `elem *` = `float *`
 */
typedef float *array_of_float;

/**
 * @brief Динамический массив из элементов
 * 
 * `array_of_int` = `elem *` = `float *`
 */
typedef int *array_of_int;

/**
 * @brief Двумерный динамический массив (матрица)
 */
typedef array_of_float *matrix_of_float;


array_of_int new_array_of_int(size_t size);

array_of_float new_array_of_float(size_t size);
array_of_float read_array_of_float(size_t size);

matrix_of_float new_matrix_of_float(size_t nrows, size_t ncols);
void delete_matrix_of_float(matrix_of_float m, size_t nrows);

matrix_of_float read_matrix_of_float(size_t nrows, size_t ncols);
void print_matrix_of_float(matrix_of_float m, size_t nrows, size_t ncols);