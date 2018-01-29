#include <stdio.h>
void main(){
	int temp;
	scanf("%d",&temp);
	if(temp<0)
		printf("FREEZING WEATHER");
	else if(temp<=10)
		printf("VERY COLD WEATHER");
	else if(temp<=20)
		printf("COLD WEATHER");
	else if(temp<=30)
		printf("Normal WEATHER");
	else if(temp<=40)
		printf("ITS HOT");
	else
		printf("ITS VERY HOT");
}
