/****************** ESCRAVO ****************/
#include "lib/escravo_util.h"


int main(int argc, char const *argv[])
{
	int i;

	PORT = atoi(argv[1]);

	if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1){
		printf("ERRO NA CRICAO DO SOCKET");
		return 1;
	}

	if(configurarMestre()==1)
		return 1;

	printf("Escravo Inicializado\n");

	//recebendo tamanho da matriz
	if(recvfrom(s, &LEN_MATRIZ, sizeof(int), 0, (struct sockaddr *) &mestre, &slen)==-1){
		printf("ERRO AO RECEBER TAMANHO DA MATRIZ\n");
		return 1;
	}
	printf("[PACOTE RECEBIDO]: TAMANHO DA MATRIZ = %d\n",LEN_MATRIZ);
	printf("[PACOTE RECEBIDO]: NECESSIDADE DE THREADS = %d\n",LEN_MATRIZ);
	matriz_A = (alocar_matriz(LEN_MATRIZ,LEN_MATRIZ));
	matriz_B = (alocar_matriz(LEN_MATRIZ,LEN_MATRIZ));
	matriz_C = (alocar_matriz(LEN_MATRIZ,LEN_MATRIZ));

	int matriz_aux[LEN_MATRIZ][LEN_MATRIZ];
	
	printf("RECEBENDO DADOS DA 1ª MATRIZ\n");
	for (i = 0; i < LEN_MATRIZ; ++i)
	{
		if(recvfrom(s, &matriz_aux[i], sizeof(int)*LEN_MATRIZ, 0, (struct sockaddr *) &mestre, &slen)==-1){
			printf("ERRO AO RECEBER DADO");
			return 1;
		}
	}
	printf("[PACOTE RECEBIDO]: DADOS DA MATRIZ 1\n");

	printf("-------MATRIZ_A-------------\n");
	for (i = 0; i < matriz_A->qtd_linhas; ++i)
	{
		clona_matriz(matriz_A,matriz_aux[i],i);
	}
	imprime_matriz(matriz_A);

	printf("\nRECEBENDO DADOS DA 2ª MATRIZ\n");
	for (i = 0; i < LEN_MATRIZ; ++i)
	{
		if(recvfrom(s, &matriz_aux[i], sizeof(int)*LEN_MATRIZ, 0, (struct sockaddr *) &mestre, &slen)==-1){
			printf("ERRO AO RECEBER DADO");
			return 1;
		}
	}
	printf("[PACOTE RECEBIDO]: DADOS DA MATRIZ 2\n");
	
	printf("\n-------MATRIZ_B-------------\n");
	for (i = 0; i < matriz_B->qtd_linhas; ++i)
	{
		clona_matriz(matriz_B,matriz_aux[i],i);
	}
	imprime_matriz(matriz_B);
	printf("\n");

	//Quantidade de threads
	pthread_t tid[LEN_MATRIZ];

	//Inicializando Mutex
	pthread_mutex_init(&mutex, NULL);

	//Efetuando calculo de multiplicação 1 linha opr thread
	for(i=0;i<LEN_MATRIZ;i++)
		pthread_create(&tid[i], NULL, multiplicaMatriz, (void *)(size_t) i);
	for(i=0;i<LEN_MATRIZ;i++)
		pthread_join(tid[i], NULL);

	for (int i = 0; i < matriz_C->qtd_linhas; ++i)
	{
		printf("\nEscravo retornando linha %d para #%d\n",i, htons(mestre.sin_port));
		sendto(s, matriz_C->dados[i], sizeof(int)*LEN_MATRIZ, 0, (struct sockaddr *)&mestre, slen);
	}
	
	return 0;
}

int configurarMestre(){
	memset((char*) &mestre, 0, sizeof(mestre));
	mestre.sin_family = AF_INET;
	mestre.sin_port = htons(PORT);
	mestre.sin_addr.s_addr = htonl(INADDR_ANY);


	if(bind(s, (struct sockaddr *) &mestre, sizeof(mestre))==-1){
		printf("ERRO NO BINDING");
		return 1;
	}
	return 0;
}


void* multiplicaMatriz(void *p){
	int linhas, colunas;
	int i,j,aux,somaprod;

	i = (int)(size_t)p;
	
	printf("\ninicio da thread %d\n", i);
	
	linhas = matriz_A->qtd_linhas;
	colunas = matriz_A->qtd_colunas;

	//Bloqueando o mutex
	pthread_mutex_lock(&mutex);	

	for(j=0;j<colunas;++j){
		somaprod=0;
		for(aux=0;aux<linhas;aux++)
			somaprod+=matriz_A->dados[i][aux]*matriz_B->dados[aux][j];
		matriz_C->dados[i][j]=somaprod;
	}
	
	printf("\n------Resultado------\n");
	for (j = 0; j < LEN_MATRIZ; ++j)
	{
		printf("%d\t",matriz_C->dados[i][j]);
	}

	printf("\nthread %d finalizada\n",i);

	//Mutex Liberado
	pthread_mutex_unlock(&mutex);	
	pthread_exit(NULL);
}