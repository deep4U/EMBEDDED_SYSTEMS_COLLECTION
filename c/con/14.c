#include<stdio.h>
void main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if (a==b&&b==c)
		printf("\nEQUILETERAL TRIANGLE FOUND");
	else if(a==b || b==c || a==c)
		printf("\n ISOSCELES TRAINGLE FOUND");
	else
		printf("\n SCALAR TRIANGLE FOUND");
}
