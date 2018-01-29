#include<stdio.h>
void main(){
	long int start,end,no,fact=1,sum=0,i,no_b,digit;
	scanf("%ld %ld",&start,&end);
	for(no_b=start;no_b<=end;no_b++){
		sum=0;
		no=no_b;
	        for(i=0;no>0;no=no/10){
	                for(digit=no%10,fact=1;digit>1;digit--)
	                        fact*=digit;
	                sum+=fact;
	        }
	        if(sum==no_b)
	                printf("%ld is strong no\n",no_b);
//	        else
//			printf("no is %d and sum of fact of digit is %d\n",no_b,sum);
	}
}
