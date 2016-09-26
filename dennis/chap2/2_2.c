#include <stdio.h>
#define MAX 1000
int getline1(char line[],int m);
void copy(char to[],char from[]);
int main()
{
	int len	;
	int max;
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
int getline1(char line[],int m)
{
char c;
int i;
//	for(i=0;i<m &&((c=getchar())!=EOF) && c!='\n';i++)
//		line[i]=c;
i=0;
while(i<m)
{
	c=getchar();
	if(c==EOF)
             break;
	else if(c=='\n')
		break;
line[i++]=c;  
}
	if(c=='\n')
{		line[i]=c;
		i++;
}
	line[i]='\0';
	return i;
}
void copy(char to[],char from[])
{
	for(int i=0;((to[i]=from[i])!='\0');i++);
}
