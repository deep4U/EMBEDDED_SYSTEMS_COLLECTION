void strcpy1(char *s,char *t)
{
int i;
i=0;
while((s[i]=t[i]) != '\0')
i++;}
void strcpy2(char *s,char *t)
{
while((*s=*t) != '\0')
{
	s++;
	t++;
}
}
void strcpy3(char *s,char *t)
{
while((*s++=*t++)!='\0');}
void strcpy4(char *s,char *t)
{
while(*s++=*t++);}

void main()
{}
