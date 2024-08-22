#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
	int data;
	struct node *next;
}Node;



void createList(Node **p)
{
	Node*ptr;
	char ch;
	ptr=(Node*)malloc(sizeof(Node));
	
	if(*p==NULL)
		*p=ptr;
	
	while(1){
		printf("Enter Data: \n");
		scanf("%d",&ptr->data);
		printf("Continue?(Y/A): ");
		fflush(stdin);
		scanf("%c",&ch);
		if(toupper(ch)=='Y')
		{
			ptr->next=(Node*)malloc(sizeof(Node));
		}
		else{
			ptr->next=NULL;
			break;
		}
		ptr=ptr->next;
	}
 }
 
 void linkedListTrav(Node *ptr)
{
	printf("-------DATA------\n");
	while(ptr!=NULL)
	{
		printf("%d-> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL");
	printf("\n");
}




void insertAtEnd(Node **head,int data)
{
	Node *p,*ptr;
	p=*head;
	ptr=(Node*)malloc(sizeof(Node));
	ptr->data=data;
	ptr->next=NULL;
	
	if(*head==NULL)
		*head=ptr;
		
	
	else{
		while(p->next)
		{
			p=p->next;
		}
		p->next= ptr;
	}
	
		
}

void evenList(Node *head,Node **even,Node **odd)
{
	for(;head;head=head->next){
	if(!(head->data%2))
		insertAtEnd(even, head->data);
	else
		insertAtEnd(odd, head->data);
}	
}



/*void oddList(Node *head,Node **odd)
{
	for(;head;head=head->next){
	if(head->data%2)
		insertAtEnd(odd, head->data);
}	
}*/


int main(){
	Node *head,*even,*odd;
	
	head=even=odd=NULL;
		
	printf("Create List: \n");
	createList(&head);
	
	printf("Displaying full List: \n");
	linkedListTrav(head);
   
    evenList(head,&even,&odd);	
    printf("Nodes with Even data: \n");
    linkedListTrav(even);

   	
    printf("Nodes with Odd data: \n");
    linkedListTrav(odd);

}

