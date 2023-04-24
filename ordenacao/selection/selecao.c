#include <stdio.h>
#include <stdlib.h>
#include "selecao.h"


int geraAleatorios(char *nomeArquivo, int qtd){
    int i, x;
    FILE *arq;
    arq = fopen(nomeArquivo, "w");
    
    if (arq == NULL)
        return -1;

    for (i = 0; i < qtd; i++){
        x = rand() % 1000;
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

void selecao(int *vet, int tam){
    int marcador = 0, menor, aux, i;
    while (marcador < tam -1){
        menor = marcador + 1;
        for (i = marcador + 1; i < tam; i++){
            if (vet[menor] > vet[i])
                menor = i;
        }
        if (vet[menor] < vet[marcador]){
            aux = vet[menor];
            vet[menor] = vet[marcador];
            vet[marcador] = aux;
        }
        marcador++;
    }
}

void imprimeVet(int *vet, int tam){
    int i;
    for (i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf ("\n");
}