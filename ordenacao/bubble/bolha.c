#include <stdio.h>
#include <stdlib.h>
#include "bolha.h"

struct tReturn {
    int *vet;
    int tam;
    int erro;
};


tReturn *alocatReturn (){
    tReturn *rep = (tReturn*) malloc (sizeof(tReturn));
    if (rep == NULL){
        rep->erro = 3;
    }
    rep->erro = 0;
    return rep; 
}


tReturn *leArquivo (char nomeArquivo[]){
    FILE *arq;
    tReturn *rep;
    int i,  x;
    rep = alocatReturn();
    arq = fopen (nomeArquivo, "r");
    
    if (arq == NULL){
        rep->erro = 1;
        return rep;
    }

    x = fscanf (arq, "%d", &rep->tam);
    if (x =! 1){
        rep->erro = 2;
        return rep;
    }
    rep->vet = (int*) malloc (rep->tam*sizeof(int));

    for (i = 0; i < rep->tam; i++){
        x = fscanf (arq, "%d", &rep->vet[i]);
        if (x != 1){
            rep->erro = 2;
            return rep;
        }
    }
    
    fclose(arq);
    return rep;
}


int getErro (tReturn *rep){
    return rep->erro;
}



int *getVet(tReturn *rep){
    return rep->vet;
}


int getTam (tReturn *rep){
    return rep->tam;
}

int bolha (int *vet, int tam){
    int comp = 0, i, aux, j;
    for (j = 0; j < tam; j++){
        for (i = 1; i < tam; i++){
            if (vet[i] < vet [i-1]){
                aux = vet[i-1];
                vet[i-1] = vet[i];
                vet[i] = aux;
            }
            comp++;
        }
    }

    return comp;
}


void imprimeVet(int *vet, int tam){
    int i;
    for (i = 0; i < tam; i++)
        printf("%d\n", vet[i]);
}

void trataErro(int erro){     
    if (erro == 1)
        printf("Erro ao abrir o arquivo\n");
    if (erro == 2)
        printf("Erro ao ler do arquivo\n");
    if (erro == 3)
        printf("Erro ao alocar memória\n");
}

int bolhaInteligente (int *vet, int tam){
    int comp = 0, troca = 1, i, aux, j;
    for (j = 0; j < tam; j++){
        if (troca == 0)
            return comp;
        troca = 0;
        for (i = 1; i < tam - j; i++){
            if (vet[i] < vet[i-1]){
                aux = vet[i-1];
                vet[i-1] = vet[i];
                vet[i] = aux;
                troca++;
            }
            comp++;
        }
    } 
    return comp;
}
