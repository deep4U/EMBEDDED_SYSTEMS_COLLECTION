#include <stdio.h>
void main()
{
char c;

long lines=0;
for(;(c=getchar())!=EOF;)
{
if(c=='\n')
lines++;
}
printf("%d\n",lines);
}
