#include<stdio.h>
void main(){
	int dec,bin=0,ten=1;
	scanf("%d",&dec);
//	bin+=(dec%2);
//	dec=dec/2;
	for(;dec>0;){
		bin=bin+((dec%2)*ten);
		dec=(dec)/2;
		ten*=10;
	}
	printf("%d",bin);
}
