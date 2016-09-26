#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>


pthread_once_t once = PTHREAD_ONCE_INIT;
pthread_mutex_t *mymutex;

int i;
void *myinit() // run  once
{
	printf("\n I am in init fun\n");
	i = 1;
	mymutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mymutex, NULL);
}

void *  mythread(void *arg )
{
	pthread_once(&once,(void *)myinit);
	pthread_mutex_lock(mymutex);
	while(i<10)
		printf("Thread  %u in iteration %d \n", pthread_self(),i++);

	pthread_mutex_unlock(mymutex);
	
}

int main()
{
	int id = 0;
	pthread_t thread[3];

	pthread_create(&thread[0],NULL,mythread,NULL);

	pthread_create(&thread[1],NULL,mythread,NULL);	

	pthread_create(&thread[2],NULL,mythread,NULL);	

	while(id<3)
	{
		pthread_join(thread[id],NULL);
		id++;
	}
	return EXIT_SUCCESS;
}
	
