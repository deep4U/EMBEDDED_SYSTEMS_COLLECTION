#include <stdio.h>
int main() {
    unsigned int number_of_in,current_number,current_number_bak,reverse_number,ander,i=0,current_bit;
    scanf("%d",&number_of_in);
    for(i=0;i<=number_of_in;i++)
    {
	    scanf("%u",&current_number);
	    reverse_number=0;
	    current_number_bak=current_number	    ;
	    ander=2147483648;
	    for(current_bit=0;current_bit<32;current_bit++,current_number=current_number>>1)
		{
			if(current_number&1)
				reverse_number=reverse_number|ander;
				ander=ander>>1;
		}
	    printf("\n%u and %u",current_number_bak,reverse_number);
    }
	//code
	return 0;
	}
