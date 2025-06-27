#include <stdio.h>
#include <math.h>
#include <locale.h>

// FIXME: Windows
// #define scanf scanf_s

int main() {
    // Установить кодировку UTF-8
    // Локаль США (для разделителя-точки)
    setlocale(LC_ALL, "en_US.UTF8");

    float x;  //< Исходное действительное число
    printf("x = ");
    scanf("%f", &x);

    puts("Значения с округлением");
    printf("%s\t%.0f\n", " вниз:", floor(x));
    printf("%s\t%.0f\n", " до ближайшего целого:", round(x));
    printf("%s\t%.0f\n", " отбрасыванием:", trunc(x));
}