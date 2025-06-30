#pragma once

#include <stdlib.h>

// Псевдонимы типов

// /**
//  * @brief Элемент массива
//  * 
//  * (`float`)
//  */
// typedef float float;

/**
 * @brief Динамический массив из элементов
 * 
 * `array` = `elem *` = `float *`
 */
typedef float *array_of_float;

/**
 * @brief Двумерный динамический массив (матрица)
 */
typedef array_of_float *matrix_of_float;


array_of_float new_array(size_t size);
matrix_of_float new_matrix(size_t nrows, size_t ncols);
void delete_matrix(matrix_of_float m, size_t nrows);