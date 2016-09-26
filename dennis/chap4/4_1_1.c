#include <stdio.h>
#define MAXLINE 1000

int getline1(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";











typedef struct TEST
{
  char *data;
  char testchar;
  int expected;
} TEST;

int main(void)
{
  TEST test[] =
  {
    {"Hello world", 'o', 7},
    {"This string is littered with iiiis", 'i', 32},
    {"No 'see' letters in here", 'c', -1}
  };

  size_t numtests = sizeof test / sizeof test[0];
  size_t i;

  char ch = 'o';
  int pos;

  for(i = 0; i < numtests; i++)
  {
    pos = strrindex(test[i].data, test[i].testchar);

    printf("Searching %s for last occurrence of %c.\n",
           test[i].data,
           test[i].testchar);

    printf("Expected result: %d\n", test[i].expected);
    printf("%sorrect (%d).\n", pos == test[i].expected ? "C" : "Inc", pos);
    if(pos != -1)
    {
      printf("Character found was %c\n", test[i].data[pos]);
    }
  }

  return 0;
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

int strrindex(char s[],char t[])
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
