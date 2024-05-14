/*
 *  Panagiotis Berberidis
 *  csd4476
 *  
 */
#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *fp;
    int i = 0;

    fp = fopen("data3", "w");
    if (fp == NULL) {
        fprintf(stderr, "error opening file!");
        exit(1);
    }

    for (i = 0; i < 100; i++) {
        if (i == 34) {
            fputc(0x23, fp); /* i after the input */
        }
        fputc(0, fp);
    }

    return 0;
}