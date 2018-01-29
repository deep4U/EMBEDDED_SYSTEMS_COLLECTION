#include <stdio.h>
void main(){
	int age;
	scanf("%d",&age);
	if(age<18)
		printf("Sorry! You are not eligible to vote");
	else
		printf("Congratulations ! You are eligible for cassting your vote");
}
