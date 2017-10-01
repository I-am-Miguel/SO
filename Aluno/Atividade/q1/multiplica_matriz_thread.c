#include "lib/multiplica_matriz_thread.h"

void* multiplica_matriz(void *p){
	int linhas, colunas;
	int i,j,aux,somaprod;

	i = (int)(size_t)p;
	
	printf("inicio da thread %d\n", i);
	
	linhas = matrizA->qtd_linhas;
	colunas = matrizA->qtd_colunas;

	
	pthread_mutex_lock(&mutex);	

	for(j=0;j<colunas;++j){
		somaprod=0;
		for(aux=0;aux<linhas;aux++)
			somaprod+=matrizA->dados[i][aux]*matrizB->dados[aux][j];
		matriz_resultante->dados[i][j]=somaprod;
		printf("Soma realizada pela thread %d, valor total = %d\n",i,somaprod);
	}
	printf("thread %d finalizada\n",i);
	pthread_mutex_unlock(&mutex);	
	pthread_exit(NULL);
}


int main(int argc, char const *argv[]){

	int tamanho = atoi(argv[1]);

	pthread_t tid[tamanho];

	pthread_mutex_init(&mutex, NULL);

	matrizA = (alocar_matriz(tamanho,tamanho));
	matrizB = (alocar_matriz(tamanho,tamanho));
	matriz_resultante = alocar_matriz(tamanho,tamanho);

	//*
	imprime_matriz(matrizA);
	printf("-----------\n");
	imprime_matriz(matrizB);
	//*/
	printf("-----------\n");

	int i;

	for(i=0;i<tamanho;i++)
		pthread_create(&tid[i], NULL, multiplica_matriz, (void *)(size_t) i);
	for(i=0;i<tamanho;i++)
		pthread_join(tid[i], NULL);

	imprime_matriz(matriz_resultante);
}