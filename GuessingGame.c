/*
************************************************************
|                                                          |
|            Binary Search Guessing Game Program           |
|                                                          |				
************************************************************
*/


/**
 *
 * @author Oladotun Opasina
 * 
 * The purpose of this program is to use Binary search to guess a user's number that they choose
 * and to check with cheat detection.
 * 
 * The algorithm calculates the mid position from the lower bounds and upper bounds into
 * and asks for the user input to make sure that the value exist
 * If the value is greater than the mid the lower bound is updated
 * If the value is lower than the middle number the upper bound is updated until the value is found 
 * 
 * 03/22/9
 * 
 */

#include<stdio.h>

int main()
{
	int low, high, middle, counter, answer;

	printf("The goal of this game is to guess a number in your mind \n");

	printf("Please enter a low bound \n");
	scanf("%d", &low);
	printf("Please enter a high bound \n");
	scanf("%d", &high);

	//Calculate the number of questions to be asked
	// in the while loop below you actually  Question 1, Question 2... Thus you should be able to count question

	counter=1;

	while (low > high) {

		printf("The bound was entered wrongly\n");
		printf("Please enter a low bound \n");
		scanf("%d", &low);
		printf("Please enter a high bound \n");
		scanf("%d", &high);

	}
	while(low<=high)
	{
		middle=(low+high)/2;

		printf("Question %d \n",counter);
		printf("Please press 1 if your number smaller than %d \n", middle);
		printf("Please press 2 if your number is equal to %d \n", middle);
		printf("Please press 3 if your number greater than %d \n", middle);

		scanf("%d", &answer);

		if(answer==2)
		{
			printf("Guessed Correctly\n");
			printf("Your number is %d", middle)
			low= high + 1; //get out of the loop
		}

		else

		{
			if(high-low <=1){
				printf("\n You are cheating.. Ending Game \n");
				low = high + 1;
			}
			if(answer==1)

				high= middle - 1;
			
			else
				low=middle + 1;



		}
		counter += 1;
	}


	return 0;

}