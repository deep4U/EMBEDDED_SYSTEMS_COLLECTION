#include<stdio.h>
void main(){
	int no,digit,fact,sum=0,i,j,no_b;
	scanf("%d",&no);
	no_b=no;
	for(i=0;no>0;no=no/10){
		for(digit=no%10,fact=1,j=1;digit>1;j++,digit--)
			fact*=digit;
		sum+=fact;
	}
	if(sum==no_b)
		printf("%d is strong no\n",no_b);
	else
		printf("no is %d and sum of fact of digit is %d\n",no_b,sum);
}
