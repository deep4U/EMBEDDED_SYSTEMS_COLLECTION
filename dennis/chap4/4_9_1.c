#include <stdio.h>
#include <string.h>

int    getch    (void);
void   ungetch  (int);

/*
 * In the case that EOF is pushed back to ungetch(), the program will simply
 * continue execution as it normally would. Ignoring the EOF.
 */
int main()
{
        char c;

        /* Prematurely send EOF. */
        ungetch(EOF);

        while ((c = getch()) != EOF) {
                putchar(c);
        };

        return 0;
}

#define BUFSIZE 100
char buf[BUFSIZE];      /* Buffer for ungetch. */
int bufp = 0;           /* Next free position in buf. */

int getch(void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        if (bufp >= BUFSIZE) {
                printf("Ungetch: Too many characters.\n");
        /*
         * The check for EOF must be made here. If EOF is found, it is ignored.
         */
        } else if (c != EOF) {
                buf[bufp++] = c;
        }
}
