#include<stdio.h>
void main(){
	int n,i,sum=0;
	scanf("%d",&n);
	for(i=n-1;i>=1;i--)
		if(n%i==0)
			sum+=i;
	if(n==sum)
		printf("\n\nTHIS IS PERFECT NUMBER!!!!!!!!\n\n");
	else
		printf("\n\nSUM IS %d so it is not perfect\n\n",sum);
}
