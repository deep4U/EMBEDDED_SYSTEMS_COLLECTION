#include<stdio.h>
void main(){
	int n,i,j;
	scanf("%d",&n);
	int spaces=n+10;
	for(i=1;i<=n;i++,spaces--){
		for(j=0;j<spaces;j++)
			printf(" ");
		for(j=1;j<i;j++)
			printf("%d",j);
		for(j=i;j>0;j--)
			printf("%d",j);
		printf("\n");
	}
	
}
