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

int bubble_sort(int *arr,size_t len){
	int i,j;
	int swapped=1;
	for(i=0;i<len;i++){
		swapped=0;
		for(j=0;j<len;j++){
			if(arr[j]>arr[j+1]){
				swap(arr,j,j+1);
				swapped=1;
			}
		}
		if(swapped==0)
			break;
	}

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
bubble_sort(arr,(sizeof(arr)/sizeof(int)));
print_arr(arr,(sizeof(arr)/sizeof(int)));
}

