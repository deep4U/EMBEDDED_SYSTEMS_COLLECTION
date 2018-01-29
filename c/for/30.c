#include<stdio.h>
#include<math.h>
void main(){
	int no_dig=0,n1,n,i,start,end;
	int digits[100];
	long int result=0;
	scanf("%d %d",&start,&end);
	for(n1=start;n1<=end;n1++){
		no_dig=0,result=0;
		n=n1;
		for( no_dig=0;n>0;n=(n-n%10)/10,no_dig++){
			digits[no_dig]=n%10;
//			printf("%d",digits[no_dig]);
		}
		for(i=0;i<no_dig;i++)
			result+=pow(digits[i],no_dig);
		if(result==n1)
			printf("\n\nIT IS ARMSTRONG NUMBER %d\n\n",n1);
//		else	
//			printf("\n\n %ld is result and %d is number IT IS NOT ARMSTRONG NUMBER\n\n",result,n1);
	}
}
