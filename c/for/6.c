#include<stdio.h>
#define TABLE_LENGTH 10
void main(){
	int i,r;
	scanf("%d",&r);
	for(i=1;i<=TABLE_LENGTH;i++)
		printf(" %d X %d = %d\n",r,i,r*i);
}
