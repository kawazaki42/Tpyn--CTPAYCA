/**
 * @file
 * @brief   Задача 480-А
 * 
 * @author  Николай Ковалев
 * 
 * @details Дан файл f, компоненты которого являются целыми числами.
 *          Получить в файле g все компоненты файла f:
 *          А) являющиеся четными числами;
 * 
 * Ссылка:  https://ivtipm.github.io/Programming/Glava13/index13.htm#z480
 */

#include <stdlib.h>  // EXIT_SUCCESS
#include <stdio.h>   // fprintf, fscanfs, FILE
#include <locale.h>  // setlocale


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

    char infname[] = "../in.txt";
    char outfname[] = "../out.txt";

    FILE *infile = fopen(infname, "r");    // открыть для чтения
    FILE *outfile = fopen(outfname, "w");  // открыть для записи

    int ret;
    int n;

    ret = fscanf_s(infile, "%i", &n);
    while(ret >= 1) {
        if(n % 2 == 0)  // n делится на 2 без остатка
            fprintf(outfile, "%i\n", n);

        ret = fscanf_s(infile, "%i", &n);
    }

    // Завершение
    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}