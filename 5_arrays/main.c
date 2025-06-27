/*
 * Автор:  Николай Ковалев
 * Задача: Даны натеральное число [n], целые числа a[1],...,a[n].
 *         Получить сумму положительных и число отрицательных членов
 *         последовательности a[1],...,a[n].
 * Номер задачи: 190
 * Ссылка: https://ivtipm.github.io/Programming/Glava07/index07.htm#z190
 */

#include <stdio.h>
#include <math.h>
#include <locale.h>

// FIXME: Windows
// #define scanf scanf_s


// Макрос препроцессора C.
// Подставляет указанное выражение вместо имени _перед_ компиляцией.
// Компилятор выдает ошибку при использовании обычной константы.

// const size_t ARR_MAX = 256;
#define ARR_MAX 256

int main() {
    // Установить кодировку UTF-8
    // Локаль США (для разделителя-точки)
    setlocale(LC_ALL, "en_US.UTF8");

    int n;  //< Кол-во элементов
    printf("Кол-во элементов (n): ");
    scanf("%i", &n);

    //const size_t ARR_MAX = 256;
    int a[ARR_MAX];  //< Последовательность целых чисел

    printf("Введите %d чисел через пробел:\n", n);

    // Чтение n целых чисел в массив
    for(size_t i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int pos_sum = 0;
    int neg_cnt = 0;
    for(size_t i = 0; i < n; i++) {
        if (a[i] > 0)
            pos_sum += a[i];
        else if (a[i] < 0)
            neg_cnt += 1;
    }

    printf("%5d - сумма положительных чисел\n", pos_sum);
    printf("%5d - кол-во отрицательных чисел\n", neg_cnt);
}