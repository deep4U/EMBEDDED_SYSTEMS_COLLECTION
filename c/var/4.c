#include<stdio.h>
#include<stdlib.h>
void main(){
	char input[]="8.0 2.0";
	char *ptr_end;
	double x,y;
	x=strtod(input,&ptr_end);
	y=strtod(ptr_end,NULL);
	printf("%f %f %f",x,y,x/y);
}
