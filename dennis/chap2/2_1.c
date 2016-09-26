#include<limits.h>
int main()
{

printf("range of unsigned int is %u to %u as in llimits .h and %u to %u as calculated",0,UINT_MAX,(unsigned int)(-((~0)>>1)),(unsigned int)(((~0)>>1)));
printf("range of signed char is %d to %d as in llimits .h and %d to %d as calculated",SCHAR_MIN,SCHAR_MAX,(((char)((~0 )))+1),(char)((unsigned char)~0 >> 1));










 printf("Minimum Signed Char %d\n",-(char)((unsigned char) ~0 >> 1) - 1);
    printf("Maximum Signed Char %d\n",(char) ((unsigned char) ~0 >> 1));

    printf("Minimum Signed Short %d\n",-(short)((unsigned short)~0 >>1) -1);
    printf("Maximum Signed Short %d\n",(short)((unsigned short)~0 >> 1));

    printf("Minimum Signed Int %d\n",-(int)((unsigned int)~0 >> 1) -1);
    printf("Maximum Signed Int %d\n",(int)((unsigned int)~0 >> 1));

    printf("Minimum Signed Long %ld\n",-(long)((unsigned long)~0 >>1) -1);
    printf("Maximum signed Long %ld\n",(long)((unsigned long)~0 >> 1));

    /* Unsigned Maximum Values */

    printf("Maximum Unsigned Char %d\n",(unsigned char)~0);
    printf("Maximum Unsigned Short %d\n",(unsigned short)~0);
    printf("Maximum Unsigned Int %u\n",(unsigned int)~0);
    printf("Maximum Unsigned Long %lu\n",(unsigned long)~0);






  printf("Size of Char %d\n", CHAR_BIT);
  printf("Size of Char Max %d\n", CHAR_MAX);
  printf("Size of Char Min %d\n", CHAR_MIN);
  printf("Size of int min %d\n", INT_MIN);
  printf("Size of int max %d\n", INT_MAX);
  printf("Size of long min %d\n", LONG_MIN);
  printf("Size of long max %d\n", LONG_MAX);
  printf("Size of short min %d\n", SHRT_MIN);
  printf("Size of short max %d\n", SHRT_MAX);
  printf("Size of unsigned char %d\n", UCHAR_MAX);
  printf("Size of unsigned long %d\n", ULONG_MAX);
  printf("Size of unsigned int %d\n", UINT_MAX);
  printf("Size of unsigned short %d\n", USHRT_MAX);


}
