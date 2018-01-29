#include<stdio.h>
void main(){
	int prev=1,next=1,i=2,n;
	scanf("%d",&n);
	printf("0 1 ");
	for(;i<=n;i++,next=prev+next,prev=next-prev)
		printf("%d ",next);
		
}
