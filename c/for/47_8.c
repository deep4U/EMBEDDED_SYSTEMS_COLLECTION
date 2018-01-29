#include<stdio.h>
void main(){
	long int no,digit,fact,sum=0,i,j,no_b;
	for(no_b=3;no_b<=1000;no_b++,sum=0){
		no=no_b;
		for(i=0;no>0;no=no/10){
			for(digit=no%10,fact=1,j=1;digit>1;j++,digit--)
				fact*=digit;
			sum+=fact;
		}
		if(sum==no_b)
			printf("%ld is strong no\n",no_b);
	//	else
		//	printf("no is %d and sum of fact of digit is %d\n",no_b,sum);
	}
}
