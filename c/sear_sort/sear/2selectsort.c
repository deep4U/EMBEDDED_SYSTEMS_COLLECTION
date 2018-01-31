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
int find_min_index(int *arr,int start,int end){
	printf("IN FINDMIN start is %d and end is %d\n",start,end);
	int min=arr[start],index,index_min=start;
	for(index=start;index<=end;index++)
		if(min>arr[index]){
			min=arr[index];
			index_min=index;
		}
	return index_min;
}
int select_sort(int *arr,size_t len){
	int curr_boundry;//boundry between sorted and unsorted part
	for(curr_boundry=0;curr_boundry<len;curr_boundry++)
		swap(arr,curr_boundry,find_min_index(arr,curr_boundry,len-1));

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
select_sort(arr,(sizeof(arr)/sizeof(int)));
print_arr(arr,(sizeof(arr)/sizeof(int)));
}

