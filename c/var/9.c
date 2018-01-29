#include<stdio.h>
void main() {
	char *a;
	a=getenv("PATH");
	printf("%s",a);
}
