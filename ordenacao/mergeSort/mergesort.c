#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

struct tVet
{
    int *vet;
    int tam;
};

int geraAleatorios(char *nomeArquivo, int qtd){
    int i, x;
    FILE *arq;

    arq = fopen(nomeArquivo, "w");
    
    if (arq == NULL)
        return -1;

    for (i = 0; i < qtd; i++){
        x = rand() % 100;
        fprintf (arq, "%d ", x);
    }
    fclose(arq);

    return 0;
}

tVet * leArquivo(char *nomeArquivo){
    tVet *vetor = (tVet*) malloc (sizeof(tVet));
    FILE *arq;
    int i;

    arq = fopen(nomeArquivo, "r");

    fscanf(arq, "%d", &vetor->tam);
    vetor->vet = (int*) malloc(sizeof(int)*(vetor->tam));

    for (i = 0; i < vetor->tam; i++){
        fscanf(arq,"%d", &vetor->vet[i]);
    }

    return vetor;
}

void mergesort(int *v, int inicio, int fim){
    int meio;
    if (inicio >= fim)
        return;
    meio = (inicio + fim)/2;
    mergesort (v, inicio, meio);
    mergesort (v, meio + 1, fim);
    merge (v, inicio, meio, fim);
    
}

void merge (int *v, int inicio, int meio, int fim){
    int vet[(fim - inicio) + 1];
    int marcador1 = inicio, marcador2 = meio + 1, aux = 0;


    while (marcador1 <= meio && marcador2 <= fim)
    {   
        if (v[marcador1] <= v[marcador2]){
            vet[aux++] = v[marcador1++];
        }
        else {
            vet[aux++] = v[marcador2++];
        }
    }

    while (marcador1 <= meio)
    {
        vet[aux++] = v[marcador1++];
    }
    
    
    while (marcador2 <= fim)
    {
        vet[aux++] = v[marcador2++];  
    }

    for (aux = inicio; aux <= fim; aux++){
        v[aux] = vet[aux - inicio];
    }
   
}

int getVetTam(tVet *res){
    return res->tam;
}

int *getVet(tVet *res){
    return res->vet;
}

void imprimeVet(int *v, int tam){
    int i;
    for (i = 0; i < tam; i++)
        printf("%d ", v[i]);
}