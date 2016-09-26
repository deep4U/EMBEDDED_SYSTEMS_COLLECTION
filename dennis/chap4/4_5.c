#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAXVAL 100
#define MAXBUF 100
#define MAXOP 100
#define NUMBER 0
#define IDENTIFIER 1
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
if(isalpha(c))	
{
	i=0;
	while(isalpha(s[i++]=c))
	{
		c=getch();
	}
s[i-1]='\0';
	if(c!=EOF)
		ungetch(c);
return IDENTIFIER;
}
	if(!isdigit(c) && c!='.' && c!='-' && c!='+')
		return c;
	if(c=='-' || c=='+')
	{		
		
		i=0;
		if(isdigit(c=getch()))
		{s[++i]=c;}
		else
			{
			ungetch(c);
			c=s[0];
			return c;
			}
	}
else
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
void Dealwithit(char t[])
{
//	if(sp<1)
//		printf("error no oprtand");
//		return;
	double o2;
	if(strcmp(t,"sin")==0)
		push(sin(pop()));
	else if(strcmp(t,"cos")==0)
		push(cos(pop()));
	else if(strcmp(t,"exp")==0)
		push(exp(pop()));
	else if(strcmp(t,"pow")==0)
	{
//		if(sp<2)
//			printf("error not enough operants for power \n");
//		else
			{
				o2=pop();
				push(pow(pop(),o2));
			}
	}
	else
			printf("error unsupported command function %s\n",t);
}
void showtop()
{
	sp>0 ? printf("\t%.8g\n",val[sp-1]) : printf("error empty stack");
}	
void clearstack()
{
	sp=0;
}

void dup()
{
double temp;
if(sp<= MAXVAL-1)
	{
		temp=pop();
		push(temp);
		push(temp);
		++sp;
		
	}
else
	printf("not enough space to duplicate");
}
void swap()
{
if(sp >= 1)
{
double temp;
temp=val[sp-1];
val[sp-1]=val[sp-2];
val[sp-2]=temp;
}
else
printf("error not two elements");
}	
int main()
{
int type;
double op2;
char s[MAXOP];

while((type=getop(s))!=EOF)
{
	switch(type)
	{
		case NUMBER :
			push(atof(s));
			printf("got number %.8g\n",atof(s)); 
			break;
		case IDENTIFIER :
			Dealwithit(s);			
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
		case '%' :
                        op2=pop();
                        if(op2 != 0.0)
                        push(fmod(pop() , op2));
                        else
                                printf("err division by 0!!!!!!!!");
                        printf("mod\n");
                        break;
		case '/' :
			op2=pop();
			if(op2 != 0.0)
			push(pop() / op2);
			else
				printf("err division by 0!!!!!!!!");
			printf("div\n");
			break;
		case '?' :
			showtop();
			printf("showing top\n");
			break;
		case '~' :
			swap();
			printf("swapping\n");
			break;
		case '#' :
			dup();
			printf("duplicat \n");
			break;
		case '!' :
			printf("clear \n");
			clearstack();
			break;
		case '\n' :
			printf("\t %.8g \n =======",pop());
			break;
		default :
			printf("errror unknown command %s \n",s);
			break;
	}
}
return 0;
}
