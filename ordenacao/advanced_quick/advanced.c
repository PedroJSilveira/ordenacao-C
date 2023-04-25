#include <stdio.h>
#include <stdlib.h>
#include "advanced.h"


struct tVet
{
    int *vet;
    int tam;
};


tVet *leArquivo(char *nomeArquivo){

    tVet *vetor = (tVet*) malloc (sizeof(tVet));
  
    FILE *arq;
    int i = 0;
  
    arq = fopen(nomeArquivo, "r");

    if(arq == NULL){
      printf("ERROR: arquivo nao encontrado");
    }

    fscanf(arq, "%d", &vetor->tam);
  
    vetor->vet = (int*) malloc (sizeof(int)*vetor->tam);

    while (!feof(arq)){
      
        fscanf(arq, "%d", &vetor->vet[i]);
        i++;
      
    }

    fclose(arq);

    return vetor;
}


void geraAleatorios(char *nomeArquivo, int qtd){
    int i, x;
    FILE *arq;
    arq = fopen(nomeArquivo, "w");

    fprintf(arq, "%d\n", qtd);

    for (i = 0; i < qtd; i++){
        x = rand() % 100;
        fprintf (arq, "%d\n", x);
    }
    fclose(arq);
}


void insercao(int *vet, int inicio, int fim){
    int marcador , aux, i, posicao;
    for (marcador = inicio + 1; marcador <= fim; marcador++){
        posicao = marcador - 1;
        aux = vet[marcador];
        while (aux < vet[posicao] && posicao >= 0){
            vet[posicao+1] = vet[posicao];
            posicao--;
        }
        vet[posicao+1] = aux;
    }
}

void quick(int *vet, int inicio, int fim){
    int posPivo;
    //ponto de parada da recursão
    if (inicio < fim){
        //caso o vetor seja menor que nove usa-se a inserção, caso contrário, usa-se o quicksort
        if (fim - inicio < 9)
            insercao(vet, inicio, fim);
        else{
            posPivo = particiona(vet, inicio, fim);
            quick(vet, inicio, posPivo - 1);
            quick(vet, posPivo + 1, fim);
        }
    }
}

int particiona(int *vet, int inicio, int fim){
    int pivo = vet[inicio];
    int pos = inicio;
    int i, aux;

    for (i = inicio; i <= fim; i++){
        if (vet[i] < pivo){
            pos++;
            if (i != pos){
                aux = vet[i];
                vet[i] = vet[pos];
                vet[pos] = aux;
            }
        }
    }
    aux = vet[inicio];
    vet[inicio] = vet[pos];
    vet[pos] = aux;

    return pos;
}

int getTam(tVet *vetor){
    return vetor->tam;
}

int *getVet(tVet *vetor){
    return vetor->vet;
}

void imprimeVet(int *vetor, int tam){
    int i;
    for (i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
}

void liberaVet(tVet *vetor){  
    free(vetor->vet);
    free(vetor);
}
