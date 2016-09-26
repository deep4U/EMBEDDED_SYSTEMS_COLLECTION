/*
   Rewrite fopen and _fillbuf with fields instead of explicit bit operations.
   To avoid confusion, my implementation of standard definitions have a suffix "x" 


   Field based approach is time consuming as we would have to check if each field 
   is set or not while finding a free slot. Using Bit manipulation, we just have to 
   compare the particular flag bit to zero.
   
   Bit fields can be used in struct _flags structure to reduce the total size of a File type.
 */

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

#define EOF (-1)
#define OPEN_MAX 20 // Maximum files that can be open
#define PERMS 0666



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
	bufsize = (fp->flags._UNBUF != 0)? 1:BUFSIZ;
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
}
