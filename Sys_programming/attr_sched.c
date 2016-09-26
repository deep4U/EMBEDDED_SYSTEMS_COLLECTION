#include <stdio.h>
#include <linux/errno.h>
#include <pthread.h>

void * t_routine(void *null)
{
	int policy;
        struct sched_param param;

	pthread_getschedparam(pthread_self(),&policy,&param);
	// 0 - SCHED_OTHERS     1 - SCHED_FIFO          2 - SCHED_RR
        printf("\n Current Thread Policy : %d Priority : %d",policy,param.sched_priority);

	sleep(5);
	pthread_getschedparam(pthread_self(),&policy,&param);
	// 0 - SCHED_OTHERS     1 - SCHED_FIFO          2 - SCHED_RR
        printf("\n Current Thread Policy : %d Priority : %d\n",policy,param.sched_priority);
	pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
	int inherit,policy,priority,rc;
	pthread_t tcb;
	pthread_attr_t attr;
	struct sched_param param;

	pthread_attr_init(&attr);

        /* switch off sched inheritence from parent */	
	pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);
    
       /* Now assign Sched policy and priority */
	policy = SCHED_FIFO;
	pthread_attr_setschedpolicy(&attr,policy);
	
        param.sched_priority = 20;
        pthread_attr_setschedparam(&attr,&param);

        pthread_create(&tcb, &attr, t_routine, NULL);

        sleep(2);
	
        param.sched_priority = 10;
	policy = SCHED_RR;
	pthread_setschedparam(tcb, policy, &param);	
	
	/* destroy attribute object */
	pthread_attr_destroy(&attr);

	printf("\n Exiting from main Thread\n");
	pthread_exit(NULL);

}


