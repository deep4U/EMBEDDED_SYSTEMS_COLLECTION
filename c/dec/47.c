#include<stdio.h>
void main(){
	int i,j;
	scanf("%d",&i);
	for(j=1;j<=i;j++ )
		if(i%j==0)
			printf("%d\n",j);
	}
