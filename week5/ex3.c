#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;
pthread_cond_t cons_cond, prod_cond;
int buffer = 0;

void *producer (void *arg) {
	int iter = 0;
	while (1) {
		pthread_mutex_lock(&lock);
    	while (buffer != 0) {      
			pthread_cond_wait (&prod_cond, &lock);
    	}
		buffer = iter;
	    iter = iter + 1;
	    pthread_cond_signal (&cons_cond);
    	pthread_mutex_unlock(&lock);
  	}
  	pthread_exit(0);
}

void *consumer (void *arg) {
  	int iter = 0;
  	while (1) {
  		pthread_mutex_lock(&lock);
    	while (buffer == 0) {
      		pthread_cond_wait (&cons_cond, &lock);
    	}
    	buffer = 0;
    	iter = iter + 1;
    	
    	pthread_cond_signal (&prod_cond);
    	pthread_mutex_unlock(&lock);
    	
    	printf ("produces: %d\n", iter);
  	}
  	pthread_exit(0);
}

int main () {
  pthread_t cons, prod;
  
  pthread_mutex_init (&lock, 0);
  
  pthread_cond_init (&cons_cond, 0);
  pthread_cond_init (&prod_cond, 0);
  
  pthread_create (&cons, 0, consumer, 0);
  pthread_create (&prod, 0, producer, 0);
  
  pthread_join (cons, 0);
  pthread_join (prod, 0);
  
  pthread_cond_destroy (&cons_cond);
  pthread_cond_destroy (&prod_cond);
  
  pthread_mutex_destroy(&lock);
  
  return 0;
}
