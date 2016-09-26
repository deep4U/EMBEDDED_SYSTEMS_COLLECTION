#include<stdio.h>
void main()
{
	char c;
	int state=1; // 0 is IN 1 is OUT
	int nl,nw,nc;
	nl=nw=nc=0;
	while((c=getchar())!=EOF)
	{
		nc++;
		if(c=='\n')
		nl++;
		if(c==' ' || c=='\t' || c=='\n')
		{
			state=1;
		}
		else if(state == 1)
		{
			state=0;
			nw++;
		}
	}
	printf(" nl %d nw %d nc %d",nl,nw,nc);
		
}
