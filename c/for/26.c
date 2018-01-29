#include <stdio.h>
#include <math.h>
void main(){
	long int i,j;
	long int n;
	long int sum=0;
	scanf("%ld",&n);
	for(i=0,j=0;j<=n;i+=(1*pow(10,j)),j++)
{		sum+=i;
	printf("\n\n\nSUM OF THIS SERIES IS %ld",sum);
}
}
