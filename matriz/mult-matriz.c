//multiplicação de matriz quadrada com alocação dinâmica.

#include <stdio.h>
#include <stdlib.h>


int main() {
  int i , j , k, sum;
  int m;
  int **mat1;
  int **mat2;
  int **mult;

//definindo tamanho da matriz;
  printf ("Digite a ordem da matriz: ");
  scanf ("%d", &m);

  //alocação dinâmina das matrizes
  mat1 = (int**) malloc (m * sizeof(int*));
  for (i = 0; i < m; i++)
    mat1[i] = (int*) malloc (m * sizeof(int));
  
  mat2 = (int**) malloc (m * sizeof(int*));
  for (i = 0; i < m; i++)
    mat2[i] = (int*) malloc (m * sizeof(int));

  mult = (int**) malloc (m * sizeof(int*));
  for (i = 0; i < m; i++)
    mult[i] = (int*) malloc (m * sizeof(int));

//definindo elementos da matriz 1
printf ("MATRIZ 1\n");
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++){
      printf ("Mat[%d][%d] = ", i, j);
      scanf("%d", &mat1[i][j]);
    }


  printf("\n");


//definindo elementos da matriz 2
printf ("MATRIZ 2\n");
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      printf ("Mat2[%d][%d] = ", i, j);
      scanf("%d", &mat2[i][j]);
    }



//calculando a multiplicação entra as matrizes
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      sum= 0;
      for (k = 0; k < m; k++)
        sum= sum + mat1[i][k] * mat2[k][j];
      mult[i][j] = sum;
    }


//escrevendo o produto das matrizes
  for (i = 0; i < m; i++) {
    printf("\n");
    for (j = 0; j < m; j++)
      printf("%d ", mult[i][j]);
  }

  printf ("\n");


//liberação da memória;
  for (i = 0; i < m; i++)
    free(mat1[i]);
  free(mat1);

  for (i = 0; i < m; i++)
    free(mat2[i]);
  free(mat2);

  for (i = 0; i < m; i++)
    free(mult[i]);
  free(mult);

  return 0;
}
