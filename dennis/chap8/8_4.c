/*
   Rewrite fopen and _fillbuf with fields instead of explicit bit operations.
   To avoid confusion, my implementation of standard definitions have a suffix "x" 


   Field based approach is time consuming as we would have to check if each field 
   is set or not while finding a free slot. Using Bit manipulation, we just have to 
   compare the particular flags bit to zero.
   
   Bit fields can be used in struct _flags structure to reduce the total size of a File type.
 */
#include <stdio.h>
#include<stdlib.h>
#define O_RDONLY        0x0000
#define O_WRONLY        0x0001
#define EOF (-1)
#define OPEN_MAX 20 // Maximum files that can be open
#define PERMS 0666
#define BUFSIZE 4096
// Field based approach for flags
typedef struct _flags{
	int _READ;
	int _WRITE;
	int _UNBUF;
	int _EOF;
	int _ERR;
}flags;

// File Data structre.

typedef struct _iobuf {
	int cnt;
	char *ptr;
	char *base;
	struct _flags flags;
	int fd;
}FILEx;

FILEx _iob[OPEN_MAX];

int _flushbufx(int, FILEx *);
#define feof(p) ((p->flags& _EOF)!=0)
#define ferror(p) ((p->flags & _ERR)!=0)
#define fileno(p) (p->fd)
#define getchar() (getc(stdin))
#define putchar(x) (putc((x),stdout))

int _fillbuffx(FILEx *f);


#define getcx(p) (--(p)->cnt >= 0? (unsigned char) *(p)->ptr++:_fillbufx(p))


//Check if Slot is empty by checking if all fields are
//empty in the flags structure


int is_empty(struct _flags flags){
	if(!flags._READ && !flags._WRITE && !flags._UNBUF &&
			!flags._EOF && !flags._ERR)
		return 1;
	return 0;
}



FILEx *fopenx(char *name,char *mode){
	
	int fd;
	FILEx *fp;
	// Invalid Input
	if( *mode != 'r' && *mode != 'w' && *mode != 'a' )
		return NULL;

	// Check for free slot
	for( fp= _iob; fp< _iob + OPEN_MAX ; fp++)
		if(is_empty(fp->flags))
			break;
	// If FULL return NULL
	if( fp>= _iob+OPEN_MAX )
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
	if(*mode == 'r')
		fp->flags._READ = 1;
	else
		fp->flags._WRITE = 1;
	return fp;
}



int _fillbufx(FILEx *fp){

	int bufsize;

	if(fp->flags._READ == 0)
		return EOF;
	bufsize = (fp->flags._UNBUF != 0)? 1:BUFSIZE;
	if(fp->base == NULL)
		if((fp->base = (char *) malloc (bufsize))==NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd,fp->ptr,bufsize);
	if(--fp->cnt< 0){

		if(fp->cnt == -1)
			fp->flags._EOF=1;
		else
			fp->flags._ERR=1;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}
int _flushbufx(int c, FILEx *f) {
        int num_written, bufsize;
        unsigned char uc = c;

        if((f->flags._EOF | f->flags._ERR) ) {
                return EOF;
        }

        if(f->base == NULL && ((f->flags._UNBUF)==0)) {
                if((f->base = malloc(BUFSIZE))==NULL)
                        f->flags._UNBUF=1;
                else {
                        f->ptr = f->base;
                        f->cnt = BUFSIZE - 1;
                }
        }
        if(f->flags._UNBUF==1) {
                f->ptr = f->base = NULL;
                f->cnt = 0;
                if(c==EOF) {
                        return EOF;
                }
                num_written=write(f->fd,&uc,1);
                bufsize=1;
        } else {
                bufsize = (int )(f->ptr - f->base);
                num_written = write(f->fd, f->base, bufsize);
                f->ptr = f->base;
                f->cnt = BUFSIZE - 1;
        }
        if (num_written == bufsize)
                return c;
            else {
                f->flags._ERR= 1;
                return EOF;
            }
}

int fflushx(FILEx *f)
{
	int retval;
	int i;
	retval =0;
	if(f==NULL) {
		for(i=0;i<OPEN_MAX;i++) {
			if((_iob[i].flags._WRITE==1) &&(fflushx(&_iob[i])==-1))
				return -1;
	}
	}	else {
			if((f->flags._WRITE)==0)
				return -1;
			_flushbufx(EOF, f);
			if(f->flags._ERR)
				return -1;
	}
	return retval;
}

int fclosex(FILEx *f)
{
    int fd;

    if (f == NULL)
        return -1;

    fd = f->fd;
    fflushx(f);
    f->cnt = 0;
    f->ptr = NULL;
    if (f->base != NULL)
        free(f->base);
    f->base = NULL;
    f->flags._READ=f->flags._WRITE=f->flags._ERR=f->flags._EOF=f->flags._UNBUF = 0;
    f->fd = -1;
    return close(fd);
}





int main(int argc, char *argv[]) {
    int c;
    while ((c =getchar()) != 'x') {
        putchar(c);
    }
}

int fseekx(FILEx *fp, long offset, int origin) {
	if((fp->flags._UNBUF==0) && fp->base!=NULL) {
		//buffered io so handle buffer first
		if((fp->flags._WRITE==1)) {
			if(fflushx(fp))
				return EOF;
		} else if(fp->flags._READ) {
			fp->cnt=0;
			fp->ptr=fp->base;
		}
	}
	  return (lseek(fp->fd, offset, origin) < 0);
		
	}


/*
int main(void){
	//Use your own file.
	FILEx *fp = fopenx("test.c","r");
	if(fp!=NULL){	
		char c;
		// getcx is a macro defined above
		while((c=getcx(fp))!=EOF)
			putchar(c);
	}
	else
		puts("Error");
	return 0;
}*/
