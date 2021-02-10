/* Describe this program. this program will show a menu for users includeing:  adding a node at the tail, 
adding a node at the head of the link list, deleting a node at the head of the link list,
 deleting a node at the tail of the link list, and deleting at any position in the link list.
 */
#include <stdio.h>
#include <stdlib.h>

//create structure and rename for a node
typedef struct Node{
	int data;
	struct Node* next;
}node;

//create a node
node* createNode(int n){
	node*p= (node*)malloc(sizeof(node));
	p->data=n;
	p->next=NULL;
	return p;
}

//adding node at the head of link list
node* addAtHead(node* head, int n){
	 node* newNode=createNode(n);
	
	if(head==NULL){
		head=newNode;
	
	}
	else{
		newNode->next=head;
		head=newNode;
	}
	return head;
}
//adding nodes at the end of link list
node* addAtEnd(node* head, int x){
	node* newNode=createNode(x);
	node* tail=NULL;
	if(head==NULL){
		head=newNode;
	}
	else{
		tail=head;
	
		while(tail->next!=NULL){

		tail=tail->next;}
	
		tail->next=newNode;

	}
	
	return head;
}
//delete a node at head of link list
node* deleteHead(node* head){
	node* temp;
	if(head==NULL){
		printf("The link list is empty!\n");
	}
	else{
		temp= head;
		head=head->next;
		free(temp);
	}
	return head;
	
}
//delete a node at tail of link list
node* deleteTail(node* head){
	if(head==NULL){
		printf("The list is empty!\n");
	}
	else if(head->next==NULL){
		free(head);
		return NULL;
	}
	else{
	node* temp;
	temp=head;
	while(temp->next->next!=NULL){
		//second last node
		temp=temp->next;
		}
		//delete last node
		free(temp->next);
		temp->next=NULL;
}
	return head;
}
//delete a node at any position
void deleteAnyNode(node** head, int value) 
{ 
   node* temp= *head, *prev;
   if(temp!=NULL && temp->data==value){
   	*head= temp->next;
   	free(temp);
   	return;
   }
   //search the key value
   while(temp!=NULL && temp->data!=value)
{
	prev=temp;
	temp=temp->next;
   }   
   if(temp==NULL){
   	printf("\nThe value is not exist.\n");
   	return NULL;
   }
   prev->next=temp->next;
   free(temp);
}

//display values of link list
void display(node* head){
	node* p=head;
	while(p!=NULL){
		printf("%d ->",p->data);
		p=p->next;
	}
}

int main() {
	node* head=NULL;
	int choice, x;

	
	while(1){
	
		printf("\t=========== Menu ===========");
		printf("\n\t1.Add value for a node at the head of the link list");	
		printf("\n\t2.Add value for a node at the end of the link list.");
		printf("\n\t3.Delete a node at the head of list.");
		printf("\n\t4.Delete a node at the tail of list.");
		printf("\n\t5.Delete a node at any position.");
		printf("\n\t6.Display values of the list.");
		printf("\n\t7.Exit program.");
		printf("\n\tEnter your choice:");
		scanf("%d",&choice);
		if(choice==1){
			printf("\n\tEnter value for a node:\n");
			scanf("%d",&x);
		
		    head=addAtHead(head,x);
		}
		else if(choice==2){
			printf("Enter value for a node:\n");
			scanf("%d",&x);
			head=addAtEnd(head,x);
		}
		else if(choice==3){
			head=deleteHead(head);
		
		}
		else if(choice==4){
			head=deleteTail(head);
		}
		
		else if(choice==5){
			printf("Enter value which you want to delete.\n");
			scanf("%d", &x);
			deleteAnyNode(&head,x);
		}
		else if(choice==6){
		display(head);
		}
		else{
			exit(0);
		}
	
	
		printf("\n\t============ End ==========\n\n");
	}


	return 0;
}
