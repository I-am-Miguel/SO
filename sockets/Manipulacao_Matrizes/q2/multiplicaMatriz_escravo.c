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

	matriz_A = (alocar_matriz(LEN_MATRIZ,LEN_MATRIZ));
	matriz_B = (alocar_matriz(LEN_MATRIZ,LEN_MATRIZ));
	matriz_C = (alocar_matriz(LEN_MATRIZ,LEN_MATRIZ));

	int matriz_aux[LEN_MATRIZ][LEN_MATRIZ];
	
	printf("RECEBENDO DADOS DA 1ª MATRIZ\n");
	if(recvfrom(s, &matriz_aux[0], sizeof(int)*LEN_MATRIZ, 0, (struct sockaddr *) &mestre, &slen)==-1){
		printf("ERRO AO RECEBER DADO");
		return 1;
	}
	printf("[PACOTE RECEBIDO]: DADOS DA MATRIZ 1\n");

	printf("-------MATRIZ_A-------------\n");
	clona_matriz(matriz_A,matriz_aux[0],0);
	imprime_matriz(matriz_A);

	printf("RECEBENDO DADOS DA 2ª MATRIZ\n");
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

	//Efetuando calculo de multiplicação de apenas 1 linha
	multiplicarMatriz();

	printf("\nEscravo retornando linha para #%d\n", htons(mestre.sin_port));
	sendto(s, matriz_C->dados[0], sizeof(int)*LEN_MATRIZ, 0, (struct sockaddr *)&mestre, slen);
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

void multiplicarMatriz(){
	int somaprod;
	//Percorrendo colunas da matriz A
	for(int j=0;j<LEN_MATRIZ;++j){
		somaprod=0;

		//Percorrendo linhas matriz B
		for(int aux=0;aux<LEN_MATRIZ;aux++){
			somaprod+=matriz_A->dados[0][aux]*matriz_B->dados[aux][j];
			matriz_C->dados[0][j] = somaprod;
		}
	}

	printf("------Resultado------\n");
	for (int i = 0; i < LEN_MATRIZ; ++i)
	{
		printf("%d\t",matriz_C->dados[0][i]);
	}
}