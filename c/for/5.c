#include<stdio.h>
void main(){
	int no,i;
	scanf("%d",&no);
	for(i=1;i<no;i++)
		printf("Cube of no %d is %ld\n",i,((long)i)*i*i);
}
