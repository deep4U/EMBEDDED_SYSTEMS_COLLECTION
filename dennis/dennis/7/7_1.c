#include <stdio.h>
#include <ctype.h>

int main(int argc,char *argv[]) {
	char c;
	if(!strcmp(argv[0],"./lower"))
	while((c=getchar())!=EOF)
		putchar(tolower(c));
	else if(!strcmp(argv[0],"./upper"))
	while((c=getchar())!=EOF)
		putchar(toupper(c));
	else
    {
      printf("This program performs two functions.\n");
      printf("If the executable is named lower then it converts all the input on stdin to lowercase.\n");
      printf("If the executable is named upper then it converts all the input on stdin to uppercase.\n");
      printf("As you have named it %s it prints this message.\n", argv[0]);
    }	
return 0;
}
