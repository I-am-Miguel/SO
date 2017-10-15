#ifndef MESTRE_UTIL_INCLUDED
#define MESTRE_UTIL_INCLUDED

#include "matriz_util.h"
#include "sockets_util.h"

int porta_inicial = 0;
int LEN_ESCRAVOS = 0;
int LEN_MATRIZ = 0;

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