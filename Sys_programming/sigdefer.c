/*
 * sigaction()
 *
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define DEATH(mess) { perror(mess); exit(errno); }

/* our signal handlers */

void handler (int signum)
{
    printf ("We have received signal :  %d \n", signum);
    sleep(5);
    printf(" exit from sighandler \n");
}

int main (int argc, char *argv[])
{
    struct sigaction act;

    memset (&act, 0, sizeof (act));

    /* Install signal handlers */
    act.sa_flags = SA_NODEFER;
    act.sa_handler = handler;
    if (sigaction (SIGINT, &act, NULL) < 0) /* for CTRL-C */
        DEATH ("sigaction");

    printf ("Successfully installed signal handler for SIGINT\n");

    /* Do something pointless, forever */
    for (;;) {
        printf ("This is a pointless message.\n");
        sleep (1);
    }

    exit (0);
}
