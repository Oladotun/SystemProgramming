// Oladotun Opasina
// Show Family three

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	char lname[30];
	char fname[30];
	char relation[30];

	struct Node *child1, *child2, *child3, *child4,*mar;
};

void main()
{
	struct Node *temp, *root, *root1,*root2;

	temp = malloc(sizeof(struct Node));

	strcpy(temp->relation,"GreatGrandMother");
	strcpy(temp->fname, "Ade");
	strcpy(temp->lname, "doyin");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;
	temp->mar=NULL;
	root=temp;

	// GrandMother

	temp = malloc(sizeof(struct Node));

	strcpy(temp->relation,"GrandMother");
	strcpy(temp->fname, "Esther");
	strcpy(temp->lname, "Olatunde");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;
	temp->mar=NULL;

	root->child2 = temp;

	// Mother, first child of grandmother

	temp = malloc(sizeof(struct Node));

	strcpy(temp->relation,"Mother");
	strcpy(temp->fname, "Olusola");
	strcpy(temp->lname, "Opasina");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;
	temp->mar=NULL;
	root->child2->child1 = temp;

	printf("%s\n", root->child2->child1->relation );
	printf("%s\n", root->child2->child1->fname );
	printf("%s\n", root->child2->child1->lname );


	temp = malloc(sizeof(struct Node));

	strcpy(temp->relation,"GrandFather");
	strcpy(temp->fname, "Bov");
	strcpy(temp->lname, "Mcguire");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;
	temp->mar=NULL;

	root1= temp;
	root->child2->mar = root1;
	root1->mar=root->child2;
	printf("\nAnother path\n");
	printf("%s\n",root1->mar->child1->relation );
	printf("%s\n",root1->mar->child1->fname);
	printf("%s\n",root1->mar->child1->lname );



	temp = malloc(sizeof(struct Node));

	strcpy(temp->relation,"Father");
	strcpy(temp->fname, "Emiola");
	strcpy(temp->lname, "Opasina");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;
	temp->mar=NULL;

	root2= temp;
	root->child2->child1->mar = root2;
	root2->mar=root->child2->child1;
	printf("\nAnother path\n");
	printf("%s\n",root1->mar->child1->relation );
	printf("%s\n",root1->mar->child1->fname);
	printf("%s\n",root1->mar->child1->lname );

	//Myself

	temp = malloc(sizeof(struct Node));

	strcpy(temp->relation,"Son");
	strcpy(temp->fname, "Dotun");
	strcpy(temp->lname, "Opasina");
	temp->child1=NULL;
	temp->child2=NULL;
	temp->child3=NULL;
	temp->child4=NULL;
	temp->mar=NULL;

	root->child2->child1->child2 = temp;
	printf("\nMyself\n_____________________\n");
	printf("%s\n", root->child2->child1->child2->relation );
	printf("%s\n", root->child2->child1->child2->fname );
	printf("%s\n", root->child2->child1->child2->lname );

	root1->mar->child1->child2 = temp;

	printf("\nAnother path\n");
	printf("%s\n", root1->mar->child1->child2->relation );
	printf("%s\n", root1->mar->child1->child2->fname );
	printf("%s\n", root1->mar->child1->child2->lname );


	root2->mar->child2 = temp;

	printf("\nAnother path\n");
	printf("%s\n", root2->mar->child2->relation );
	printf("%s\n", root2->mar->child2->fname );
	printf("%s\n", root2->mar->child2->lname );


}