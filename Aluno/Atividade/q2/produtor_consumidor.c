#include "lib/produtor_consumidor.h"

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

	pthread_t thread_produtor[QTD_T_PRODUTOR], thread_consumidor[QTD_T_CONSUMIDOR];

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&condc, NULL);
	pthread_cond_init(&condp, NULL);
	
	int i;
	for (i = 0; i < QTD_T_PRODUTOR; ++i)
		pthread_create(&thread_produtor[i], NULL, produzir, (void *)(size_t) i);

	for (i = 0; i < QTD_T_CONSUMIDOR; ++i)	
		pthread_create(&thread_consumidor[i], NULL, consumir, (void *)(size_t) i);



	for (i = 0; i < QTD_T_PRODUTOR; ++i)
		pthread_join(thread_produtor[i], NULL);		
	
	for (i = 0; i < QTD_T_CONSUMIDOR; ++i)
		pthread_join(thread_consumidor[i], NULL);		
	

	pthread_mutex_destroy(&mutex);	
	pthread_cond_destroy(&condc);		
	pthread_cond_destroy(&condp);	

}


