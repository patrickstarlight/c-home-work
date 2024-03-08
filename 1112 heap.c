#include <stdio.h> 
#include <stdlib.h> 
#define LEN 10

void heapsort(int* arr, int len)
{
	int i;
	for(i=len-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		minheap(arr, i,0);
	}
} 
void minheap(int* arr, int len,int root)
{
	int left,right,smallest;
	left=root*2+1;
	right=root*2+2;
	if(left<len && arr[left]<arr[root])
		smallest=left;
	else
		smallest=root;
	if(right<len && arr[right]<arr[smallest])
		smallest=right;
	if(smallest!=root)
	{
		swap(&arr[smallest],&arr[root]);
		minheap(arr,len,smallest);
	}	
}
void swap(int *x,int* y)
{
	int temp;
	temp = *x;
 	*x = *y;
	*y = temp;
}
void print(int* arr, int len) {
    int i,j=2,x;
    for(i = 0; i < len; i++)
	{ 
		if(i==0)
	{
	
	}
	printf("%d ", arr[i]);
	if(i==0)
	{
		
			printf("\n");
	
	}
	if(i%j==0 && i>1)
	{
			printf("\n");
		j=j+j*2;
	}
	} 
    printf("\n");
}

int main() { 
    int num[LEN] = {10, 1, 9, 2, 5, 3, 8, 7, 12, 11};
	int i;
	printf("binary tree: \n");
    print(num, LEN);
    for(i=LEN-1;i>=0;i--)
    {
    	minheap(num, LEN,i); 
	}
	printf("min heap: \n");
    print(num, LEN);  
	heapsort(num,LEN);
	printf("heap sort: \n");
	for(i=0;i<10;i++)
		printf("%d ",num[i]);
	printf("\n");
	for(i=LEN-1;i>=0;i--)
		printf("%d ",num[i]);
    return 0; 
}