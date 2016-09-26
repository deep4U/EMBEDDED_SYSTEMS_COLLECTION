#include<stdio.h>
#define MAXWORDLEN 10
void main()
{
	long max=0;
	long arr[MAXWORDLEN+1];
	for(int i=0;i<=MAXWORDLEN+1;i++)
		arr[i]=0;
	char c;int a=0;
	int state=1; // 0 is IN 1 is OUT
	int nl,nw,nc;
	nl=nw=nc=0;
	while((c=getchar())!=EOF)
	{
		nc++;
		if(c=='\n')
		nl++;
		if(c==' ' || c=='\t' || c=='\n')
		{
			if(a!=0)
//			printf("%d ",a);
			{
			if(a<=MAXWORDLEN)
				arr[a]++;
			else
				{arr[MAXWORDLEN+1]++;}		
			}
			a=0;
			state=1;
		}
		else if(state == 1)
		{
			a++;
			state=0;
			nw++;
		}
		else
			a++;
	}
	for(int i=0;i<=MAXWORDLEN;i++)
	{	printf(" %ld words of %d length\n",arr[i],i);
		if (arr[i]>max)
		max=arr[i];}
	printf(" %ld words of 11 or more length\n",arr[11]);
		if(arr[11]>max)
		max=arr[11];

	

	for(long aa=max;aa>=1;aa--)
	{
		for(int i=0;i<=(MAXWORDLEN+1);i++)
		{
	//	printf("%ld||\t",aa);
			if(arr[i]>=aa)
			printf("* ");
			else 
			printf("  ")		;
		}
		printf("\n");
	}		
	printf(" 1 2 3 4 5 6 7 8 9 10 11+");	
}
