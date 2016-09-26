#include<stdio.h>

void func(int x,float y)
{
	int i=11;
	printf("\n i = : %d ",i);
	i++;
	printf("\n i = : %d",i);
	i++;
	printf("\n i = : %d",i);
	i++;
	printf("\n i = : %d",i);
	i++;
	printf("\n i = : %d",i);
}

int main()
{
	int x=100;
	func(100,20.6);
	printf("\n x = : %d",x);
	return 0;
}

