#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{	int Tally[6];
	int index = 1, i; //index will be used for numbering the elements in the tally array
	
	for(i=0; i<6; i++)
	{
		Tally[i] = 0;
	}
	
	srand(time(0)); //Time seed to generate random numbers
	
	for(i=0; i<200; i++)
	{
		int die = (rand() % 6) + 1;
				
		switch(die)
		{
			case 1:
					Tally[0] += 1;
				break;
			case 2:
					Tally[1] += 1;
				break;
			case 3:
					Tally[2] += 1;
				break;
			case 4:
					Tally[3] += 1;
				break;
			case 5:
					Tally[4] += 1;
				break;
			case 6:
					Tally[5] += 1;
				break;
		}
	}
	
	printf("\t\t\t\t  ===========*TALLY CHART*===========\n\n");
	
	for(i=0; i<6; i++)
	{
		printf("\n\t\t\t\t\t\t\t*********\n");
		printf("\t\t\t\t\tNumber of %d's   |%d\t|", index, Tally[i]);
		printf("\n\t\t\t\t\t\t\t*********\n");	
		index ++;
	}
	
	return 0;
}
