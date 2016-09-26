
/* show how to  catch interrupt signal.
Version : 1.0
Author : Team -C
*/
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

void sighand(int signum){
	printf("Interrupt signal rec'd \n");
}

main(){
	signal(SIGINT,sighand);
	while(1){
	}
}
