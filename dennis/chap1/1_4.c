#include <stdio.h>
main()
{
float fahr,celc;
celc=0;
printf("celc fahr\n");
while (celc <= 300)

{
//	celc= (5.0/9.0) * (fahr - 32.0);
	fahr=((9.0/5.0)*celc)+32;
	printf("%3.0f %6.1f\n",celc,fahr);
	celc+=20;
}
}
