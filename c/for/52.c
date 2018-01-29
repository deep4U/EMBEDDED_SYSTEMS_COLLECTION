#include<stdio.h>
void main(){
	float start,items,progression,sum=0,current,i;
	scanf("%f %f %f",&start,&items,&progression);
	current=start;
	for(i=0;i<items;i++){
		printf("%f + ",current);
		sum+=current;
		current*=progression;
	}
	printf(" = %f\n",sum);
}
