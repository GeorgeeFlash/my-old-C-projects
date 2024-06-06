#include <stdio.h>
#include <stdlib.h>

void printStars();
void space();
int main()
{
	int input;
	
	do
	{
		printf("Enter an odd number: ");
		scanf("%d", &input);
	}while(input % 2 != 1);
	
	printStars(input);
	
	return 0;
}

void printStars( int input)
{	
	for(int i=1; i<=input; i+=2)
	{
		
		for(int j=0; j<i;j++ )
		{
		
		
		printf("\n
	");
	for(int k=input-2; k>=1; k-=2)
	{
		      k
		//input +=2;
		for(int l=1; k>=l; l++)
		{
			
		}
		printf("\n");
	}
}
void space(int spa)
{
	for(int i=0; (spa/2)>i; i++)
	{
		printf(" ");
	}
}
              

	
