#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numbers[4] = {6, 1, 5, 6};
	int index = 1;
	
	printf("List of items: \n");
	for(int i=0; i<4; i++)
	{	
		printf("Item %d\t:%d\n", index,numbers[i]);
		index++;
	}
	
	float sum = 0;
	for(int j=0; j<4; j++)
	{
		sum += numbers[j];
	}
	
	printf("\nEvery other item in the list: \n");
	
	for(int k=0; k<4; k++)
	{
		printf("%d\n", numbers[k]);
	}
	
	float avr = sum/4;
	printf("\nThe average of the items in the list is:\t%f", avr);
	
	return 0;
}