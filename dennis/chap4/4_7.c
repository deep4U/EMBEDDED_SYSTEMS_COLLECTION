/* There are a few situations wherein ungets() using ungetch() may cause a problem.
It is because ungets() doesn't do any bounds checking. If I have a string of length one million and one and the 
available space in buf[] is only one million, then only after copying the first one million characters will I come
to know that there isn't any space for the last character and depending upon the situation I might have to undo the
entire process. So ungets() must do its own bounds checking for which it will require access to both buf[] and bufp.
Notice that if you provide ungets() with access to buf[] and bufp, the whole idea of using ungetch() becomes moot.
I'll still use it for brevity.*/

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
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

int getch(void)
{
	return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("error: stack is full, can't execute ungetch()\n");
	else
		buf[bufp++] = c;
}

void ungets(char *s)
{
	int i, len;
	len = strlen(s);
	if(BUFSIZE - bufp >= len)  // ungets() must do its own bounds checking
	{
		for(i = strlen(s) - 1; i >= 0; i--)
			ungetch(s[i]);
	}
	else
		printf("error: insufficient space in buffer, can't execute ungets()\n");
}

int main()
{
	char s[] = "Rapa chika paka, raja babu\n";
	int c;
	ungets(s);
	while((c = getch()) != EOF)
		putchar(c);
	return 0;
}

/* You might think that now bounds checking is being done twice, both by ungets() and ungetch(). Isn't it a waste
of time. No, because there might be other functions using ungetch() to store back just one variable. In such cases,
ungetch() must have its own bounds checking as well. */ 
