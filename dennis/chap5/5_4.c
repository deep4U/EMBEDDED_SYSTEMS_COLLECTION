int strcmp1(char *s,char *t)
{
for(;*s==*t;s++,t++)
if(*s=='\0')
return 0;
return *s-*t;
}
int strlen2(char *s)
{
char *p=s;
while(*p!='\0')
p++;
return p-s;}
int strend(char *s,char *t)
{
int Res=0;
int s_len=0;
int t_len=0;


s_len=strlen2(s);
t_len=strlen2(t);

if(t_len<=s_len)
{
s+=s_len-t_len;
if(!strcmp(s,t))
{
Res=1;
}
}
return Res;
}
#include <stdio.h>


int main(void)
{
  char *s1 = "some really long string.";
  char *s2 = "ng.";
  char *s3 = "ng";

  if(strend(s1, s2))
  {
    printf("The string (%s) has (%s) at the end.\n", s1, s2);
  }
  else
  {
    printf("The string (%s) doesn't have (%s) at the end.\n", s1, s2);
  }
  if(strend(s1, s3))
  {
    printf("The string (%s) has (%s) at the end.\n", s1, s3);
  }
  else
  {
    printf("The string (%s) doesn't have (%s) at the end.\n", s1, s3);
  }

  return 0;
}

