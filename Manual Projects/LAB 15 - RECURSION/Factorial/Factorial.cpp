#include <stdio.h>

int fact(int y);

int main()
{
	int n, factorial;
	
	printf("Enter a positive integer: ");
	scanf("%d", &n);
	
	factorial = fact(n);
	
	printf("The factorial of %d is %d", n, factorial);
	
	return 0;
}

int fact(int y)
{
	
	if(y == 0 || y == 1)
		return 1;
	else
		return y * fact(y-1); 
		
}
