/* Shows how to use Fork system call 
Version : 1.0
Author : Team -C
*/

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>

# define CHILD 0

main(){
       pid_t pid;	
	pid = fork();
//	printf(" My pid = %d \n", getpid());
//	getchar();
	if( pid == CHILD){
		printf(" child: My pid = %d and ppid = %d  \n", getpid(),getppid());
		sleep(10);
		printf(" child: My pid = %d and ppid = %d  \n", getpid(),getppid());
	//	while(1);
	}
	// parent
	else{
		printf(" PARENT : My pid = %d \n", getpid());
		printf(" Newly created child pid = %d \n", pid);
	//	while(1);
	}
}
		

