#include<stdio.h>
int tol_mins;
void main(){
	scanf("%d",&tol_mins);
	printf("\n\n%d",tol_mins/60);
	printf("\n\n%d",tol_mins-(60*(tol_mins/60)));
	
}
