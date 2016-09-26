#include <stdio.h>
void main()
{
char c;

long lines=0,tabs=0,blanks=0;
for(;(c=getchar())!=EOF;)
{
if(c=='\n')
lines++;
else if(c=='\t')
tabs++;
else if(c==' ')
blanks++;
}
printf(" lines %d tabs  %d blanks %d\n",lines,tabs,blanks);
}
