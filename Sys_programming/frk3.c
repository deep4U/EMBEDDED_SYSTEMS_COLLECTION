/* Shows how to use Fork system call 
Version : 1.0
Author : Team -C
*/

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>

# define CHILD 0
int childstatus;
void sighand(int signum){
	printf(" I am in sig handler \n");
//	wait(&childstatus);
}

main(){
        pid_t pid;
		
	struct sigaction act;
	pid = fork();
	if( pid == CHILD){
	printf(" I am in child task \n");
	sleep(10);
	}
	// parent
	else{
		act.sa_flags = SA_NOCLDWAIT ;
//		act.sa_flags = SA_NOCLDSTOP;
		act.sa_handler = SIG_DFL;
//		act.sa_handler = sighand;
		if( sigaction(SIGCHLD,&act,NULL) == -1);
			perror("sigaction: ");
                
		while(1);
	}
}
		

