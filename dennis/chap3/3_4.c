#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]) {
    int length = strlen(s);
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[]) {

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
    s[i] = '\0';

    reverse(s);


}


main() {


    char s[128];
    itoa(INT_MIN, s);
    printf("%d is converted to %s.\n", INT_MIN, s);

}


