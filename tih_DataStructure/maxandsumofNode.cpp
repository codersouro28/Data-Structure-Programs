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

Node *findMax(Node *head){
	Node *p;
	Node *max;
	
	max=head;
	p=max->next;
	
	if(head==NULL)
	{
		printf("Empty linked list\n");
	}
	else if(p==NULL){
		max= p;
	}
	else{
	
	while(p!=NULL){
	if(max->data < p->data){
		max=p;
	}
	p=p->next;
	
   }
	}
	return max;
	
}

int sumOfNodes(Node *head){
	
	Node *p;
	int sum=0;
	
	p=head;
	
	while(p!=NULL){
		sum=sum+(int)p->data;
		p=p->next;
	}
	
	return sum;
}

	int main(){
	Node *head,*max;
	int sum;
	head=NULL;
		
	printf("Create List: \n");
	createList(&head);
	
	printf("Displaying fullList: ");
	linkedListTrav(head);
	
	printf("Node with maximum value: ");
	max=findMax(head);
	printf("%d\n",max->data);
	
	printf("Sum of Nodes: ");
	sum=sumOfNodes(head);
	printf("%d\n",sum);
}

