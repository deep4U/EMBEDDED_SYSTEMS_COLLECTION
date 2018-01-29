#include<stdio.h>
void main(){
	int no; long fact=1;int i;
	scanf("%d",&no);
	for(i=1;i<=no;i++)
		fact=fact*i;
	printf(" Factorial of %d is %ld\n",no,fact);
}
