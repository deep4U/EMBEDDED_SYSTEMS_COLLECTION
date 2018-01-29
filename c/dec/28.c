#include<stdio.h>
void main()
{
	int j,i;
	int pos=0;int neg=0;
	double total=0;double count=0;
	for(i=0;i<5;i++)	{
		scanf("%d",&j);
		printf("IN FOR WITH %d\n",j);
		if(j<0)
			neg++;
		else	{
			pos++;
			total+=j;
			count++;
			printf("COUNT %f and total %f\n",count,total);
		}
	}
	printf("NO OF +VE %d,NO OF -VE %d average is %f",pos,neg,total/count);
}
