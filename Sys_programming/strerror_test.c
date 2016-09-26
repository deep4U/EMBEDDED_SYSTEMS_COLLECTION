/* strerror_test.c

   A program to test whether the implementation of strerror() thread-safe.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>                 /* Get declaration of strerror() */
#include <pthread.h>

#define DEATH(mess) { perror(mess); exit(errno); }

static void * threadFunc(void *arg)
{
    char *str;

    printf("Other thread about to call strerror()\n");
    str = strerror(EPERM);
    printf("Other thread: str (%p) = %s\n", str, str);

    return NULL;
}

int main()
{
    pthread_t t;
    int ret;
    char *str;

    str = strerror(EINVAL);
    printf("Main thread has called strerror()\n");

    ret = pthread_create(&t, NULL, threadFunc, NULL);
    if (ret != 0)
        DEATH ("pthread_create");

    ret = pthread_join(t, NULL);
    if (ret != 0)
        DEATH ("pthread_join");

    /* If strerror() is not thread-safe, then the output of this printf() be
       the same as that produced by the analogous printf() in threadFunc() */

    printf("Main thread:  str (%p) = %s\n", str, str);

    exit(EXIT_SUCCESS);
}
