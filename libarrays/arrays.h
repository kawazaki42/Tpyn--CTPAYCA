#pragma once

#include <stdlib.h>

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
 * @brief Двумерный динамический массив (матрица)
 */
typedef array *matrix;


array new_array(size_t size);
matrix new_matrix(size_t nrows, size_t ncols);
void delete_matrix(matrix m, size_t nrows);