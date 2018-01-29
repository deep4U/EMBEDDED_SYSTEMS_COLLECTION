#include<stdio.h>
#define LINE_SIZE 3
void main(){
	int i,j;
	scanf("%d",&j);
	for(i=1;i<=(j*LINE_SIZE);i++){
		
		if(i%3==1)
			printf("\n");
		printf("%d ",i);
		}
	printf("\n");
}
