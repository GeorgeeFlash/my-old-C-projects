#include <stdio.h>
#include <windows.h>

int factorial (int);
int main()
{
	int num, fact;
	printf("Enter a positive integer value: ");
	scanf("%d", &num);
	fact = factorial (num);
	printf("\nFactorial of %d = %5d\n", num, fact);
}
int factorial (int n)
{
	int i, result = 1;
	if(n==0)
		return (result);
	else if(n>0)
	{
		for(i=1; i<n; i++)
			result = result * i; // Iteration
	}
	else
	{
		printf("You didn't enter a positive integer!\n");
		exit(0);
	}
	return (result);
}