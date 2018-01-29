#include<stdio.h>
void main()	{
	float wi1,wi2,noi1,noi2;
	scanf("%f %f %f %f",&wi1,&wi2,&noi1,&noi2);
	printf("%f",(wi1*noi1+noi2*wi2)/(noi1+noi2));
}
