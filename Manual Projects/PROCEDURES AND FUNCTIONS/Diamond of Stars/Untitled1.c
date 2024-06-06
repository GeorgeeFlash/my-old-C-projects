#include <stdio.h>
#include <stdlib.h>

void stars();
void spaces();

int main()
{
	int input;
	
	do
	{
		printf("Enter an odd number: ");
		scanf("%d", &input);	
	} while(input % 2 != 1);
	
	stars(input);
	
	
	return 0;
}

void stars(int input)
{
	int spa = input;

	for(int i=1; i<=input; i+=2)
	{
		spaces(spa);
		spa -=2;
		for(int j=0; j<i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	spa = spa - (spa-2);
	for(int k=input - 1; 1<k; k-=2)
	{
		spaces(spa);
		for(int l=1; k>l; l++)
		{
			printf("*");
		}
		spa+=2;
		printf("\n");
	}
}
void spaces(int spa)
{
	for(int i=0; i<spa/2; i++)
	{
		printf(" ");
	}
} 