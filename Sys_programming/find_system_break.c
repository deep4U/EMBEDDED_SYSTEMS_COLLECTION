/* Include the sbrk function */

#include <unistd.h>
void *last_valid_address;
void main()

{

	/* grab the last valid address from the OS */

	last_valid_address = sbrk(0);


	/* we don't have any memory to manage yet, so
 * 	 *just set the beginning to be last_valid_address
 * 	 	 */

	printf("\n %p \n",last_valid_address);

	malloc(10);
	last_valid_address = sbrk(0);
	printf("\n %p \n",last_valid_address);


	/* Okay, we're initialized and ready to go */


}

