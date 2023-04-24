#include <stdio.h>
#include <stdlib.h>
#include "advanced.h"

int main(){
    tVet *vetor;
    char nomeArquivo[30];
    int qtd;

    scanf("%s", nomeArquivo);
    printf("Digite a quantidade de numeros: ");
    scanf("%d", &qtd);
    geraAleatorios(nomeArquivo, qtd);
    vetor = leArquivo(nomeArquivo);
    imprimeVet(getVet(vetor), getTam(vetor));
    printf("\n");
    quick(getVet(vetor), 0, getTam(vetor) - 1);
    imprimeVet(getVet(vetor), getTam(vetor));

    liberaVet(vetor);

    return 0;
}