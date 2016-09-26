#include <stdio.h>
float ftoc(float fahr)
{
return ((5.0/9.0) * (fahr - 32.0));
}



main()
{
float fahr,celc;
fahr=0;
while (fahr <= 300)

{
        printf("%3.0f %6.1f\n",fahr,ftoc(fahr));
        fahr = fahr + 20;
}
}

