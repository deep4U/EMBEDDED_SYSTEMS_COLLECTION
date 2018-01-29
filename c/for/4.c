#include<stdio.h>
#define NO 10
void main (){
	int i,sum=0;int r;
	for(i=0;i<NO;i++){
		scanf("%d",&r);
		sum+=r;
	}
	printf("SUM OF THE 10 NUMBERS ENTERED IS %d \n Average is %f \n",sum,((float)sum/NO));
		
}
