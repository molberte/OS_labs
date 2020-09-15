#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;
int cnt = 0;

void *Thread(void *vargp) 
{ 
	unsigned int* thread_id = (unsigned int*) vargp;
	pthread_mutex_lock(&lock);
	cnt = cnt+1;
  	printf("it's id is: %u\n",  *thread_id);
    printf("thread number %d with id: %u  has been finished\n", cnt, *thread_id);

    pthread_mutex_unlock(&lock);
 
}

int main() {

	int n = 5;
	pthread_mutex_init(&lock, NULL);

	pthread_t thread_id[n];
	for (int i = 0; i < n; i++)
		if (pthread_create(&thread_id[i], NULL, Thread, (void *) &thread_id[i]) == 0) 
			printf("thread number %d has been created\n", i + 1);

	for (int i = 0; i < n; i++)
		pthread_join(thread_id[i], NULL);

	pthread_mutex_destroy(&lock);
	return 0;
}
