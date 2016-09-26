#include <ctype.h>
#include <stdio.h>

#define MAX 10
int bufp = 0;
int buf[MAX];

int getch(void)
{
	return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp < MAX)
		buf[bufp++] = c;
}
int getfloat(float *pn)
{
	int c,sign,power=1;
	while(isspace(c=getch()));
	if(!isdigit(c) && c!=EOF && c!='+' && c!='-' && c!='.')
	{
		ungetch(c);
		return 0;
	}
	sign=(c=='-') ? -1 : 1;
	if(c=='-' || c=='+')
	{	
		c=getch();
		if(!isdigit(c) && c!='.')
		{
			ungetch(c);
			ungetch((sign==-1)? '-' : '+');
			return 0;
		}
	}
	else
		if(!isdigit(c) && c!='.')
		 ungetch(c);
	if(c!='.')
	for(*pn=0;isdigit(c);c=getch())
		*pn= *pn * 10 + (c-'0');

	if(c=='.')
	{
		c=getch();
		for(;isdigit(c);c=getch())
		{
	                *pn= *pn * 10 + (c-'0');
			power*=10;
		}
	}
	*pn*=sign;
	*pn/=power;
	if(c!=EOF)
		ungetch(c);
	return c;	
}
int main(void)
{
        int ret;

        do {
                float f;

                fputs("Enter a number: ", stdout);
                fflush(stdout);
                ret = getfloat(&f);
                if (ret > 0) {
                        printf("You entered: %f\n", f);
                }
        } while (ret > 0);

        if (ret == EOF) {
                puts("Stopped by EOF.");
        } else {
                puts("Stopped by bad input.");
        }
        
        return 0;
	}
