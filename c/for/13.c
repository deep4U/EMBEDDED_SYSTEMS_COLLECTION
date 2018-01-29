#include <stdio.h>
#define SIZE 4
void main(){
	int spaces=(SIZE),no=1,i,j,k,l;
	for(i=0;i<SIZE;i++,spaces--){
		for(k=0;k<spaces;k++)
			printf(" ");
		for(j=0;j<(i+1);j++,no++)
			printf("%d ",no);
		for(k=0;k<spaces;k++)
			printf(" ");
		printf("\n");
	
	}
}
