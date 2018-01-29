#include<stdio.h>
	void main()	{
		int in=1,i,average=0;
		printf("Enter mathamatchics marks (0 to terminate):");
		for(i=0;in>0;i++){
			scanf("%d",&in);
			average+=in;
		}
		printf("AVERAGE %d IS : %f",average,average/(i-1.0));
	}
