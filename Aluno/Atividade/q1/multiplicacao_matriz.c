#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


pthread_mutex_t mutex;

int **matrizA;
int **matrizB;
int **matrizResultante;

int linhas;
int colunas;

void imprime_matriz(int **matriz){
	int i, j;
	for ( i = 0; i < linhas; ++i)
	{
		printf("%d\t", matriz[0][0]);
	}
	/*
	for(i=0;i<linhas;i++){
		printf("%d\n",i );
		for(j=0;j<colunas;j++){
			printf("%d\n",j );
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}*/
}

void inicializa_matriz(int **matriz){	

	int j, i;
	for (i = 0; i < linhas; ++i)
	{
		for(j=0;j<colunas;j++)
			matriz[i][j] = rand()%100;
	}	
}

int alocar_matriz (int **matriz, int linha, int coluna){  
  
  int   index;    /* variavel auxiliar      */
  if (linha < 1 || coluna < 1) {
     printf ("** Erro: Parametro invalido **\n");
     return (-1);
     }
     
     matriz = (int**)malloc(linha * sizeof(int*));

  if (matriz == NULL) {
     printf ("** Erro: Memoria Insuficiente **");
     return (-1);
     }
  /* aloca as colunas da matriz */
  for ( index = 0; index < coluna; index++ ) {
      matriz[index] = (int*) malloc (coluna * sizeof(int));
      if (matriz[index] == NULL) {
         printf ("** Erro: Memoria Insuficiente **");
         return (-1);
   	  }
  }    
  inicializa_matriz(matriz);
  return 1;
}


int main(int argc, char **argv) {
	linhas = atoi(argv[1]);
	colunas = atoi(argv[1]);
	alocar_matriz(matrizA,linhas,colunas);

	imprime_matriz(matrizA);

	return 0;

}
