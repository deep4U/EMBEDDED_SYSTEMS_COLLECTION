#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#define MAXVAL 100
#define MAXBUF 100
#define MAXOP 100
#define NUMBER 0

int sp=0;
double val[MAXVAL];


void push(double a)
{
if(sp<MAXVAL)
val[sp++]=a;
else
printf("error : stack is full CAN NOT PUSH %g\n",a);
}

double pop(void)
{
if(sp>0)
{
return val[--sp];
}
else 
{printf("error : stack is empty \n");
return 0.0;
}
}
char buf[MAXBUF];
int bufp=0;

int getch(void)
{
return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int p)
{
if(bufp>=MAXBUF)
	printf("ungetch overloaded");
else
	buf[bufp++]=p;
}

int getop(char s[])
{
	int i,c;
	while((s[0]=c=getch())==' ' || c=='\t');
	s[1]='\0';
	if(!isdigit(c) && c!='.')
		return c;
	i=0;
	if(isdigit(c))
		while(isdigit(s[++i]=c=getch()));
	if(c=='.')
		 while(isdigit(s[++i]=c=getch()));
	s[i]='\0';
	if(c!=EOF)
		ungetch(c);
return NUMBER;
}
		
int main(int argc, char **argv)
{
int type;
double op2;
char s[MAXOP];
int i;
//while((type=getop(s))!=EOF)
//while(argc)
for(i=1;i<argc;i++)
{
	switch(argv[i][0])
	{
	case '\0':
			printf("empty command line argument\n");
		break;
			
		case '0' :
		case '1' :
		case '2' :
		case '3' :
		case '4' :
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			printf("atof of %s",argv[i]);
			push(atof(argv[i]));
			printf("got number %.8g\n",atof(argv[i])); 
			break;
		case '+' : 
			push(pop() + pop());
			printf("add\n");
			break;
		case '*' :
                        push(pop() * pop());
			printf("mul\n");
                        break;
		case '-' : 
			op2=pop();
			push(pop() - op2);
			printf("sub\n");
			break;
		case '/' :
			op2=pop();
			if(op2 != 0.0)
			push(pop() / op2);
			else
				printf("err division by 0!!!!!!!!");
			printf("div\n");
			break;
		default :
			printf("errror unknown command %s \n",argv[i][0]);
			break;
	}
}
printf("%g\n", pop());
return 0;
}
