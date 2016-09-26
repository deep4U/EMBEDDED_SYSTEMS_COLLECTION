#include<ctype.h>
#include<stdio.h>
#define MAXLINE 1000
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

double atof(char s[])
{
	double val,power;
	int i,sign;
	for(i=0;isspace(s[i]);i++);
	sign= (s[i]=='-') ? -1 : 1;
	
	if(s[i]=='-' || s[i]=='+')
		i++;
	for(val=0.0;isdigit(s[i]);i++)
		val=(10.0 * val) + (s[i] - '0');
	if(s[i]=='.')
		i++;
	for(power=1.0;isdigit(s[i]);i++)
		{
			val=(10.0*val) + (s[i] - '0');
			power*=10.0;	
		}
return sign * val / power;
}
main()
{
double sum;
char line[MAXLINE];
sum=0;
while(getline1(line,MAXLINE) > 0)
	printf("\t%g\n",atof(line));
return(0);
}
