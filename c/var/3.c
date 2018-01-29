#include<stdio.h>
#include<stdlib.h>
int main(){
	char buffer[]="2016 40a0b0 -1101110100110111100110 0x5abfff";
	char * ptr_end;
	long int i1,i2,i3,i4;
	i1=strtol(buffer,&ptr_end,10);
	i2=strtol(ptr_end,&ptr_end,16);
	i3=strtol(ptr_end,&ptr_end,2);
	i4=strtol(ptr_end,NULL,0);
	printf("i1=%ld\n i2=%ld\n i3=%ld\n i4=%ld\n",i1,i2,i3,i4);
}
