/*
************************************************************
|                                                          |
|            Ternary Search Guessing Game Program          |
|                                                          |				
************************************************************
*/


/**
 *
 * @author Oladotun Opasina
 * 
 * The purpose of this program is to use ternary search to guess a user's number that they choose
 * and to check with cheat detection.
 * 
 * The algorithm splits the lower bounds and upper bounds into three and check in the three bounds
 * to make sure that the value exist
 * The algorithm checks in mid1 to see if the number exists
 * Then mid2 if the number is greater than mid1 until the value is found or not 
 * 
 * 03/22/9
 * 
 */



#include <stdio.h>

int main(void)
{
	int low,high,mid1, mid2, counter, answer;

	printf("The goal of this game is to guess a number in your mind \n");

	printf("Please enter a low bound \n");
	scanf("%d", &low);
	printf("Please enter a high bound \n");
	scanf("%d", &high);
	counter = 1;

	while (low <= high) {
		
		mid1 = low +((high - low)/3); // Calculate the first mid value for the first quarter of the bound
		mid2 = high - ((high - low)/3); // Calculate the second mid value for the first quarter of the bound

		printf("Question %d \n",counter);
		printf("Please press 1 if your number smaller than %d \n", mid1);
		printf("Please press 2 if your number is equal to %d \n", mid1);
		printf("Please press 3 if your number greater than %d \n", mid1);

		scanf("%d", &answer);
		counter += 1;

		if(answer==2)
		{
			printf("Guessed Correctly\n");
			printf("Your number is %d", mid1);
			low = high + 1; //get out of the loop
		}
		else if(answer == 1)  // If the number is smaller than mid1, update the upper bound
		{
			
			high= mid1- 1;
			
		}

		else // If the number is larger than mid1, check the mid2 part of the number

		{
			
			printf("Question %d \n",counter);
			
			printf("Please press 1 if your number smaller than %d \n", mid2);
			printf("Please press 2 if your number is equal to %d \n", mid2);
			printf("Please press 3 if your number greater than %d \n", mid2);

			scanf("%d", &answer);
			counter += 1;

			if(answer==2)
			{
				printf("Guessed Correctly\n");
				printf("Your number is %d", mid2);
				low= high + 1; //get out of the loop
			}
			else if(answer == 1) { // If the number is smaller than mid2, update the upper bound
				high = mid2 -1 ;

			} else { // If the number is larger than mid2, update the lower bound
				// low = mid1 + 1;
				low = mid2 + 1;
			}
		}
		
		if(high-low <= 1){ // Check if the user is cheating
			printf("\n You are cheating..Ending game\n");
			low = high + 1;
		}
				
		
	}
	return 0;
}









