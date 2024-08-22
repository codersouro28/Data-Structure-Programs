#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

	
void cLinkedListTraversal(Node *p){
    Node *ptr;
	ptr=p;
	
	if(p==NULL){
	printf("Null list!");
	return ;
   }
    do{
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }while(ptr!=p);
    //printf("%d",p->data);
    printf("\n");
}

void insertBegC(Node **p,int n){
	
	Node *r,*q;
	q=(Node*)malloc(sizeof(Node));
	q->data=n;
		
	if(*p == NULL)
		q->next=q;
	else{
		r=*p;
		while(r->next!=*p){                
			r=r->next;
		}		
		q->next=*p;
		r->next=q;
	}
	*p=q;
}

void insertLastC(Node **p,int n)
{
	Node *q,*r;
	q=(Node*)malloc(sizeof(malloc));
	q->data=n;
	
	if(*p==NULL)
	{
		*p=q;
		q->next=q;
	}
	else{
		r=*p;
		while(r->next != *p){
			r=r->next;
		}
		r->next=q;
		q->next=*p;
	}
}


void insertAtPositionC(Node **p, int n, int pos){
	int i=1;
	Node*q,*r;
	q=(Node*)malloc(sizeof(Node));
	q->data=n;
	
	if(pos==1){
		if(*p == NULL)
		{
			q=q->next;
			*p=q;
		}
		else{
	
		q->next=*p;
		r=*p;
		while(r->next!=*p){                
		r=r->next;
		}		
		r->next=q;
		*p=q;
	}
   }
	else
	{
		r=*p;
		while(i!=pos-1 && r->next != *p){
			i++;
			r=r->next;
		}
		if(r->next == *p)
		{
			if(pos==(i+1)){
			r->next=q;
			q->next=*p;
			}
			else
				printf("Invalid Position");
		}
		else
		{
			q->next=r->next;
			r->next=q;
		}
		
	}
}

void deleteFirstC(Node **p){
	Node*q,*r,*t;
	q=*p;
	
	
	if(*p == NULL){
		printf("Empty List!Deletion Not Possible");
	return;
}
	t=q->next;
	 if(q->next == q){
		free(q);
		*p=NULL;
		}
	else
	{
		while(q->next != *p)
		{
			q=q->next;
			}
		q->next=(*p)->next;
		free(*p);
		*p=t;	
			
	}	
	}
void deleteLastC(Node **p){
	Node*q,*r;
	q=*p;
	
	if(*p == NULL)
		printf("Empty List!Deletion Not Possible");
	
	else if(q->next == q){
		free(q);
		*p=NULL;
		}
	else{
		while(q->next->next != *p){
			q=q->next;
		}
		free(q->next);
		q->next=*p;
	}
}

void deleteNodeAtPosition(Node **p, int pos)
{
	int i=1;
	Node *r,*t;
	r=*p;
	
	if(*p==NULL){
	printf("Null list!DEletion not possible");
	return ;
   }
	t=r->next;
	
	if(pos==1)
	{
		*p=r->next;
		free(r);
	}
	else
	{
		while(i!=(pos-1) && r->next != *p)
		{
			i++;
			r=r->next;
			t=t->next;
		}
		if(r->next == *p)
			printf("Position does not exist.");
		else
		{
			r->next=t->next;
			free(t);
		}
	}
 } 
  
void main()
{
	int num,ch,pos;
	Node *head;
	head=NULL;
	
	
	while(1)
	{
		system("cls");
		printf("ENTER 1 TO -> DISPLAY LIST\n"
		        "ENTER 2 TO -> INSERT AT FIRST\n" 
				"ENTER 3 TO -> INSERT AT LAST\n"
				"ENTER 4 TO -> INSERT AT A GIVEN POSITION 'n'\n"
				"ENTER 5 TO -> DELETE FIRST NODE\n"
				"ENTER 6 TO -> DELETE LAST NODE\n"
				"ENTER 7 TO -> DELETE AT A GIVEN POSITION 'n'\n"
				"ENTER 0 TO -> EXIT\n");
		printf("ENTER YOUR CHOICE:");
		scanf("%d",&ch);
		printf("\n");
		switch(ch){
			
			case 1:
				cLinkedListTraversal(head);
				break;
			case 2:
				printf("Enter the number you want to insert:");
				scanf("%d",&num);
				insertBegC(&head,num);
				break;
			case 3:
				printf("Enter the number you want to insert:");
				scanf("%d",&num);
				insertLastC(&head,num);	
				break;
			case 4:
				printf("Enter the number you want to insert:");
				scanf("%d",&num);
				printf("Enter the positin you want to perform insertion: ");
				scanf("%d",&pos);
				insertAtPositionC(&head,num,pos);	
				break;
			case 5:
				deleteFirstC(&head);
				break;
			case 6:
				deleteLastC(&head);
				break;
			case 7:
				printf("Enter the position you want to perform deletion:");
				scanf("%d",&pos);
				deleteNodeAtPosition(&head,pos);
				break;
			case 0:
				printf("EXITING THE PROGRAM...");
				exit(0);
			default:
			printf("WRONG INPUT!!TRY AGAIN");
		}
		getch();	
		
	}
  }  
  
  
  
  
  
  
  
  
  
  //head-1000 
  // 10|1004 -> 16|2000 -> 19|2004 ->  21|1000
   //   1000     1004       2000        2004 
   
  // Inserting-25
  //head-5000
   // 25|1000  -> 10|1004 -> 16|2000 -> 19|2004 ->  21|5000
   //   5000       1000        1004       2000        2004     
