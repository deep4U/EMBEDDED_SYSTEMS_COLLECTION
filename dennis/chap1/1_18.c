#include <stdio.h>
#define MAX 1000
long getline1(char line[],int m);
void copy(char to[],char from[]);
int main()
{
	long len	;
	char line[MAX];
	while((len=getline1(line,MAX))>0)
		if(len!=0)
		{
					int dif=1;
					long a=len;
					if(line[a-1]=='\n')
					dif=2;
					for(;line[a-dif]==' ' || line[a-dif]=='\t';a--)
					{
					}
					if(dif=2)
					{line[++a]='\0';line[a-1]='\n';	}
					else
					line[++a]='\0';
					printf("%s",line);
		}

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
