#include <stdio.h>

#define STR_BUF    10000
#define STR_MATCH  7 /* Used as the base number of characters to match with. */


char *deep_strncpy(char *s, const char *t, int n)
{
int count=1;
while((*s++=*t++))
{
	if(count++==n)
		{break;}
}
return s;
}

char *deep_strncat(char *s, const char *t, int n)
{
	int i=0;
	int len=0;
	char *a=s;
	while(*a++!='\0')
		len++;
	for(i=0;n>0;i++,n--)
	{
		*(s+len+i)=*t++;
	
	}
	*(s+len+i) = '\0';
	return s;
}
int deep_strncmp(const char *s, const char *t, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(*(s+i)> *(t+i))
			return ((*(s+i))-(*(t+i)));
	
	}
	return 0;
}
int main(int argc, char *argv[])
{
        int result;
        char str_s[STR_BUF] =  "All along the watchtower.";
        char buf_1[STR_BUF];
        char buf_2[STR_BUF] = "Bob Dylan: ";
        char buf_3[STR_BUF] = "All along the Watchposition.";

        printf ("----------------------------------------------------------\n");
        printf ("  Base String: %s\n", str_s);
        printf ("----------------------------------------------------------\n");

        deep_strncpy (buf_1, str_s, STR_MATCH);
        printf ("buf_1 (deep_strncpy, 7 chars): %s\n", buf_1);

        deep_strncat (buf_2, str_s, STR_MATCH);
        printf ("buf_2 (deep_strncat, 5 chars): %s\n", buf_2);

        result = deep_strncmp(buf_3, str_s, STR_MATCH);

        printf ("buf_3 (deep_strncmp, 6 chars): %s\n", buf_3);

        if ( result == 0 ) {
                printf ("deep_strncmp result: Both strings match up to %d (s).\n",
                        STR_MATCH );
        } else if ( result == -1 ) {
                printf ("deep_strncmp result: Strings do not match, buf_3 string ");
                printf ("has a lesser value.\n");
        } else if ( result == 1 ) {
                printf ("deep_strncmp result: Strings do not match, ");
                printf ("base string has a greater value than buf_3.\n");
        }

        return 0;
}

