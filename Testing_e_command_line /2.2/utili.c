#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*xmalloc 
* alloca dinamicamente una locazione di memoria di taglia size
*/
void* xmalloc(size_t size){
    void *app;
    if((app=malloc(size))==NULL){
        exit(-1);
    }
    return app;
}

/*scambia: scambia due elementi di una vettore di interi 
*   nelle posizioni j e i
*/
void scambia(int a[],int i,int j){
    int app;
    app=a[i];     
    a[i]=a[j];
    a[j]=app;
}

FILE* apriFileLettura(char *pathname){
    FILE *fcon;
    if((fcon=fopen(pathname,"r"))==NULL){
        printf("Il file non estiste\n");
        return NULL;
    }
    return fcon;
}

FILE *creaFile(char *pathname){
    FILE* fcon;
    if((fcon=fopen(pathname,"w"))==NULL){
        printf("creazione non avvenuta correttamente\n");
        return NULL;
    }
    return fcon;
}

int contaRighe(FILE *fcon){
    int i=0,j;
    char p[40];
    while(!feof(fcon)){
        fscanf(fcon,"%s %d\n",p,&j);
        i++;
    }
    return i--;
}

