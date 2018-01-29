#include<stdio.h>
#define TABLE_LENGTH 10
void main(){
	int i,r,j;
	scanf("%d",&r);
	for(i=1;i<=TABLE_LENGTH;i++){
		for(j=1;j<=r;j++)
			printf("%dX%d = %d, ",j,i,j*i);
		printf("\n");
	}
}
