#include<stdio.h>
void main(){
	int i,n,start,end,prime;
//	scanf("%d",&n);
	scanf("%d %d",&start,&end);
	for(n=start;n<=end;n++){
	prime=1;
	for(i=2;i<=(n/2);i++)
		if(n%i==0)	{
	//	printf("NOT PRIME\n");
//		return;
		prime=0;
		break;
	}
	if (prime==1)
		printf("PRIME %d\n",n);
	}
}
