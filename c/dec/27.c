#include<stdio.h>
void main()
{
	int j,i;
	int pos=0;int neg=0;
	for(i=0;i<5;i++)
		scanf("%d",&j);
		if(j<0)
			neg++;
		else
			pos++;
	printf("NO OF +VE %d,NO OF -VE %d",pos,neg);
}
