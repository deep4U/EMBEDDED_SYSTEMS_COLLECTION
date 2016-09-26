#include<stdio.h>
#define MAX 1000
void reverse(char s[])
{
int leng=0;
while(s[leng]!='\0')
leng++;

int start=0;
int end=leng;
--end;
for(;start<end;start++)
{
char c;
c=s[start];
s[start]=s[end];
s[end]=c;
end--;
}
}

long getline1(char line[],int m)
{
char c;
long i,j;
        for(i=0,j=0;((c=getchar())!=EOF) && c!='\n';i++)
        {
                if(i<(m-1))
                line[j++]=c; 
        }
        if(c=='\n') 
{               
                if(j< m-1)
                line[j++]=c;
}
        line[j]='\0';
        return i;
}
void copy(char to[],char from[])
{
        for(int i=0;((to[i]=from[i])!='\0');i++);
}



void main()
{

	long len;
        char line[MAX];
        while((len=getline1(line,MAX))>0)
{		reverse(line);
printf("%s",line);

}
}
