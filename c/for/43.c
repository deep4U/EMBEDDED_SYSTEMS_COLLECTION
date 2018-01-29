#include<stdio.h>
void main(){
	int no1,no2,i=2,hcf;
	scanf("%d %d",&no1,&no2);
	int j=no1>no2?no1:no2;
	for(;i<=j;i++)
		if(no1%i==0 && no2%i==0)
			hcf=i;
	printf("%d",hcf);
}
