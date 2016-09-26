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

void handler (int what)
{
    printf ("We have received SIGALRM: Executing periodic work\n");
    sleep (10);
    printf (" done sleeping 2 seconds\n");
    alarm(5);
}

int main (int argc, char *argv[])
{
    struct sigaction act;

    memset (&act, 0, sizeof (act));

    /* Install signal handlers */
    act.sa_handler = handler;
    if (sigaction (SIGALRM, &act, NULL) < 0) /* for CTRL-C */
        DEATH ("sigaction");

    printf ("Successfully installed signal handler for SIGINT\n");

     alarm(5);

    /* Do something pointless, forever */
    for (;;) {
        printf ("This is a pointless message.\n");
        sleep (1);
    }

    exit (0);
}
