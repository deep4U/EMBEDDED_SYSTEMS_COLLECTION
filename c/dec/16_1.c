#include<stdio.h>
void main()	{
	int number;
	printf("Enter the amount:");
	scanf("%d",&number);
	int denom_size=7;
	int denom[7]={100,50,20,10,5,2,1};
	int j=0;
	for(j=0;j<=denom_size;j++)	{
		printf("%d notes of %d\n",number/denom[j],denom[j]);
		if(number>=denom[j])
			number=number%denom[j];
	}
}
