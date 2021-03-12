#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test{
    char nome[5];
    int dim;
}Test;


void* xmalloc(size_t size);
void scambia(int a[],int i,int j);
FILE* apriFileLettura(char *pathname);
FILE *creaFile(char *pathname);
int contaRighe(FILE *fcon);

