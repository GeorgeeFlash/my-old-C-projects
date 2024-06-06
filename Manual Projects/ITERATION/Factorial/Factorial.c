#include <stdio.h>
#include <conio.h>

int main(void)
{
	int n, i,  factorial = 1, check = 0;

	printf("Enter a positive integer: ");
	scanf("%d", &n);

	i = 1;

	if(n < check)
	{
		do
		{
			printf("Enter a non-negative integer: ");
			scanf("%d",&n);
		}while(n < check);
	}
	
	do
	{
		factorial *= i ;
		i ++;	
	} while(i <= n);
	
	printf("The factorial of %d is: %d\n", n, factorial);
	
	
	return 0;
}