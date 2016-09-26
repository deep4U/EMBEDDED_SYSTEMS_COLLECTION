#include<stdio.h>
#define MAX_CHAR 256

void main ()
{
	long max=0;
        long arr[MAX_CHAR+1];
	char c;
        for(int i=0;i<=MAX_CHAR+1;i++)
                arr[i]=0;
	while((c=getchar())!=EOF)
		{
			
			arr[c]++;
		}


for(int i=0;i<=MAX_CHAR;i++)
        {       
		printf(" %ld words of %d length\n",arr[i],i);
                if (arr[i]>max)
                	max=arr[i];
	}
        printf(" %ld words of 11 or more length\n",arr[11]);
                if(arr[11]>max)
                max=arr[11];



        for(long aa=max;aa>=1;aa--)
        {
                for(long i=0;i<=(MAX_CHAR+1);i++)
                {
        //      printf("%ld||\t",aa);
                        if(arr[i]>=aa)
                        printf("*");
                        else if(arr[i]!=0)
                        printf(" ")            ;
                }
                printf("\n");
        }
        printf(" 1 2 3 4 5 6 7 8 9 10 11+");

	
}
