#ifndef MULTIPLICA_MATRIZ_THREAD_INCLUDED
#define MULTIPLICA_MATRIZ_THREAD_INCLUDED

#include <pthread.h>
#include "matriz_util.h"

pthread_mutex_t mutex;

Matriz matrizA;
Matriz matrizB;
Matriz matriz_resultante;

void* multiplica_matriz(void *p);


#endif