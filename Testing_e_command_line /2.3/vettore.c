#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utili.h"

/*stampa tutti gli elementi di un vettore di interi*/
void stampaVettore(int *vet,int n){
    for(int i=0;i<n;i++)
        printf("%d ",vet[i]);
    printf("\n");
}

/*  SPECIFICA ordina:
*   Dati in input: string array di char
*   Precondizione: la stringa non deve essere vuota
*   Dati in output: array di char
*   Postcondizione: utilizzo l'algoritmo di ordinamento bubble sort
*     l'array di output contiene una permutazione degli elementi
*       dell array in input con la seguente caratteristica:
*       ∀i∈ [0,n-2],string[i]<=string[i+1]
*/
void ordina(int a[],int n){
    int i=0,j,n_scambi;
    while(n_scambi){
        n_scambi=0;
        for(j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                scambia(a,j,j+1);
                n_scambi++;
            }
        }
    }
}
/*funzione che controlla se i due vettori sono uguali
*   
*
*/
int oracoloCheck(int *oracolo,int *vet,int n){
    int i;
    for(i=0;i<n;i++){
        if(oracolo[i]!=vet[i])
            return 0;
    }
    return 1;
}