#include<stdio.h>
void main(){
	if(system(NULL))
		printf("Command line processor available!");
	else
		printf("Command line processor not there");
	int j=system("dir");
	printf("\n%d is output return of the call status",j);
}
