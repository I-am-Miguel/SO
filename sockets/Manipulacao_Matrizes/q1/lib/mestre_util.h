#ifndef MESTRE_UTIL_INCLUDED
#define MESTRE_UTIL_INCLUDED

#include "matriz_util.h"
#include "sockets_util.h"

#define LEN_ESCRAVOS 3

int porta_inicial=0;

Matriz matriz_A;
Matriz matriz_B;
Matriz matriz_C;

//Structs escravos
struct sockaddr_in *escravos;

//socket de comunicacao
int sock_A;
socklen_t slen_A;

//Funcoes
int configurarEscravos(int qtd_escravos,int porta_inicial);
int enviarTamanhoMatriz(int qtd_escravos);


#endif