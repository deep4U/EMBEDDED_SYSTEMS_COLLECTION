#include<stdio.h>
#include<math.h>
void main()	{
	int x1,x2,y2,y1;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
//	printf("%d",(((x1-x2))+((y1-y2)*(y1-y2))));
	printf("%f",pow((pow(x1-x2,2)+pow(y1-y2,2)),.5));
}
