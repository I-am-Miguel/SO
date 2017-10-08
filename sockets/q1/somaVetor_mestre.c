/****************** MESTRE ****************/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFLEN 512
#define SRV_IP "127.0.0.1"

int *faixa_portas;
int *vetor;
int len_portas;
int len_vetor;

int main(int argc, char *argv[]){

	struct sockaddr_in *escravos;
	int sock_A, i;
	socklen_t slen_A;
	char buf[BUFLEN];

	len_portas = atoi(argv[3]);
	faixa_portas = (int*) malloc(len_portas * sizeof(int));
	faixa_portas[0] = atoi(argv[1]);

	len_vetor = atoi(argv[2]);
	vetor = (int*) malloc(len_vetor * sizeof(int));

	escravos = (struct sockaddr_in*) malloc(len_portas * sizeof(struct sockaddr_in));
	slen_A =sizeof(escravos[0]);

	if((sock_A=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1){
		printf("ERRO AO CRIAR SOCKET\n");
		return 1;
	}

	for(i=0;i<len_vetor;i++){
		vetor[i]=(i+1)*10;//rand()%3;
	}

	for(i=1;i<len_portas;i++){
		faixa_portas[i]=faixa_portas[i-1]+1;
	}

	for(i=0;i<len_portas;i++)
	{
		memset((char*) &escravos[i], 0, sizeof(escravos[i]));
		escravos[i].sin_family = AF_INET;
		escravos[i].sin_port = htons(faixa_portas[i]);

		if(inet_aton(SRV_IP, &escravos[i].sin_addr) == 0){
			printf("ERRO AO TRANSFORMAR ENDEREÇO %d\n",faixa_portas[i]);
			return 1;
		}
	}

	printf("Enviando o tamanho do vetor\n");
	if(sendto(sock_A, &len_vetor, sizeof(int), 0, (struct sockaddr *) &escravos[0], slen_A)==-1){
		printf("ERRO AO ENVIAR PACOTE\n");
		return 1;
	}

	printf("Enviando quantidade de escravos necessários\n");
	if(sendto(sock_A, &len_portas, sizeof(int), 0, (struct sockaddr *) &escravos[0], slen_A)==-1){
		printf("ERRO AO ENVIAR PACOTE\n");
		return 1;
	}

	for (i = 0; i < len_portas; ++i)
	{    
		printf("Enviando o vetor [%d] para [%d]\n",i+1, ntohs(escravos[i].sin_port));
		if(sendto(sock_A, vetor, sizeof(int)*len_vetor, 0, (struct sockaddr *) &escravos[i], slen_A)==-1){
			printf("ERRO AO ENVIAR PACOTE\n");
			return 1;
		}
	}

	for (i = 0; i < len_portas; ++i)
	{  
		recvfrom(sock_A, buf, BUFLEN, 0, (struct sockaddr *) &escravos[i],&slen_A);
		printf("Pacote recebido de %s:%d\nDado: %s\n", inet_ntoa(escravos[i].sin_addr), ntohs(escravos[i].sin_port),  buf);
		
	}
	close(sock_A);
	return 0;
}
