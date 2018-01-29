#include<stdio.h>
void main(){
	char buffer[123];
	unsigned long ul;
	printf ("\nInput an unsigned number: ");
	fgets (buffer,123,stdin);
	ul=strtoul(buffer,NULL,0);
	printf("\n %lu\n\n",ul);
}
