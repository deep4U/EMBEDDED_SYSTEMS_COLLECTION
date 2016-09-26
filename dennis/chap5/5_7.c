#include<stdio.h>
#include<string.h>
#define MAXLEN 100
#define MAXLINE 500
#define ALLOCSIZE 100000
int getline1(char *,int);
char *alloc(int);
char *lineptr[MAXLINE];

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);

void qsort(char *lineptr[],int left,int right);
static char allocbuf[ALLOCSIZE];
static char *allocp=allocbuf;
void swap(char *v[],int i,int j)
{
char *temp;
temp=v[i];
v[i]=v[j];
v[j]=temp;
}
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

char *alloc(int n)
{
if(allocbuf+ ALLOCSIZE - allocp >=n)
{
        allocp+=n;
        return allocp-n;
}
else
return 0;
}

void afree(char *p)
{
if(p>=allocbuf && p < allocbuf + ALLOCSIZE)
        allocp=p;
}


void qsort(char *v[],int left,int right)
{
	int i,last;
	void swap(char *v[], int i, int j);
	if (left>=right)
		return;
	swap(v, left, (left + right)/2);
	last=left;
	for(i=left+1; i<=right; i++)
	if (strcmp(v+100*i, v +100*left)<0)
	swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}
int readlines(char *lineptr[],int maxlines)
{
	int len , nlines;
	char *p,line[MAXLINE];

	nlines =0;
	while((len=getline1(line,MAXLEN))>0)
		if(nlines>=maxlines )
			return -1;
		else
			{
				line[len-1] = '\0';
				strcpy(lineptr[0]+nlines++*100,line);
//				lineptr[nlines++] =p;
			}
return nlines;
}
void writelines1(char *lineptr[],int nlines)
{
	int i;
	for(i=0;i<nlines;i++)
		printf("%s\n",lineptr[i]);
}
void writelines(char *lineptr[],int nlines)
{
	while(nlines-->0)
		printf("%s\n",*lineptr++);
}

int main(void)
{
	int nlines;
	char linebuf[100][500];
	lineptr[0]=linebuf;
//	for(int i=0;i<=5000;i++)
//		lineptr[i]=linebuf+5000*i;
	if((nlines=readlines(lineptr,MAXLINE))>=0)
{	
	qsort(lineptr,0,nlines-1);
	writelines(lineptr,nlines);
	return 0;
}
	else
{
	printf("error input too big to sort\n");
	return 1;
}
}
