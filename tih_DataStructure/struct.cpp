#include<stdio.h>
struct student
{
	int roll;
	char name[20];
	int total;
};
int main()
{
	struct student s[4];
	int i,j,max;
	for(i=0;i<4;i++)		/*Input to Array of Structures*/
	{
		printf("\n Enter roll=");
		scanf("%d",&s[i].roll);
		printf("\n Enter Name:");
		fflush(stdin);
		gets(s[i].name);
		printf("\n Total Marks=");
		scanf("%d",&s[i].total);
	}
	max=s[0].total;
	j=0;
	for(i=1;i<4;i++)
	{
		if(s[i].total>max)
		{
			max=s[i].total;
			j=i;
		}
	}
	printf("Roll=%d ",s[j].roll);
	printf("Name=%s ",s[j].name);
	printf("Maximum Marks=%d ",max);
	return(0);
}


