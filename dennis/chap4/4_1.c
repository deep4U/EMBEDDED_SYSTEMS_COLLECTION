#include <stdio.h>
#define MAXLINE 1000

int getline1(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

main()
{
char line[MAXLINE];
int found=0;
int po;
while (getline1(line,MAXLINE))
{
	if((po=strindex(line,pattern))>=0)
	{
		printf("%s at %d",line,po);
		found++;	
	}
}
return found;
}

int getline1(char line[],int max)
{
	char c,i=0;
	while(--max>0 && (c=getchar())!=EOF && c!='\n')
		line[i++]=c;
if(c=='\n')
{line[i++]=c;}
line[i]='\0';
return i;
}

int strindex(char s[],char t[])
{
	int i=0,j=0,pos=-1;
	for(;s[j]!='\0';j++)
	{
		for(i=0;t[i]==s[j+i] && t[i]!='\0';i++)
		;
		if(t[i]=='\0'&& i>0)
			pos=j;
	}
return pos;
}
