#include<stdio.h>
void main(){
	int n,i;
	double res=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		res+=1.0/i;
	printf("%f\n",res);
}
