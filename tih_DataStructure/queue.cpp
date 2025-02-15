#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct Queue{
	int size;
	int r;
	int f;
	int *arr;
}queue;

int isEmpty(queue *q){
	if(q->r==q->f)
		return 1;
	else
		return 0;
		
}

int isFull(queue *q){
	if(q->r==q->size-1)
		return 1;
	else
		return 0;
}

void enqueue(queue *q, int val)
{
	if(isFull(q))
		printf("Queue Overflow\n");
	else{
		q->r++ ;
		q->arr[q->r]=val ;
		printf("Enqued element: %d\n", val);
	}
}

int dequeue(queue* q){
	int a=-1;
	if(isEmpty(q))
		printf("Queue Underflow\n");
	else{
		q->f++;
		a=q->arr[q->f];
	}
	return a;
}


int main(){
	queue q;
	q.f=q.r=0;
	int n;
	printf("Enter the size of the Queue: ");
	scanf("%d", &q.size);
	
	q.arr=(int*)malloc(q.size*sizeof(int));
	
	while(1){
		system("cls");
		printf("ENTER 1 TO ENQUEUE\n"
		      "ENTER 2 TO DEQUEUE\n"
			  "ENTER 0 TO EXIT	\n");
		printf("ENTER YOUR CHOICE:");
		scanf("%d",&n);
		
		switch(n){
			case 1:
				int nu;
				printf("\nEnter the element you want to Enqueue:");
				scanf("%d",&nu);
				enqueue(&q,nu);
				break;
			
			case 2:
				printf("\nDequeuing: %d\n", dequeue(&q));
				break;
				
			case 0:
				printf("EXITING QUEUE...\n");
				break;
			default:
				printf("WRONG CHOICE!TRY AGAIN\n");
			
		}
		getch();
	}
}
