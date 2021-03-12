#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utili.h"

/*funzione che crea il comando per eseguire un test
*/
char *crea_command(char*nome,int lung,int num,int pos){
    char pathname[100],*pathname_din,numero[10];
    int dim;
    char *estensioni[3]={"_input.txt ","_oracle.txt ","_output.txt "};
    
    strcpy(pathname,"./esegui_test.out ");
    sprintf(numero,"%d %d %d ",lung,num,pos);
    strcat(pathname,numero);
    for(int i=0;i<3;i++){
        strcat(pathname,"testing/");
        strcat(pathname,nome);
        strcat(pathname,estensioni[i]);
    }

    dim=strlen(pathname);
    pathname_din=xmalloc(dim+1);
    strcpy(pathname_din,pathname);
    pathname_din[dim]='\0';
    return pathname_din;
}

/*funzione che legge tutti i test da fare da file
*/
Test *leggiTestSuite(char *pathname,int *dim){
    FILE *fcon=apriFileLettura(pathname);
    if(fcon==NULL){
        return NULL;
    }
    int i;
    *dim=contaRighe(fcon);
    Test* vet=xmalloc(*dim*sizeof(Test));
    rewind(fcon);

    for(i=0;i<*dim;i++){
        fscanf(fcon,"%s %d %d %d\n",vet[i].nome,&vet[i].dim,&vet[i].numero,&vet[i].pos);
    }
    return vet;
}

/*funzione che esegue i test per tutti gli elementi del vettore di test*/
void eseguiTests(Test vetTest[],int n,char *nomeFileResult){
    int i=0;
    char *command;
    FILE *fcon=creaFile(nomeFileResult);

    for(;i<n;i++){
        command=crea_command(vetTest[i].nome,vetTest[i].dim,vetTest[i].numero,vetTest[i].pos);
        system(command)?fprintf(fcon,"%s PASS\n",vetTest[i].nome):fprintf(fcon,"%s FAIL\n",vetTest[i].nome);
        free(command);
    }
    fclose(fcon);
}
int main(int argc,char **argv){
    if(argc!=3){
        printf("Input da linea sbagliato\n");
        exit(-1);
    }
    int dim;
    Test *vetTests=leggiTestSuite(argv[1],&dim);

    eseguiTests(vetTests,dim,argv[2]);
    return 0;
}