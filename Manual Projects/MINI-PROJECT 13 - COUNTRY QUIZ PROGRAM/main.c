#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
	//Declaring variables
	char countries[][15] = {"Cameroon", "South Africa", "Kenya", "Senegal", "Ethopia", "Nigeria", "Algeria", "Morocco", "Uganda", "Ghana"};
	char capitals[][15] = {"Yaounde", "Cape Town", "Nairobi", "Dakar", "Addis Ababa", "Abuja", "Algiers", "Rabat", "Kampala", "Accra"};
	char response[15];
	int selected[10];	//Selected will be used to generate non-repeating random numbers(countries) from 1 to 10
	int randomCountry;
	int score = 0, i, k = 1, count = 0;
	
	//Generating a seed to select a random country
	srand(time(0));
	
	//filling selected with values from 1 to 10
	for(i = 0; i < 10; i++)
	{
		selected[i] = k;
		k++;
	}
	
	printf("\t\t==========*COUNTRY QUIZ PROGRAM!*==========\n\n");
	
	printf("Options: ");
	for(i = 0; i < sizeof(capitals)/sizeof(capitals[0]); i++)
	{
		printf("%s \t", capitals[i]);
	}
	
	printf("\n\n");
	
	//first do while loop for asking the user 10 questions
	do
	{
		//The second do while loop for generating unique random numbers 
		do
		{
			randomCountry = rand() % 10;
		} while(selected[randomCountry] == 0);
		selected[randomCountry] = 0;
		
		printf("What is the capital of %s: ", countries[randomCountry]);
		fgets(response, 15, stdin);
		response[strlen(response) - 1] = '\0';
		
		if(strcmp(response, capitals[randomCountry]) == 0)
		{
			printf("CORRECT!\n");
			score ++;
		}
		else 
		{
			printf("WRONG!\n");
		}
		count++;
		printf("\n\n");
	} while(count < 10);
	
	if(score < 4)
	{
		printf("Your Score: %d/%d. Too Bad! :(\n", score, 10);
	}
	else if(score < 7)
	{
		printf("Your Score: %d/%d. At lest you tried!\n", score, 10);
	}
	else
	{
		printf("Your Score: %d/%d. Good Job! :)\n", score, 10);
	}

	return 0;
}
