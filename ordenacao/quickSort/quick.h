typedef struct  tVet tVet;

int geraAleatorios(char *nomeArquivo, int qtd);
//função para gerar os números de forma aleatória

tVet *leArquivo (char *nomeArquivo);
//função para ler o arquivo com os números
//primeira linha contém a quantidade de números

void quick(int *vet, int inicio, int fim);
//função do método de ordenação quicksort

int particiona(int *vet, int inicio, int fim);
//função do método de ordenação quicksort

int getTam(tVet *vetor);
//função que retorna o tamanho do vetor

int *getVet (tVet *vetor);
//função que retorna o vetor

void imprimeVet (int *vetor, int tam);
//função para imprimir vetor