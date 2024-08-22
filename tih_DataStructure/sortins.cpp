#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
	int data;
	struct node *next;
}Node;


void createList(Node **p)
{
	Node*ptr;
	char ch;
	ptr=(Node*)malloc(sizeof(Node));
	
	if(*p==NULL)
		*p=ptr;
	
	while(1){
		printf("Enter Data: \n");
		scanf("%d",&ptr->data);
		printf("Continue?(Y/A): ");
		fflush(stdin);
		scanf("%c",&ch);
		if(toupper(ch)=='Y')
		{
			ptr->next=(Node*)malloc(sizeof(Node));
		}
		else{
			ptr->next=NULL;
			break;
		}
		ptr=ptr->next;
	}
 }


void sortList(Node* *head) {   
        struct node *cur = *head, *ptr;  
        int temp;  
          
        if(cur == NULL) {  
            return;  
        }  
        else {  
            while(cur != NULL) {    
                ptr = cur->next;  
                  
                while(ptr != NULL) {  
                    
                    if(cur->data > ptr->data) {  
                        temp = cur->data;  
                        cur->data = ptr->data;  
                        ptr->data = temp;  
                    }  
                    ptr = ptr->next;  
                }  
                cur = cur->next;  
            }      
        }  
    }  
    
    
void linkedListTrav(Node *ptr)
{
	printf("-------DATA------\n");
	while(ptr!=NULL)
	{
		printf("%d-> ",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL");
	printf("\n");
}


void sortedInsert(Node **head, int val){
        Node* ptr,*pre, *curr;
        ptr=(Node*)malloc(sizeof(Node));
        ptr->data=val;
        pre = NULL;
        curr = *head;
        while(curr!=NULL && val>curr->data){
            pre = curr;
            curr = curr->next;
        }
        ptr->next = curr;
        if(pre==NULL){
            *head = ptr;
        }else{
            pre->next = ptr;
        }
    }

int main(){
	Node *head;
	int n;
	head=NULL;
	
	printf("Create a linked list: \n");
	createList(&head);
	
	printf("Displaying a linked List before Sorting: \n");
	linkedListTrav(head);
	
	sortList(&head);
	printf("Displaying a linked List before Sorting: \n");
	linkedListTrav(head);
	
	printf("Insert a Node in Sorted List: \n");
	printf("Enter Data: \n");
	scanf("%d",&n);
	sortedInsert(&head,n);
	
	printf("New List: ");
	linkedListTrav(head);
	
}
