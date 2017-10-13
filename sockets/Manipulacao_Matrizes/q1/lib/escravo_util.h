#ifndef ESCRAVO_UTIL_INCLUDED
#define ESCRAVO_UTIL_INCLUDED

#include "matriz_util.h"
#include "sockets_util.h"

Matriz matriz_A;
Matriz matriz_B;
Matriz matriz_C;

//Structs mestre
struct sockaddr_in mestre;

//socket de comunicacao
int s;
socklen_t slen = sizeof(mestre);

//Funcoes
int configurarMestre();
void multiplicarMatriz();

#endif