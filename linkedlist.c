#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *prev, *next;
};

void main(){

	struct Node *head, *temp;

	temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = 5;
	temp->next = NULL;
	temp->prev = NULL;
	head = temp;

	temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = 1;
	temp->next = NULL;
	temp->prev = NULL;
	

	// connecting the first and second node
	head->next = temp;
	temp->prev = head;

	// creating the third node with 3;


	temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = 3;
	temp->next = NULL;
	temp->prev = NULL;
	
	head->next->next = temp;
	temp->prev = head->next;

	// creating the fourth node with 2;


	temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = 2;
	temp->next = NULL;
	temp->prev = NULL;
	
	head->next->next->next = temp;
	temp->prev = head->next->next;

	for (temp= head; temp!=NULL; temp=temp->next)
		printf("%d\n", temp->data );

}