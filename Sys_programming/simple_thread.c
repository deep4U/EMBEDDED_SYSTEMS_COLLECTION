/* simple_thread.c

   A simple POSIX threads example: create a thread, and then join with it.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

#define DEATH(mess) { perror(mess); exit(errno); }

static void * threadFunc(void *arg)
{
    char *s = (char *) arg;

    printf("%s", s);

    return (void *) strlen(s);
}

int main(int argc, char *argv[])
{
    pthread_t t1;
    void *res;
    int ret;

    ret = pthread_create(&t1, NULL, threadFunc, "Hello world\n");
    if (ret != 0)
        DEATH ("pthread_create");

    printf("Message from main()\n");

    ret = pthread_join(t1, &res);
    if (ret != 0)
        perror( "pthread_join");

    printf("Thread returned %ld\n", (long) res);

    exit(EXIT_SUCCESS);
}
