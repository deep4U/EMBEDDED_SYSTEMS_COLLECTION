#include<stdio.h>
void main(){
	long int decimal,octal=0,digit,pow=1;
	scanf("%ld",&decimal);
	for(;decimal>0;decimal=((decimal)/8)){
		digit=decimal%8;
		octal=octal+digit*pow;
		//printf("%d",digit);
		pow*=10;
	}
	printf("%ld",octal);
}
