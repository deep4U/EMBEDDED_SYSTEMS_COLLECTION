#include<stdio.h>
#define TRAINGLE_LENGTH 4
void main(){
	int i,j;
	for(i=1;i<=TRAINGLE_LENGTH;i++){
		for(j=1;j<=i;j++)
			printf("%d",j);
		printf("\n");
	}
}
