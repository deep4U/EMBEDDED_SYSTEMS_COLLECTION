#include <stdio.h>
char *a[]={"","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
void main(){
	int i;
	scanf("%d",&i);
	if(i<7&&i>0)
		printf("%s",a[i]);
	
}
