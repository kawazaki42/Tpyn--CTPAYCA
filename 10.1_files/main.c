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
#include "filter.h"  // filter_even


/**
 * @brief Главная процедура
 * 
 * @return `EXIT_SUCCESS` (или 0) при успешном завершении
 * 
 *         `EXIT_FAILURE` при ошибке (напр. нехватка памяти)
 */
int main(int argc, char *argv[]) {
    // Установить кодировку UTF-8
    // Локаль США (для разделителя-точки)
    setlocale(LC_ALL, "en_US.UTF8");

    char *infname = "in.txt";
    char *outfname = "out.txt";

    // argv - массив строк-аргументов, включая имя программы (argv[0]).
    // argc - длина массива, т.е. кол-во аргументов включая имя программы
    // argc-1 - кол-во аргументов _без_ имени программы.

    if(argc-1 >= 1) {
        infname = argv[1];
    }

    if(argc-1 >= 2) {
        outfname = argv[2];
    }


    FILE *infile, *outfile;


    fopen_s(&infile, infname, "r");    // открыть для чтения
    
    if(!infile) {
        perror("Cannot open file for input");
        printf(infname);
        return EXIT_FAILURE;
    }
    

    fopen_s(&outfile, outfname, "w");  // открыть для записи
    
    if(!outfile) {
        perror("Cannot open file for input");
        printf(outfname);
        return EXIT_FAILURE;
    }


    // Решение задачи при помощи функции из модуля filter
    filter_even(infile, outfile);


    // Завершение
    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}