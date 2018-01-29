#include<stdio.h>
void main(){
	int i,j,LINE_SIZE;
	scanf("%d %d",&j,&LINE_SIZE);
	for(i=1;i<=(j*LINE_SIZE);i++){
		
		if(i%LINE_SIZE==1)
			printf("\n");
		printf("%d ",i);
		}
	printf("\n");
}
