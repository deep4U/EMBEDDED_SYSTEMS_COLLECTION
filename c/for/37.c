#include<stdio.h>
void main(){
	int n,res=0;
	scanf("%d",&n);
	for(;n>0;n=(n-n%10)/10)
		res=res*10+n%10;
	printf("%d",res);
}
