#include<stdio.h>
void main(){
	int zerofirst=0;
	int n,current=1,j,i=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
{
	if (zerofirst==0)
		current=1;
	else
		current=0;
	for(j=0;j<i;j++)
	{
		printf("%d",current);
		if(current==0)
			current=1;
		else
			current=0;
	}
	printf("\n");
	if(zerofirst==0)
		zerofirst=1;
	else
		zerofirst=0;
}
}
