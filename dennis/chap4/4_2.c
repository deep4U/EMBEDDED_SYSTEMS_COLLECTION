#include<ctype.h>
#include<stdio.h>
#define MAXLINE 1000
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

double atof(char s[])
{
	double val,power;
	int i,sign;
	for(i=0;isspace(s[i]);i++);
	sign= (s[i]=='-') ? -1 : 1;
	
	if(s[i]=='-' || s[i]=='+')
		i++;
	for(val=0.0;isdigit(s[i]);i++)
		val=(10.0 * val) + (s[i] - '0');
	if(s[i]=='.')
		i++;
	for(power=1.0;isdigit(s[i]);i++)
		{
			val=(10.0*val) + (s[i] - '0');
			power*=10.0;	
		}
for ( ; isspace(s[i]); i++);
	if(s[i]=='e' || s[i] == 'E')
	{
		i++;
		int si;
for ( ; isspace(s[i]); i++);
		si = (s[i] == '-') ? -1 : 1;
		if(s[i]=='-' || s[i]=='+')		i++;
		int v=0;
for ( ; isspace(s[i]); i++);
		for(;isdigit(s[i]);i++)
                v=(10.0 * v) + (s[i] - '0');
		double e=1.0;
		if(si==1)
			for(int jj=0;jj<v;jj++)
				e*=10.0;
		else 
			for(int jj=0;jj<v;jj++)
				e/=10.0;

return sign * val /power * e;
			}
return sign * val / power;
}

/*
main()
{
double sum;
char line[MAXLINE];
sum=0;
while(getline1(line,MAXLINE) > 0)
	printf("\t%g\n",atof(line));
return(0);
}*/



int main(void)
{
	printf("%f\n", atof("123.45e-6"));



char s1[] = "87.549e2", s2[] = "-982.47e-3", s3[] = "-54e", s4[] = "-.64e4", s5[] = "+.87e+ 6";
	printf("s1 = %10s <-> %15lf\n", s1, atof(s1));
	printf("s2 = %10s <-> %15lf\n", s2, atof(s2));
	printf("s3 = %10s <-> %15lf\n", s3, atof(s3));
	printf("s4 = %10s <-> %15lf\n", s4, atof(s4));
	printf("s5 = %10s <-> %15lf\n", s5, atof(s5));
	return 0;
}
