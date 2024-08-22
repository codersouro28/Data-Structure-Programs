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
		while(r->next)
		{
			r=r->next;
		}
		r->next=q;
	}	
}

void create(Poly **head)
{	
	int pow,coef;
	char ch='Y';
	/*printf("Enter Y to start:");
	fflush(stdin);
	scanf("%c",&ch);*/
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

void addPoly(Poly *a, Poly *b, Poly **c)
{
	while(a!=NULL && b!=NULL)
	{
		if(a->pow > b->pow)
		{
			insertAtEnd(c,a->pow,a->coef);
			a=a->next;
		}
		else if(a->pow < b->pow)
		{
			insertAtEnd(c,b->pow,b->coef);
			b=b->next;
		}
		else
		{
			insertAtEnd(c,a->pow,a->coef+b->coef);
			a=a->next;
			b=b->next;
			}	
	}
	while(a!=NULL)
	{
		insertAtEnd(c,a->pow,a->coef);
		a=a->next;	
	}
	while(b!=NULL)
	{
		insertAtEnd(c,b->pow,b->coef);
		b=b->next;	
	}
}

void main()
{
	Poly *x,*y,*z;
	x=y=z=NULL;
	printf("Enter the first polynomial:");
	create(&x);
	printf("Enter the second polynomial:");
	create(&y);
	
	display(x);
	printf("\n");
	printf("+  ");
	display(y);
	printf("\n");
	printf("---------------------------------------------------\n");
	addPoly(x,y,&z);
	display(z);
	
}
