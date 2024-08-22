#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct stack{
	int data;
	struct stack *next;
}stack; 



int isEmpty(stack *top)
{
	return (top==NULL);
}

void push(stack **top,int n)
{
	stack *new=(stack*)malloc(sizeof(stack));
	new->data=n;
	new->next=*top;
	*top=new;
}

int pop(stack **top)
{
	int temp;
	stack *q;
	temp=(*top)->data;
	q=*top;
	*top=q->next;
	free(q);
	return (temp);
}

int peek(stack *top)
{
	return (top->data);
}


void display(stack *s)
{
	while(s!=NULL)
	{
		printf(" |____%d____|\n"
			   ,s->data);
			   s=s->next;
	}
}

void main()
{

int ch,data,popped,topdata;
	stack *top=NULL;
	
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
					printf("Enter the data:");
					scanf("%d",&data);
					push(&top,data);
				break;
			case 2:
				if(isEmpty(top))
					printf("Stack Underflow");
				else
				{
					popped=pop(&top);
					printf("Popped data is:%d\n",popped);
				}
				break;
			case 3:
				topdata=peek(top);
				printf("Top element is:%d\n",topdata);
				break;
			case 4:
				display(top);
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
