#include <stdio.h>
main()
{
float fahr,celc;
fahr=300;
while (fahr >= 0)

{
	celc= (5.0/9.0) * (fahr - 32.0);
	printf("%3.0f %6.1f\n",fahr,celc);
	fahr = fahr - 20;
}
}
