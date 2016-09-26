#include<stdio.h>
char *getline1(char *s,int lim)
{
char c;
char *a=s;
while(lim-->0 && (c=getchar()!=EOF) && c!='\n')
{
	*a++=c;
}
*a='\0';
return a;
}
int strlen2(char *s)
{
char *p=s;
while(*p!='\0')
p++;
return p-s;}

void reverse(char *s) {
    int length = strlen2(s);
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        c = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = c;
    }
}


void itoa(int n, char* s) {

    int sign;
    unsigned int n2;


    if ((sign = n) < 0) {
        n2 = -n;
    }
    else {
        n2 = n;
    }

    do {
        *s++ = (n2 % 10) + '0';
    }
    while ((n2 /= 10) > 0);
    if (sign < 0) {
        *s++ = '-';
    }

    reverse(s);


}

