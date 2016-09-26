/* test driver */

/* We get a helpful boost for testing from the question text, because we are
 * told that the function's behaviour is identical to strpbrk except that it
 * returns a pointer instead of a position. We use this fact to validate the
 * function's correctness.
 */

#include <stdio.h>
#include <string.h>
void squeeze(char s[], int c)
{
int i,j;

for(i=j=0;s[i]!='\0';i++)
if(s[i]!=c)
	s[j++]=s[i];
s[j]='\0';
}
int any(char s1[],char s2[])
{
int i,j,k;
for(i=j=0;s1[i]!='\0';i++)
//if(s[i]!=c)
{
for(k=0;s2[k]!='\0';k++)
{
if(s2[k]==s1[i])        
return(i);
//s[j++]=s[i];
//else
//j--;
}

}
return(-1);
}
int main(void)
{
  char *leftstr[] =
  {
    "",
    "a",
    "antidisestablishmentarianism",
    "beautifications",
    "characteristically",
    "deterministically",
    "electroencephalography",
    "familiarisation",
    "gastrointestinal",
    "heterogeneousness",
    "incomprehensibility",
    "justifications",
    "knowledgeable",
    "lexicographically",
    "microarchitectures",
    "nondeterministically",
    "organizationally",
    "phenomenologically",
    "quantifications",
    "representationally",
    "straightforwardness",
    "telecommunications",
    "uncontrollability",
    "vulnerabilities",
    "wholeheartedly",
    "xylophonically",
    "youthfulness",
    "zoologically"
  };
  char *rightstr[] =
  {
    "",
    "a",
    "the",
    "quick",
    "brown",
    "dog",
    "jumps",
    "over",
    "lazy",
    "fox",
    "get",
    "rid",
    "of",
    "windows",
    "and",
    "install",
    "linux"
  };

  size_t numlefts = sizeof leftstr / sizeof leftstr[0];
  size_t numrights = sizeof rightstr / sizeof rightstr[0];
  size_t left = 0;
  size_t right = 0;

  int passed = 0;
  int failed = 0;

  int pos = -1;
  char *ptr = NULL;

  for(left = 0; left < numlefts; left++)
  {
    for(right = 0; right < numrights; right++)
    {
      pos = any(leftstr[left], rightstr[right]);
      ptr = strpbrk(leftstr[left], rightstr[right]);

      if(-1 == pos)
      {
        if(ptr != NULL)
        {
          printf("Test %d/%d failed.\n", left, right);
          ++failed;
        }
        else
        {
          printf("Test %d/%d passed.\n", left, right);
          ++passed;
        }
      }
      else
      {
        if(ptr == NULL)
        {
          printf("Test %d/%d failed.\n", left, right);
          ++failed;
        }
        else
        {
          if(ptr - leftstr[left] == pos)
          {
            printf("Test %d/%d passed.\n", left, right);
            ++passed;
          }
          else
          {
            printf("Test %d/%d failed.\n", left, right);
            ++failed;
          }
        }
      }
    }
  }
  printf("\n\nTotal passes %d, fails %d, total tests %d\n",
         passed,
         failed,
         passed + failed);
  return 0;
}

