#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insertion.h"

int main() {
    char nomeArquivo[30];
    int *vet; //guarda o vetor que será ordenado
    int tam;

    scanf("%s", nomeArquivo);
    scanf("%d", &tam);
    geraAleatorios(nomeArquivo, tam);
    vet = leArquivo(nomeArquivo, tam);
    insercao(vet, tam);
    imprimeVet(vet, tam);
    
    free(vet);

    return 0;
}
