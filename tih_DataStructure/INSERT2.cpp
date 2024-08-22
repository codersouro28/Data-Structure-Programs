#include<stdio.h>
#include<stdlib.h>
typedef struct Customer{
	int cust_id;
	char pno[12];
	char name[100];
	int items;
	int *price;
	float amount;
}Custo;

int main(){
	Custo Cust;
	int i;
	float amt;
	printf("PLEASE ENTER THE CUSTOMER ID: ");
	scanf("%d",&Cust.cust_id);
	printf("ENTER THE PHONE NUMBER OF CUSTOMER: ");
	fflush(stdin);
	scanf("%s",&Cust.pno);
	printf("ENTER THE NAME OF THE CUSTOMER: ");
	fflush(stdin);
	gets(Cust.name);
	printf("ENTER THE NUMBER OF ITEMS:");
	scanf("%d",&Cust.items);
	Cust.price=(int* )malloc(Cust.items*sizeof(int));
	for(i=0;i<Cust.items;i++)
	{
		printf("ENTER PRICE OF ITEM-%d: ",(i+1));
		scanf("%d",&Cust.price[i]);
		Cust.amount=Cust.amount+Cust.price[i];
		}
			

  printf("CUSTOMER ID\t\t CUSTOMER PHONE NUMBER\t\t CUSTOMER NAME \t\t PRICE\n");
  printf("%d				%s	%-200s",Cust.cust_id,Cust.pno,Cust.name);
  for(i=0;i<Cust.items;i++){
  	printf("%210d\n",Cust.price[i]);
  }
  	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("Amount=%200.2f",Cust.amount);
} 
