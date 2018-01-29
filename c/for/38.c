#include<stdio.h>
void main(){
	int n,res=0,n1;
	scanf("%d",&n1);
	n=n1;
	for(;n>0;n=(n-n%10)/10)
		res=res*10+n%10;
//	printf("%d",res);
	if(res==n1)
		printf("Palindrome");
	else
		printf("NOT Palindrome");
}
