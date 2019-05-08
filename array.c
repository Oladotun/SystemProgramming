/*
* Name: Oladotun Opasina
* Class: System Programming
* Filename: array.c
* Assignment details: The aim of this assignment is to write functions on a pointer array
	Functions including sorting, searching, finding min and max
*/

#include <stdio.h>
#include <stdlib.h>
#include "array.h" // Header file included



void main() 
{
	int size;

	int *a;
	int i;

	printf("How many numbers do you want to enter? \n");
	scanf("%d", &size);

	a = (int*) calloc(size, sizeof(int));
	array_accom(a, size) ;
	
	printf("Printing the array\n");
	for(i=0; i < size; i++)
		printf("%d\n", a[i]);

	switch_func(a,size); // Menu function
	printf("Freeing up memory\n" );
	free(a);
}

void switch_func(int *a, int size){

	int input = 1;

	printf("Selection Menu\n");
	printf("-----------------\n");
	printf("1. Linear Search\n");
	printf("2. Find Minimum and Maxium in array\n");
	printf("3. Bubblesort array\n");
	printf("4. Bubblesort array in reverse\n");
	printf("5. Counting sort array\n");
	printf("6. Print with Pointers Backward\n");
	printf("7. Print recursively forward\n");
	printf("8. Print recursively backward\n");
	printf("9. Binary Search\n");
	printf("Enter an input from 1-8 to select a function: ");
	scanf("%d",&input);

   switch(input) {
      case 1 :
         linear_search(a,size);
         break;
      case 2 :
      	  find_minmax(a,size);
      	  break;
      case 3 :
         bubble_sort(a,size);
         print_fw(a,size);
         break;
      case 4 :
         bubble_sort_reverse(a,size);
         print_fw(a,size);
         break;
      case 5 :
         counting(a, size);
         break;
      case 6 :
         print_withpointers(a,size);
         break;
      case 7 :
         forward_rec(a,size,0);
         break;
      case 8 :
         backward_rec(a,size);
         break;
      case 9:
      	  binary_search(a,size);
      	  break;
      default :
         printf("Wrong Input\n" );
   }
}

// Create Array allocation

void array_accom(int *a, int size) 
{
	int i;
	printf("please enter %d numbers \n", size);

	for (i = 0; i < size; i++) 
	{
		scanf("%d", &a[i]);
	}
}

// Do a linear search
void linear_search(int *a, int size)
{
	int num;
	int found = 0;
	int i;
	printf("What number do you want to search for ? \n");
	scanf("%d", &num);

	
	// Search in array
	for (i = 0; i < size && found == 0; i++) {
		if (a[i] == num) {
			printf("Number %d found\n", num);

			found = 1;
		}
	}

	if (found == 0)
		printf("Number %d not in array\n", num);
	
}

// Binary search on array

void binary_search(int *a,int size){
	int low, high, middle,num;
	int found = 0;
	low = 0;
	high = size-1;



	printf("What number do you want to search for ? \n");
	scanf("%d", &num);


	// Start the binary search
	while(low<=high)
	{
		middle=(low+high)/2; // Split array to two

		// printf("a[middle] is %d\n", a[middle]);
		// printf("Your number is %d\n", num);
		// printf("middle is %d\n",middle );

		if(a[middle]==num)
		{
			printf("Your number %d was found\n", num);
			low= high + 1; //get out of the loop
			found = 1;
		}else {
			if(num < a[middle]) // if the number is less than middle , update high number
				high= middle - 1;
			else // if the number is greater than middle, update lower number
				low=middle + 1;

		}
	}

	if(found == 0){
		printf("Your number %d was not found\n", num);
	}
}


void find_minmax(int *a, int size) {
	int min;
	int max;
	int i;
	min = a[0];
	max = a[0];
	


	for (i = 0; i < size; i++) {
		// Find min
		if (a[i] < min){
			min = a[i];
		}

		// Find max
			
		if (a[i] > max) {
			max = a[i];
		}
			

	}

	printf("Minimum is %d and Maximum is %d \n", min,max);

}

// Bubble sort efficient
void bubble_sort(int *a, int size) 
{
	int i,j;
	int temp;
	int changed = 1;

	// Sort only if needed

	for (j = 0; j < size-1 && changed == 1; j++){

		changed = 0;

		for ( i = 0; i < size-1; i++) {

		if(a[i] > a[i+1]) {

			temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
			changed = 1; // The array was changed
		}
	}
	// printf("Resorting again\n");

	}
	
}

// Print forward
void print_fw(int *a, int size)
{
	int i;
	printf("Printing Forward\n");
	for( i=0; i < size; i++)
		printf("%d\n", a[i]);

}

// Print array backward

void print_bw(int *a, int size)
{
	int i;
	printf("Printing Backward\n");
	for( i=size-1; i >= 0; i--)
		printf("%d\n", a[i]);

}

// Do a bubble sort reverse
void bubble_sort_reverse(int *a, int size) 
{
	int i,j;
	int temp;
	int changed = 1;
	for (j = 0; j < size-1 && changed == 1; j++){
		changed = 0;
		for ( i = 0; i < size-1; i++) {

		if(a[i] < a[i+1]) {

			temp = a[i+1];
			a[i+1] = a[i];
			a[i] = temp;
			changed = 1;
		}
	}

	}
	
}

// Swap Array position

void swap(int *a, int *b)
{
	int *temp;

	temp = a;
	a = b;
	b = temp;
}


// Make sense to use when the maximum number of the array is comparable to the length of the array


int check(int *a,int size)
{
  if(size==0)
  {
       return 1;
  }
  else
  {
     if(a[size]>a[size-1])
     {
       return check(a,size-1);
     }
     else
     {
       return 0;
     }
 
  }
}

// Efficient counting stable array
void counting(int *a, int size)
{
	int c_size;
	int *c;
	int input;

	int max;
	int i;
	max = a[0];

	if (check(a,size-1)==1) // If it sorted print and do not search: Efficient
	{
		printf("Your array is already sorted\n");
		print_fw(a,size);
	}else { 

		// Find max value
		for (i = 0; i < size; i++) {
				
			if (a[i] > max) {
				max = a[i];
			}
				

		}

		c_size = max + 1;



		c = (int*)calloc(c_size, sizeof(int));

		// Initialize position of index with zero
		for (i=0; i < c_size;i++)
			c[i] =0;


		// Increment index value if value is found
		for ( i = 0; i < size; i ++) {
			int index = a[i];
			c[index]++;

		}
		//Print out the sorted array
		for (i = 0; i < c_size; i++){
			int index_value = c[i];
			while(index_value > 0){
				printf("%d \n", i);
				index_value--;
			}
			
		}

		// for search ask the user for the target number

		printf("Enter the input you are searching for in the array: \n");
		scanf("%d",&input);

		if(input < c_size){
			if(c[input] > 0 ) {
				printf("%d was found\n", input);
			}else {
				printf("%d was not found\n", input);
			}
		} else {
			printf("%d was not found\n", input);
		}
		printf("Freeing up memory\n" );
		free(c); //Free created pointer

	}



	
	


}



// Print with pointers
void print_withpointers(int *a, int size)
{
	int *p;

	

	printf("Printing array backwards with pointers \n");

	for (p= a + size -1; p >= a; p--) 
		printf("%d\n",*p );

}

// Forward recursion print
void forward_rec(int *a, int size, int first_index) {
	
	if (first_index == size-1){
		printf("%d\n",a[first_index] );
	} else {
		printf("%d\n",a[first_index] );

	first_index++;
	forward_rec(a,size,first_index);

	}
	
}

// Backward recursion print
void backward_rec(int *a, int size) {
   int last_index;
   if (size > 0){

   	last_index = size - 1;
	printf("%d\n",a[last_index] );
	size--;

	if(last_index >= 0) {

		backward_rec(a,size);
	}

   }
	
}
