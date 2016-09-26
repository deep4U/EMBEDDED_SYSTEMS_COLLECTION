#include<stdio.h>
#include <stdlib.h>

const char hex[]="aAbBcCdDeEfF\0";
unsigned int htoi(const char s[])
{
	unsigned int ans=0;
	int valid=1;
	int i=0;
	if(s[i]=='0')
	{
		i++;
		if(s[i]=='X' || s[i]=='x')
		i++;
	}
	while(valid&& s[i]!='\0')
	{
//		printf("%d %c %u",i,s[i],ans)
		ans*=16;
		if(s[i]>='0'&&s[i]<='9')
			ans=ans+(s[i]-'0');
		else 
			{
				int j,a=0;
				for(j=0;a==0&&hex[j]!='\0';j++)
					if(s[i]==hex[j])
						a=10+(j/2);
			ans=ans+a;
			if(a==0)
				valid=0;
			}
i++;
	}
	if(!valid)
		return 0;
else
return ans;	
}
int main(void)
{
  char *endp = NULL;
  char *test[] =
  {
    "F00",
    "bar",
    "0100",
    "0x1",
    "0XA",
    "0X0C0BE",
    "abcdef",
    "123456",
    "0x123456",
    "deadbeef",
    "zog_c"
  };

  unsigned int result;
  unsigned int check;

  size_t numtests = sizeof test / sizeof test[0];

  size_t thistest;

  for(thistest = 0; thistest < numtests; thistest++)
  {
    result = htoi(test[thistest]);
    check = (unsigned int)strtol(test[thistest], &endp, 16);

    if((*endp != '\0' && result == 0) || result == check)
    {
      printf("Testing %s. Correct. %u\n", test[thistest], result);
    }
    else
    {
      printf("Testing %s. Incorrect. %u\n", test[thistest], result);
    }
  }

  return 0;
}



