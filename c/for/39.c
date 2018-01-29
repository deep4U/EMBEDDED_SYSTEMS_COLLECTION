#include<stdio.h>
void main(){
	int i,cnt=0;
	for(i=100;i<=200;i++ )
		if(i%9==0)
			printf("%d %d ",i,cnt+=i);
	printf("\n COUNT IS %d",cnt);
}
