#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

void create(int *arr,int SIZE)
{
	int pow,coef;
	char ch;
	printf("Enter Y to start:");
	fflush(stdin);
	scanf("%c",&ch);
	while(toupper(ch)=='Y')
	{
		printf("Enter the power:");
		scanf("%d",&pow);
		printf("Enter the Coefficient:");
		scanf("%d",&coef);
		arr[pow]=coef;
		printf("Do you want to continue?(Y/N)");
		fflush(stdin);
		scanf("%c",&ch);
	}
}

void main()
{
	int i=0;
	int *arr,SIZE;
	printf("Enter the max.degree of the polynomial:");
	scanf("%d",&SIZE);
	SIZE++;
	arr=(int*)calloc(SIZE,sizeof(int));
	create(arr,SIZE);
	printf("The polynomial is:\n");
	for(i=SIZE-1;i>=0;i--)
	{
		if(arr[i]!=0)
		{
			if(arr[i]>0)
				printf("+%dx^%d",arr[i],i);
			else
				printf("%dx^%d",arr[i],i);
		}
	}
	
}
