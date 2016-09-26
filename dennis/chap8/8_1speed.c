#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 1024
void main(int argc,char *argv[])
{
	int fp;
	void filecopy(int,int);
	if(argc==1)
		filecopy(0,1);
	else
		while(--argc>0)
			if((fp = open(*++argv,O_RDONLY))==-1) {
				printf("cant open %s",*argv);
				return 1;
			} else {
				filecopy(fp,1);
				close(fp);
			}
	return 0;
			
}
void filecopy(int ifp,int ofp)
{
	int c;
	char buf[BUFSIZE];
	while((c=read(ifp,buf,BUFSIZE))>0)
		if(write(ofp,buf,c)!=c)
			error("write to file failed");
	
}
