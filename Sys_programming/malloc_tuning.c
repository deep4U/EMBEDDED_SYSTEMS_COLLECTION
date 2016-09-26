#include <stdio.h>
#include <malloc.h>

int main(int argc, char **argv) 
{

	int thr;
	char *p1;
	struct mallinfo status;

  	status = mallinfo();
   	printf("\n top-most, releasable (via malloc_trim) space : %d\n",status.keepcost);
  	
	thr = 5000;
  	if (!mallopt(M_TOP_PAD, thr)) {
		printf("mallopt() failed\n");
  	}
  
	p1 = malloc(100);
	status = mallinfo();
   	printf("\n top-most, releasable (via malloc_trim) space : %d\n",status.keepcost);
  	
	malloc_stats();

  	printf("\nNow freeing 100k\n");
	malloc_trim(0);
  	free(p1);
  	malloc_stats();
}

