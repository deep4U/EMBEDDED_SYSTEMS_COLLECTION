#include<stdio.h>
void main(){
	int n,i,k;char j;
	scanf("%d",&n);
	int spaces=n+10;
	for(i=1;i<=n;i++,spaces--){
		for(j=0;j<spaces;j++)
			printf(" ");
		for(k=1,j='A';k<(i);j++,k++)
			printf("%c",j);
		for(k=(i);k>0;j--,k--)
			printf("%c",j);
		printf("\n");
	}
	
}
