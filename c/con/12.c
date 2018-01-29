#include<stdio.h>
int roll;
int pcc[3];
char name[100];
void main(){
	int i;
	scanf("%s %d",name,&roll);
	for(i=0;i<3;i++)
		scanf("%d",&pcc[i]);
	for(i=0;i<3;i++)
		printf("%d",pcc[i]);
	printf("Roll no : %d\n Name %s\nM in P:%d,M in c %d,M in CA %d\nTotal %d\n",roll,name,pcc[0],pcc[1],pcc[2],pcc[3],pcc[0]+pcc[1]+pcc[2]);
	if((float)(pcc[0]+pcc[1]+pcc[2])/3>=75)
		printf("%f\nFirst",(float)(pcc[0]+pcc[1]+pcc[2])/3);
	else if((float)(pcc[0]+pcc[1]+pcc[2])/3>=60)
		printf("%f\nSecond",(float)(pcc[0]+pcc[1]+pcc[2])/3);
	else if((float)(pcc[0]+pcc[1]+pcc[2])/3>=40)
		printf("%f\nThird",(float)(pcc[0]+pcc[1]+pcc[2])/3);
	else if((float)(pcc[0]+pcc[1]+pcc[2])/3<40)
		printf("%f\nFail",(float)(pcc[0]+pcc[1]+pcc[2])/3);
}
