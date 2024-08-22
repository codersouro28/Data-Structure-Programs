#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 5


typedef struct Queue{
	int front,rear;
	int arr[size];
}queue;

int isEmpty(queue q)
{
	return(q.front== -1 && q.rear== -1);
		
}

int isFull(queue q)
{
	return (q.front== 0 && q.rear== size-1 || q.front==q.rear+1);

}

void enqueue(queue *q,int val)
{
	int i,j=0;
	if(q->rear == -1)                   //if queue is empty
		q->front=q->rear=0;
	else if(q->rear == size-1){        //if rear is at end but queue is not full
		q->rear=0;
	}
	else
		q->rear++;                     //incrementing rear by 1
		
	q->arr[q->rear]=val;		        //insertion at rear
	printf("Enqueued element:%d\n",val);
}

int dequeue(queue *q)
{
	int temp=q->arr[q->front];
	if(q->front==q->rear)             //only one element in queue
		q->front=q->rear=-1;
	else if(q->front == size-1)
		q->front=0;
	else
		q->front++;
	return temp;	
}


void display(queue q)
{
	int i=0;
	if(q.front<q.rear)
	{
	for(i=q.front;i<=q.rear;i++)
		printf("%d ",q.arr[i]);
	printf("\n");
	}
	else
	{
		for(i=q.front;i<=size-1;i++)
			printf("%d ",q.arr[i]);
		for(i=0;i<=q.rear;i++)
			printf("%d ",q.arr[i]);
		printf("\n");
	}
	
}

void main()
{
	queue q;
	q.front=-1;
	q.rear=-1;
	q.arr[size];
	

	int n,ch,val;
	
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
					if(isFull(q))
						printf("Queue Overflow");
					else
					{
						printf("Enter the value you want to Enqueue");
						scanf("%d",&val);
						enqueue(&q,val);
						}	
					break;
			case 2:
					if(isEmpty(q))
						printf("Queue Underflow");
					else
					{
						n=dequeue(&q);
						printf("Dequeued:%d",n);
					}
					break;
			case 3:
					display(q);
					break;
			default:
					printf("Wrong Choice");
				
		}
		getch();
		
	}
	
	
}
