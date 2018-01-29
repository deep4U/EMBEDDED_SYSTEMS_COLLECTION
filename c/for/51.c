#include<stdio.h>
void main(){
	long int octal,decimal=0,pow=1;
	scanf("%ld",&octal);
	for(;octal>0;octal/=10,pow*=8){
		decimal+=((octal%10)*pow);
	}
	printf("%ld",decimal);
}
