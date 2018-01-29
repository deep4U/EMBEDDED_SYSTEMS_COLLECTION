#include<stdio.h>
const void *binsearch_gen(const void *key,  const void *base1,
                    size_t nmemb, size_t size,
                    int (*compar)(const void *, const void *)){
	void *base=base1;
	void *middle= base+(size*(nmemb/2));
	nmemb--;
	printf("INITAL MIDDLE IS %p size*(nmemb/2) is %d\n ",middle,size*(nmemb/2));
//	nmemb/=2;
	while(1)
	{
	
		printf("CALLED \n");
	if(nmemb>1){
		nmemb=nmemb/2;
		printf("CALLED1 middle = %p base=%p\n",middle,base);
		if(compar(middle,key)==0)
			return middle;
		else if(compar(middle,key)==1)
			middle= base -((size)*(nmemb/2));
//			middle= base + (size*nmemb)/4;
		else if(compar(middle,key)==-1)
		{	base=middle+size;middle= base +((size)*(nmemb/2));}
		printf("CALLED2 middle=%p base=%p  \n",middle,base);
	}
	else if (compar(middle,key)==0)
		return middle;
	else
		return NULL;
	}
	return NULL;
}

int intcomp (const void *i,const void *j){
	if((*((int *)i)>((*(int *)j))))
		return 1;
	else if ((int)(*(int *)i)<(int)(*(int *)j))
		return -1;
	else
		return 0;
}
int charcomp (const void *i,const void *j){
        if((*((char *)i)>((*(char *)j))))
                return 1;
        else if ((*(char *)i)<(*(char *)j))
                return -1;
        else
                return 0;
}

int binsearch(const int key,int nmemb, int base, int arr[]) 
{
		printf("CALLED \n");
		if(nmemb > 1) 
		{
//			int middle = base + (nmemb - base)/2;
			int middle = (base + nmemb)/2;
			if(arr[middle] == key)
				return middle;
			
			if (key < arr[middle])
				return	binsearch(key,middle-1,base,arr);
			else if(key > arr[middle])  			 	
				return	binsearch(key,nmemb,middle+1,arr);
		}
				return -1;
		
}

void main(int argc,char *argv[]) {

	int key = atoi(argv[1]);int i;
	int arr[] = { 5,6,7,12,26,37,65,78,89,92 };
	printf(" START %p	 END  %p\n",arr,arr+(sizeof(arr)/sizeof(int))-1);
	for( i=0;i<(sizeof(arr)/sizeof(int));i++)
		printf(" arr %d index is %p value is %d\n",i,(arr+(i)),*(arr+i));
	size_t size = sizeof(arr)/sizeof(arr[0]);
	
//	int res = binsearch(key,size,0,arr,intcomp);
//	int res =*((int *) binsearch_gen(&key,&arr,10,sizeof(int),intcomp));
	int *res=((int *) binsearch_gen(&key,&arr,10,sizeof(int),intcomp));
	if(res!=NULL)
		printf("found at %p value is %d after %p where value is %d\n",res,*res,res-1,*(res-1));
	char carr[]={'a','b','c','d','e','f'};
	char key_c=argv[2][0];

	printf(" START %p	 END  %p	%d\n",carr,carr+(sizeof(carr)/sizeof(char))-1,(sizeof(carr)/sizeof(char))-1);
	for( i=0;i<(sizeof(carr)/sizeof(char));i++)
		printf(" arr %d index is %p value is %c\n",i,(carr+(i)),*(carr+i));
	char *res_c=((char *) binsearch_gen(&key_c,&carr,6,sizeof(char),charcomp));
        if(res_c!=NULL)
                printf("found at %p value is %c after %p where value is %c\n",res_c,*res_c,res_c-1,*(res_c-1));

//	if(NULL!=((int *) binsearch_gen(&key,&arr,10,sizeof(int),intcomp)))
//		printf("found at %p",((int *) binsearch_gen(&key,&arr,10,sizeof(int),intcomp)));
//	if (res == -1)
	//	printf("Number not found\n");
//	else
//		printf("Number found Index: %d\n",res);

	return ;
		
}
