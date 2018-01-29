#include<stdio.h>
#define TRAINGLE_LENGTH 40
void main(){
	int i,j;
	for(i=1;i<=TRAINGLE_LENGTH;i++){
		for(j=0;j<i;j++)
			printf("*");
		printf("\n");
	}
}
