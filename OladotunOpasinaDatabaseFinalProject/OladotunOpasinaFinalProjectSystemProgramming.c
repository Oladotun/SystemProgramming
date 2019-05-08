/*
************************************************************
|                                                          |
|            Structure and Database Linked List            |
|                                                          |        
************************************************************
*/


/**
 *
 * @author Oladotun Opasina
 * 
 * The purpose of this program is to create a database using linked list and run
 * certain functions on them.
 * 05/08/19
 * 
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 
struct Node

{

  char name[15];

  char title[15];

  int year;

  struct Node *next;

  struct Node *prev;

                            

};

 
typedef struct Node* Box;
Box insert_node(FILE *inputp);
void sort_by_name( Box head, int noNodes);
void sort_by_title( Box head, int noNodes); // Swap by node instead of data 
void sort_by_year( Box head, int noNodes);
int numberOfLines(FILE *fp);
Box search_by_name(Box head,char *input);
Box search_by_title(Box head,char *input);
Box search_by_year(Box head,int year);
void delete_node(Box *head,Box *node);
int input() ;
Box addNode();
void print_fw(Box head);
int numberOfNodes(Box head);
void print_bw(Box tail);
void generateOutputFile(Box head);
char* translate(char *str);

int main()

{

  Box head=NULL,temp,tail,storage;
  int i,year;
  int nodesNo=0;
  int choice, num; 
  FILE *inputp, *outputp;
  char string[] ="Vivaldi";
  char string2[] = "Beethoven";

  
  inputp = fopen("input.txt", "r");
  nodesNo = numberOfLines(inputp);
  inputp = fopen("input.txt", "r");

  head=insert_node(inputp);
  tail = head;

 
  for(int i=0; i < nodesNo - 1; i++)
  {

    temp = insert_node(inputp);
     
    temp->next = head;
    head->prev = temp;
    head=temp;


  }

  printf("Loading Input from File\n");

  printf("Printing Forward\n");
  for (temp = head; temp != NULL; temp=temp->next){

    printf( "%s, %s, %d \n", temp->name, temp->title, temp->year);
  }

  // Menu

  while(choice != -1){

    printf("\nWelcome to Oladotun Opasina CD Store \n "); 
    printf("\nHere are your options below \n\n"); 
    printf("Enter -1 to Quit Program \n"); 
    printf("Press 1 to Add a new CD to the list\n"); 
    printf("Press 2 to Sort list by Name\n"); 
    printf("Press 3 to Sort list by Title\n"); 
    printf("Press 4 to Sort list by Year\n"); 
    printf("Press 5 to Delete list by Name\n"); 
    printf("Press 6 to Delete list by Title\n"); 
    printf("Press 7 to Delete list by Year\n"); 
    printf("Press 8 to Search list by Name\n"); 
    printf("Press 9 to Search list by Title\n"); 
    printf("Press 10 to Search list by Year\n"); 
    printf("Press 11 to Print list Forward\n"); 
    printf("Press 12 to Print list Backward\n"); 
    printf("Press 13 to Store in OutPut file\n"); 
    printf("Enter your choice: "); 
    choice = input(); 



    switch (choice) { 
    case 1: { 
        printf("Adding New Cd\n"); 
        temp = addNode();
        temp->next = head;
        head->prev = temp;
        head=temp;
        printf("New Cd Added\n"); 
        print_fw(head);
        break; 
    } 
    case 2: { 
        printf("Sort List by Name\n"); 
        nodesNo = numberOfNodes(head);
        sort_by_name(head, nodesNo);
        break; 
    } 
    case 3: { 
        printf("Sort List by Title\n"); 
        nodesNo = numberOfNodes(head);
        sort_by_title(head, nodesNo);
        break; 
    } 

    case 4: { 
        printf("Sort List by Year\n"); 
        nodesNo = numberOfNodes(head);
        sort_by_year(head, nodesNo);
        break; 
    } 

    case 5: { 
        printf("Delete List by Name\n"); 
        nodesNo = numberOfNodes(head);
        printf("Enter Name to delete\n");
        scanf("%s",string);
        temp = search_by_name(head,&string);
        delete_node(&head,&temp);
        print_fw(head);
        break; 
    } 

    case 6: { 
        printf("Delete List by Title\n"); 
        nodesNo = numberOfNodes(head);
        printf("Enter Title to delete\n");
        scanf("%s",string);
        temp = search_by_title(head,&string);
        delete_node(&head,&temp);
        print_fw(head);
        break; 
    }

    case 7: { 
        printf("Delete List by Year\n"); 
        nodesNo = numberOfNodes(head);
        printf("Enter Year to delete\n");
        scanf("%d",&year);
        printf("Searching for Year to delete\n");
        temp = search_by_year(head,year);
        printf("Deleting inputs\n");
        delete_node(&head,&temp);
        printf("Printing new list\n");
        print_fw(head);
        break; 
    }  

    case 8: { 
        printf("Search List by Name\n"); 
        nodesNo = numberOfNodes(head);
        printf("Enter Name to search for\n");
        scanf("%s",string);
        temp = search_by_name(head,&string);
        print_fw(temp);
        break; 
    } 

    case 9: { 
        printf("Search List by Title\n"); 
        nodesNo = numberOfNodes(head);
        printf("Enter Title to search for\n");
        scanf("%s",string);
        temp = search_by_title(head,&string);
        print_fw(temp);
        break; 
    } 

    case 10: { 
        printf("Search List by Year\n"); 
        nodesNo = numberOfNodes(head);
        printf("Enter Year to search for\n");
        scanf("%d",&year);
        temp = search_by_year(head,year);
        print_fw(temp);
        break; 
    } 

    case 11: { 
        printf("Print List Forward\n\n"); 
        print_fw(head);
        break; 
    } 
    case 12: { 
        printf("Print List Backward\n\n"); 
        print_bw(tail);
        break; 
    } 
    case 13: {
      printf("Storing List to Output.txt file\n");
      generateOutputFile(head);
      print_fw(head);
      break;
    }

    case -1: {
      printf("Ending Program. Good bye and see you again\n");
      break;
    }


    default: 
        printf("Wrong Input\n"); 
    } 

  }


  return 0;

}


void generateOutputFile(Box head){
  
  Box temp;
  FILE *outputp;
  char *title;

  outputp=fopen("output.txt", "w");

  for (temp = head; temp != NULL; temp=temp->next){

    printf( "%s, %s, %d \n", temp->name, temp->title, temp->year);

    title = translate(temp->title);

    
    fprintf( outputp,"%s, %s, %d \n\n", temp->name, title, temp->year);

    printf("\n");
  }

  fclose(outputp);

}
// Print Backward
void print_bw(Box tail){
  Box temp;
  for (temp = tail; temp != NULL; temp=temp->prev){
    printf( "%s, %s, %d \n", temp->name, temp->title, temp->year);
  }
}

int numberOfNodes(Box head) {
  Box temp;
  int count = 0;
  for (temp = head; temp != NULL; temp=temp->next){
    count = count + 1;
  }

  printf("Total Number of Nodes is %d\n", count );

  return count;
}

int input() 
{ 
    int number; 
    scanf("%d", &number); 
    return (number); 
} 

void print_fw(Box head) {
  Box temp;
  for (temp = head; temp != NULL; temp=temp->next){
    printf( "%s, %s, %d \n", temp->name, temp->title, temp->year);
  }

}


Box addNode(){

  Box temp;
  char name[15];
  char title[15];
  int year;



  temp=(Box)malloc(sizeof(struct Node));
  printf("Enter name of CD: ");
  scanf("%s",name);
  strcpy(temp->name,name);



  printf("Enter title of CD: ");
  scanf("%s",title);
  strcpy(temp->title,title);

  printf("Enter year of CD: ");
  scanf("%d",&year);

  temp->year = year;


  return temp;

}

void delete_node(Box *head,Box *node){
  Box temp = NULL;
  Box nodeToDelete = NULL;
  temp = *head;

  while (*node != NULL && temp != NULL){


    if ((strcmp(temp->name, (*node)->name) == 0 )){

      if( (strcmp((*node)->title,temp->title) == 0) ) {
        if (((*node)->year==temp->year)) {
          nodeToDelete = temp;
          printf("\nNew Deletion\n");
          printf("List name to delete %s\n", nodeToDelete->name);
          printf("Node name to delete %s\n",  (*node)->name);
          printf("\n");

          if(temp->prev != NULL){
            temp->prev->next = temp->next;
            // printf("Setting Heading index\n");
          } else {
            
            temp->next->prev = NULL;
            temp = temp->next;
            (*head) = (*head)->next;
            temp->prev = NULL;
          }

          if(temp->next != NULL){
            temp->next->prev = temp->prev;
          }else {
            temp->prev->next = NULL; 
          }
            nodeToDelete = NULL;
            *node = (*node)->next;
          }

        } 
      }

     
        temp = temp->next;
      
    
  }

}

Box search_by_name(Box head,char *input){
   Box temp = NULL;
  Box result = NULL;
  Box next = NULL;
  Box storage;
  int found = 0;
  for (temp=head; temp != NULL; temp = temp->next) {
  
    if(strcmp(temp->name,input) == 0) {
      storage=(Box)malloc(sizeof(struct Node));
      strcpy(storage->name,temp->name);
      strcpy(storage->title, temp->title);
      storage->year = temp->year;

      if (found == 1){
        next->next = storage;
        next = next->next;
      }else {
        result = storage;
        next = storage;
      }
      found = 1;
    }

  }

  if(found == 0){
    printf("Name %s Not found\n",input );
  } else {
    printf("Name %s found\n",input );
  }

  return result;

}


Box search_by_title(Box head,char *input){
  Box temp = NULL;
  Box result = NULL;
  Box next = NULL;
  Box storage;
  int found = 0;
  for (temp=head; temp != NULL; temp = temp->next) {
  
    if(strcmp(temp->title,input) == 0) {

      storage=(Box)malloc(sizeof(struct Node));
      strcpy(storage->name,temp->name);
      strcpy(storage->title, temp->title);
      storage->year = temp->year;

      if (found == 1){
        next->next = storage;
        next = next->next;
      }else {
        result = storage;
        next = storage;
      }
      found = 1;
    }

  }

  if(found == 0){
    printf("title %s Not found\n",input );
  } else {
    printf("title %s found\n",input );
  }

  return result;

}


char* translate(char *str)
{ 
    
  int len = strlen(str);
    // Start traversing from second chracter 
    for (int i=1; i < len; i++) 
    { 
        // If previous character is 'A' and 
        // current character is 'B" 
        if ( str[i]=='_') 
        { 
          
            str[i] = ' '; 
          
        } 
    } 
    return str; 
}



Box search_by_year(Box head,int year){
  Box temp = NULL;
  Box result = NULL;
  Box next = NULL;
  Box storage;
  int found = 0;
  for (temp=head; temp != NULL; temp = temp->next) {
  
    if(temp->year == year) {

      printf("Found Title %s\n",temp->name );

      storage=(Box)malloc(sizeof(struct Node));
      strcpy(storage->name,temp->name);
      strcpy(storage->title, temp->title);
      storage->year = temp->year;


      if (found == 1){
        next->next = storage;
        next = next->next;
      } else {
        result = storage;
        next = storage;
      }
      
      found = 1;
      
    }

  }

  if(found == 0){
    printf("Year %d Not found\n",year);
  } else {
    printf("Year %d found\n",year );
  }

  return result;

}

int numberOfLines(FILE *fp){
    int count = 0;
    char c;
    int pc = '\n';
    if (fp == NULL) 
    { 
      printf("Could not open file "); 
      return 0; 
    }


    while (c = fgetc(fp), c != EOF)
    {
      if (c == '\n'  &&  pc != '\n')
          count++;
      pc = c;
    }
    if (pc != '\n')
        count++;

  
    // Extract characters from file and store in character c 
    // for (c = getc(fp); c != EOF; c = getc(fp)) 
    //     if (c == '\n') // Increment count if this character is newline 
    //         count = count + 1; 
  
    // Close the file 
    fclose(fp); 
    
    printf("The file has %d lines\n", count); 
  
    return count;
}

// void delete_by_name(Box head, char *name){
//   Box temp;
// }

void sort_by_name( Box head, int noNodes){
  
    Box temp,storage;
    int i = 0;

    for (i = 0; i < noNodes-1 ; i++)
      for (temp=head; temp->next != NULL; temp = temp->next)
      {
        if(strcmp(temp->name,temp->next->name) > 0)
        {
          storage=(Box)malloc(sizeof(struct Node));
          strcpy(storage->name,temp->name);
          strcpy(storage->title, temp->title);
          storage->year = temp->year;

          strcpy(temp->name,temp->next->name);
          strcpy(temp->title,temp->next->title);
          temp->year = temp->next->year;

          strcpy(temp->next->name, storage->name);
          strcpy(temp->next->title,storage->title);
           temp->next->year = storage->year ;

        }
      }
      printf("\n");

        printf("Sorting by Name \n");

      for (temp = head; temp != NULL; temp=temp->next){

      printf( "%s, %s, %d \n", temp->name, temp->title, temp->year);
    }


  }


  // Sort and Swap by DATA
  void sort_by_title( Box head,int noNodes){
  
    Box temp;
    Box before,after;
    Box one,two,storage;
    int i = 0;

    for (i = 0; i < noNodes-1; i++)
     
      for (temp=head; temp != NULL && temp->next != NULL; )
      {
        // printf("Running\n");

        printf(" title is %s  \n", temp->title);
        printf("Next title is %s  \n", temp->next->title);
        if(strcmp(temp->title,temp->next->title) > 0)
        {
                 
          
          before = temp->prev;
          one = temp;
          two = temp->next;

          printf("Error is here\n");

          if (temp->next != NULL)
            after = temp->next->next;

          
          storage = one;
          one = two;
          two = storage;

          if (before != NULL)
            before->next = one;
          else
            head = one;
          one->prev = before;
          one->next = two;
          two->prev = one;
          two->next = after;
          if (after != NULL)
            after->prev = two;


          temp = temp->next;



        } else {
          temp = temp->next;
        }


      }
      printf("\n");

        printf("Sorting by Title \n");

      for (temp = head; temp != NULL; temp=temp->next){

      printf( "%s,%s,%d \n", temp->name, temp->title, temp->year);
    }


  }

  void sort_by_year( Box head,int noNodes){
  
    Box temp,storage;
    int i = 0;

    for (i = 0; i < noNodes-1; i++)
      for (temp=head; temp->next != NULL; temp = temp->next)
      {
        if(temp->year > temp->next->year)
        {
          storage=(Box)malloc(sizeof(struct Node));
          strcpy(storage->name,temp->name);
          strcpy(storage->title, temp->title);
          storage->year = temp->year;

          strcpy(temp->name,temp->next->name);
          strcpy(temp->title,temp->next->title);
          temp->year = temp->next->year;

          strcpy(temp->next->name, storage->name);
          strcpy(temp->next->title,storage->title);
           temp->next->year = storage->year ;

        }
      }
      printf("\n");

        printf("Sorting by Year\n");

      for (temp = head; temp != NULL; temp=temp->next){

      printf( "%s, %s, %d \n", temp->name, temp->title, temp->year);
    }


  }

 

 
Box insert_node(FILE *inputp)

{

    Box temp=NULL;



    temp=(Box)malloc(sizeof(struct Node));

    fscanf(inputp, "%s", &temp->name);

   fscanf(inputp, "%s",  &temp->title);

   fscanf(inputp, " %d", &temp->year);

    temp->next=NULL;

    temp->prev=NULL;

    

  return temp;

}