#include<stdio.h>
long int bin2dec(long int bin){
	long int dec=0,pow=1;
	for(;bin>0;){
		dec+=(pow*(bin%10));
		bin/=10;
		pow*=2;
	}
	return dec;
}
void main(){
	long int binary,octal=0,next3;
	scanf("%ld",&binary);
	long int pow=1;
	for(;binary>0;binary/=1000){
		next3=binary%1000;
		octal+=bin2dec(next3)*pow;
		pow*=10;
	}
	printf("%ld",octal);
}
