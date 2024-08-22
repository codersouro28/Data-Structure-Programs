#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct stack{
	char ele;
	struct stack *next;
}stack;


int isEmpty(stack *top)
{
	return (top==NULL);
}

void push(stack **top,char ele)
{
	stack *new=(stack*)malloc(sizeof(stack));
	new->ele=ele;
	new->next=*top;
	*top=new;
}


char pop(stack **top)
{
	char temp;
	stack *p;
	temp=(*top)->ele;
	p=*top;
	*top=p->next;
	free(p);
	return temp;
}


int stackTop(stack *top)
{
	return (top->ele);
}


int precedence(char ch){
    if(ch == '*' || ch=='/' ||ch == '%')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}

int isOperator(char ch)
{
	return(ch == '+'||ch == '-'||ch == '*'||ch == '/'||ch=='%');
}

void print(stack *p){
	while(p!=NULL){
		printf("|____%c____|\n", p->ele);
		p=p->next;
	}
}

char* infixToPostfix(char* infix){
	stack *top=NULL;
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));  //target string
    char x;
    int i=0;      // Track infix traversal
    int j = 0;    // Track postfix addition 
    int k;        //Print target String
    for(i=0;infix[i]!='\0';i++)
    {
        printf("Read Character: %c\n", infix[i]);
        if(infix[i]=='(')
        	push(&top, infix[i]);
		else if(isalnum(infix[i]))
            postfix[j++] = infix[i];        
		else if(infix[i]==')')
        {
        	while((x=pop(&top))!= '('){
        		printf("Popped:%c\n",x);
        		postfix[j++] = x;
		   }
	    }
    	else if(isOperator(infix[i])){
            while(!isEmpty(top) && stackTop(top)!='(' && precedence(stackTop(top)) >= precedence(infix[i]))
            {	x=pop(&top);
            	printf("Popped:%c\n",x);
                postfix[j++]=x;
            }
            push(&top,infix[i]);
        	}
        	
			
		printf("Target String: ");
		for(k = 0; k<j; k++){
			printf("%c", postfix[k]);
		}
			
		printf("\nStack: \n");
		print(top);
		printf("\n\n");
			//PRINTING //
	}
    while (!isEmpty(top))    
    {
    	x=pop(&top);
    	printf("Popped:%c\n",x);
        postfix[j] =x;
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int postfixEvaluation(char postfix[])
{
	stack *top=NULL;
	int x;
	int y;
	int z;
	int j=0;
	
	while(postfix[j])
	{
		printf("Scanned character:%c\n",postfix[j]);
		if(isalnum(postfix[j]))
			push(&top,postfix[j]);
		else{
			printf("Performing operation: %c %c %c\n",stackTop(top->next),postfix[j],stackTop(top));
			y=pop(&top)-'0';
			x=pop(&top)-'0';
			
			switch(postfix[j])
			{
				case '+':z=x+y;
						break;
				case '-':z=x-y;
						break;	
				case '*':z=x*y;
						break;
				case '/':z=x/y;
						break;
			}
			push(&top,z+'0');
		}
		j++;
		printf("Stack:--\n");
		print(top);
	}
	
	z=pop(&top)-'0';
	return z;
}

void main(){
	stack *top=NULL;
	char infix[100];
	char *postfix;
	printf("Enter a infix expression");
	fflush(stdin);
	gets(infix);
    postfix=infixToPostfix(infix);
    printf("REQUIRED EXPRESSION:\n");
    puts(postfix);
    printf("EVALUATING THE ABOVE EXPRESSION:\n");
    printf("Evaluated result:%d",postfixEvaluation(postfix));
}



