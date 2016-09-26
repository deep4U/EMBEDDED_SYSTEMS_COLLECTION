/*
 * Threads with Mutexes (exiting while holding lock version)
 *
 @*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

#define DEATH(mess) { perror(mess); exit(errno); }

static char running = 1;        /* note this can be static now! */
static long long counter = 0;

pthread_mutex_t c_mutex;
int i;

/* This is the "computational" thread */
void *process (void *arg)
{
    while (running) {
        pthread_mutex_lock (&c_mutex);
        if (i > 4)
            pthread_exit (NULL);
        counter++;
        pthread_mutex_unlock (&c_mutex);
    }
    pthread_exit (NULL);
}

/* This is the "user interface" thread */
int main ()
{
    pthread_t threadId;
    void *retval;

    /* Initialize a mutex with default attributes */
    pthread_mutex_init (&c_mutex, NULL);

    /* Start up the processing thread. */
    if (pthread_create (&threadId, NULL, process, "0"))
        DEATH ("pthread_create");

    /* Every so often, look at the counter and print it out. */
    for (i = 0; i < 10; i++) {
        sleep (1);
        pthread_mutex_lock (&c_mutex);
        printf ("%lld\n", counter);
        pthread_mutex_unlock (&c_mutex);
    }

    /* Tell the processing thread to quit. */
    running = 0;

    /* Wait for the processing thread to quit. */
    if (pthread_join (threadId, &retval))
        DEATH ("pthread_join");

    return 0;
}
