#include<stdio.h>
void main(){
	int i,j,k,sum=0;
	printf("ENTER THE 2 NUMBERS:->");
	scanf("%d %d",&i,&j);
	for(k=i;k<=j;k++)
			if(k%17!=0)
				sum+=k;
	printf("\n%d\n",sum);
	}
