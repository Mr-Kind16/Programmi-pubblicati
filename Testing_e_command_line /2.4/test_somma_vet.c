#include "utili.h"
#include "vettore.h"

void somma_array(int a[],int b[],int c[],int n){
    int i;
    for(i=0;i<n;i++)
        c[i]=a[i]+b[i];
}

int f_input_vet(char *path_name,int n,int vet[]){
    FILE* fcon;
    if((fcon=apriFileLettura(path_name))==NULL)
        return 0;
    int i;

    for(i=0;i<n;i++)
        fscanf(fcon,"%d\n",&vet[i]);
    
    fclose(fcon);
    return 1;
}

int f_output_file(char *path_name,int n,int vet[]){
    int i;
    FILE *fcon;
    if((fcon=creaFile(path_name))==NULL)
        return 0;
    
    for(i=0;i<n;i++)
        fprintf(fcon,"%d\n",vet[i]);

    fclose(fcon);
    return 1;
}

int main(int argc,char *argv[]){
    if(argc!=6){
        printf("input sbagliato\n");
        exit(-1);
    }
    int dim=atoi(argv[1]);
    int vet1[dim],vet2[dim],vet3[dim],oracolo[dim];
    int risultato;
    f_input_vet(argv[2],dim,vet1);
    f_input_vet(argv[3],dim,vet2);
    somma_array(vet1,vet2,vet3,dim);
    f_input_vet(argv[4],dim,oracolo);

    risultato=oracoloCheck(oracolo,vet3,dim);
    printf("Il test:%s è %s\n",argv[4],risultato?"PASSED":"FAILED");
    f_output_file(argv[5],dim,vet3);
    if(risultato)
        return 1;
    else
        return 0;
}