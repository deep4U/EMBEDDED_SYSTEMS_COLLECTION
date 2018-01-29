#include<stdio.h>
void main(){
	int i,odd,j=0,sum=0;
	scanf("%d",&i);
	printf("ODD NUMERS ARE\n");
	for(odd=1,j=0;j<i;odd+=2,j++){
		printf("%d ",odd);
		sum+=odd;
	}
	printf("\nsum is %d\n",sum);
		
}
