/* Shows how to use mmap sys call
Version : 1.0
Author : Team -C
Note : All modern OS supports memory mapping of files.
*/

# include <unistd.h>
# include <sys/types.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <stdio.h>

main(){
	int fd,i;
	unsigned char *filedata= NULL,*temp;
	
	getchar();	
	filedata = (char *) mmap((void*)0,100,PROT_READ|PROT_WRITE,\
			MAP_ANONYMOUS|MAP_SHARED,-1,0);	
	getchar();
	if(filedata == NULL){
		perror("Maping Failed");
		exit(1);
	}
	// now we can access the content of the file as if it is part of
	// our process starting from the memory pointed by filedata.
	temp = filedata;
	for(i=0;i<100;i++,filedata++)
		*filedata = (char)(i+65);
	filedata-=100;
	for(i=0;i<100;i++,filedata++)
		printf("%c",*filedata );
	
	i = munmap(temp,100);
	getchar();
	if( i != 0)
		printf(" failed to unmap\n");
}
