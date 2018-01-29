#include<stdio.h>
void main(){
	float i, range=50, out=0;
	for(i=1;i<=range;i++)
		out+=1/i;
	printf("%.2f",out);
}
