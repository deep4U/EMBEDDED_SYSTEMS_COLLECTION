#include <stdio.h>
#include <malloc.h>	

void malloc_status(struct mallinfo status)
{
	printf("\n total size of memory allocated with sbrk by malloc : %6d",status.arena);
        printf("\n number of free chunks                        	: %10d",status.ordblks);
        printf("\n number of mmapped regions                    	: %10d",status.hblks);
        printf("\n space in mmapped regions                     	: %10d",status.hblkhd);
        printf("\n total allocated space                        	: %10d",status.uordblks);
        printf("\n total free space                             	: %10d",status.fordblks);
        printf("\n top-most, releasable (via malloc_trim) space 	: %10d\n",status.keepcost);
}

int main ()
{
	struct mallinfo status;
	int i = 131060;		// Max for brk 
	//int i = 130;		// Max for brk 
	//int i = 131061;		// Start for mmap
	void *p;
	
	printf("\n Befor malloc call \n");
	status = mallinfo();
	malloc_status(status);


	printf("\n After malloc call \n");
	p = malloc(i);
	status = mallinfo();
	malloc_status(status);
	
		
	free(p);

	status = mallinfo();
	malloc_status(status);

}


