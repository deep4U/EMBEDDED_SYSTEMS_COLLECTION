#include <stdio.h>
void main()
{
char c;

long lines=0,tabs=0,blanks=0;
for(;(c=getchar())!=EOF;)
{
if(c==' ' && blanks == 0)
{
blanks++;
putchar(c);
}
else if(c != ' ' )
{
putchar(c);
if(blanks!=0)
blanks=0;

}
else
;
}
printf(" lines %d tabs  %d blanks %d\n",lines,tabs,blanks);
}
