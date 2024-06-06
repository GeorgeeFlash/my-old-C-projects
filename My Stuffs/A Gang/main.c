#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int  day, lower = 2014, upper = 2021, i;
	
	srand(time(0));
	
	printf("\t\t\t\t***********************************************\n");
	printf("\t\t\t\t\t\tTime Table And Program\n");
	printf("\t\t\t\t***********************************************\n");
	
	printf("\n\t\t\t\t\t---------------\n");
	printf("\t\t\t\t\t|Enter day: ");
	scanf("%d", &day);
	fgetc(stdin);
	printf("\t\t\t\t\t---------------");
	
	int randYear = (rand() % ( upper-lower+1 )) + lower;
	int randPaper = (rand() % (3-1+1)) + 1;
	
	printf("\n\t\t\t\t***********************************************");
	switch(day)
	{
		case 1:
			printf("\n\t\t\t\t\tTuesday: Computer Science\n");
			printf("\t\t\t\t\tWe will be studying %d paper %d today\n", randYear, randPaper);
			break;
		case 2:
			printf("\n\t\t\t\t\tWednesday: Computer Science\n");
			printf("\t\t\t\t\tWe will be studying %d paper %d today\n", randYear, randPaper);
			break;
		case 3:
			printf("\n\t\t\t\t\tThursday: Biology and Physics\n");
			printf("\t\t\t\t\tWe will be studying %d paper %d today\n", randYear, randPaper);
			break;
		case 4:
			printf("\n\t\t\t\t\tFriday: Computer Science and Biology\n");
			printf("\t\t\t\t\tWe will be studying %d paper %d today\n", randYear, randPaper);
			break;
		case 5:
			printf("\n\t\t\t\t\tSaturday: Maths and Chemistry\n");
			printf("\t\t\t\t\tWe will be studying %d paper %d today\n", randYear, randPaper);
			break;
		default:
			printf("\nPlease enter a number from 1 to 5 coresponding to a day of studies!\n");
			break;
	}
	printf("\t\t\t\t***********************************************\n");
	printf("\n\n\n\n");
	
			
	return 0;
}
