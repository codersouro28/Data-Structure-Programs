#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
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

void insertAtBeginning(Node **head, int data)
{
	Node *ptr;
	ptr=(Node*)malloc(sizeof(Node));
	
	ptr->data=data;
	
	if(*head==NULL){
		*head=ptr;
		ptr->next=NULL;
	}
	
	else{
		ptr->next=*head;
		*head=ptr;		
	}
}

void insertAtEnd(Node **head, int data){
	Node *ptr,*p;
	ptr=(Node*)malloc(sizeof(Node));
	ptr->data=data;
	if(*head==NULL){
	 *head=ptr;
	 ptr->next=NULL;
	 }
	else
	{
	 p=*head;
	while(p->next != NULL)
	{
		p=p->next;
	}
	
	p->next=ptr;
	ptr->next=NULL;
}
}

void insertAtAnyPosition(Node **head, int data, int pos)
{
	Node *ptr, *q, *r;
	int i=1;
	
	ptr=(Node*)malloc(sizeof(Node));
	q=*head;
	r=q->next;
	ptr->data=data;
	if(pos==1)
	{
		*head=ptr;
		ptr->next=q;
	}
	else{
		while(i!=pos-1 && q!=NULL)
		{
			i++;
			q=q->next;
			r=r->next;
		}
		
	if(q==NULL)
		printf("Invalid position\n");
	else{
		ptr->next=r;
		q->next=ptr;
	}
	
	}
}

void insertAfter(Node **head, int n, int ele){
	Node *ptr, *p, *q;
	ptr=(Node*)malloc(sizeof(Node));
	ptr->data=n;
	ptr->next=NULL;
		
	p=*head;	
	q=p->next;
	
	while(p->data!=ele && p!=NULL){
		p=p->next;
		q=q->next;
	}
	if(p==NULL)
		printf("Invalid Position\n");
	else{
	
	if(p->data==ele){
		ptr->next=q;
		p->next=ptr;
	}
 }
}

void deleteFirstNode(Node **p)
{
    Node *r;
    if (*p == NULL)
    {
        puts("Null list");
    }
    else
    {
        r = *p;
        *p = r->next;
        free(r);
    }
}

void deleteLastNode(Node **p)
{
	node *r=*p;
	if(*p==NULL)
	{
		puts("Null list!deletion not possible!");
	}	
	else
	{
		if(r->next==NULL)
		{
			*p=NULL;
			free(r);
		}
		else
		{
			while(r->next->next!=NULL)
			{
				r=r->next;
			}
			free(r->next);
			r->next=NULL;
		}
	}
}

void deleteAnyNode(Node **p,int n)
{
	Node *r=*p,*prev;
	if(*p==NULL)
	{
		puts("Null list!deletion not possible!");
	}	
	else
	{
		if(r->data==n)
		{
			*p=r->next;
			free(r);
		}
		else
		{
			while(r!=NULL)
			{
				if(r->data==n)
					break;
				prev=r;
				r=r->next;	
			}
			if(r==NULL)
			{
				printf("Node not found\n");
			}
			else
			{
				prev->next=r->next;
				free(r);
			}
		}
	}
}
void deleteNodeAtPosition(Node **head, int pos)
{
	Node *q, *r;
	q=*head;
	r=q->next;
	int i=1;
	if(*head==NULL)
	{
		puts("Null list!deletion not possible!");
	}	
	
	else if(pos==1)
		{
			*head=q->next;
			free(q);
		}
		
		else
		{
			while(i!=pos-1 && q!=NULL)
			{
				q=q->next;
				r=r->next;
				i++;	
			}
			
			if(q==NULL)
			{
				printf("Invalid Position");
			}
			else
			{
				q->next=r->next;
				free(r);
			}
		}
	}



int main(){
	int n,num,pos,ele,nd,i;
    Node *head;
	head=NULL;	
	

	while(1){
	system("cls");
	printf("ENTER 1 TO -> CREATE LIST\n"
	       "ENTER 2 TO -> TRAVERSE AND DISPLAY LIST\n"
		   "ENTER 3 TO -> PERFORM INSERTION AT BEGINNING\n"
		   "ENTER 4 TO -> PERFORM INSERTION AT END\n"
		   "ENTER 5 TO -> PERFORM INSERTION AT ANY POSITION\n"
		   "ENTER 6 TO -> PERFORM INSERTION AFTER A SPECIFIC NODE\n"
		   "ENTER 7 TO -> PERFORM DELETION AT BEGINNING\n"
		   "ENTER 8 TO -> PERFORM DELETION AT END\n"
		   "ENTER 9 TO -> PERFORM DELETION OF A SPECIFIC NODE WITH DATA\n"
		   "ENTER 10 TO -> PERFORM DELETION OF A SPECIFIC NODE WITH A POSITION\n"
		   "ENTER 0 TO EXIT\n");
		   
	printf("ENTER YOUR CHOICE: ");
	scanf("%d",&n);
	
	switch(n){
		case 1:
			createList(&head);
			break;
		case 2:
			linkedListTrav(head);
			break;
		case 3:
			printf("Enter the number you want to enter:");
			scanf("%d",&num);
			insertAtBeginning(&head,num);
			break;
		case 4:
			printf("Enter the number you want to enter:");
			scanf("%d",&num);
			insertAtEnd(&head,num);
			break;
		case 5:
			printf("Enter the position:");
			scanf("%d",&pos);
			printf("Enter the number you want to enter:");
			scanf("%d",&num);
			insertAtAnyPosition(&head,num,pos);
			break;
		case 6:
			printf("Enter the data after which you want to insert a new node:");
			scanf("%d",&ele);
			printf("Enter the number you want to enter:");
			scanf("%d",&num);
			insertAfter(&head,num,ele);
			break;
		case 7:
			deleteFirstNode(&head);
			break;
		case 8:
			deleteLastNode(&head);
			break;
		case 9:
			printf("Enter the Data of the Node you want to delete:");
			scanf("%d",&ele);
			deleteAnyNode(&head,ele);	
			break;		
		case 10:
			printf("Enter the Index of the Node you want to delete:");
			scanf("%d",&pos);
			deleteNodeAtPosition(&head,pos);	
			break;
		case 0:
		printf("STOPPING LINKED LIST UPDATION.");
		exit(0);	
		default:
			printf("WRONG CHOICE!!!TRY AGAIN.");
		
	}
	getch();	   
}
}
