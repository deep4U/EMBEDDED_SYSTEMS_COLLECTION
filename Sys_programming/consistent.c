	/*	Example for implementing errorcheck mutex */
#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <errno.h>

// pthread mutex object
pthread_mutex_t mutex;


void recover(void)
{
	printf("\n Performing Recovery by Thread : %ld \n",pthread_self());
	pthread_mutex_consistent_np(&mutex);
	pthread_mutex_unlock(&mutex);	
	printf("\n Recovery completed by Thread : %ld \n",pthread_self());
	pthread_mutex_lock(&mutex);
}

 
// Threads created will execute the following routines

void * write_thread (void *p)
{
	if(pthread_mutex_lock(&mutex)==0)
	{
		printf("\nWrite thread: updating commits....\n");
		pthread_exit(NULL);
	}
}
void * read_thread1(void *p)
{
	int rv;
	sleep(1);
	rv = pthread_mutex_lock(&mutex);
	 if(rv==EOWNERDEAD)
        {
                printf("\n Owner Dead identified by : %ld\n",pthread_self());
		recover();
        }
        printf(" Lock acquired by : %ld\n",pthread_self());
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

void * read_thread2(void *p)
{
        int rv;
	sleep(2);
        rv = pthread_mutex_lock(&mutex);
        if(rv==EOWNERDEAD)
        {
                printf("\n Owner Dead identified by : %ld\n",pthread_self());
		recover();
        }
        printf(" Lock acquired by : %ld\n",pthread_self());
	sleep(4);
        pthread_mutex_unlock(&mutex);
        pthread_exit(NULL);
}


void * read_thread3(void *p)
{
        int rv;

        rv = pthread_mutex_lock(&mutex);
        if(rv==EOWNERDEAD)
        {
                printf("\n Owner Dead identified by : %ld\n", pthread_self());
		recover();
        }
        printf(" Lock aquaired by : %ld\n",pthread_self());
	sleep(2);
        pthread_mutex_unlock(&mutex);
        pthread_exit(NULL);
}



int main ()
{
	// Object to hold thread ID
	pthread_t tcb1,tcb2,tcb3,tcb4;

	// Mutex Attribute object
	pthread_mutexattr_t attr;
	int rv;

	// initializing mutex attribute object 
	pthread_mutexattr_init(&attr);

	//pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_ROBUST_NP);
	// initializing statically allocated mutex object 
	pthread_mutexattr_setrobust_np(&attr, PTHREAD_MUTEX_ROBUST_NP);
	pthread_mutex_init(&mutex,&attr);

	
	// Routine shell create a new thread
	rv = pthread_create(&tcb1, NULL, write_thread, NULL);
	if(rv)
		puts("Failed to create thread");

	rv = pthread_create(&tcb2, NULL, read_thread1, NULL);
        if(rv)
                puts("Failed to create thread");
	
	rv = pthread_create(&tcb3, NULL, read_thread2, NULL);
        if(rv)
                puts("Failed to create thread");

	rv = pthread_create(&tcb4, NULL, read_thread3, NULL);
        if(rv)
                puts("Failed to create thread");

	// suspend execution of the intial thread until the target threads terminate
	pthread_exit(NULL);
}
