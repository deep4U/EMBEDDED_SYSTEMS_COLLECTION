#include<stdio.h>
void main(){
	int bin,dec=0,pow=1;
	scanf("%d",&bin);
	for(;bin>0;){
		dec+=(pow*(bin%10));
		bin/=10;
		pow*=2;
	}
	printf("%d",dec);
}
