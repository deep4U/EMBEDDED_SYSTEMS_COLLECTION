#include <stdio.h>
#define OCTAL 8
#define HEXADECIMAL 16
void getargs(int argc,char *argv[],int *a)
{
	int i=0;
	while(argc>1)
	{
		argc--;
		if(argv[argc][0]=='-')
		{
			i=1;
			while(argv[argc][i]!='\0')
			{
					if(argv[argc][i]=='o')
						*a=OCTAL;
					else if(argv[argc][i]=='x' || argv[argc][i]=='X')
						*a=HEXADECIMAL;
					i++;
			}
		}
		
	}
}
int can_print(int ch)
{
  char *printable = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !\"#%&'()*+,-./:;<=>?[\\]^_{|}~\t\f\v\r\n";

  char *s;
  int found = 0;

  for(s = printable; !found && *s; s++)
  {
    if(*s == ch)
    {
      found = 1;
    }
  }

  return found;
}
int main(int argc,char *argv[])
{
  int split = 80;
  int output = HEXADECIMAL;
  int ch;
  int textrun = 0;
  int binaryrun = 0;
  char *format;
  int width = 0;

 getargs(argc, argv, &output);

  if(output == HEXADECIMAL)
  {
    format = "%02X ";
    width = 4;
  }
  else
  {
    format = "%3o ";
    width = 4;
  }
  while((ch=getchar())!=EOF)
  {
	if(can_print(ch))
	{
  	  if(binaryrun>0)
	  {
	    binaryrun=0;
	    textrun=0;
	    putchar('\n');		
	  }
	  putchar(ch);
  	  ++textrun;
	  if(ch=='\n')
	    textrun=0;
	  if(textrun==split)
	  {
	    putchar('\n');
	    textrun=0;
	  }
  	}
	 else
    {
      if(textrun > 0 || binaryrun + width >= split)
      {
        printf("\nBinary stream: ");
        textrun = 0;
        binaryrun = 15;
      }
      printf(format, ch);
      binaryrun += width;
    }
  }
 putchar('\n');

  return 0;
}
