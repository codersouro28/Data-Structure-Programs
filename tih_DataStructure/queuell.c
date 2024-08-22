#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct Node
{
	int data;
	struct Node *next;
 }node;

typedef struct Queue
{
	node *front;
	node *rear;
 }queue;
 
 int isEmpty(queue q)
 {
 	return (q.rear == NULL);
  } 
 
 
 void enqueue(queue *q, int n)
 {
 	node *newNode;
 	newNode=(node*)malloc(sizeof(node));
 	newNode->data=n;
 	newNode->next=NULL;
 	if(q->rear==NULL)
 		q->front=q->rear=newNode;
 	else{
 		q->rear->next=newNode;
 		q->rear=newNode;
 	}
}

int dequeue(queue *q)
{
	int temp;
	node *n;
	temp=q->front->data;
	n=q->front;
	
	if(q->front == q->rear)
		q->front = q->rear =NULL;
	else
		q->front=q->front->next;
	free(n);
	return temp;
		
}


void main()
{
	queue *q=(queue*)malloc(sizeof(queue));
	q->front=q->rear=NULL;
	
	int ch,val,n;
	while(1)
	{
		system("cls");
		
		printf("ENTER 1 TO ENQUEUE\n"
			   "ENTER 2 TO DEQUEUE\n"
			   "ENTER 3 TO DISPLAY QUEUE\n");
			   
		printf("ENTER YOUR CHOICE:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: 
						printf("Enter the value you want to Enqueue");
						scanf("%d",&val);
						enqueue(q,val);	
					break;
			case 2:
					if(isEmpty(*q))
						printf("Queue Underflow");
					else
					{
						n=dequeue(q);
						printf("Dequeued:%d",n);
					}
					break;
			/*case 3:
					display(q);
					break;*/
			default:
					printf("Wrong Choice");
				
		}
		getch();
		
	}
	
	
}
	
	

