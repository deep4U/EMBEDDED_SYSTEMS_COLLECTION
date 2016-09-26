#include <stdio.h>
void strcat1(char *s,char *t)
{
while(*s++);
s--;
while(*s++=*t++);
}
int main(void)
{
  char testbuff[128];

  char *test[] =
  {
    "",
    "1",
    "12",
    "123",
    "1234"
  };

  size_t numtests = sizeof test / sizeof test[0];
  size_t thistest;
  size_t inner;

  for(thistest = 0; thistest < numtests; thistest++)
  {
    for(inner = 0; inner < numtests; inner++)
    {
      strcpy(testbuff, test[thistest]);
      strcat1(testbuff, test[inner]);

      printf("[%s] + [%s] = [%s]\n", test[thistest], test[inner], testbuff);
    }
  }

  return 0;
}

