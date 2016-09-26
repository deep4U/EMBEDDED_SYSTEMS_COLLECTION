/* This will show you how to create a new process with clone and share data between processes*/
#include<stdio.h>
#include<sys/mman.h>
#include<sched.h>
#include<stdlib.h>
#define STACK_SIZE  16000
int variable;
int dosomething(void *arg)
{
	printf("\nIn child process\n");
	variable=40;
}

int main()
{
	void *child_stack;
	variable=10;
	/*get memory for child stack*/
	printf("\nValue of variable now is %d\n",variable);
	child_stack=malloc(STACK_SIZE);
	if(child_stack==NULL){
		perror("\nError creating \n");
		exit(1);
	}
	/*create new child with clone*/
	clone(dosomething,child_stack+STACK_SIZE,CLONE_VM|CLONE_FILES,NULL);
	/*sleep some time so that child can change 'variable'*/
	sleep(1);
	printf("\n Value of variable now is %d\n",variable);
}


	
	
	
