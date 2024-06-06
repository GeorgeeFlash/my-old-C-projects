#include <stdio.h>
#include <conio.h>

int main(void)
{
	int n, i,  factorial = 1;

	printf("Enter a positive integer: ");
	scanf("%d", &n);

	for(i = 1; i <= n; i ++)
	{
		factorial *= i;
	}

	printf("Sum of first %d natural numbers is: %d\n", n, factorial);
	
	return 0;
}
