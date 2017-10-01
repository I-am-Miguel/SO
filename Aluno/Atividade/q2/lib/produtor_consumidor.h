#ifndef PRODUTOR_CONSUMIDOR_INCLUDED
#define PRODUTOR_CONSUMIDOR_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QTD_T_CONSUMIDOR 3
#define QTD_T_PRODUTOR 2

pthread_mutex_t mutex;
pthread_cond_t condc, condp;

int buffer;
int tamanho_buffer;



#endif