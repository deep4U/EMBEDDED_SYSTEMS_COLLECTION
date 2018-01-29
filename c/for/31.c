#include<stdio.h>
void main(){
	int n,i,j,hash=1;
	scanf("%d",&n);
	int max_spaces=(n-1)/2+10;
	for(i=0;i<n;i++){
		for(j=0;j<=max_spaces;j++)
			printf(" ");
		for(j=0;j<hash;j++)
			printf("*");
		for(j=0;j<=max_spaces;j++)
			printf(" ");
		printf("\n");
		max_spaces--;hash+=2;
			
	}
//	max_spaces=(n-1)/2+10;
	hash-=4;max_spaces+=2;
        for(i=1;i<n;i++){
                for(j=0;j<=max_spaces;j++)
                        printf(" ");
                for(j=0;j<hash;j++)
                        printf("*");
                for(j=0;j<=max_spaces;j++)
                        printf(" ");
                printf("\n");
                max_spaces++;hash-=2;

        }

}
