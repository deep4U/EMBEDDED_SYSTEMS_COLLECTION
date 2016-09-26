
#include <stdio.h>

int buf = EOF; /* buffer */

int getch(void) /* get pushed or from input character */
{
  int t;

  if (buf != EOF) {
    t = buf; //if buf has some pushed back char take it and empty buf
    buf = EOF;
  } else {
    t = getchar();  //else get from ip
  }
  return t;                          
}
 
void ungetch(int c) // push character back  
{
  if(buf != EOF)
    printf("too many characters you told you will do it only once Dennis :( \n");
  else       
    buf = c;
}
 
int main(void)
{
  int c;

  while ((c = getch()) != EOF) {
    if (c == '/') {
      putchar(c);
      if ((c = getch()) == '*') { 
        ungetch('!');
      }         
    } 
    putchar(c);               
  }
  return 0;
}


