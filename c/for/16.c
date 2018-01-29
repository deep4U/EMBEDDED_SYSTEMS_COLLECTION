#include<stdio.h>
void main(){
	int i,even,j=0,sum=0;
	scanf("%d",&i);
	printf("even NUMERS ARE\n");
	for(even=2,j=0;j<i;even+=2,j++){
		printf("%d ",even);
		sum+=even;
	}
	printf("\nsum is %d\n",sum);
		
}
