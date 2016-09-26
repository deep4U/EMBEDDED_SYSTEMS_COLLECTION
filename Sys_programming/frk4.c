/* Shows how to use Fork system call 
Version : 1.0
Author : Team -C
*/

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

# define CHILD 0

main(){
	int fd;
	char buf[2];
        pid_t pid;	
	int childstatus;
	fd = open("./test",O_RDONLY);
	pid = fork();	
//	fd = open("./test",O_RDONLY);
	if( pid == CHILD){
		read(fd,buf,2);
		printf(" in child %c\n",buf[0]);
		printf(" in child %c\n",buf[1]);
		close(fd); // COW
		read(fd,buf,2);
		printf(" in child %c\n",buf[0]);
		printf(" in child %c\n",buf[1]);
	}
	// parent
	else{
		wait(&childstatus);
		read(fd,buf,2);
		printf(" in parent %c\n",buf[0]);
		printf(" in parent %c\n",buf[1]);
		close(fd);
	}
}
		

