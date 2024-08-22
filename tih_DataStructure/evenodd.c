#include<stdio.h>
void main(){
	int arr[10],i;
	
	for(i=0;i<5;i++)
	{
		printf("Enter element for arr[%d]",i);
		scanf("%d",&arr[i]);
		
	}
	
	printf("The elements of array are:");
	
		for(i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
		
	}
		for(i=0;i<5;i++)
	{

		if(arr[i]%2==0){
		printf("The Even numbers are:%d\n ",arr[i]);
	}
	else{
		printf("The odd numbers are:%d\n" ,arr[i]);
	}
}
}

