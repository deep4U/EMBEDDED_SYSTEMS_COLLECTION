#include<stdio.h>
void main(){
	int i;
	long int sum=0;
	int n;
	scanf("%d",&n);
	long int sq=1;
	for(i=1;i<=n;i++){
		sq=i*i;
		printf("%ld\n",sq);
		sum+=sq;
	}
	printf("%ld",sum);
}
