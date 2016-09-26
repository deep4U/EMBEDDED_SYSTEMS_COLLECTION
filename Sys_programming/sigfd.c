/* 
   Demonstrate the use of signalfd() to receive signals via a file descriptor.

   This program is Linux-specific. The signalfd API is supported since kernel
   2.6.22.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/signalfd.h>
#include <signal.h>

#define DEATH(mess) { perror(mess); exit(errno); }


void handler(int signum)
{
	printf(" Got Signal %d \n", signum);
}


int main(int argc, char *argv[])
{
    sigset_t mask;
    int sfd, j;
    struct signalfd_siginfo fdsi;
    ssize_t s;

    signal(SIGINT, handler);
    signal(SIGQUIT, handler);

    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGQUIT);
    sigaddset(&mask, SIGTERM);

    if (sigprocmask(SIG_BLOCK, &mask, NULL) == -1)
        DEATH ("sigprocmask");

    sfd = signalfd(-1, &mask, 0);
    if (sfd == -1)
        DEATH ("signalfd");

    for (;;) {
        s = read(sfd, &fdsi, sizeof(struct signalfd_siginfo));
        if (s != sizeof(struct signalfd_siginfo))
            DEATH ("read");

        printf("%s: got signal %d", argv[0], fdsi.ssi_signo);
        if (fdsi.ssi_code == SI_QUEUE) {
            printf("; ssi_pid = %d; ", fdsi.ssi_pid);
            printf("ssi_int = %d", fdsi.ssi_int);
        }
        printf("\n");
    }
}
