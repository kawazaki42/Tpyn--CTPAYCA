/*
 * Автор:  Николай Ковалев
 * Задача: Даны натуральное n, действительное х. Вычислить:
 *     sin(х) + sin^2(х) + ... + sin^n(х)
 * Номер задачи: 84-A
 * Ссылка: https://ivtipm.github.io/Programming/Glava04/index04.htm#z84
 */

#include <stdio.h>
#include <math.h>
#include <locale.h>

// FIXME: Windows
// #define scanf scanf_s

int main() {
    // Установить кодировку UTF-8
    // Локаль США (для разделителя-точки)
    setlocale(LC_ALL, "en_US.UTF8");

    float x;  //< Аргумент синуса
    printf("x = ");
    scanf("%f", &x);

    int n;  //< Кол-во слагаемых
    printf("n = ");
    scanf("%i", &n);

    // Значение sin(x) не зависит от итерации, вычислим заранее
    float sin_x = sin(x);
    float sin_x_pow = 1.0;

    float sum = 0.0;
    for(size_t i = 1; i <= n; i++) {
        // sum += powf(sin_x, i);
        sin_x_pow *= sin_x;
        sum += sin_x_pow;
    }

    printf("%f\n", sum);
}