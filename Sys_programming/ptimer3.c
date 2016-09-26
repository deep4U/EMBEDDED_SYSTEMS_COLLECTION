/* 
   This program demonstrates the use of threads as the notification mechanism
   for expirations of a POSIX timer.
   The timer notification method is specified as SIGEV_THREAD, causing the
   timer notifications to be delivered via a thread that invokes threadFunc()
   as its start function. The threadFunc() function displays information
   about the timer expiration, increments a global counter of timer expirations,
   and signals a condition variable to indicate that the counter has changed.
   In the main thread, a loop waits on the condition variable, and each time
   the condition variable is signaled, the main thread prints the value of the
   global variable that counts timer expirations.

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>

#define BUF_SIZE 1000

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int expireCnt = 0;           /* Number of expirations of all timers */

char * currTime(const char *);

static void threadFunc(union sigval sv)  /* Thread notification function */
{
    timer_t *tidptr;
    int s;

    tidptr = sv.sival_ptr;

    printf("[%s] Thread notify\n", currTime("%T"));
    printf("    timer ID=%ld\n", (long) *tidptr);
    printf("    timer_getoverrun()=%d\n", timer_getoverrun(*tidptr));

    /* Increment counter variable shared with main thread and signal
       condition variable to notify main thread of the change. */

    s = pthread_mutex_lock(&mtx);
    if (s != 0)
        perror("pthread_mutex_lock");

    expireCnt += 1 + timer_getoverrun(*tidptr);

    s = pthread_mutex_unlock(&mtx);
    if (s != 0)
        perror( "pthread_mutex_unlock");

    s = pthread_cond_signal(&cond);
    if (s != 0)
        perror("pthread_cond_signal");
}

int main()
{
    struct sigevent sev;
    struct itimerspec ts;
    timer_t tid;
    int s, j;


    sev.sigev_notify = SIGEV_THREAD;            /* Notify via thread */
    sev.sigev_notify_function = threadFunc;     /* Thread start function */
    sev.sigev_notify_attributes = NULL;         /* Could be pointer to pthread_attr_t structure */

    /* Create and start timer */
    
    ts.it_interval.tv_sec = 2;
    ts.it_interval.tv_nsec = 10;
    ts.it_value.tv_sec = 1;
    ts.it_value.tv_nsec = 20;


    sev.sigev_value.sival_ptr = &tid ; /* Passed as argument to threadFunc() */

        if (timer_create(CLOCK_REALTIME, &sev, &tid) == -1){
            perror("timer_create");
	    exit(1);
            }

        if (timer_settime(tid, 0, &ts, NULL) == -1)
            perror("timer_settime");

    /* The main thread waits on a condition variable that is signaled
       on each invocation of the thread notification function. We
       print a message so that the user can see that this occurred. */

    s = pthread_mutex_lock(&mtx);
    if (s != 0)
        perror("pthread_mutex_lock");

    for (;;) {
        s = pthread_cond_wait(&cond, &mtx);
        if (s != 0)
            perror("pthread_cond_wait");
        printf("main(): expireCnt = %d\n", expireCnt);
    }
}


/* Return a string containing the current time formatted according to
 * the specification in 'format' (see strftime(3) for specifiers).
 * If 'format' is NULL, we use "%c" as a specifier (which gives the'
 * date and time as for ctime(3), but without the trailing newline).
 * Returns NULL on error. */

char * currTime(const char *format)
{
    static char buf[BUF_SIZE];  /* Nonreentrant */
    time_t t;
    size_t s;
    struct tm *tm;

    t = time(NULL);
    tm = localtime(&t);
    if (tm == NULL)
        return NULL;

    s = strftime(buf, BUF_SIZE, (format != NULL) ? format : "%c", tm);

    return (s == 0) ? NULL : buf;
}

