/* 
   This program demonstrates the use of signals as the notification mechanism
   for expirations of a POSIX timer.The program establishes a handler for the 
   timer notification signal and then pauses. Each timer expiration causes the
   generation of a signal

*/
#define _POSIX_C_SOURCE 199309
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define TIMER_SIG SIGRTMAX              /* Our timer notification signal */
#define BUF_SIZE 1000

char * currTime(const char *);

static void handler(int sig, siginfo_t *si, void *uc)
{
    timer_t *tidptr;

    tidptr = si->si_value.sival_ptr;


    printf("(%s) Got signal %d\n", currTime("%T"), sig);
    printf("    *sival_ptr         = %ld\n", (long) *tidptr);
    printf("    timer_getoverrun() = %d\n", timer_getoverrun(*tidptr));
}

int main(int argc, char *argv[])
{
    struct itimerspec ts;
    struct sigaction  sa;
    struct sigevent   sev;
    timer_t tid;
    int j;

    /* Establish handler for notification signal */

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    if (sigaction(TIMER_SIG, &sa, NULL) == -1){
        perror("sigaction");
	}

    /* Create and start timer  */

    ts.it_interval.tv_sec = 2;
    ts.it_interval.tv_nsec = 10;
    ts.it_value.tv_sec = 1;
    ts.it_value.tv_nsec = 20;

   /* pass timer id to handler */
    sev.sigev_value.sival_ptr = &tid;


    sev.sigev_notify = SIGEV_SIGNAL;    /* Notify via signal */
    sev.sigev_signo = TIMER_SIG;        /* Notify using this signal */

    if (timer_create(CLOCK_REALTIME, &sev, &tid) == -1){
            perror("timer_create");
	    exit(1);
	   }

        if (timer_settime(tid, 0, &ts, NULL) == -1)
            perror("timer_settime");

    for (;;)                            /* Wait for incoming timer signals */
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

