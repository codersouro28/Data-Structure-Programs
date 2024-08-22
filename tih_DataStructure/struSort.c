#include<stdio.h>
#include<stdlib.h>

struct Student{
	int roll;
	char name[20];
	int tmarks;
};

void main()
{
	struct Student s[5];
	struct Student t;
	int i,j;
	for(i=0;i<3;i++)
	{
		printf("Enter the roll no. of student %d: \n",i+1);
		scanf("%d",&s[i].roll);
		printf("Enter the name of student %d: \n",i+1);
		fflush(stdin);
		gets(s[i].name);
		printf("Enter the Total marks of student %d: \n",i+1);
		scanf("%d",&s[i].tmarks);
		printf("\n\n");
   }
   
   for(i=0;i<3;i++)
   {
   	for(j=i+1;j<3;j++)
   	{
   		if(s[i].tmarks<s[j].tmarks){
   			t=s[i];
   			s[i]=s[j];
   			s[j]=t;
		   }
	   }
   }
	printf("\n---------------MERIT LIST----------------\n");
	printf("\nROLL \t NAME \t\t TOTAL MARKS\n");
	for(i=0;i<3;i++)
	{
		printf("%3d \t %-20s \t\t %-3d\n",s[i].roll,s[i].name,s[i].tmarks);
	}
}
