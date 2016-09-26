/* anon_mmap.c

   Demonstrate how to share a region of mapped memory between a parent and
   child process without having to create a mapped file, either through the
   creation of an anonymous memory mapping or through the mapping of /dev/zero.
*/
#ifdef USE_MAP_ANON
#define _BSD_SOURCE             /* Get MAP_ANONYMOUS definition */
#endif
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int *addr;                  /* Pointer to shared memory region */
    pid_t cpid;
    /* Parent creates mapped region prior to calling fork() */

#ifdef USE_MAP_ANON             /* Use MAP_ANONYMOUS */
    addr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (addr == MAP_FAILED)
        perror("mmap");

#else                           /* Map /dev/zero */
    int fd;

    fd = open("/dev/zero", O_RDWR);
    if (fd == -1)
        perror("open");

    addr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
        perror("mmap");

    if (close(fd) == -1)        /* No longer needed */
        perror("close");
#endif

    *addr = 1;                  /* Initialize integer in mapped region */

    cpid = fork();
   	if(cpid < 0)        
             perror("fork");


    if (cpid == 0) {                /* Child: increment shared integer and exit */
        printf("Child started, value = %d\n", *addr);
        (*addr)++;
        if (munmap(addr, sizeof(int)) == -1)
            	perror("munmap");
        exit(EXIT_SUCCESS);
       }

   else {                    /* Parent: wait for child to terminate */
       if (wait(NULL) == -1)
               perror("wait");
           printf("In parent, value = %d\n", *addr);
           if (munmap(addr, sizeof(int)) == -1)
            	perror("munmap");
           exit(EXIT_SUCCESS);
    }
}
