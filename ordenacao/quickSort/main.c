#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quick.h"

int main(){
    tVet *vetor;
    char nomeArquivo[30];
    int qtd;

    printf("Digite o nome do arquivo: ");
    scanf ("%s", nomeArquivo);
    printf("Digite a quantidade de numeros gerados: ");
    scanf ("%d", &qtd);
    geraAleatorios(nomeArquivo, qtd);
    vetor = leArquivo(nomeArquivo);
    imprimeVet(getVet(vetor), getTam(vetor));
    printf ("\n");
    quick(getVet(vetor), 0, getTam(vetor)-1);
    imprimeVet(getVet(vetor), getTam(vetor));

    free(vetor);

    return 0;
}