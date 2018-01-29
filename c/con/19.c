#include<stdio.h>
long int units;
void main(){
	float cost;
	scanf("%ld",&units)	;
	if(units<200)
		cost=1.2;
	else if (units<400)
		cost=1.5;
	else if(units<600)
		cost=1.8;
	else
		cost=2.0;
	double charge=cost*units;
	if(charge>400)
		charge=charge*1.15;
	else if(charge<100)
		charge=100;
	printf("%f",charge);
}
