#define _GNU_SOURCE
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include "matriz_util.h"

pthread_mutex_t mutex;


void imprime_matriz(int **matriz){
	int i, j=0;

	for(i=0;i<linhas;i++){
	
		for(j=0;j<colunas;j++){
	
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
}

void inicializa_matriz(int **matriz){	

	int j=0, i=0;
	for (i = 0; i < linhas; ++i)
	{		
		for(j=0;j<colunas;++j){
			matriz[i][j] = rand()%1000;
		}
	}	
}

void alocar_matriz (int **matriz,int linhas,int colunas){  
  
  int   index;    /* variavel auxiliar      */
  matrizA = (int**)malloc(linhas * sizeof(int*));


  /* aloca as colunas da matriz */
  for ( index = 0; index < colunas; index++ ) {
      matrizA[index] = (int*) malloc (colunas * sizeof(int));      
  }    

  inicializa_matriz(matrizA);
}


int main(int argc, char **argv) {
	linhas = atoi(argv[1]);
	colunas = atoi(argv[1]);
	alocar_matriz(matrizA,linhas,colunas);

	imprime_matriz(matrizA);

	return 0;

}