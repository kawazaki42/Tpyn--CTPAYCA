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
#include "filter.h"


/**
 * @brief Главная процедура
 * 
 * @return `EXIT_SUCCESS` (или 0) при успешном завершении
 * 
 *         `EXIT_FAILURE` при ошибке (напр. нехватка памяти)
 */
int main(int argc, char **argv) {
    // Установить кодировку UTF-8
    // Локаль США (для разделителя-точки)
    setlocale(LC_ALL, "en_US.UTF8");

    char *infname = "in.txt";
    char *outfname = "out.txt";

    if(argc >= 1) {
        infname = argv[0];
    }

    if(argc >= 2) {
        infname = argv[1];
    }

    FILE *infile, *outfile;
    fopen_s(&infile, infname, "r");    // открыть для чтения
    fopen_s(&outfile, outfname, "w");  // открыть для записи

    if(!infile) {
        perror("Cannot open input file");
        return EXIT_FAILURE;
    }

    if(!outfile) {
        perror("Cannot open output file");
        return EXIT_FAILURE;
    }

    filter_even(infile, outfile);

    // Завершение
    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}