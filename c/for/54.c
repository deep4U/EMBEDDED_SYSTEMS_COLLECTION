#include<stdio.h>
long int dec2bin(long int dec){
	long int bin=0,ten=1;
	for(;dec>0;){
		bin=bin+((dec%2)*ten);
		dec=(dec)/2;
		ten*=10;
	}
	return bin;
}
void main(){
	//OCTAL TO BIN
	long int octal,bin2=0,digit,pow=1;
	scanf("%ld",&octal);
	//dec2bin(octal);
	for(;octal>0;octal=octal/10){
	printf("octal %ld octal10 %ld  pow %ld dec2bin(octal10)) %ld bin2 ",octal,octal%10,pow,dec2bin(octal%10));
		bin2=bin2+((dec2bin(octal%10))*pow);
		pow*=1000;
	printf("%ld\n",bin2);
	}
	printf("%ld",bin2);
	
		
}
