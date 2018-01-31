#include<stdio.h>
void print_arr(int* ,size_t );
void swap(int *arr,int first,int second){
	printf("IN SWAP %d and  %d \n",first,second);
	if(first==second) return;
	arr[first]=arr[first]+arr[second];
	arr[second]=arr[first]-arr[second];
	arr[first]=arr[first]-arr[second];
	printf("OUT SWAP %d and  %d \n",first,second);
	print_arr(arr,8);
}

int insert_sort(int *arr,size_t len){
	int i,j;
	for(i=1;i<len;i++)
		for(j=i;j>0 && arr[j-1]>arr[j];j--)
			swap(arr,j,j-1);
	}

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
insert_sort(arr,(sizeof(arr)/sizeof(int)));
print_arr(arr,(sizeof(arr)/sizeof(int)));
}

