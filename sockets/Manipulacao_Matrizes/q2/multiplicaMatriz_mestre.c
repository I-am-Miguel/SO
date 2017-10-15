/****************** MESTRE ****************/
#include "lib/mestre_util.h"

int main(int argc, char const *argv[])
{
	porta_inicial = atoi(argv[1]);
	LEN_MATRIZ = atoi(argv[2]);
	LEN_ESCRAVOS = LEN_MATRIZ;
	
	int  i,j;

	matriz_A = (alocar_matriz(LEN_MATRIZ,LEN_MATRIZ));
	matriz_B = (alocar_matriz(LEN_MATRIZ,LEN_MATRIZ));
	matriz_C = (alocar_matriz(LEN_MATRIZ,LEN_MATRIZ));	
	
	if((sock_A=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1){
		printf("ERRO AO CRIAR SOCKET\n");
		return 1;
	}

	//Configurando escravos
	if(configurarEscravos(LEN_MATRIZ,porta_inicial)==1)
		return 1;

	//Enviando tamanho da matriz para todos os escravos
	enviarTamanhoMatriz(LEN_ESCRAVOS);
	

	printf("-------MATRIZ_A-------------\n");
	
	imprime_matriz(matriz_A);


	printf("-------MATRIZ_B-------------\n");
	imprime_matriz(matriz_B);

	//Enviando linha a linha da matriz para escravos diferentes
	printf("Enviando Dados da 1ª matriz\n");
	for (i = 0; i < LEN_ESCRAVOS; ++i)
	{    
		printf("Enviando o linha [%d] para [%d]\n",i+1, ntohs(escravos[i].sin_port));
		if(sendto(sock_A, matriz_A->dados[i], sizeof(int)*LEN_MATRIZ, 0, (struct sockaddr *) &escravos[i], slen_A)==-1){
			printf("ERRO AO ENVIAR PACOTE\n");
			return 1;
		}
	}

	//Enviando a matriz 2 para todos os escravos 
	printf("\n\nEnviando Dados da 2ª matriz\n");
	for (i = 0; i < LEN_ESCRAVOS; ++i)
	{    
		printf("Enviando o matriz 2 para [%d]\n", ntohs(escravos[i].sin_port));
		for (j = 0; j < LEN_MATRIZ; ++j)
		{	
			if(sendto(sock_A, matriz_B->dados[j], sizeof(int)*LEN_MATRIZ, 0, (struct sockaddr *) &escravos[i], slen_A)==-1){
				printf("ERRO AO ENVIAR PACOTE\n");
				return 1;
			}
		}
		
	}

	
	for (i = 0; i < LEN_ESCRAVOS; ++i)
	{  
		recvfrom(sock_A, matriz_C->dados[i], sizeof(int)*LEN_MATRIZ, 0, (struct sockaddr *) &escravos[i],&slen_A);
		printf("Pacote recebido de %s:%d\n", inet_ntoa(escravos[i].sin_addr), ntohs(escravos[i].sin_port));
		
	}
	

	printf("Matriz Resultante\n");
	
	imprime_matriz(matriz_C);
	
	close(sock_A);
	return 0;
}

int configurarEscravos(int qtd_escravos,int porta_inicial)
{
	escravos = (struct sockaddr_in*) malloc(qtd_escravos * sizeof(struct sockaddr_in));
	slen_A =sizeof(escravos[0]);

	for(int i=0; i<qtd_escravos; ++i)
	{
		memset((char*) &escravos[i], 0, sizeof(escravos[i]));
		escravos[i].sin_family = AF_INET;
		escravos[i].sin_port = htons(porta_inicial+i);

		if(inet_aton(SRV_IP, &escravos[i].sin_addr) == 0){
			printf("ERRO AO TRANSFORMAR ENDEREÇO %d\n",(porta_inicial+i));
			return 1;
		}
	}
	return 0;
}

int enviarTamanhoMatriz(int qtd_escravos){
	for (int i = 0; i < qtd_escravos; ++i)
	{
		printf("Enviando o tamanho da matriz\n");
		if(sendto(sock_A, &LEN_MATRIZ, sizeof(int), 0, (struct sockaddr *) &escravos[i], slen_A)==-1){
			printf("ERRO AO ENVIAR PACOTE\n");
			return 1;
		}
	}
	return 0;
}