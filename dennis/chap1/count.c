#include<stdio.h>
void main ()
{
	int blanks,others,c;
	int digits[10];
	blanks=others=0;
	for(int i=0;i<10;i++)
		digits[i]=0;
	while((c=getchar())!=EOF)
		{
			if(c==' ' || c=='\n' || c=='\t')
				++blanks;
			else if(c<='9' || c>='0')
				++digits[c-'0'];
			else
				others++;
			printf("digits are");
			for(int i=0;i<10;i++)
				printf("%d came %d times \n",i,digits[i]);
			printf("white space %d and others are %d",blanks,others);
		}
}
