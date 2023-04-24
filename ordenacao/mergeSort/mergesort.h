typedef struct tVet tVet;

int geraAleatorios(char *nomeArquivo, int qtd);
//Função para gerar os números de forma aleatória

void mergesort(int *v, int inicio, int fim);
//Função recursiva que executa a fase de divisão do algoritmo mergesort

void merge(int *v, int inicio, int meio, int fim);
//Função que faz a fusão de dois vetores pré-ordenados e os copia para o vetor original

void imprimeVet(int *v, int tam);
//Função que imprime um vetor

tVet * leArquivo(char *nomeArquivo);
//Função que lê os dados de um arquivo e carrega em um vetor de inteiros
//Retorna o tipo tVet, composto por um vetor de inteiros e o tamanho do vetor
//A primeira linha do arquivo possui o tamanho do vetor

int getVetTam(tVet *res);
//Função que retorna o tamanho do vetor

int *getVet(tVet *res);
//Função que retorna o vetor


