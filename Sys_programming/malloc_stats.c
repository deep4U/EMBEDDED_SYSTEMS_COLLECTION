#include <stdio.h>

main ()
{
	int i = 130;		 
	void *p;
	printf("\n Before Malloc Call \n");
	malloc_stats();
	printf("\n");
	getchar();
	printf("\n After Malloc Call \n");
	p = malloc(i);
	printf("\n %p \n",p);
	getchar();
	malloc_stats();
	free(p);
	getchar();
	malloc_stats();
}


