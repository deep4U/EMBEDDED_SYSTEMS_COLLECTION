#include <stdio.h>

void main(int argc,char *argv[])
{
	FILE *fp;
	void filecopy(FILE *,FILE *);
	if(argc==1)
		filecopy(stdin,stdout);
	else
		while(--argc>0)
			if(fp = fopen(*++argv,"r")) {
				printf("cant open %s",*argv);
				return 1;
			} else {
				filecopy(fp,stdout);
				fclose(fp);
			}
	return 0;
			
}
void filecopy(FILE *ifp,FILE *ofp)
{
	int c;
	while((c=getc(ifp))!=EOF)
		putc(c,ofp);
}
