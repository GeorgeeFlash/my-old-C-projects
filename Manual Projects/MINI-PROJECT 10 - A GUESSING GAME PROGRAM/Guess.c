#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A guessing game program

int main(void) 
{
	// Declaring variables
	int num, input, count = 0, countHowHigh = 0, countHowLow = 0;
	
	// To generate a random seed
	srand(time(0));
	
	num = (rand() % 10) + 1;
	
	// Loop this till the answer is correct
	while(input != num)
	{
		printf("Enter a number: ");
		scanf("%d", &input);
		if(input < num)
		{
			printf("Too low.\n");
			countHowLow ++;
		}
		else if(input > num)
		{
			printf("Too high.\n");
			countHowHigh ++;
		}
		
		count ++;
	}
	
	if(input == num)
	{
		printf("You won!\n");
		printf("You guessed %d times.\n", count);
		printf("You guessed %d times higher than the answer and %d times lower than the  answer.\n", countHowHigh, countHowLow);
	}
	
	return 0;
}