
/* strerror_tsd.c

   An implementation of strerror() that is made thread-safe through
   the use of thread-specific data.

*/
#define _GNU_SOURCE                 /* Get '_sys_nerr' and '_sys_errlist'
                                       declarations from <stdio.h> */
#include <stdio.h>
#include <string.h>                 /* Get declaration of strerror() */
#include <pthread.h>

static pthread_once_t once = PTHREAD_ONCE_INIT;
static pthread_key_t strerrorKey;

#define MAX_ERROR_LEN 256           /* Maximum length of string in per-thread
                                       buffer returned by strerror() */

static void destructor(void *buf){                        /* Free thread-specific data buffer */
    
	free(buf);
}

static void createKey(void) {                       /* One-time key creation function */

    int ret;

    /* Allocate a unique thread-specific data key and save the address
       of the destructor for thread-specific data buffers */

    ret = pthread_key_create(&strerrorKey, destructor);
    if (ret != 0)
        perror("pthread_key_create");
}

char * strerror(int err)
{
    int ret;
    char *buf;

    /* Make first caller allocate key for thread-specific data */

    ret = pthread_once(&once, createKey);
    if (ret != 0)
        perror( "pthread_once");

    buf = pthread_getspecific(strerrorKey);
    if (buf == NULL) {          /* If first call from this thread, allocate
                                   buffer for thread, and save its location */
        buf = malloc(MAX_ERROR_LEN);
        if (buf == NULL)
            perror("malloc");

        ret = pthread_setspecific(strerrorKey, buf);
        if (ret != 0)
            perror("pthread_setspecific");
    }

    if (err < 0 || err >= _sys_nerr || _sys_errlist[err] == NULL) {
        snprintf(buf, MAX_ERROR_LEN, "Unknown error %d", err);
    } else {
        strncpy(buf, _sys_errlist[err], MAX_ERROR_LEN - 1);
        buf[MAX_ERROR_LEN - 1] = '\0';          /* Ensure null termination */
    }

    return buf;
}
