/**
 * @file
 * @brief   Задача 692-Д
 * @author  Николай Ковалев
 * Задача: Дана действительная квадратная матрица порядка n.
 *         Найти наибольшее из значений элементов,
 *         расположенных в заштрихованной части матрицы.
 * Ссылка: https://ivtipm.github.io/Programming/Glava20/index20.htm#z692
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
 * @brief Двумерный динамический массив (матрица)
 */
typedef array *matrix;


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
 * @brief Выделить новый динамический двумерный массив (матрицу)
 *        из элеметнов типа `elem`
 * @param nrows кол-во строк
 * @param ncols кол-во столбцов
 * @return Указатель на выделенную память (динамический двумерный массив)
 */
matrix new_matrix(size_t nrows, size_t ncols) {
    // Выделяем массив указателей
    matrix result = calloc(nrows, sizeof(array));
    if(result == NULL) {
        // Если не удалось выделить память, завершить программу с ошибкой.
        puts("Не удалось выделить память.");
        exit(EXIT_FAILURE);
    }

    // Заполняем массив указателями на память других массивов
    for(size_t i = 0; i < nrows; i++) {
        // result[i] = calloc(ncols, sizeof(elem));
        result[i] = new_array(ncols);
    }

    return result;
}


/**
 * @brief Очистить матрицу
 * @param m матрица
 * @param nrows кол-во строк в матрице
 */
void delete_matrix(matrix m, size_t nrows) {
    for(size_t i = 0; i < nrows; i++) {
        // Очистить память каждой строки
        free(m[i]);
        m[i] = NULL;  // Избегаем висячих указателей
    }

    free(m);  // Очищаем массив указателей
}


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
 * @return `EXIT_SUCCESS` (или 0) при успешном завершении
 * 
 *         `EXIT_FAILURE` при ошибке (напр. нехватка памяти)
 */
int main() {
    // Установить кодировку UTF-8
    // Локаль США (для разделителя-точки)
    setlocale(LC_ALL, "en_US.UTF8");

    int mat_order;  ///< Кол-во элементов в `a`
    printf("Порядок матрицы (n): ");
    scanf("%i", &mat_order);

    // array a = new_array(mat_order);  // Выделяем память
    matrix m = new_matrix(mat_order, mat_order);

    printf("Введите %dx%d (%d) действительных чисел через пробел:\n",
           mat_order, mat_order, mat_order*mat_order);

    // Считываем `n` x `n` целых чисел в массив
    for(size_t i = 0; i < mat_order; i++) {
        for(size_t j = 0; j < mat_order; j++) {
            scanf("%f", &m[i][j]);
        }
    }

    elem tempmax = m[0][0];
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

    putchar('\n');
    printf("%f\n", tempmax);

    delete_matrix(m, mat_order);

    return EXIT_SUCCESS;
}