#include<stdio.h>
#include<malloc.h>


void test(int size)
{
	
        int *p;
	int i=0;
	p = malloc(size);
	printf("\n %p \n",p);
	printf("\n");
}


int main()
{
	test(100);
	return 0;	
}
