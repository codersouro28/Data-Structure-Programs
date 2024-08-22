#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 5

typedef struct stack{
	int top;
	int arr[size];
}stack; 

/*stack *createStack()
{
	stack *s=(stack*)malloc(sizeof(stack));
	s->top=-1;
	s->arr[size];
	return s;
}*/

int isEmpty(stack *s)
{
	return (s->top==-1);
}

int isFull(stack *s)
{
	return (s->top==size-1);
}

void push(stack **s,int n)
{
	(*s)->arr[++(*s)->top]=n;
}

int pop(stack **s)
{
	return ((*s)->arr[(*s)->top--]);
	
}

void enqueue(stack **top1,int n)
{
	push(top1,n);
}


int dequeue (stack **top1,stack **top2)
{
	int ele,a,i,s2t;
	while((*top1)->top!=-1)
	{
		ele=pop(top1);
		push(top2,ele);
		}	
		
	s2t=pop(top2);
	
	for(i=0;i<=(*top2)->top;i++)
	{
		a=pop(top2);
		push(top1,a);
	}
	return s2t;
}

void main()
{
	stack *s1,*s2;
 	s1=(stack*)malloc(sizeof(stack));
	s1->top=-1;
	s1->arr[size];
	
	s2=(stack*)malloc(sizeof(stack));
	s2->top=-1;
	s2->arr[size];
	
	
	
	int n,ch,val;
	
	while(1)
	{
		system("cls");
		
		printf("ENTER 1 TO ENQUEUE\n"
			   "ENTER 2 TO DEQUEUE\n");
			   
		printf("ENTER YOUR CHOICE:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: 
					if(isFull(s1))
						printf("Queue Overflow");
					else
					{
						printf("Enter the value you want to Enqueue");
						scanf("%d",&val);
						enqueue(&s1,val);
						}	
					break;
			case 2:
					if(isEmpty(s1))
						printf("Queue Underflow");
					else
					{
						n=dequeue(&s1,&s2);
						printf("Dequeued:%d",n);
					}
					break;
			default:
					printf("Wrong Choice");
				
		}
		getch();
		
	
   }
}
