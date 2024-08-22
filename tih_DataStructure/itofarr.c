#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


typedef struct stack{
	int top;
	int size;
	char *arr;
}stack; 

int isEmpty(stack *s)
{
	return (s->top==-1);
}


void push(stack *s,char n)
{
	s->arr[++(s)->top]=n;
}

char pop(stack *s)
{
	return (s->arr[s->top--]);
	
}

char stackTop(stack *s)
{
	return (s->arr[s->top]);
}


int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}


char* infixToPostfix(char* infix){
	struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10; 
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));  //target string
    char x;
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0')
    {
        if(isalnum(infix[i]))
            postfix[j++] = infix[i++];
        else if(infix[i]=='(')
        	push(sp, infix[i++]);
        else if(infix[i]==')')
        {
        	while((x=pop(sp))!= '(')
        		postfix[j++] = x;
        	i++;
		}
    	else{
            while(precedence(stackTop(sp)) >= precedence(infix[i]))
                postfix[j++]=pop(sp);
            push(sp,infix[i++]);
        	}
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
}

int main()
{
    char * infix = "x-y/z-k*d";
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}
