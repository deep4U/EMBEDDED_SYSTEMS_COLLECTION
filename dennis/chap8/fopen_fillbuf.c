#include<stdlib.h>
#define O_RDONLY	0x0000
#define O_WRONLY	0x0001
#define EOF (-1)
#define OPEN_MAX 20 // Maximum files that can be open
#define PERMS 0666
#define BUFSIZE 1024

// File Data structre.

typedef struct _iobuf {
	int cnt;
	char *ptr;
	char *base;
	int flags;
	int fd;
}FILE;

FILE _iob[OPEN_MAX];


int _fillbuffx(FILE *f);
#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags {
_READ=01,
_WRITE=02,
_UNBUF=04,
_EOF=10,
_ERR=20};
#define feof(p) ((p->flags& _EOF)!=0)
#define ferror(p) ((p->flags & _ERR)!=0)
#define fileno(p) (p->fd)
#define getchar() (getc(stdin))
#define putchar(x) (putc((x),stdout))

#define getcx(p) (--(p)->cnt >= 0? (unsigned char) *(p)->ptr++:_fillbufx(p))


//Check if Slot is empty by checking if all fields are
//empty in the flags structure





FILE *fopenx(char *name,char *mode){
	
	int fd;
	FILE *fp;
	// Invalid Input
	if( *mode != 'r' && *mode != 'w' && *mode != 'a' )
		return NULL;

	// Check for free slot
for(fp=_iob;fp<_iob + OPEN_MAX;fp++)
	if((fp->flags & (_READ | _WRITE ))==0)
	break;
	if(fp>=_iob+OPEN_MAX)
		return NULL;
	// Create file on Write Mode
	if( *mode == 'w')
		fd = creat(name,PERMS);
	// Append Mode - If file not present create one
	else if( *mode == 'a') {
		if((fd = open(name,O_WRONLY,0))==-1)
			fd = creat(name,PERMS);
		lseek(fd,0L,2); // Go to end, in case of append
	}
	else
		fd = open(name,O_RDONLY,0);
	if(fd == -1)
		return NULL;
	fp->fd = fd;
	fp->cnt=0;
	fp->base=NULL;
	fp->flags= (*mode =='r') ? _READ : _WRITE;
	return fp;
}



int _fillbufx(FILE *fp){

	int bufsize;

	if(fp->flags&(_READ|_EOF|_ERR) !=_READ)
		return EOF;
	bufsize = ((fp->flags)&_UNBUF != 0)? 1:BUFSIZE;
	if(fp->base == NULL)
		if((fp->base = (char *) malloc (bufsize))==NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd,fp->ptr,bufsize);
	if(--fp->cnt< 0){

		if(fp->cnt == -1)
			fp->flags  |=_EOF;
		else
			fp->flags |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}


int main(void){
	//Use your own file.
	FILE *fp = fopenx("./test.c","r");
	if(fp!=NULL){	
		char c;
		// getcx is a macro defined above
		while((c=getcx(fp))!=EOF)
			putchar(c);
	}
	else
		puts("Error");
	return 0;
}

