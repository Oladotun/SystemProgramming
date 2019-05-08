/*
************************************************************
|                                                          |
|            Linked List Test program                      |
|                                                          |				
************************************************************
*/


/**
 *
 * @author Oladotun Opasina
 * 
 * The purpose of this program is to create a linked list and run
 * certain functions on them.
 * 04/17/19
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next, *prev;
	
};

void print_fw(struct Node *node);
void print_bw(struct Node *node);
void delete(struct Node **node);
void insert(struct Node *node, int num);
void insertSecond(struct Node *node, int num);
void setupNodes(struct Node **tail,int size);
void deleteFirst(struct Node **node);
void deleteLast(struct Node **last);
void deleteNode(struct Node **node, int num);
void placeSecondLast(struct Node *tail);
void findMidNode(struct Node *head, int num);
int lengthOfList(struct Node *head);

void main()
{
	struct Node *head, *temp, *tail;

	int size,next;
	int numOfNodes = 0;

	size = 6;
	next = rand() % 100 + 1;

	temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = next;
	temp->prev = NULL;
	temp->next = NULL;

	head= temp;
	tail = temp;

	setupNodes(&tail,size);
	print_fw(head);

	// Question 1
	insertSecond(head,100);

	print_fw(head);
	print_bw(tail);

	temp = head->next->next;
	// Question 2
	deleteNode(&temp, temp->data);

	print_fw(head);
	print_bw(tail);

	// Question 3

	deleteFirst(&head);

	print_fw(head);
	print_bw(tail);

	// Question 4 
	deleteLast(&tail);

	print_fw(head);
	print_bw(tail);

	// Question 5
	placeSecondLast(tail);

	//Bonus
	numOfNodes = lengthOfList(head);

	findMidNode(head,numOfNodes);
	printf("Inserting new data\n");

	insertSecond(head,500);
	print_fw(head);

	numOfNodes = lengthOfList(head);

	findMidNode(head,numOfNodes);
	
}

void findMidNode(struct Node *head, int num){
	struct Node *temp;
	int midNumber;
	int count;
	count = 0;

	if(num % 2==0){
		printf("We have even numbers of items in the list\n");
	}else {

		midNumber = num/2;
		temp = head;

		while(count < midNumber ){
			temp= temp->next;
			count = count + 1;
		}

		printf("Middle node data is %d \n", temp->data);

	}
}

int lengthOfList(struct Node *head){
	int count = 0;

	struct Node *temp;

	temp = head;

	while(temp != NULL){
		count = count + 1;
		temp = temp->next;
	}

	printf("Number of nodes is %d \n",count );

	return count;
}


void placeSecondLast(struct Node *tail){
	struct Node *temp;

	temp = tail->prev;

	printf("Second to the Last Data is %d from Top\n", temp->data );
}

void setupNodes(struct Node **tail,int size){
	struct Node *temp;
	struct Node *tailNode;

	tailNode = *tail;
	int next;

	for (int i = 0; i < size-1; i++) {

		next = rand() % 100 + 1;
		

		temp = (struct Node*) malloc(sizeof(struct Node));
		temp->data = next;
		temp->prev = NULL;
		temp->next = NULL;

		(*tail)->next = temp;
		temp->prev = *tail;
		*tail = temp;

	}

}

//Insert in Second Position
void insertSecond(struct Node *above, int num){

	struct Node *temp;
	struct Node *below;

	below = above->next;

	printf("Inserting %d between first and second node\n", num);

	temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = num;
	temp->prev = NULL;
	temp->next = NULL;

	above->next = temp;
	temp->prev = above;

	temp->next = below;
	below->prev = temp;

}

// Insert Number
void insert(struct Node *node, int num){
	struct Node *temp;

	temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = num;
	temp->prev = NULL;
	temp->next = NULL;

	node->next = temp;

}
// Delete First Node
void deleteFirst(struct Node **head){
	struct Node *temp;

	printf("Deleting first Node \n");

	temp = *head;
	*head = NULL;

	*head = temp->next;
	(*head)->prev = NULL;

	free(temp);


}

// Delete Last Node and Free Memory

void deleteLast(struct Node **last){
	struct Node *temp;

	

	temp = *last;
	printf("Deleting %d \n", temp->data);
	temp->prev->next = NULL;
	*last = temp->prev;
	free(temp);


}

// Delete particular node
void deleteNode(struct Node **node, int num){
	struct Node *temp;

	printf("Deleting %d \n",num);

	temp = *node;

	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	free(temp);


}

void delete(struct Node **node){

	struct Node *temp;
	int found = 0;
	int num;

	printf("Enter number to delete \n");
	scanf("%d",&num);

	temp = *node;

	while(temp != NULL && found == 0){
		if(temp->data == num){
			found = 1;
			
		if (temp->prev != NULL){
			
			temp->prev->next = temp->next;
			
		}

		if (temp->next != NULL){
			
			temp->next->prev = temp->prev;
			
		}

		if((*node)->data == num){
			*node = temp->next;

		}
		
		free(temp);	
		}
		

		temp = temp->next;
	}	

}

void print_fw(struct Node *node){
	struct Node *temp;

		printf("Printing forward\n");

		for(temp=node;temp!=NULL; temp = temp->next)
			printf("%d\n", temp->data);
}

void print_bw(struct Node *node){
		struct Node *temp;

		printf("Printing the list backward\n");
		for(temp=node;temp!=NULL; temp = temp->prev)
			printf("%d\n", temp->data);
}