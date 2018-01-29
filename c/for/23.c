#include<stdio.h>
#include<math.h>

void main(){
	long x,terms,j,fact,cnt=0;
	double result =1;
	scanf("%ld %ld",&x,&terms);
	for (cnt=1;cnt<terms;cnt++)
{
		for(j=1,fact=1;j<=cnt;j++)
			fact*=j;
		result+=(pow((double)x,(double)cnt))/(double)fact;
		printf("%ld result is %f %f %f %ld\n",cnt,result,(pow((double)x,(double)cnt))/(double)fact,(pow((double)x,(double)cnt)),fact);
}

	printf("%f\n",result);

		
	
}
