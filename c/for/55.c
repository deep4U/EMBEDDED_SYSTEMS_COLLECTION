#include<stdio.h>
void main(){
	long int decimal,octal=0,digit,pow=1,i,j;
	char hex[100];
	scanf("%ld",&decimal);
	for(i=0;decimal>0;decimal=((decimal)/16),i++){
		digit=decimal%16;
		if(digit<=9)
			hex[i]=digit+'0';
		else
			hex[i]=digit-10+'A';
//		octal=octal+digit*pow;
		printf("%ld %c %ld\n",digit,hex[i],i);

	//		pow*=10;
	}
		printf("%ld \n",i);
	for(j=(i-1);j>=0;j--)
		printf("%c",hex[j]);
	printf("\n",i);
}
