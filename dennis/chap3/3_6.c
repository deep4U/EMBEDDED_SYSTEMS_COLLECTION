#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAXLINE 1000

void reverse(char s[]) {
    int length = strlen(s);
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[], int w) {

    int i, sign;
    unsigned int n2;
    i = 0;


    if ((sign = n) < 0) {
        n2 = -n;
    }
    else {
        n2 = n;
    }

    do {
        s[i++] = (n2 % 10) + '0';
    }
    while ((n2 /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
while(i<w)
{
s[i++]=' ';
}
    s[i] = '\0';

    reverse(s);


}


int main(void)
{
    char s[MAXLINE];
    int width;

    width = 11;
    itoa(INT_MIN, s, width);
    printf("%12d is converted to %s.\n", INT_MIN, s);
    itoa(826, s, width);
    printf("%12d is converted to %s.\n", 826, s);
    itoa(-2093, s, width);
    printf("%12d is converted to %s.\n", -2093, s);

    return 0;
}

