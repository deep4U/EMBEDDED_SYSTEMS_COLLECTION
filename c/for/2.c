#include <stdio.h>
#define FIRST_N 10
void main() {
	int i,sum=0;
	printf("The first 10 natural number is:\n");
	for(i=1;i<=FIRST_N;i++)	{
		printf("%d ",i);sum+=i;
	}
	printf("\nsum is %d\n",sum);
	
}
