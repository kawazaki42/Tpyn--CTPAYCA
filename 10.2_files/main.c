/**
 * @file
 * @author  Николай Ковалев
 * 
 * @details 
 *     (507) Сведения об ученике состоят из его имени, фамилии и
 *           названия класса (года обучения и буквы), в котором он учится.
 * 
 *           Дан файл f, содержащий сведения об учениках школы.
 *           В) Выяснить, имеются ли однофамильцы в каком-нибудь классе.
 * 
 * Ссылка:
 *     https://ivtipm.github.io/Programming/Glava13/index13.htm#z507
 */

#include <stdlib.h>  // EXIT_SUCCESS
#include <stdio.h>   // fprintf, fscanfs, FILE
#include <locale.h>  // setlocale
#include <string.h>  // strcmp


struct student {
    char first_name[128];
    char last_name[128];
    unsigned char class_year;
    char class_letter;
};


int read_student(FILE *fp, struct student *s) {
    // s = malloc( sizeof(struct student) );
    int ret = fscanf(fp, "%127s,%127s,%hhu%c",
                       s->first_name, sizeof s->first_name,
                       s->last_name,  sizeof s->last_name,
                       &s->class_year,
                       &s->class_letter, 1);
    // s->first_name[127] = '\n';
    // s->last_name[127] = '\n';
    return ret;
}


int print_student(struct student *s) {
    return printf_s("%hhu%c: %s %s\n",
                    s->class_year,
                    s->class_letter,
                    s->last_name,
                    s->first_name);
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

    char infname[] = "../students.csv";
    // char outfname[] = "../out.txt";

    FILE *infile = fopen(infname, "r");    // открыть для чтения
    // FILE *outfile = fopen(outfname, "w");  // открыть для записи

    int ret;
    struct student storage[1024];
    size_t storage_size = 0;

    do {
        ret = read_student(infile, &storage[storage_size]);
        storage_size++;
    } while(ret == 4);

    for(size_t i = 0; i < storage_size; i++) {
        for(size_t j = 0; j < storage_size; j++) {
            if(
                // (i != j) &&
                (storage[i].class_year == storage[j].class_year) &&
                (storage[i].class_letter == storage[j].class_letter) &&
                strcmp(storage[i].last_name, storage[j].last_name) == 0
            ) {
                print_student(&storage[i]);
                print_student(&storage[j]);
            }
        }
    }

    // Завершение
    fclose(infile);
    // fclose(outfile);

    return EXIT_SUCCESS;
}