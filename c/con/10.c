#include<stdio.h>
int maths,chem,phy;
void main(){
	scanf("%d %d %d",&maths,&phy,&chem);
	if(maths>=65 && phy>=55 && chem>=50 && (((chem+phy+maths)>=180)|| (maths+phy)>=140))
		printf("ELIGIBLE FOR ADMISSION");
	else
		printf("SORRY");
}
