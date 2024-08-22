#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct stack{
	char para;
	struct stack *next;
}stack; 


int isEmpty(stack *top)
{
	return (top==NULL);
}

void push(stack **top,char ch)
{
	stack *new=(stack*)malloc(sizeof(stack));
	new->para=ch;
	new->next=*top;
	*top=new;
}

char pop(stack **top)
{
	char temp;
	stack *q;
	temp=(*top)->para;
	q=*top;
	*top=q->next;
	free(q);
	return (temp);
}

char peek(stack *top)
{
	return (top->para);
}

char match(char ch)
{
	switch(ch)
	{
		case ')':return '(';
		case '}':return '{';
		case ']':return '[';
		}
	}


int checkmatch(char exp[])
{
	stack *top=NULL;
	int i,flag=1;
	char ch;
	char par;
	for(i=0;exp[i]!='\0';i++)
	{
		ch=exp[i];	
		if(ch=='('||ch=='{'||ch=='[')
			push(&top,ch);
		else if(ch==')'||ch=='}'||ch==']')
		{
			if(isEmpty(top))
				return 0;
			if(match(ch)==peek(top))
				pop(&top);
			else
				return 0;
		}
	}
		
	return (isEmpty(top));
		
		
}

void main()
{
	char ex[100];
	int s=100,i;
	stack *top=NULL;
	
	printf("Enter the expression:");
	fflush(stdin);
/*	for(i=0;i<s;i++)
	{
		scanf("%c",&ex[i]);
		ex[i+1]='\0';
		if(ex[i]=='\n')
			break;
	}*/
	
	gets(ex);
	
	fflush(stdin);
	printf("Expression is:");
	/*for(i=0;ex[i]!='\0';i++)
	{
		printf("%c",ex[i]);
	}*/
	puts(ex);
	if(checkmatch(ex))
		printf("PARANTHESIS BALANCED");
	else
		printf("PARANTHESIS UNBALANCED");	
}

/*
UNBALANCED-[[4-6]((8){(9-8])}})
BALANCED-((8){(9-8)})*/
