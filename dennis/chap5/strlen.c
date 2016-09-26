int strlen1(char *s)
{
int n;
for(n=0;*s!='\0';s++)
n++;
return n;}
int strlen2(char *s)
{
char *p=s;
while(*p!='\0')
p++;
return p-s;}
main()
{
printf("enter stuff");
char a[1000];
while(*a!='EOF')
{scanf("%s",a);
int nn=strlen2(a);
printf("\n length of %s is %d",a,nn);
}
}
