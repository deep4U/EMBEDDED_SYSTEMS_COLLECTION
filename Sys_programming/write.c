/*

This program explains about Low Level Outpu 

Author	: Team Veda
Usage 	: ssize_t write (int fd, void *buffer, size_t size);
Version	: 1.0

*/

#include<stdio.h> 
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd,i=1;
	char ch='A';
	fd = open("Demo.txt",O_RDWR|O_CREAT);
	while(i++<=4096)
		write(fd,&ch,1);
	close(fd);
}
