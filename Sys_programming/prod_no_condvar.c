
/* prod_no_condvar.c

   A simple POSIX threads producer-consumer example.

*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } Boolean;

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static int avail = 0;

static void * threadFunc(void *arg)
{
    int cnt = *((int *) arg);
    int j;

    for (j = 0; j < cnt; j++) {
        sleep(1);

        /* Code to produce units */

         pthread_mutex_lock(&mtx);

         avail++;/* Let consumer know another unit is available */

        pthread_mutex_unlock(&mtx);
    }

    return NULL;
}

int main()
{
    pthread_t tid;
    int ret, j;
    int totRequired;            /* Total number of units that all
                                   threads will produce */
    int numConsumed = 0;            /* Total units so far consumer */
    Boolean done= FALSE;

    totRequired = 10;
  
   /* launch producer thread */

    ret = pthread_create(&tid, NULL, threadFunc, &totRequired);
	        if (ret != 0)
            	 perror("pthread_create:      ");


    /* Consumer code to process produced units */

    /* Use a polling loop to check for available units */
    for (;;) {
        	 pthread_mutex_lock(&mtx);

       			 while (avail > 0) {             /* Consume all available units */
            			/* Do something with produced unit */
           			 numConsumed ++;
            			 avail--;
            			 printf("numConsumed=%d\n",numConsumed);
            			 done = numConsumed >= totRequired;
        			}

         	 pthread_mutex_unlock(&mtx);

        if (done)
            break;

         }
	
    pthread_exit(NULL);
    exit(EXIT_SUCCESS);
}
