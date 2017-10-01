#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex_valor_dado;
pthread_mutex_t mutex;

int qtd_leitores;
int valor_dado;
int qtd_thread_leitores;
int qtd_thread_escritores;

void* lendo(int i);
void* escrevendo(int i);

