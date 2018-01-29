#include <stdio.h>
void main(){
	int n,i;
	scanf("%d",&n);
	int* array=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++ )
		scanf("%d",&array[i]);
	printf("\n");
	for(i=0;i<n;i++ )
		printf("%d ",array[i]);
}
