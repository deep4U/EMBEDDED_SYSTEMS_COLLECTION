#include<stdio.h>
void main(){
	long int i,j;
	scanf("%ld",&j);
	for(i=1;i<=j;i++)
		printf("%ld %ld %ld\n",i,i*i,i*i*i);
	printf("\n");
}
