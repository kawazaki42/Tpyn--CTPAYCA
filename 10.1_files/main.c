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
#include <string.h>  // strcmp
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

    
    // argv - массив строк-аргументов, включая имя программы (argv[0]).
    // argc - длина массива, т.е. кол-во аргументов включая имя программы
    // argc-1 - кол-во аргументов _без_ имени программы.

    // Значения по умолчанию
    char *infname = "in.txt";
    char *outfname = "out.txt";
    
    if(argc-1 >= 1) {
        // switch(0) {
        //     case strcmp(argv[1], "--help"):
        //     case strcmp(argv[1], "/?"):
        // }
        int switches[] = {strcmp(argv[1], "--help"),
                          strcmp(argv[1], "/?")};
        if( (switches[0] == 0) || (switches[1] == 0) ) {
            printf("%s [<infile>] [<outfile>]\n", argv[0]);

            putchar('\n');
            
            puts("Записать в выходной файл "
                "только четные числа из входного файла.");
                
            putchar('\n');

            printf("'infile' - входной файл. "
                   "По умолчанию: '%s'\n", infname);

            printf("'outfile' - выходной файл. "
                   "По умолчанию: '%s'\n", outfname);

            return 0;
        }
    }

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