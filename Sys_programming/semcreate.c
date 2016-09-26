/* 

   Create a POSIX named semaphore.

   On Linux, named semaphores are supported with kernel 2.6 or later, and
   a glibc that provides the NPTL threading implementation.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>


#define NAME "/mysem"

int main()
{
    int flags, opt;
    unsigned int value = 100;
    sem_t *sem;

    sem = sem_open(NAME ,O_CREAT | O_RDWR , 666 , value);
    if (sem == SEM_FAILED)
        perror("sem_open");

    exit(EXIT_SUCCESS);
}
