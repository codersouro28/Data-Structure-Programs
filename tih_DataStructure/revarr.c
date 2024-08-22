#include<stdio.h>

void main(){
	int arr[20],ar2[20];
	int n,i,j,temp;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	
	for(i=0; i<n; i++){
		printf("Enter element arr[%d]:",i);
		scanf("%d",&arr[i]);
	}
	
	printf("\n--------ORIGINAL ARRAY---------\n");
	for(i=0; i<n; i++){
		printf("%d\t",arr[i]);
	}
	
	int size;
	for(i=0,size=n; i<size; i++, size--)
	{
		temp=arr[i];
		arr[i] = arr[size-1];
		arr[size-1] = temp;
	}
	
	printf("\n--------REVERSE ARRAY---------\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
