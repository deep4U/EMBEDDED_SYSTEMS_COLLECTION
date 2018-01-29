#include <stdio.h>
void main() {
	int i,sum=0,n;
	scanf("%d",&n);
	printf("The first 10 natural number is:\n");
	for(i=1;i<=n;i++)	{
		printf("%d ",i);sum+=i;
	}
	printf("\nsum is %d\n",sum);
	
}
