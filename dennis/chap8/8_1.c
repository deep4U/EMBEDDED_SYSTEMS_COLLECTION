#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
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
	int *a=&c;
	while((read(ifp,a,1))==1)
		if(write(ofp,a,1)!=1)
			error("write to file failed");
	
}
