#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAXVAL 100
#define MAXBUF 100
#define MAXOP 100
#define NUMBER 5
#define IDENTIFIER 1
#define VARIABLE 2
#define MAXLINE 1000
char last;
double variablevalue[26]={0};
int sp=0;
double val[MAXVAL];

char line[MAXLINE];
int line_i=0;

int getline1(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

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


//////////////
/* getop:  get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = line[line_i++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;      /* not a number */
    i = 0;
    if (isdigit(c))    /* collect integer part */
        while (isdigit(s[++i] = c = line[line_i++]))
            ;
    if (c == '.')      /* collect fraction part */
        while (isdigit(s[++i] = c = line[line_i++]))
              ;
    s[i] = '\0';
    line_i--;

    return NUMBER;
}


///////////////


int getop1(char s[])
{
printf("iam in getop\n");
	int i=0,c;
	while(((c=s[0]=line[line_i++])==' ' || c=='\t'));
	s[1]='\0';
if(isalpha(c))	
{
i=0;
//	line_i=0;
	while(isalpha(s[++i]=c=line[line_i++]))
	{
		c=s[++i]=line[line_i++];
	}
s[++i]='\0';
	if(c!=EOF)
{		i--;line_i--;}
//		ungetch(c);
long len = strlen(s);
	if(len == 1 && isalpha(s[0]))
	{
		last = s[0];
		return VARIABLE;
	}	
return IDENTIFIER;
}
	if(!isdigit(c) && c!='.' && c!='-' && c!='+')
//		return c;
{
 //       s[0]=c=line[line_i];
c=s[0];
	printf("return operator %s %c ",s,c);
                        return c;
}
	if(c=='-' || c=='+')
	{		
		
		i=0;
		if(isdigit(s[++i]=c=line[line_i++]))
		{s[++i]=c=line[line_i++];}
		else
			{
			i--;
//			s[0]=c=line[line_i];
c=s[0];
s[1]='\0';
			printf("return operator %s ============== %c ",s,c);
			return c;
			printf("wtffffffffffffffffFF?");
			}
	}
else
i=0;
	if(isdigit(c))
		printf("I am in isdigit %c %s\n",c,s);
	if(isdigit(c))
		while(isdigit(c=s[++i]=line[line_i++]));
	if(c=='.')
		 while(isdigit(c=s[++i]=line[line_i++]));
		line_i--;

	s[i]='\0';
//printf("number string found is %s",s);
printf("return as number");
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
			printf("error not enough operants for power \n");
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
while(getline1(line,MAXLINE)!=0)
while((type=getop(s))!='\0');// && line[line_i]!='\0');
{
line_i=0;
{
	printf("type is %s character %d int",type,type);
	switch(type)
	{
		case NUMBER :
			push(atof(s));
			printf("got number %.8g\n",atof(s)); 
			break;
		case IDENTIFIER :
			Dealwithit(s);			
			break;
		case VARIABLE :
			push(variablevalue[last-97]);
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

}
return 0;
}
