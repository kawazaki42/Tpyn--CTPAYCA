#include <stdio.h>

void filter_even(FILE *infile, FILE *outfile) {
    int n;
    int ret = fscanf_s(infile, "%i", &n);
    while(ret >= 1) {
        if(n % 2 == 0)  // n делится на 2 без остатка
            fprintf(outfile, "%i\n", n);
    
        ret = fscanf_s(infile, "%i", &n);
    }
}
