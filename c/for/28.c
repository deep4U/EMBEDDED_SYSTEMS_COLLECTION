#include<stdio.h>
void main(){
	int n,i,sum=0,start,end;
	scanf("%d %d",&start,&end);
	
	for(n=start;n<=end;n++)	{
	sum=0;
	for(i=n-1;i>=1;i--)
		if(n%i==0)
			sum+=i;
	if(n==sum)
		printf("\n\nTHIS IS PERFECT NUMBER!!!!!!!!%d\n\n",sum);
//	else
//		printf("\n\nSUM IS %d so it is not perfect\n\n",sum);
	}
}
