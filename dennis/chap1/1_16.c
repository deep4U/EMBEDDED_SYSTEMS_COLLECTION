#include <stdio.h>
#define MAX 1000
long getline1(char line[],int m);
void copy(char to[],char from[]);
int main()
{
	long len	;
	long max;
	char line[MAX];
	char longest[MAX];
	max=0;
	while((len=getline1(line,MAX))>0)
		{
			if(len>max)
				{
					max=len;
					copy(longest,line);
				}
		}

			if(max>0)
				printf("longest line of %d length is %s",max,longest);
		return 0;
}
long getline1(char line[],int m)
{
char c;
long i,j;
	for(i=0,j=0;((c=getchar())!=EOF) && c!='\n';i++)
	{
		if(i<(m-1))
		line[j++]=c;
	}
	if(c=='\n')
{		
		if(j< m-1)
		line[j++]=c;
}
	line[j]='\0';
	return i;
}
void copy(char to[],char from[])
{
	for(int i=0;((to[i]=from[i])!='\0');i++);
}
