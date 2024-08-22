#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int data;
	struct node *prev,*next;
}dNode; 


void insertAtBeg(dNode **p, int n)
{
	dNode *q;
	q=(dNode*)malloc(sizeof(dNode));
	q->data=n;
	q->next=*p;
	q->prev=NULL;
	if(*p == NULL)
		(*p)->prev=q;
	*p=q;	
}


void insertAtEnd(dNode **p, int n){
	dNode *q,*r,*pr;
	r=*p;
	q=(dNode*)malloc(sizeof(dNode));
	q->data=n;
	q->next=NULL;
	
	if(*p == NULL)
	{
		
		q->prev=NULL;
		*p=q;
	}
	else{
		while(r->next!=NULL){
			r=r->next;
		}
		
		r->next=q;
		q->prev=r;
		
	}
}

void deleteAtBeg(dNode **p){
	dNode *r;
	r=*p;
	
	if(*p == NULL)
	{
		printf("Null list!Deletion not possible");
	}
	else{
		*p=r->next;
		
		if(*p!=NULL)
			(*p)->prev=NULL;
		free(r);		
	}
}

void delLastNode(dNode **p)
{
	dNode *r;
	r=*p;
	
	if(*p == NULL)
	{
		printf("Null list!Deletion not possible");
	}
	else if(r->next==NULL)
	{
		*p=NULL;
		free(r);	
	}
	else{
		while(r->next!=NULL){
			r=r->next;
		}
		r->prev->next=NULL;
		free(r);
		
	}
	
}
void display(dNode *p){
	while(p!=NULL)
	{
		printf("%d->", p->data);
		p=p->next;
	}
	printf("NULL");
	printf("\n");
}

int main(){
	dNode *head;
	head=NULL;
	
	printf("Running inserAtEnd()\n");
	insertAtEnd(&head,5);
	insertAtEnd(&head,8);
	insertAtEnd(&head,10);
	insertAtEnd(&head,21);
	
	display(head);
	
	printf("Running insertAtBeg()\n");
	insertAtBeg(&head,12);
	insertAtBeg(&head,11);
	insertAtBeg(&head,18);
	insertAtBeg(&head,28);
	display(head);
	
	printf("Running deleteAtBeg()\n");
	deleteAtBeg(&head);
	display(head);
	printf("Running deleteLastNode()\n");	
	delLastNode(&head);
	display(head);
	
}
