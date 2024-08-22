#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct stack{
	int top;
	int capacity;
	int *arr;
}stack; 

stack *createStack(int capacity)
{
	stack *s=(stack*)malloc(sizeof(stack));
	s->capacity=capacity;
	s->top=-1;
	s->arr=(int*)malloc(capacity*sizeof(int));
	return s;
}

int isEmpty(stack *s)
{
	return (s->top==-1);
}

int isFull(stack *s)
{
	return (s->top==s->top-1);
}

void push(stack **s,int n)
{
	(*s)->arr[++(*s)->top]=n;
}

int pop(stack **s)
{
	return ((*s)->arr[(*s)->top--]);
	
}

int peek(stack *s)
{
	return (s->arr[s->top]);
}

void display(stack *s)
{
	int i=0;
	
	for(i=s->top;i>=0;i--)
	{
		printf(" |    %d     |\n"
				" |__________|\n"
			   ,s->arr[i]);
	}
}
void main()
{
	int n,ch,data,popped,topdata;
	printf("ENTER THE CAPACITY OF THE STACK:");
	scanf("%d",&n);
	stack *s=createStack(n);
	
	while(1){
		system("cls");
		printf(" ENTER 1 TO   ------->  PUSH\n"
				" ENTER 2 TO   ------->  POP\n"
				" ENTER 3 TO   ------->  PEEK\n"
				" ENTER 4 TO   ------->  DISPLAY STACK\n"
				" ENTER 0 TO   ------->  EXIT\n");
		printf("ENTER YOUR CHOICE:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				if(isFull(s))
					printf("Stack Overflow");
				else
				{
					printf("Enter the data:");
					scanf("%d",&data);
					push(&s,data);
				}
				break;
			case 2:
				if(isEmpty(s))
					printf("Stack Underflow");
				else
				{
					popped=pop(&s);
					printf("Popped data is:%d\n",popped);
				}
				break;
			case 3:
				topdata=peek(s);
				printf("Top element is:%d\n",topdata);
				break;
			case 4:
				display(s);
				break;
			case 0:
				printf("STOPPING STACK OPERATION------");
				exit(0);
			default:
				printf("WRONG CHOICE");
		}
		printf("\n\n\nPRESS A KEY TO CONTINUE STACK OPERATION");
		getch();
	}
}
