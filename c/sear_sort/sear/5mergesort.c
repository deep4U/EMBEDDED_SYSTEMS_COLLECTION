#include<stdio.h>
void print_arr(int* ,size_t );
void merge(int arr[],size_t l,size_t m,size_t r) {
	printf("INTO MERGE l is %d\n m is %d\n r is %d\n",l,m,r);
	print_arr(arr,10);
	int n1,n2;
	n2=r-m;
	n1=m-l+1;
	int i,j,k;
	int array_right[n2];int array_left[n1];
	for(i=0;i<n1;i++)
		array_left[i]=arr[i+l];
	for(j=0;j<n2;j++)
		array_right[j]=arr[m+j+1];
	for(i=0,j=0,k=l;i<n1&&j<n2;k++){
		if(array_right[j]<=array_left[i])
		{	arr[k]=array_right[j];j++;}
		else
		{	arr[k]=array_left[i];i++;}
	}
	while(i<n1){
		
			arr[k]=array_left[i];i++;k++;
	}
	while(j<n2)
		{	arr[k]=array_right[j];j++;k++;}
	print_arr(arr,10);
}
void merge_sort(int *arr,size_t l,size_t r){
	if(l<r){
	print_arr(arr,10);
	int m=l+(r-l)/2;
	printf("INTO MERGE_SORT FOR L %d AND R %d m is %d \n",l,r,m);
	merge_sort(arr,l,m);
	merge_sort(arr,m+1,r);
	merge(arr,l,m,r);
	printf("OUT OF MERGE_SORT FOR L %d AND R %d \n",l,r);
	print_arr(arr,10);
	}}

void print_arr(int *arr,size_t len){
	int i;
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void main(void){
//const int *a;
//const int* const a;	
int arr[]={10,200,32,54,53,56,500,5};
print_arr(arr,(sizeof(arr)/sizeof(int)));
merge_sort(arr,0,(sizeof(arr)/sizeof(int))-1);
print_arr(arr,(sizeof(arr)/sizeof(int)));
}

