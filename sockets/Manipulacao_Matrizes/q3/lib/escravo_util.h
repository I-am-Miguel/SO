#ifndef ESCRAVO_UTIL_INCLUDED
#define ESCRAVO_UTIL_INCLUDED

#include "matriz_util.h"
#include "sockets_util.h"
#include <pthread.h>

//Thread Mutex
pthread_mutex_t mutex;


Matriz matriz_A;
Matriz matriz_B;
Matriz matriz_C;

//Structs mestre
struct sockaddr_in mestre;

//socket de comunicacao
int s;
socklen_t slen = sizeof(mestre);

int LEN_MATRIZ=0;

//Funcoes
int configurarMestre();
void* multiplicaMatriz(void *p);

#endif