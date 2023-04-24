typedef struct tReturn tReturn;

tReturn* alocatReturn();
//Essa função aloca memória para uma variável do tipo tReturn

int *getVet(tReturn *rep);
//função que retorna o vetor

int getTam(tReturn *rep);
//função que retorna o tamanho do vetor

int getErro(tReturn *rep);
//Essa função retorna o valor da variável error contido na estrutura tReturn;

void trataErro(int erro);
//Essa função trata os erros relativos à função leArquivo
//erro 1 : abertura do arquivo -- printf("Erro ao abrir o arquivo\n");
//erro 2: leitura do arquivo -- printf("Erro ao ler do arquivo\n");
//erro 3 : alocação de memória -- printf("Erro ao alocar memória\n");

tReturn* leArquivo(char nomeArquivo[]);
//função para ler o arquivo com os números

int bolha (int *vet, int tam);
//Essa função ordena o vetor usando o método bolha e retorna a quantidade de comparações realizadas

int bolhaInteligente (int *vet, int tam);
//Essa função ordena o vetor usando o método bolha inteligente e retorna a quantidade de comparações realizadas

void imprimeVet(int *vet, int tam);
//função para imprimir o vetor

