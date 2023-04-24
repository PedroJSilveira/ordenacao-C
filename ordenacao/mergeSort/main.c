#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergesort.h"

int main() {
    //DECLARAÇÃO DE VARIÁVEIS
    tVet *vet;
    char nomeArquivo[80];
    int qtd;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);
    printf("Digite a quantidade de numeros gerados:" );
    scanf("%d", &qtd);

    geraAleatorios(nomeArquivo, qtd);
    vet = leArquivo(nomeArquivo);
    imprimeVet(getVet(vet), getVetTam(vet));
    printf("\n");
    mergesort(getVet(vet),0, getVetTam(vet)-1);
    imprimeVet(getVet(vet), getVetTam(vet));
    free(vet);

    return 0;
}
