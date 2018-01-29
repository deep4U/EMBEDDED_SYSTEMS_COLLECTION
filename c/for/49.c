#include<stdio.h>
void main(){
	long int start,items,progression,sum=0,current,i;
	scanf("%ld %ld %ld",&start,&items,&progression);
	current=start;
	for(i=0;i<items;i++){
		printf("%ld + ",current);
		sum+=current;
		current+=progression;
	}
	printf(" = %ld\n",sum);
}
