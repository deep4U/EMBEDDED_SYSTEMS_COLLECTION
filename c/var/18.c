#include<stdio.h>
int main()
{
    int a;
    long b;
    long long c;

    double e;
    long double f;
    printf("\n Demonstrate the working of keyword long \n");
    printf("------------------------------------------\n");

    printf(" The size of int = %ld bytes \n", sizeof(a));
    printf(" The size of long = %ld bytes\n", sizeof(b));
    printf(" The size of long long = %ld bytes\n", sizeof(c));

    printf(" The size of double = %ld bytes\n", sizeof(e));
    printf(" The size of long double = %ld bytes\n\n", sizeof(f));

    return 0;
}
