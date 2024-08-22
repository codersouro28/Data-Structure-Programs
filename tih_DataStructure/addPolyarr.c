#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

void create(int arr[],int SIZE)
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

void addPoly(int a1[],int a2[],int a3[],int SIZE1,int SIZE2,int SIZE3)
{
	int i;
	int min=(SIZE1<SIZE2)?SIZE1:SIZE2;
	int flag=(SIZE1>SIZE2)?1:2;
	
	for(i=SIZE3;i>=0;i--)
	{
		if(i<=min)
			a3[i]=a1[i]+a2[i];
		else
		{
			if(flag==1)
				a3[i]=a1[i];
			else
				a3[i]=a2[i];
		}
		}	
}
void display(int *arr,int SIZE)
{
	int i,j;
	j=SIZE-1;
	for(i=SIZE-1;i>=0;i--)
	{
			if(arr[i]!=0)
			{
			if(arr[i]>0)
				printf("+%dx^ %d",arr[i],i);
			else
				printf("%dx^ %d",arr[i],i);
	}
	
}
}
void main()
{
	int i=0;
	int *arr1,*arr2,*arr3,SIZE1,SIZE2,SIZE3;
	printf("Enter the maximum degree of Poly1:");
	scanf("%d",&SIZE1);
	SIZE1++;
	arr1=(int*)calloc(SIZE1,sizeof(int));
	create(arr1,SIZE1);
	printf("Enter the maximum degree of Poly2:");
	scanf("%d",&SIZE2);
	SIZE2++;
	arr2=(int*)calloc(SIZE2,sizeof(int));
	create(arr2,SIZE2);
	SIZE3=(SIZE1>SIZE2)?SIZE1:SIZE2;
	arr3=(int*)calloc(SIZE3,sizeof(int));
		
	display(arr1,SIZE1);
	printf("\n");
	printf("+");
	display(arr2,SIZE2);
	printf("\n-------------------------------------------------\n");
	printf("=");
	addPoly(arr1,arr2,arr3,SIZE1,SIZE2,SIZE3);
	display(arr3,SIZE3);
}
	
