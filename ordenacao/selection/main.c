#include <stdio.h>
#include <stdlib.h>
#include "selecao.h"

int main() {
    char nomeArquivo[30];
    int *vet; 
    int tam; 

    scanf("%s", nomeArquivo);
    scanf("%d", &tam);
    geraAleatorios(nomeArquivo, tam);
    vet = leArquivo(nomeArquivo, tam);
    selecao(vet, tam);
    imprimeVet(vet, tam);

    free(vet);

    return 0;
}
