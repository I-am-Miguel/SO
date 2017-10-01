#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t condc, condp;

int buffer;
int tamanho_buffer;

void* produzir(void *p) {
	
	while(1){
		pthread_mutex_lock(&mutex);

		while (buffer == tamanho_buffer)	{	      
			printf("PRODUTOR %d: Buffer CHEIO. Indo dormir\n",(int)(size_t)p);
			pthread_cond_wait(&condp, &mutex);
		}
		buffer += 1;
		printf("PRODUTOR %d: Acordado! Produzindo...\n",(int)(size_t)p);
		pthread_cond_signal(&condc);	
		pthread_mutex_unlock(&mutex);	
		
	}
	pthread_exit(0);
}

void* consumir(void *p) {

	while(1) {
		pthread_mutex_lock(&mutex);
		while (buffer == 0){			
			printf("CONSUMIDOR %d: Buffer VAZIO. Indo dormir\n",(int)(size_t)p);
			pthread_cond_wait(&condc, &mutex);
		}
		buffer -= 1;
		printf("CONSUMIDOR %d: Acordado! Consumindo...\n",(int)(size_t)p);
		
		pthread_cond_signal(&condp);	
		pthread_mutex_unlock(&mutex);	
	}
	pthread_exit(0);
}

int main(int argc, char **argv) {

	tamanho_buffer = atoi(argv[1]);
	buffer = 0;

	pthread_t thread_produtor[2], thread_consumidor[3];

	pthread_mutex_init(&mutex, NULL);

	int i;
	
	pthread_cond_init(&condc, NULL);
	pthread_cond_init(&condp, NULL);
	

	for (i = 0; i < 2; ++i)
	{
		pthread_create(&thread_produtor[i], NULL, produzir, (void *)(size_t) i);
	}
	for (i = 0; i < 3; ++i)
	{
		pthread_create(&thread_consumidor[i], NULL, consumir, (void *)(size_t) i);
	}

	for (i = 0; i < tamanho_buffer; ++i)
	{
		pthread_join(thread_consumidor[i], NULL);
		pthread_join(thread_produtor[i], NULL);
	}

	pthread_mutex_destroy(&mutex);	
	pthread_cond_destroy(&condc);		
	pthread_cond_destroy(&condp);	

}


