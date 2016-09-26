
/* 
   A program to demonstrate POSIX timer.
*/
#define _POSIX_C_SOURCE 199309

#define BUF_SIZE 1000

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

char * currTime(const char *);

static void handler(int sig, siginfo_t *si, void *uc)
{
    printf("[%s] Got signal %d\n", currTime("%T"), sig);
    printf("    sival_int          = %d\n", si->si_value.sival_int);
    printf("    timer_getoverrun() = %d\n",
            timer_getoverrun((timer_t) si->si_value.sival_ptr));
}

int main()
{
    struct itimerspec ts;
    timer_t tid;
    int j;
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGALRM, &sa, NULL) == -1)
        perror("sigaction");

    if (timer_create(CLOCK_REALTIME, NULL, &tid) == -1)
        perror("timer_create");
    printf("timer ID = %ld\n", (long) tid);

    ts.it_value.tv_sec = 2;
    ts.it_value.tv_nsec = 0;
    ts.it_interval.tv_sec = 0;
    ts.it_interval.tv_nsec = 0;

    if (timer_settime(tid, 0, &ts, NULL) == -1)
        perror("timer_settime");

    for (j = 0; ; j++)
        pause();
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

