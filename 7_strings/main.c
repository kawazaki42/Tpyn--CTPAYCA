/**
 * @file
 * @brief   Задача 269-Д
 * @author  Николай Ковалев
 * @details Даны натуральное число n, символы s1,...,sn.
 *          Группы символов, разделенные пробелами (одним или несколькими)
 *          и не содержащие пробелов внутри себя будем называть словамию
 *          Д) Найти какое-нибудь слово, начинающееся с буквы а.
 * Ссылка:  https://ivtipm.github.io/Programming/Glava08/index08.htm#z269
 */

#include <stdio.h>   // printf, scanf
#include <locale.h>  // setlocale
#include <stdlib.h>  // EXIT_SUCCESS
#include <ctype.h>
#include <string.h>
// #include "arrays.h"  // arrays, matrices


char skip_word() {
    char cur;
    do
        cur = getchar();
    while( !isspace(cur) );  // Пропустить не-пробелы
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

    /// Длина строки
    // int length;
    // printf("Длина строки в байтах (n): ");
    // scanf_s("%i ", &length);

    /// Искомый символ
    char look_for;
    printf("Искомый символ: ");
    scanf_s("%c", &look_for, 1);
    // size_t cwidth = strlen(look_for);

    // putchar('\n');
    printf("Введите строку:\n");
    // puts("Остальное будет игнорировано");

    // / Первый символ слова

    // char buf[cwidth + 1];
    // while(1) {
    //     // scanf_s("%4s", buf, sizeof buf);
    //     scanf_s(" ");
    //     for(size_t i = 0; i < cwidth; i++) {
    //         buf[i] = getchar();
    //     }
    //     buf[cwidth] = '\0';
    
    //     if(strncmp(buf, look_for, cwidth) == 0)
    //         break;
    //     scanf_s(" ");
    //     scanf_s("%*s");
    // }

    // printf("%s", buf);

    char cur;
    // scanf_s(" ");
    while(1) {
        // if(cur == look_for) {
            // break;
        // }
        scanf_s(" ");  // Пропустить пробелы, если есть
        cur = getchar();  // Считать ровно один символ
        if(cur == look_for)
            break;  // Нашли символ в начале слова
        else {
            // `ungetc` 'возвращает' считанный символ
            // в очередь чтения файла/потока данных.
            //
            // При помощи `%s` мы хотим пропустить остаток слова.
            //
            // У однобуквенного слова нет остатка.
            // После него сразу идут пробелы.
            //
            // `%s` пропускает начальные пробелы,
            // поэтому поглощает целое слово после однобуквенного.
            //
            // Нужно вернуть символ в очередь ввода,
            // чтобы поглотилось только однобуквенное слово.

            // Когда мы считываем из однобуквенного слова символ,
            // `%*s` пропускает пробелы после него и 'поглощает' слово после них.
            // Нам же нужно 'поглотить' только остаток слова.
            // У однобуквенного слова нет остатка.
            //
            // Необходимо для случаев с однобуквенными словами.
            // Когда мы считываем из него первый и единственный символ,
            // далее в очереди идут пробелы и следующее слово.
            // `%*s` пропускает начальные пробелы и 'поглощает' слово после них.
            // Нам же нужно 'поглотить' только остаток слова, которого у
            ungetc(cur, stdin);
            scanf_s("%*s");
        }
            // cur = skip_word();


        // scanf_s("%*s");
        // if(isspace(cur)) {
        //     cur = getchar();  // символ после пробела
        //     if(cur == look_for)
        //         break;  // Нашли
        //     // else
        //         // continue;
        // }
        // cur = getchar();
    }

    // do {
    //     scanf_s(" %c", cur);
    //     if(cur == look_for) break;
    // } while(cur != look_for);
    // if(cur == look_for) {

    // char cur = getchar();

    putchar('\n');
    while(!isspace(cur)) {
        putchar(cur);
        cur = getchar();
    }
    putchar('\n');
    return EXIT_SUCCESS;
    // }

    // printf("(Разделители - пробел и перевод строки)\n");

    // putchar('\n');
    // printf("Матрица A:\n");
    // matrix_of_float A = read_matrix_of_float(length, length);
    // putchar('\n');

    // puts("Для каждого вектора введите n действительных чисел");
    // puts("(Разделитель - пробел)");
    
    // printf("(n = %d)\n\n", length);

    // printf("Вектор x: ");
    // array_of_float x = read_array_of_float(length);

    // printf("Вектор y: ");   
    // array_of_float y = read_array_of_float(length);
    

    // // Вычисления
    // vec_add_inplace(x, y, length);
    // free(y);
    // y = multiply_mat_vec(A, x, length);


    // Вывод

    // putchar('\n');
    // printf("A(x + y) = (");

    // // Все элементы, кроме последнего, через запятую
    // for(size_t i = 0; i < length-1; i++)
    //     printf("%.2f, ", y[i]);

    // printf("%.2f)", y[length-1]);  // последний
    // putchar('\n');
    

    // Завершение
    // free(x);
    // free(y);
    // delete_matrix_of_float(A, length);
    // x = y = NULL;
    // A = NULL;

    // return EXIT_SUCCESS;
}