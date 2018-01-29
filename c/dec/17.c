#include<stdio.h>
void main(){
	long int secs;
	scanf("%ld",&secs);
	long int h,s,m;
	s=secs%60;
	m=(secs%3600-s)/60;
	h=(secs-s-(m*60))/3600;
	printf("%ld:%ld:%ld",h,m,s);
}
