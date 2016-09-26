/*
 * 
 * Write a short program that allocates memory in chunks until the
 * system can no longer obtain any more.
 *
 @*/

#include <stdio.h>
#include <stdlib.h>
#define MB (1024*1024)

int main ()
{
    int j;
    char *buf;
    /* allocate 4 MB at a time */
    for (j = 0;; j++) {
        if (j%100 == 0)
            printf ("%d ", j);
        buf = malloc (MB);
    }
    exit (0);
}
