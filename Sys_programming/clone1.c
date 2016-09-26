/* This will show you how to create a new process with clone*/
#include<stdio.h>
#include<sys/mman.h>
#include<sched.h>
#include<stdlib.h>
#define STACK_SIZE 16000
int dosomething(void *arg)
{
	printf("\nIn child process\n");
	getchar();
}

int main()
{
	void *child_stack;
	/*get memory for child stack*/
	child_stack=malloc(STACK_SIZE);
	if(child_stack==NULL){
		perror("\nError creating \n");
		exit(1);
	}
	/*create new child with clone*/
	clone(dosomething,child_stack+STACK_SIZE,CLONE_VM|CLONE_FILES,NULL);
	getchar();
	printf("\nIn Parent process\n");
}


	
	
	
