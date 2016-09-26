
/* This module takes care of gif files 
Version : 1.0
Author : Team -C
*/

# include <string.h>
# include "handlers.h"


// function returns whether this can handle the file or not

int gif_canHandle(char *filename){
	int len;
	char *end;
	printf(" Checking whether I can handle %s or not \n",filename);
	len = strlen(filename);
	end = filename + (len -3);
	printf(" end = %s\n",end);
	// just for testing purpose, in the real code the file need to be
	// opened and we need to check for magic no's.
	if(strcmp(end,"gif") == 0)
		return TRUE;
	else
		return FALSE;
}

int gif_drawImage(char *filename){
	if( gif_canHandle(filename)){
		printf(" How is this image %s \n",filename);
		return TRUE;
	}
	else
		return FALSE;
}

int gif_savefile(char *newfilename ){
	printf(" file saved by gif handler \n");
	return TRUE;
}

imageHandler gifhandler = {
	gif_canHandle,
	gif_drawImage,
	gif_savefile
};

int _init(){
	printf(" registering gifhandler \n");
	reg_handler(&gifhandler);
	return 0;
}

int _fini(){
	printf(" Un registering gifhandler \n");
	return 0;
}	
