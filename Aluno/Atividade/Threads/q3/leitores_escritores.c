#include "lib/leitores_escritores.h"

void* lendo(int i) {
	while (1) {

		sleep(1);
  		pthread_mutex_lock(&mutex);
	    qtd_leitores=qtd_leitores+1;

	    if(qtd_leitores==1)
	    {
	    	pthread_mutex_lock(&mutex_valor_dado);
	    }
	    pthread_mutex_unlock(&mutex);

	    printf("Leitor #%d: lendo dado %d\n",i,valor_dado);
	    pthread_mutex_lock(&mutex);
	    qtd_leitores=qtd_leitores-1;

	    if(qtd_leitores==0) 
	    {
	    	pthread_mutex_unlock(&mutex_valor_dado);
	    }
	    pthread_mutex_unlock(&mutex);
	}
}

void* escrevendo(int i) {

	while(1)
	{
	    sleep(2);
        pthread_mutex_lock(&mutex_valor_dado);
        
        valor_dado+=1;

        printf("Escritor #%d: escrevendo dado %d\n",i,valor_dado);        

        pthread_mutex_unlock(&mutex_valor_dado);
    }
}


int main(int argc, char const *argv[])
{
	qtd_thread_leitores = atoi(argv[1]);
	qtd_thread_escritores = atoi(argv[2]);

	valor_dado = 0;
	pthread_t escrevendothreads[qtd_thread_escritores], lendothreads[qtd_thread_leitores]; 

	pthread_mutex_init(&mutex_valor_dado, NULL);
	pthread_mutex_init(&mutex, NULL);

	int i;
	for(i=0;i<qtd_thread_escritores;i++){
		pthread_create( &escrevendothreads[i], NULL,(void *) escrevendo, (int*) (size_t)i);
	}

	for(i=0;i<qtd_thread_leitores;i++){
		pthread_create( &lendothreads[i], NULL,(void *) lendo, (int*) (size_t)i);
	}


	for(i=0;i<qtd_thread_escritores;i++){
		pthread_join(escrevendothreads[i], NULL);
	}

	for(i=0;i<qtd_thread_leitores;i++){
		pthread_join(lendothreads[i], NULL);
	}


	return 0;
}