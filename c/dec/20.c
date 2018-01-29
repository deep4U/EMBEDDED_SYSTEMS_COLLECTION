#include<stdio.h>
#include<math.h>
void main()	{
	int a,b,c;
	double x1,x2,p,s1;
	scanf("%d %d %d",&a,&b,&c);
	p=(b*b)-(4*a*c);
	printf("p is %f\n",p);
	if(p>=0 && a!=0)
	{
		s1=sqrt(p);
		x1=((-b+s1)/(2*a));
		x2=((-b-s1)/(2*a));
		printf("%f	%f",x1,x2);
	}
	else
		printf("Not Possible");
}
