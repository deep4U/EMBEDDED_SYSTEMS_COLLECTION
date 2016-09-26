#include <stdio.h>
void main()
{
char c;

long lines=0,tabs=0,blanks=0;
for(;(c=getchar())!=EOF;)
{
if(c=='\b')
{
putchar('\\');
putchar('b');
}
else if(c=='\t')
{
putchar('\\');
putchar('t');
}
else if(c=='\\')
{
putchar('\\');
putchar('\\');

}
else
putchar(c);
}
}
