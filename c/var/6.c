int array[100];
int compare(const void *x,const void *y){
	return (*(int *)x-*(int *)y);
}
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&array[i]);
	qsort(array,n,sizeof(int),compare);
	
	for(i=0;i<n;i++)
		printf("\n\n%d\n",array[i]);
}
