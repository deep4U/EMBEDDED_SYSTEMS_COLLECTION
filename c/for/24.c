#include<stdio.h>
#include<math.h>

void main(){
	long x,terms,i,j,fact,cnt=0;
	int plus=1;
	double result =0;
	scanf("%ld %ld",&x,&terms);
	for (i=1,cnt=1;cnt<=terms;i+=2,cnt++)
{
		for(j=1,fact=1;j<=i;j++)
			fact*=j;
		if(plus==1)
{			result+=(pow((double)x,(double)i));plus=0;}
		else
{			result-=(pow((double)x,(double)i));plus=1;}
printf("%ld result is %f %f %f %ld\n",i,result,(pow((double)x,(double)i))/(double)fact,(pow((double)x,(double)i)),fact);
}

	printf("%f\n",result);

		
	
}
