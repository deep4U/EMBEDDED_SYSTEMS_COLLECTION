#include<stdio.h>
void main()	{
	int number;
	printf("Enter the amount:");
	scanf("%d",&number);
	printf("%d notes of 100.00\n",number/100);
	if(number>=100)
		number=number%100;
	printf("%d notes of 50.00\n",number/50);
	if(number>=50)
		number=number%50;
	printf("%d notes of 20.00\n",number/20);
	if(number>=20)
		number=number%20;
	printf("%d notes of 10.00\n",number/10);
	if(number>=10)
		number=number%10;
	printf("%d notes of 5.00\n",number/5);
	if(number>=5)
		number=number%5;

	printf("%d notes of 2.00\n",number/2);
	if(number>=2)
		number=number%2;
	printf("%d notes of 1.00\n",number/1);
	if(number>=1)
		number=number%1;


}
