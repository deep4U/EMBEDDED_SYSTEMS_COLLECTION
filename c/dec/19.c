#include<stdio.h>
void main()	{
	int p,q,r,s;
	scanf("%d %d %d %d",&p,&q,&r,&s);
	if (p%2==0 && q>r && s>p && (r+s)>(q+p))
		printf("Correct Values");
	else
		printf("Wrong Values");
}
