
/* detached_attrib.c

   An example of the use of POSIX thread attributes (pthread_attr_t):
   creating a detached thread.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>


#define DEATH(mess) { perror(mess); exit(errno); }

static void * threadFunc(void *x)
{
    return x;
}

int main(int argc, char *argv[])
{
    pthread_t thr;
    pthread_attr_t attr;
    int ret;

    ret = pthread_attr_init(&attr);       /* Assigns default values */
    if (ret!= 0)
       perror("pthread_attr_init");

    ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (ret != 0)
        perror("pthread_attr_getdetachstate");

    ret = pthread_create(&thr, &attr, threadFunc, (void *) 1);
    if (ret != 0)
        DEATH ("pthread_create");

    ret = pthread_attr_destroy(&attr);    /* No longer needed */
    if (ret != 0)
        perror( "pthread_attr_destroy");

    ret = pthread_join(thr, NULL);
    if (ret != 0)
        perror("pthread_join failed as expected");

    exit(EXIT_SUCCESS);
}
