#include<stdio.h>
#define TRAINGLE_LENGTH 4
void main(){
	int i,j;
	int count=1;
	for(i=1;i<=TRAINGLE_LENGTH;i++){
		for(j=1;j<=i;j++,count++)
			printf("%d",count);
		printf("\n");
	}
}
