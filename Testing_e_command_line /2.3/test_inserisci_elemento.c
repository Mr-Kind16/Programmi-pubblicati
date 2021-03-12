#include "vettore.h"
#include "utili.h"

/*      funzione che inserisce un elemento nel vettore
*       nella posizione desiderata*/
void inserisciElemento(int vet[],int n,int pos,int dim){
    for(;dim>pos;dim--){
        vet[dim]=vet[dim-1];
    }
    vet[pos]=n;
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
    if(argc!=7){
        printf("input sbagliato\n");
        exit(-1);
    }
    int dim=atoi(argv[1])+1;
    int numero=atoi(argv[2]);
    int pos=atoi(argv[3])-1;
    int vet[dim],oracolo[dim];
    int risultato;
    
    f_input_vet(argv[4],dim,vet);
    inserisciElemento(vet,numero,pos,dim);
    f_input_vet(argv[5],dim,oracolo);

    risultato=oracoloCheck(oracolo,vet,dim);
    printf("Il test:%s è %s\n",argv[4],risultato?"PASSED":"FAILED");
    f_output_file(argv[6],dim,vet);

    if(risultato)
        return 1;
    else
        return 0;
}