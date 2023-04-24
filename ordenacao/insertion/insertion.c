#include <stdio.h>
#include <stdlib.h>
#include "insertion.h"


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

int* leArquivo(char *nomeArquivo, int qtd){
    int i;
    FILE *arq;
    int *vet = (int*) malloc (sizeof(int)*qtd);
    arq = fopen(nomeArquivo, "r");

    for (i = 0; i < qtd; i++){
        fscanf(arq, "%d", &vet[i]);
    }

    fclose(arq);
    return vet;
}


void insercao(int *vet, int tam){
    int marcador = 1, aux, i, posicao;
    for (marcador = 1; marcador < tam; marcador++){
        posicao = marcador - 1;
        aux = vet[marcador];
        while (aux < vet[posicao] && posicao >= 0){
            vet[posicao+1] = vet[posicao];
            posicao--;
        }
        vet[posicao+1] = aux;
    }
}


void imprimeVet(int *vet, int tam){
    int i;
    for (i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf ("\n");
}