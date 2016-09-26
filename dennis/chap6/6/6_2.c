#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Capacity of putback buffer. */
#define BUFSIZE 100

/* Putback buffer. */
char buf[BUFSIZE];

/* Number of characters in putback buffer. */
int bufp = 0;

/* Retrieves and returns a character from stdin or from the putback
   buffer.
   Returns EOF if end of file is encountered. */
int getch(){
	return (bufp > 0)? buf[--bufp] : getchar();
}

void ungetch(int c){
	if(bufp >= BUFSIZE)
		printf("\nUngetch: Too many characters");
	else
		buf[bufp++] = c;
}
struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right
};
#define MAXWORD 100
struct tnode *addtree(struct tnode *,char *);
void treeprint(struct tnode *);
int getword(char *,int );
struct tnode *talloc(void);
char *strdup1(char *s);




int mystrcmp(char *, char *, int);

void mytreeprint(struct tnode *p, int n)
{
    static int printprevious = 1; /*flag to print previous node */
    static struct tnode *previous;
    if (p != NULL)
    {
        mytreeprint(p->left, n);
        if (n == 0) /* if n = 0, print all the nodes */
            printf("%4d %s\n", p->count, p->word);
        else
        {
            if (previous != NULL)
            {
                if (mystrcmp(previous->word, p->word, n))  /* returns 1 if first n chars are identical */
                {

                    if (printprevious)
                    {
                        printf("%4d %s\n", previous->count, previous->word);
                        printprevious = 0; /* when previous has been printed, no need to print again until a new series is encountered */
                    }
                    printf("%4d %s\n", p->count, p->word);


                }
                else
                    printprevious = 1; /* if the comparison are no longer true, reset printprevious to get ready for next series */

            }
            previous = p; /* keep track of pointers to previous encountered node for comparison purposes */
        }
        mytreeprint(p->right, n);
    }
}

int mystrcmp(char *s1, char *s2, int n)
{
    int i;
    if (n == 0)
        return 1;
    for (i = 0; *s1 == *s2 && *s1 != '\0' && i < n; i++, *s1++, *s2++)
        ;
    if (i == n)
        return 1;
    return 0;
}











main()
{
	struct tnode *root;
	char word[MAXWORD];
	root = NULL;
	while(getword(word,MAXWORD)!=EOF)
		if(isalpha(word[0]))
			root=addtree(root,word);
	treeprint(root);
	return 0;
}


struct tnode *addtree(struct tnode *p,char *w)
{
	int cond;
	if(p==NULL) {
		p=talloc();
		p->word=strdup1(w);
		p->count=1;
		p->left=p->right=NULL;
	}
	else if((cond=strcmp(w,p->word))==0) {
		p->count++;	
	}
	else if(cond<0)
		p->left=addtree(p->left,w);
	else
		p->right=addtree(p->right,w);
	return p;
}


void treeprint(struct tnode *p)
{
	if(p!=NULL) {
		treeprint(p->left);
		printf("%4d %s \n",p->count,p->word);
		treeprint(p->right);
	}
}
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup1(char *s)
{
	char *p;
	p=(char *) malloc(strlen(s)+1);
	if(p!=NULL)
		strcpy(p,s);
	return p;
}


// getword returns the length of the word.
// Word can begin with an underscore.
int getword(char *word,int lim){
	
	int c;
	char *w = word;

	while(isspace(c = getch()));
	if(c==EOF)
		return -1;
	
	// Word begin with alpha or _
	if(isalpha(c) || c=='_')
		*w++=c;
	//Remove <*>
	if(c=='<'){
		while(c!='>')
			c = getch();
	}

	//Remove comments
	if(c=='/'){
		c = getch();
		if(c=='/'){
			while(c!='\n' && c!=EOF)
				c = getch(); // skip till end of line.
		}
		else if(c=='*'){
			while(1){
				c = getch(); 
				if(c == '*'){
					c = getch();
					if(c=='/' || c==EOF)
						break; // break on abrupt end of file.
				}
				if(c == EOF)
					break; // break on abrupt end of file.
			}
		}
	}

	//Remove string constants
	if(c=='"'){
		do{
			c = getch();
		}while(c!='"' && c!=EOF);
	}

	if(!isalpha(c) && c!='_'){
		*w = '\0';
		return w-word;
	}
	for(; --lim>0; w++){
		*w = getch();

		if(!isalnum(*w) && *w!='_'){
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return w-word;
}



