#include <stdio.h>
#include <malloc.h>	

main ()
{
	void *p;
	
	p = malloc(1);
	printf("\n number of usable allocated bytes associated with allocated chunk : %d \n",malloc_usable_size(p));



}


