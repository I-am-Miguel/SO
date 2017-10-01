#include "lib/matriz_util.h"

void imprime_matriz(Matriz matriz){
	int linhas_locais, colunas_locais;

	linhas_locais = matriz->qtd_linhas;
	colunas_locais = matriz->qtd_colunas;

	int i, j=0;

	for(i=0;i<linhas_locais;i++){
	
		for(j=0;j<colunas_locais;j++){
	
			printf("%d\t", matriz->dados[i][j]);
		}
		printf("\n");
	}
}

Matriz inicializa_matriz(Matriz matriz){	

	int j=0, i=0;
	for (i = 0; i < matriz->qtd_linhas; ++i)
	{		
		for(j=0;j< matriz->qtd_colunas;++j){
			matriz->dados[i][j] = rand()%3;
		}
	}	
	return matriz;
}

Matriz alocar_matriz (int linhas_locais,int colunas_locais){  
  Matriz matriz = new tipo_Matriz;

  matriz->qtd_colunas = colunas_locais;
  matriz->qtd_linhas = linhas_locais;


  matriz->dados = (int**)malloc(linhas_locais * sizeof(int*));


  /* aloca as colunas da matriz */
  int   index;
  for ( index = 0; index < colunas_locais; index++ ) {
      matriz->dados[index] = (int*) malloc (colunas_locais * sizeof(int));      
  }    

  return inicializa_matriz(matriz);
}