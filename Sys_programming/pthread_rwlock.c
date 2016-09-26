#include <pthread.h>
#include <stdio.h>

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER; 
// Can also use pthread_rwlock_init (pthread_rwlock_t *, pthread_rwlockattr_t *);

 
void * writer(void *p)
{
	/* writer lock interfaces available
			pthread_rwlock_wrlock (pthread_rwlock_t *);
			pthread_rwlock_trywrlock (pthread_rwlock_t *);
			pthread_rwlock_timedwrlock (pthread_rwlock_t *,struct timespec *); */
/*	printf("WRITER: waiting on lock \n");	
	sleep(4);	*/
	if(pthread_rwlock_wrlock(&rwlock)!=0)
		printf("\n Error :: Failed to Acquire Write Lock\n");
	else
	{
		printf("Successfully Acquired Write Lock\nWriting .........\n");
		sleep(1);
		printf("Writer: releasing write lock \n");
		pthread_rwlock_unlock(&rwlock);
	}	
	pthread_exit(NULL);	
}

void * reader(void *p)
{
	 /* Reader lock interfaces available
                        pthread_rwlock_rdlock (pthread_rwlock_t *);
                        pthread_rwlock_tryrdlock (pthread_rwlock_t *);
                        pthread_rwlock_timedrdlock (pthread_rwlock_t *,struct timespec *); */

	if(pthread_rwlock_rdlock(&rwlock)!=0)
		printf("\n Error :: Failed to Acquire Read Lock by %ld \n" , pthread_self());
	else
	{
		
		printf("Reader Thread %ld : Read Lock acquired\n", pthread_self());
		sleep(3);
		printf("Reader Thread %ld :Releasing read lock \n", pthread_self());
		pthread_rwlock_unlock(&rwlock);
	}
        pthread_exit(NULL);
}

int main ()
{
	pthread_t tcb1,tcb2,tcb3;
	int rv;
	
	rv = pthread_create(&tcb1, NULL, writer, NULL);
	if(rv)
		puts("Failed to create thread");

	rv = pthread_create(&tcb2, NULL, reader, NULL);
        if(rv)
                puts("Failed to create thread");

	rv = pthread_create(&tcb3, NULL, reader, NULL);
        if(rv)
                puts("Failed to create thread");

	pthread_join(tcb1,NULL);
	pthread_join(tcb2,NULL);
	pthread_join(tcb3,NULL);
	return 0;
}
