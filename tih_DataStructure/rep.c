#include<stdio.h>
void main(){
	int arr[10],i,n,c=0;
	
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
	printf("Enter the element whose dupliccity is to be checked:");
	scanf("%d",&n);
		
	
		for(i=0;i<5;i++)
		{
			if(arr[i]==n)
			c++;
		}
		if(c>1)
		printf("%d is present %d times",n,c);
		
 
		 
}


