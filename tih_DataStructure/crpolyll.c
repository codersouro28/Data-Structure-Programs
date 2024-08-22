#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

typedef struct Poly{
	int coef,pow;
	struct Poly *next;
}Poly;

void insertAtEnd(Poly **head, int pow, int coef)
{
	Poly *q,*r;
	q=(Poly*)malloc(sizeof(Poly));
	q->pow=pow;
	q->coef=coef;
	q->next=NULL;
	
	if(*head==NULL)
		*head=q;
	else
	{
		r=*head;
		while(r->next!=NULL)
		{
			r=r->next;
		}
		r->next=q;
	}	
}

void create(Poly **head)
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
		insertAtEnd(head,pow,coef);
		printf("Do you want to continue?(Y/N)");
		fflush(stdin);
		scanf("%c",&ch);
	}
}

void display(Poly *head)
{
	Poly *q=head;
	if(q->coef<0)
	{
		printf("%dx^%d",q->coef,q->pow);
		q=q->next;
	}
	else{
	while(q!=NULL)
	{
		if(q->coef>0)
			printf("+%dx^%d",q->coef,q->pow);
		else
			printf("%dx^%d",q->coef,q->pow);
		q=q->next;
	}
	printf("\r ");
}
}
void main()
{
	Poly *head=NULL;
	create(&head);
	printf("The polynomial is:\n");
	display(head);
}
