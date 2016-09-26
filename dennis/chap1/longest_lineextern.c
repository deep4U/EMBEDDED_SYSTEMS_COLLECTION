#include <stdio.h>
#define MAX 1000
int max;
char line[MAX];
char longest[MAX];
int getline1(void);
void copy(void);
int main()
{
	int len	;
extern	int max;
//
	char line[MAX];
extern	char longest[MAX];
	max=0;
	while((len=getline1())>0)
		{
			if(len>max)
				{
					max=len;
					copy();
				}
		}

			if(max>0)
				printf("longest line of %d length is %s",max,longest);
		return 0;
}
int getline1(void)
{
char c;
int i;
extern char line[];
for(i=0;i<MAX &&((c=getchar())!=EOF) && c!='\n';i++)
		line[i]=c;
	if(c=='\n')
{		line[i]=c;
		i++;
}
	line[i]='\0';
	return i;
}
void copy(void)
{
extern char line[],longest[];
	for(int i=0;((longest[i]=line[i])!='\0');i++);
}
