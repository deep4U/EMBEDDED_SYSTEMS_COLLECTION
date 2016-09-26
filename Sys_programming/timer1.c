#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>

static volatile sig_atomic_t gotAlarm = 0;

static void sigalrmHandler(int sig)
{
    printf(" got sigalarm %d times \n", ++gotAlarm);
}

int main(int argc, char *argv[])
{
    struct itimerval itv;
    struct sigaction sa;


    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = sigalrmHandler;
    if (sigaction(SIGALRM, &sa, NULL) == -1)
        perror("sigaction");

    /* Set timer */

    itv.it_value.tv_sec = 1;
    itv.it_value.tv_usec = 10;
    itv.it_interval.tv_sec = 2;
    itv.it_interval.tv_usec = 10;


    if (setitimer(ITIMER_REAL, &itv, NULL) == -1){
        perror("setitimer : ");
	exit(1);
	}
   while(1);

}
